#include "widgetmanager.h"
#include "client.h"
#include "server.h"

WidgetManager::WidgetManager(QObject *parent)
    : QObject{parent}
{
    Client* client = new Client;
    Server* server = new Server;

    /* 使用窗口管理器，管理 Client 和 Server 之间的信号 */
    connect(client, &Client::sendPublicKey, server, &Server::setPublicKey);
    connect(server, &Server::sendCodedText, client, &Client::getCodedText);

    client->show();
    server->show();
}
