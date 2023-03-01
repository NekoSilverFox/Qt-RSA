#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

signals:
    void sendPublicKey(unsigned int e, unsigned int n);

private slots:
    void clickBtnGenerateNewRSAParameters();
    void clickBtnReset();

private:
    Ui::Client *ui;
};

#endif // CLIENT_H
