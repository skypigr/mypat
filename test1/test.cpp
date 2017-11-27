#include <iostream>
#include <string>
using namespace std;

//pat 1012

/*
一个网友的程序，用递归调用实现了逆序输出，非常的机智
缺点是只能输出10以下的进制
*/
void printBin(int C, int D)
{
	if (C == 0) return;
	printBin(C / D, D);
	printf("%d", C%D);
}


/*
另一个水友的答案，也很机智，把每次产生的字数放在string的最前面
只支持10进制，因为9后面的字幕是:;<=>?@A,也不符合16进制规范，没有对大于10进制进行处理
链接：https://www.nowcoder.com/questionTerminal/52fee0e0ffc44d258b8f940184017c00
来源：牛客网
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

//进制转换
//我自己的答案
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