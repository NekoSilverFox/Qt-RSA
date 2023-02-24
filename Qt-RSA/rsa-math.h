#ifndef RSAMATH_H
#define RSAMATH_H

#include <QRandomGenerator>
#include <qDebug>

struct RSAKey
{
    quint64 p;
    quint64 q;
    quint64 e;
    quint64 k;
    quint64 n;
    quint64 fn;
    quint64 d;
};

/** 获得两数的最大公约数
 * @brief gcd
 * @param a
 * @param b
 * @return
 */
int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

/** 判断是否互为质数
 * @brief isMutuallyPrime
 * @param a
 * @param b
 * @return 互为质数返回 true
 */
bool isMutuallyPrime(int a, int b)
{
    return gcd(a, b) == 1? true : false;
}

/** 获取指定范围内的随机质数
 * @brief generateRandomPrimes
 * @param min
 * @param max
 * @return
 */
quint64 generateRandomPrimes(const quint64 min, const quint64 max)
{
    quint64 i = 0;
    quint64 i_random = 0;

    while (true)
    {
        i_random = QRandomGenerator::global()->bounded(min, max);
        for (i = 2; i <= sqrt(i_random); i++)
        {
            if (i_random % i == 0) break;
        }
        if (i > sqrt(i_random)) return i_random;
        else continue;
    }
}

/** 计算欧拉函数 Ф(p * q)
 * @brief get_fn
 * @param p 质数
 * @param q 质数
 * @return
 */
quint64 get_fn(const quint64 p, const quint64 q)
{
    return (p - 1) * (q - 1);
}

/** 获取指定范围内的随机 e
 * @brief get_e
 * @param min
 * @param max
 * @return
 */
quint64 get_e(const quint64 p, const quint64 q)
{
    quint64 e = 2;
    while (!isMutuallyPrime(get_fn(p, q), e)) e++;
    return e;
}

/** 获取 k
 * @brief get_k
 * @param p
 * @param q
 * @param e
 * @return
 */
quint64 get_k(const quint64 p, const quint64 q, const quint64 e)
{
    quint64 k = 1;
    while (true)
    {
        if (0 == (k * get_fn(p, q) + 1) % e) return k;
        else k++;
    }
}

/** 计算 d
 * @brief get_d
 * @param k
 * @param p
 * @param q
 * @param e
 * @return
 */
quint64 get_d(const quint64 k, const quint64 p, const quint64 q, const quint64 e)
{
    return (k * (p - 1) * (q - 1) + 1) / e;
}


/** 随机生成一个 RSA 密钥所需的所有信息
 * @brief generateRSAKey
 * @param min_p_q
 * @param max_p_q
 * @param min_e
 * @param max_e
 * @return
 */
RSAKey generateRSAKey(const quint64 min_p_q, const quint64 max_p_q)
{
    RSAKey key;

    do
    {
        key.p = generateRandomPrimes(min_p_q, max_p_q);
        key.q = generateRandomPrimes(min_p_q, max_p_q);
    } while (key.p == key.q);

    key.e = get_e(min_p_q, max_p_q);
    key.k = get_k(key.p, key.q, key.e);
    key.n = key.p * key.q;
    key.fn = get_fn(key.p, key.q);
    key.d = get_d(key.k, key.p, key.q, key.e);

    return key;
}


/**
 * @brief encryptionChar
 * @param str
 * @return
 */
QByteArray encryptionString(const QString str)
{
    QByteArray resByteArray = str.toUtf8();

    for (auto c : resByteArray)
    {
        qDebug() << c * 20;
    }

    return resByteArray;
}

/** 解密字符
 * @brief decryptionChar
 * @param c
 */
void decryptionChar(const char c)
{

}

#endif // RSAMATH_H
