#include "client.h"
#include "rsa.h"

#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Client client;
    client.show();



    return a.exec();
}

