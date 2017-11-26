//����Ҫ�����A / B������A�ǲ�����1000λ����������B��1λ������������Ҫ�������Q������R��ʹ��A = B * Q + R������
//������1�������θ���A��B���м���1�ո�ָ���
//��1�����������Q��R���м���1�ո�ָ���
//
//�������� :
//123456789050987654321 7
//
//������� :
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