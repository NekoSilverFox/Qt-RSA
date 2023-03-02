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

signals:
    void sendCodedText(std::vector<unsigned int> ciphertext_int);

public slots:
    void setPublicKey(unsigned int e, unsigned int n);
    void clickBtnEncrypt();

private:
    Ui::Server *ui;
    std::vector<unsigned int> ciphertext_int;
};

#endif // SERVER_H
