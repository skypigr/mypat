//1004,福尔摩斯的约会
/*
1.前个字符串中的第一对和第二对相同的大写字母的位置
2.后两对中第一对相同的字母

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string str1, str2, str3, str4;
	cin >> str1 >> str2 >> str3 >> str4;

	int n1 = str1.length() < str2.length() ? str1.length() : str2.length();
	int n2 = str3.length() < str4.length() ? str3.length() : str4.length();

	vector<char> v1;
	
	char X;
	bool first = true;
	//find the first and second pair CHAR
	for (size_t i = 0; i < n1; i++)
	{
		X = str1[i];
		if (first)
		{
			//这里有个坑，字母是不超过G的，因为一个星期就7天，大于G的数字将导致无理的结果，因此不符合条件
			if (X >= 'A' && X <= 'G' && str1[i] == str2[i])
			{
				v1.push_back(X);
				first = false;
			}
		}
		//这里有个坑，如果只判断相同的字符而不鉴别其类型，则可能出现漏洞，因为符合条件的字符
		//只有0-9，A-N,小写字母，标点符号特殊字符等其他字符是不符合要求的，N以后的大写字母也同样不符合要求
		//因此需要做如下鉴别条件
		else if (str1[i] == str2[i] && (X >= 'A' && X <= 'N' || isdigit(X)) )
		{
			v1.push_back(X);
			break;
		}
	}

	//1. output days
	vector<string> vDays = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	if(v1.size()==2) 
		cout << vDays[v1[0]-'A'] <<" ";

	//2. Hours
	if (v1[1] <= '9') cout << "0" << v1[1]<<":";
	else 	cout << v1[1] - 'A' + 10 << ":";

	for (size_t i = 0; i < n2; i++)
	{
		X = str3[i];
		if ((X >= 'a' && X <= 'z') || (X >= 'A' && X <= 'Z'))
			if (X == str4[i])
			{
				if (i < 10) cout << "0" << i;
				else cout << i;
				break;
			}
	}
	return 0;
}
