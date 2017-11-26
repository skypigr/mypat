//本题要求计算A / B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。
//输入在1行中依次给出A和B，中间以1空格分隔。
//在1行中依次输出Q和R，中间以1空格分隔。
//
//输入例子 :
//123456789050987654321 7
//
//输出例子 :
//	17636684150141093474 3

#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int main()
{
    string nom;
    int dom;
    cin >> nom >> dom;

    if (dom == 1) {
        cout << nom << " " << 0;
        return 0;
    }

    char rst[1001];
    memset(rst, 0, 1001*sizeof(char));
    int n = 0, r = 0, cnt_rst = 0;
    for (size_t i = 0; i < nom.length(); i++)
    {
        n = (nom.at(i) - '0') + r * 10;
        rst[cnt_rst++] = n / dom + '0';
        r = n % dom;
    }

    // delete the zeros in the front of the rst
    // must be careful, when the result only have 1 digit and it is zero, we should not remove that zero
    char * rst_p = rst;
    while (cnt_rst >1 && rst_p[0] == '0') rst_p++;

    cout << rst_p << " " << r;
    return 0;
}