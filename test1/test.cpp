#include <iostream>
#include <string>
using namespace std;

//pat 1012

/*
һ�����ѵĳ����õݹ����ʵ��������������ǳ��Ļ���
ȱ����ֻ�����10���µĽ���
*/
void printBin(int C, int D)
{
	if (C == 0) return;
	printBin(C / D, D);
	printf("%d", C%D);
}


/*
��һ��ˮ�ѵĴ𰸣�Ҳ�ܻ��ǣ���ÿ�β�������������string����ǰ��
ֻ֧��10���ƣ���Ϊ9�������Ļ��:;<=>?@A,Ҳ������16���ƹ淶��û�жԴ���10���ƽ��д���
���ӣ�https://www.nowcoder.com/questionTerminal/52fee0e0ffc44d258b8f940184017c00
��Դ��ţ����
*/
string dSystem(int num, int D)
{
	string str = "";
	while (num > 0) {
		str = (char)(num%D + '0') + str;
		num /= D;
	}
	return str;
}

//����ת��
//���Լ��Ĵ�
string convertor(int n, int d)
{

	if (d < 2 | d>10) return "";

	char digits[] = "0123456789";
	char buf[33];
	
	
	buf[32] = '\0';
	int i = 31, s = n;
	while (s > 0)
	{
		buf[i] = digits[s%d];
		s /= d;
		i--;
	}
	return string(&buf[i+1]);
}


int main(int argc, char **argv) {

	int a, b, d;
	//if (argc == 4)
	//{
	//	a = atoi(argv[1]);
	//	b = atoi(argv[2]);
	//	d = atoi(argv[3]);
	//}
	//else
		cin >> a >> b >> d;

	if (a + b == 0) cout << 0;
	else			cout << convertor(a + b, d);
	return 0;
}