#include "server.h"
#include "rsa.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    connect(ui->btnEncrypt, &QPushButton::clicked, this, &Server::clickBtnEncrypt);
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
    vector<unsigned int> ciphertext_int(ui->pteExplicitText->toPlainText().toStdString().size(), 0);
    RSA::Encrypt(ui->pteExplicitText->toPlainText().toStdString(), ciphertext_int,
                 ui->le_public_e->text().toUInt(), ui->le_public_n->text().toUInt());
    qDebug() << ciphertext_int;

    ui->tbCodedText->clear();
    QByteArray byteArray;
    for (unsigned int i : ciphertext_int)
    {
        byteArray.append(char(i));
        qDebug() << char(i);
    }

    ui->tbCodedText->append(QString::fromLatin1(byteArray));
}
