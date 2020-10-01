#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <ostream>

#include <bytestream/ByteStream.h>
#include <udp/UdpClient.h>
#include <query/Query.h>
#include <query/SortedQuery.h>

void Log(std::string str);

extern std::string g_sMainDirectory;
