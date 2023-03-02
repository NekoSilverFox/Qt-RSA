#include "server.h"
#include "rsa.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    connect(ui->btnEncrypt, &QPushButton::clicked, this, &Server::clickBtnEncrypt);
    connect(ui->btnSendCodedText, &QPushButton::clicked,
            this, [=](){ emit Server::sendCodedText(this->ciphertext_int); });

}

Server::~Server()
{
    delete ui;
}


void Server::setPublicKey(unsigned int e, unsigned int n)
{
    ui->le_public_e->setText(QString::number(e));
    ui->le_public_n->setText(QString::number(n));
}

void Server::clickBtnEncrypt()
{
    vector<unsigned int> temp_ciphertext_int(ui->pteExplicitText->toPlainText().toStdString().size(), 0);
    RSA::Encrypt(ui->pteExplicitText->toPlainText().toStdString(), temp_ciphertext_int,
                 ui->le_public_e->text().toUInt(), ui->le_public_n->text().toUInt());
    this->ciphertext_int = temp_ciphertext_int;

    ui->tbCodedText->clear();
    QString str;
    for (unsigned int i : temp_ciphertext_int)
    {
        str.append(QString::number(i));
    }
    ui->tbCodedText->append(str);
//    ui->tbCodedText->append(QString::fromStdString(std::string(this->ciphertext_int.begin(), this->ciphertext_int.end())));  // 字符形式的输出

}
