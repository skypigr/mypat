//给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到
//一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。
//
//例如，我们从6767开始，将得到
//
//7766 - 6677 = 1089
//9810 - 0189 = 9621
//9621 - 1269 = 8352
//8532 - 2358 = 6174
//7641 - 1467 = 6174
//... ...
//
//现给定任意4位正整数，请编写程序演示到达黑洞的过程。

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool mgreater(int a, int b)
{
    return a > b;
}

//排序函数，ua=true, 递减，非递增
int mySort(int n, bool down)
{
    
    int buf[4] = { 0 };
    for (size_t i = 0; i < 4; i++)
    {
        buf[4 - i - 1] = n % 10;
        n /= 10;
    }

    //sort
    down ? sort(buf, buf + 4, mgreater) : sort(buf, buf + 4);

    int rst = 0;
    for (size_t i = 0; i < 4; i++)
        rst = rst * 10 + buf[i];

    return rst;
}
//四位输出
void myprint(int n)
{
    char buf[5] = { 0 };
    for (size_t i = 0; i < 4; i++)
    {
        buf[4 - i - 1] = n % 10 + '0';
        n /= 10;
    }
    cout << buf;
}

int main()
{
    int a;
    cin >> a;

    if (a % 1111 == 0) {
        cout << a << " - " << a << " = 0000";
        return 0;
    }

    int a_down, a_up;
    while (true) 
    {
        //1.output the original value of a 
        a_down = mySort(a, 1);
        a_up = mySort(a, 0);

        myprint(a_down);  cout << " - ";  myprint(a_up); cout << " = ";
        a = a_down - a_up;
        myprint(a);
        cout << endl;
        if (a == 6174) break;
    }

    return 0;
}