#include "mainwindow.h"
#include "config.h"
#include "worker.h"
#include <QApplication>



int main(int argc, char *argv[])
{

    int SERV_PORT;
    char SERV_IP[100];
    int server_sock;
    struct sockaddr_in server_addr;

    SERV_PORT = 5500;
    strcpy(SERV_IP, "127.0.0.1");
    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERV_IP);
    // Step 3: Request to connect to the server
    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) < 0)
    {
        perror("t fix connecting to the server");
        close(server_sock); // Close the socket before exiting
        return 1;
    }
    MySingleton::instance().setValue(server_sock);
    qInfo() <<  MySingleton::instance().getValue()  << " main";

    QApplication a(argc, argv);
    MainWindow w;




    w.show();

    return a.exec();
}
