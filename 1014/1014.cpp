//题目描述
//科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1 - 9]"."[0 - 9] + E[+-][0 - 9] + ，即数字的整数部分
//只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。
//
//现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。
//
//输入描述 :
//每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，
//且其指数的绝对值不超过9999。

#include <iostream>
#include <string>

using namespace std;


void doswitch(string& str, char expsign)
{

    if (str.front() == '.') str = "0" + str;
    else if (str.back() == '.') str += "0";

    size_t posdot = str.find_first_of('.');

    expsign == '+'
        ? (str[posdot] = str[posdot + 1], str[posdot + 1] = '.')
        : (str[posdot] = str[posdot - 1], str[posdot - 1] = '.');
}

int main()
{
    string instr;
    cin >> instr;

    size_t posE = instr.find_first_of('E');
    //size_t posD = instr.find_first_of('.');
    
    char sign = instr.front();
    char expsign = instr[posE+1];
    int exp = atoi(&instr[posE + 2]);

    string rst(instr, 1, posE - 1);

    //主要思路就是移动小数点的位置
    //the main idea is to change the position of decimal point one by one
    while (exp--)
    {
        doswitch(rst, expsign);
    }

    
    if (rst.front() == '.') rst = "0" + rst;
    else if (rst.back() == '.') rst.pop_back();

    if (sign == '-') cout << sign;
    cout << rst;

    return 0;
}