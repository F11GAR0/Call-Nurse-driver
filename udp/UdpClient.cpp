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

    int len;
    socklen_t size;
    char buf[128];

    for(;;){
        len = recvfrom(m_Socket, buf, sizeof(buf), 0, (sockaddr*)&cli, &size);
        if(len != -1){
            Log("gotcha!");
            ByteStream bs(buf, len);
            //maybe short, maybe int idk
            int id;
            bs.Read(id, 4);
            Log(std::to_string(id));
            break;
        }
    }
}
