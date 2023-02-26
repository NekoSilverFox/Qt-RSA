#include "client.h"
#include "rsa-math.h"
#include <QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    client w;
//    w.show();

    RSAKey key = generateRSAKey(16, 25);

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


