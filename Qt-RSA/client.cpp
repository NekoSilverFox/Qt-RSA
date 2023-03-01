#include "rsa.h"
#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    connect(ui->btnGenerateNewRSAParameters, &QPushButton::clicked, this, &Client::clickBtnGenerateNewRSAParameters);
    connect(ui->btnReset, &QPushButton::clicked, this, &Client::clickBtnReset);
}

Client::~Client()
{
    delete ui;
}


void Client::clickBtnGenerateNewRSAParameters()
{
    RSA *rsa;
    string plaintext_str("abc");                            // 字符串类型的明文
    vector<unsigned int> ciphertext_int(plaintext_str.size(), 0); // 无符号整数类型的密文
    string plaintext_str1(plaintext_str.size(), '\0');            // 字符串类型的明文   解密后的明文

    do
    {
        rsa = new RSA;

        RSA::Encrypt(plaintext_str, ciphertext_int, rsa->e_arg_, rsa->n_arg_);  // 加密得密文
        RSA::Decrypt(ciphertext_int, plaintext_str1, rsa->d_arg_, rsa->n_arg_); // 解密得明文

    } while (plaintext_str != plaintext_str1);

    ui->lb_p->setText(QString::number(rsa->p_arg_));
    ui->lb_q->setText(QString::number(rsa->q_arg_));
    ui->lb_e->setText(QString::number(rsa->e_arg_));
    ui->lb_d->setText(QString::number(rsa->d_arg_));
    ui->lb_n->setText(QString::number(rsa->n_arg_));
    ui->lb_fn->setText(QString::number(rsa->n_Euler_func_arg_));

    ui->le_privete_d->setText(QString::number(rsa->d_arg_));
    ui->le_privete_n->setText(QString::number(rsa->n_arg_));

    ui->le_public_e->setText(QString::number(rsa->e_arg_));
    ui->le_public_n->setText(QString::number(rsa->n_arg_));

    delete rsa;
}

void Client::clickBtnReset()
{
    ui->le_privete_d->setText(ui->lb_d->text());
    ui->le_privete_n->setText(ui->lb_n->text());
}
