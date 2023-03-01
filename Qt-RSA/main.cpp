#include "clientw.h"
#include "rsa.h"

#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    client client;
    client.show();

    RSA *rsa;
    string plaintext_str("abc");                            // 字符串类型的明文
    vector<unsigned int> ciphertext_int(plaintext_str.size(), 0); // 无符号整数类型的密文
    string plaintext_str1(plaintext_str.size(), '\0');            // 字符串类型的明文   解密后的明文

    do
    {
        rsa = new RSA;

        rsa->Encrypt(plaintext_str, ciphertext_int, rsa->e_arg_, rsa->n_arg_);  // 加密得密文
        rsa->Decrypt(ciphertext_int, plaintext_str1, rsa->d_arg_, rsa->n_arg_); // 解密得明文

    } while (plaintext_str != plaintext_str1);


    delete rsa;

//    return a.exec();
    return 0;
}

