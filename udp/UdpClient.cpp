#include "../main.h"

UdpClient::UdpClient(short port){
    m_Socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    m_sPort = port;

    if(m_Socket == -1){
        Log("failed to create socket");
        return;
    }

    if (fcntl(m_Socket, F_SETFL, O_NONBLOCK) < 0) {
        Log("socket unlock error");
        return;
    }

    unsigned long opt = 1;
    if (setsockopt(m_Socket, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(long)) < 0) {
        Log("setsockopt error");
        return;
    }

    sockaddr_in srv, cli;

    srv.sin_addr.s_addr = htonl(INADDR_ANY);
    srv.sin_family = AF_INET;
    srv.sin_port = htons(m_sPort);

    if (bind(m_Socket, (sockaddr*)&srv, sizeof(sockaddr)) < 0) {
        Log("bind socket error. port: " + std::to_string(m_sPort));
        return;
    }

    Log("Socket setting succesful.");
}

int UdpClient::GetSocket(){
    return m_Socket;
}

bool UdpClient::IsListening(){
    return m_bRecieveThreadWorking;
}

void UdpClient::StartListen(callbackPacketRecieve on_packet_recieve){
    m_OnPacketRecieve = on_packet_recieve;
    m_bRecieveThreadWorking = true;
    int err = pthread_create(&m_RecieveThread, NULL, &RecieveThreadFunc, this);
    if (err != 0){
        Log("Cant create thread.");
        m_bRecieveThreadWorking = false;
    }
}

void UdpClient::StopListen(){
    if(m_bRecieveThreadWorking){
        m_bRecieveThreadWorking = false;
        pthread_join(m_RecieveThread, NULL);
    }
}

callbackPacketRecieve UdpClient::GetRecieveCallback(){
    return m_OnPacketRecieve;
}

UdpClient::~UdpClient(){
    Log("Called destructor for UdpClient.");
    if(m_bRecieveThreadWorking){
        m_bRecieveThreadWorking = false;
        pthread_join(m_RecieveThread, NULL);
    }
    close(m_Socket);
}

void* RecieveThreadFunc(void *self){
    UdpClient *client = (UdpClient*)self;
    int sock = client->GetSocket();
    int len;
    socklen_t size;
    char buf[128];
    sockaddr_in cli;
    Log("[THREAD]: Listening.");
    while(client->IsListening()){
        len = recvfrom(sock, buf, sizeof(buf), 0, (sockaddr*)&cli, &size);
        if(len != -1){
            ByteStream bs(buf, len);
            client->GetRecieveCallback()(bs);
            break;
        }
        usleep(10);
    }
    Log("[THREAD]: Exit listening.");
    return nullptr;
}
