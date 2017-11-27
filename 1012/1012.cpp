//题目描述
//输入两个非负10进制整数A和B(<= 230 - 1)，输出A + B的D(1 < D <= 10)进制数。
//    输入描述 :
//输入在一行中依次给出3个整数A、B和D。
//
//输出描述 :
//输出A + B的D进制数。
//
//输入例子 :
//123 456 8
//
//输出例子 :
//    1103

#include <iostream>
#include <string>

using namespace std;


string convertor(int a, int d)
{
    //能够轻易扩展为任意进制
    char *digits = "0123456789ABCDEF";
    char buf[33] = {0};

    int i = 31, s = a;
    if (s == 0) return string("0");
    while (s > 0)
    {
        buf[i] = digits[s%d];
        s /= d;
        i--;
    }
    return string(&buf[i + 1]);
}

int main(int argc, char** argv)
{
    int a, b,d,rst;
    cin >> a >> b>>d;
    cout<<convertor(a+b,d);
    return 0;
}