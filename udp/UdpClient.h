#pragma once

class UdpClient{
public:
    UdpClient(short port);
private:
    int m_Socket;
    short m_sPort;
};
