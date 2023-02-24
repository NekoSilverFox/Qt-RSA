#include "client.h"
#include "rsa-math.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    client w;
//    w.show();

    RSAKey key = generateRSAKey(16, 25);

    qDebug() << isMutuallyPrime(352, 3);
    qDebug() << isMutuallyPrime(352, 7);
    qDebug() << "p = " << key.p << "\n"
             << "q = " << key.q << "\n"
             << "e = " << key.e << "\n"
             << "k = " << key.k << "\n"
             << "n = " << key.n << "\n"
             << "fn= " << key.fn << "\n"
             << "d = " << key.d << "\n";

    encryptionString("a文ф");

//    return a.exec();
}
