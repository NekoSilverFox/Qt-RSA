#include "server.h"
#include "rsa.h"
#include "ui_server.h"

#include <QMessageBox>

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    this->setWindowTitle("RSA Server");
    this->setWindowIcon(QIcon(":/Encrypt.svg"));
    this->setAttribute(Qt::WA_DeleteOnClose);

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
    if (ui->pteExplicitText->toPlainText().isEmpty() ||
            ui->le_public_e->text().isEmpty() ||
            ui->le_public_n->text().isEmpty())
    {
        QMessageBox::warning(this, "Warining", "Public key or Explicit text is empty!");
        return;
    }

    this->ciphertext_int = RSA::Encrypt(ui->pteExplicitText->toPlainText().toStdString(),
                                        ui->le_public_e->text().toUInt(), ui->le_public_n->text().toUInt());

    ui->tbCodedText->clear();
    QString str;
    for (unsigned int i : this->ciphertext_int)
    {
        str.append(QString::number(i));
    }
    ui->tbCodedText->append(str);
//    ui->tbCodedText->append(QString::fromStdString(std::string(this->ciphertext_int.begin(), this->ciphertext_int.end())));  // 字符形式的输出

}
