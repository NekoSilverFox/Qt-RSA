#ifndef SERVER_H
#define SERVER_H

#include <QWidget>

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();

public slots:
    void setPublicKey(unsigned int e, unsigned int n);
    void clickBtnEncrypt();

private:
    Ui::Server *ui;
};

#endif // SERVER_H
