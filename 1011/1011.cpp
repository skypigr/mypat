//给定一个k位整数N = dk - 1 * 10k - 1 + ... + d1 * 101 + d0(0 <= di <= 9, i = 0, ..., k - 1, dk - 1>0)，
//请编写程序统计每种不同的个位数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。
//每个输入包含1个测试用例，即一个不超过1000位的正整数N。
//对N中每一种不同的个位数字，以D : M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。
//    输入例子 :
//100311
//输出例子 :
//    0 : 2
//    1 : 3
//    3 : 1

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string in_s;
    cin >> in_s;

    short buf[10] = { 0 };
    for (size_t i = 0; i < in_s.length(); i++)
        buf[in_s.at(i)-'0']++;

    for (size_t i = 0; i < 10; i++) {
        if (buf[i]) cout << i << ":" << buf[i] << endl;
    }

    return 0;
}