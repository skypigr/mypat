// nowcoder 1008
//���Ӽ�����
//���Ӧ�ö����桰���Ӽ�����������Ϸ��
//
//�ָ������˵Ľ����¼����ͳ��˫����ʤ��ƽ�������������Ҹ���˫���ֱ��ʲô���Ƶ�ʤ�����
//
//�������� :
//�����1�и���������N�� <= 105������˫������Ĵ��������N�У�ÿ�и���һ�ν������Ϣ�����ס���˫��ͬʱ�����ĵ����ơ�C�������ӡ���J������������B��
//
//����������1����ĸ����׷�����2�������ҷ����м���1���ո�
//
//
//������� :
//�����1��2�зֱ�����ס��ҵ�ʤ��ƽ�������������ּ���1���ո�ָ�����3�и���������ĸ���ֱ����ס��һ�ʤ�����������ƣ��м���1���ո�����ⲻΨ
//
//һ�����������ĸ����С�Ľ⡣

#include <iostream>
#include <string>
#include <utility>
using namespace std;

int C2I(char JCB)
{
    if (JCB == 'C') return 0;
    else if (JCB == 'J') return 1;
    else return 2;
}

char I2C(int n)
{
    if (n == 0) return 'C';
    else if (n == 1) return 'J';
    else return 'B';

}
// p1>p2, return 1
// p1<p2, return 0
// p1=p2, return -1
int jcbComp(char p1, char p2)
{
    if (p1 == p2) return -1;
    else if (
        (p1 == 'C' && p2 == 'J') ||
        (p1 == 'J' && p2 == 'B') ||
        (p1 == 'B' && p2 == 'C')
        )
        return 1;
    else return 0;
}

char findMax(int p[])
{
    char rst = 'B';
    int max = p[2];
    if (p[0] > max) {
        rst = 'C'; 
        max = p[0];
    }

    if (p[1] > max) {
        rst = 'J';
        max = p[1];
    }

    return rst;
}

int main()
{
    int count;
    cin >> count;

    char p1[100001] = { 0 }, p2[100001] = { 0 };

    for (size_t i = 0; i < count; i++)
        cin >> p1[i] >> p2[i];

    int n1 = 0, n2 = 0, st1[3] = { 0 }, st2[3] = { 0 };
    for (size_t i = 0; i < count; i++)
    {
        int rst = jcbComp(p1[i], p2[i]);
        if (rst == 1) {
            //1>2
            n1++;
            st1[C2I(p1[i])]++;
        }
        else if (rst == 0)
        {
            //1<2
            n2++;
            st2[C2I(p2[i])]++;
        }
    }
    
    // output the result
    //line 1:
    cout << n1 << " " << count - n1 - n2 << " " << n2 << endl;

    //line 2:
    cout << n2 << " " << count - n1 - n2 << " " << n1 << endl;

    // line 3:
    cout << findMax(st1) << " "<< findMax(st2);
    return 0;
}