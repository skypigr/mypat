//��Ŀ����
//��ѧ�������ǿ�ѧ��������ʾ�ܴ���С�����ֵ�һ�ַ���ķ�����������������ʽ[+-][1 - 9]"."[0 - 9] + E[+-][0 - 9] + �������ֵ���������
//ֻ��1λ��С������������1λ�������ּ���ָ�����ֵ������ż�ʹ������Ҳ�ض���ȷ������
//
//���Կ�ѧ�������ĸ�ʽ����ʵ��A�����д������ͨ���ֱ�ʾ�����A������֤������Чλ����������
//
//�������� :
//ÿ���������1��������������һ���Կ�ѧ��������ʾ��ʵ��A�������ֵĴ洢���Ȳ�����9999�ֽڣ�
//����ָ���ľ���ֵ������9999��

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

    //��Ҫ˼·�����ƶ�С�����λ��
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