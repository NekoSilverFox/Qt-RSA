#include "client.h"
#include "rsa-math.h"
#include <QDebug>

#include <QApplication>
#include "ras.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RSA *rsa = new RSA;

        string plaintext_str("yezhening");                            // 字符串类型的明文
        vector<unsigned int> ciphertext_int(plaintext_str.size(), 0); // 无符号整数类型的密文
        string plaintext_str1(plaintext_str.size(), '\0');            // 字符串类型的明文   解密后的明文

        rsa->Encrypt(plaintext_str, ciphertext_int);  // 加密得密文
        rsa->Decrypt(ciphertext_int, plaintext_str1); // 解密得明文

        delete rsa;

        return 0;


}


#if 0
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    client w;
//    w.show();

    RSAKey key = generateRSAKey(16, 100);

    qDebug() << "p = " << key.p << "\n"
             << "q = " << key.q << "\n"
             << "e = " << key.e << "\n"
             << "k = " << key.k << "\n"
             << "n = " << key.n << "\n"
             << "fn= " << key.fn << "\n"
             << "d = " << key.d << "\n";

//    qDebug() << QString("a").toLatin1();
#if 0
    QByteArray byteArr = encryptionString("a", 3, 391);
    qDebug() << byteArr;
    QString res_str = decryptionChar(byteArr, 587, 391);
    qDebug() << res_str;
#endif
    QByteArray byteArr = encryptionString("a", key.e, key.n);
    qDebug() << "加密后的 bytearray" << byteArr;
    QString res_str = decryptionChar(byteArr, key.d, key.n);
    qDebug() << "解密后的 bytearray" << res_str;
//    return a.exec();
}
#endif

