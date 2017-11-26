//������һ����λ���ֲ���ȫ��ͬ��4λ����������������Ȱ�4�����ְ��ǵ��������ٰ��ǵݼ�����Ȼ���õ�1�����ּ���2�����֣����õ�
//һ���µ����֡�һֱ�ظ������������Ǻܿ��ͣ���С����ֺڶ���֮�Ƶ�6174��������������Ҳ��Kaprekar������
//
//���磬���Ǵ�6767��ʼ�����õ�
//
//7766 - 6677 = 1089
//9810 - 0189 = 9621
//9621 - 1269 = 8352
//8532 - 2358 = 6174
//7641 - 1467 = 6174
//... ...
//
//�ָ�������4λ�����������д������ʾ����ڶ��Ĺ��̡�

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool mgreater(int a, int b)
{
    return a > b;
}

//��������ua=true, �ݼ����ǵ���
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
//��λ���
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