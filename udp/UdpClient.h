#pragma once
#include <pthread.h>

typedef void (*callbackPacketRecieve)(ByteStream);

class UdpClient{
public:
    UdpClient(short port);
    void StartListen(callbackPacketRecieve on_recieve_packet);
    void StopListen();
    ~UdpClient();
    int GetSocket();
    bool IsListening();
    callbackPacketRecieve GetRecieveCallback();
private:
    int m_Socket;
    pthread_t m_RecieveThread;
    callbackPacketRecieve m_OnPacketRecieve;
    bool m_bRecieveThreadWorking;
    short m_sPort;
};

/// Threading func for UdpClient. Param "self" is pointer to UdpClient which create thread with this func.
void* RecieveThreadFunc(void *self);
