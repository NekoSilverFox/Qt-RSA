#ifndef RSA_H
#define RSA_H


#include <iostream> //cout、endl、string
#include <vector>   // vector
#include <string>
#include <ctime>   //time()
#include <cstdlib> //srand()、rand()
#include <QRandomGenerator>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class RSA
{
public:
    RSA();                                                                            // 构造
    static vector<unsigned int> Encrypt(const string &plaintext_str, unsigned int e, unsigned int n);  // 加密
    static QString Decrypt(const vector<unsigned int> &ciphertext_int, unsigned int d, unsigned int n); // 解密

private:
    void KeyGen(); // 密钥生成

    unsigned int GetPrimeNum();                                                                    // 获取素数
    bool PrimalityTest(const unsigned int &n, const unsigned int &a);                              // Miller-Rabin素性测试
    static unsigned int QuickPowMod(const unsigned int &a, const unsigned int &q, const unsigned int &n); // 蒙哥马利快速幂模运算
    static unsigned int QuickMulMod(const unsigned int &a, const unsigned int &b, const unsigned int &c); // 快速乘模

    unsigned int ExGcd(const unsigned int &a, const unsigned int &b, unsigned int &x, unsigned int &y); // 扩展欧几里得算法
    unsigned int GetMulInverse(const unsigned int &a, const unsigned int &b);                           // 求乘法逆元

public:
    unsigned int p_arg_; // p参数
    // 提示：参数>=0，使用unsigned int更符合语义
    unsigned int q_arg_;            // q参数
    unsigned int n_arg_;            // n参数
    unsigned int n_Euler_func_arg_; // n的欧拉函数参数
    unsigned int e_arg_;            // e参数
    unsigned int d_arg_;            // d参数
};

#endif // RSA_H
