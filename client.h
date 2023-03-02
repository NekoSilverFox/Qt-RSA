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

public slots:
    void clickBtnGenerateNewRSAParameters();
    void clickBtnReset();
    void clickBtnDecrypt();
    void getCodedText(std::vector<unsigned int> ciphertext_int);

private:
    Ui::Client *ui;
    std::vector<unsigned int> _ciphertext_int;
};

#endif // CLIENT_H
