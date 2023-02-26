#ifndef RSAMATH_H
#define RSAMATH_H

#include <QRandomGenerator>
#include <qDebug>
#include <string>>

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
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

bool isPrimeNum(long long num)
{
    if (num < 2)return false;
    for (int i = 2; i < num / 2; i++)
    {
        if (num % i == 0)return false;
    }
    return true;
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




std::string getCountAdd(std::string a, std::string b)
{
    std::string c = "";
    int bit = -1; //判断是否进位 -1为否，其他为进位数
    int i = a.length()-1; //获得a字符串长度
    int j = b.length()-1; //获得b字符串长度
    //第一种情况 两者都处理完
    while (i != -1 && j != -1)
    {
        int t1 = a[i] - 48;
        int t2 = b[j] - 48;
        //不存在进位
        if (bit == -1)
        {
            if (t1 + t2 >= 10)
            {
                int d = (t1 + t2) % 10;
                c.insert(0, 1, d + 48);
                bit = (t1 + t2) / 10;
            }
            else
            {
                c.insert(0, 1, t1 + t2 + 48);
            }
        }
        //存在进位
        else
        {
            if (t1 + t2 + bit >= 10)
            {
                int d = (t1 + t2 + bit) % 10;
                c.insert(0, 1, d + 48);
                bit = (t1 + t2 + bit) / 10;
            }
            else
            {
                c.insert(0, 1, t1 + t2 + bit + 48);
                bit = -1;
            }
        }
        i--;
        j--;
    }
    //第二种情况 前者处理完
    while (i == -1 && j != -1)
    {
        int t2 = b[j] - 48;
        if (bit == -1)
        {
            c.insert(0, 1, b[j]);
        }
        else
        {
            if (t2 + bit >= 10)
            {
                int d = (t2 + bit) % 10;
                c.insert(0, 1, d + 48);
                bit = (t2 + bit) / 10;
            }
            else
            {
                c.insert(0, 1, t2 + bit + 48);
                bit = - 1;
            }
        }
        j--;
    }
    //第三种情况 后者处理完
    while (i != -1 && j == -1)
    {
        int t1 = a[i] - 48;
        if (bit == -1)
        {
            c.insert(0, 1, a[i]);
        }
        else
        {
            if (t1 + bit >= 10)
            {
                int d = (t1 + bit) % 10;
                c.insert(0, 1, d + 48);
                bit = (t1 + bit) / 10;
            }
            else
            {
                c.insert(0, 1, t1 + bit + 48);
                bit = -1;
            }
        }
        i--;
    }
    //最后再判断是否存在进位
    if (bit != -1)
    {
        c.insert(0, 1, bit + 48);
    }
    bit = -1;
    return c;
}


std::string getCountExp(int a, int b)
{
    //计算a^b
    std::string a1 = std::to_string(a);
    //std::string b1 = to_std::string(b);
    int i = a1.length()-1;//a的最后下角标
    //int j = b1.length()-1;//b的最后下角标
    //m位数*n位数长度不会超过m+n位
    std::string temp = a1; //temp一直变化
    std::string temp_2 = "0";
    int bitcount = 0; //判断当前位数
    int bit = -1;//判断是否存在进位
    std::string * arr = new std::string[a1.length()];//保存每次计算的数
    int arr_i = 0;
    for (int x = 1; x < b; x++)//几次方就循环几次
    {
        while (i != -1)//乘数的位数
        {
            //temp * a1
            int t1 = a1[i] - 48;
            int j = temp.length() - 1;//temp的最后下角标
            for (int z = 0; z < bitcount; z++)
            {
                arr[arr_i].insert(0, 1, '0');
            }
            while (j != -1)//temp的位数
            {
                int t2 = temp[j] - 48;
                if (bit == -1)//判断是否有进位
                {
                    if (t1*t2 >= 10)
                    {
                        int d = (t1*t2) % 10;
                        arr[arr_i].insert(0, 1, d + 48);
                        int d_2 = (t1*t2) / 10;
                        bit = d_2;
                    }
                    else
                    {
                        int d = t1*t2;
                        arr[arr_i].insert(0, 1, d + 48);
                    }
                }
                else
                {
                    if ((t1*t2)+bit >= 10)
                    {
                        int d = ((t1*t2) + bit) % 10;
                        arr[arr_i].insert(0, 1, d + 48);
                        int d_2 = ((t1*t2) + bit) / 10;
                        bit = d_2;
                    }
                    else
                    {
                        int d = (t1*t2) + bit;
                        arr[arr_i].insert(0, 1, d + 48);
                        bit = -1;
                    }
                }
                j--;
            }
            if (bit != -1)
            {
                arr[arr_i].insert(0, 1, bit + 48);
                bit = -1;
            }
            temp_2 = getCountAdd(temp_2, arr[arr_i]);
            bitcount++;
            arr_i++;
            i--;
        }
        bitcount = 0;
        temp = temp_2;
        temp_2 = "0";
        for (int z = 0; z < arr_i; z++)
        {
            arr[z] = "";
        }
        arr_i = 0;
        i = a1.length() - 1;
    }
    return temp;
}

int getCountMod(std::string a, int b)
{
    int bit = -1; //判断是否需要进位
    //例如4255%5
    int i = 0;
    while (i < a.length())
    {
        int t1 = a[i] - 48;
        if (bit == -1)
        {
            if (t1%b > 0)
            {
                bit = t1%b;
            }
        }
        else
        {
            if (((bit * 10) + t1) % b>0)
            {
                bit = ((bit * 10) + t1) % b;
            }
        }
        i++;
    }
    if (bit != -1)
    {
        return bit;
    }
    else
    {
        return 0;
    }
    return 0;
}


QByteArray encryptionString(const QString str, quint64 e, quint64 n)
{
    QByteArray resByteArray;
    for (auto c : str.toLatin1())
    {
        std::string str = getCountExp(c, e);
        long long m = getCountMod(str, n);
        qDebug() << "当前需加密字符：" << c << " 加密之后  加密字符：" << m;
        resByteArray.append(m);
    }

    return resByteArray;
}

/** 解密字符
 * @brief decryptionChar
 * @param c
 */
QString decryptionChar(QByteArray byteArr, quint64 d, quint64 n)
{
    QByteArray resByteArr;
    for (auto c : byteArr)
    {
//         qDebug() << "解密字符：" << c << (quint64)c << qPow((quint64)c, d) << "加密后的A码：" << (char)qPow((quint64)c, d) % n;
        std::string str = getCountExp(c, d);
        long long m = getCountMod(str, n);
        resByteArr.append(m);
    }

    return QString(resByteArr);
}

#endif // RSAMATH_H
