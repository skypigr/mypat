//��Ŀ����
//���������Ǹ�10��������A��B(<= 230 - 1)�����A + B��D(1 < D <= 10)��������
//    �������� :
//������һ�������θ���3������A��B��D��
//
//������� :
//���A + B��D��������
//
//�������� :
//123 456 8
//
//������� :
//    1103

#include <iostream>
#include <string>

using namespace std;


string convertor(int a, int d)
{
    //�ܹ�������չΪ�������
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