#include "main.h"

std::string g_sMainDirectory = "";

void Log(std::string str){
    std::ofstream os;
    os.open(g_sMainDirectory + "//session.log", std::ios_base::app);
    os << str << "\n";
    os.close();
}
void ClearLog(){
    remove((g_sMainDirectory + "//session.log").c_str());
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()){
        Log("cant load engine");
        return -1;
    }
    g_sMainDirectory = app.applicationDirPath().toStdString();
    ClearLog();
    Log("Session started");

    UdpClient *client = new UdpClient(22222);

    return app.exec();
}
