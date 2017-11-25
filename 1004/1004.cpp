//1004,����Ħ˹��Լ��
/*
1.ǰ���ַ����еĵ�һ�Ժ͵ڶ�����ͬ�Ĵ�д��ĸ��λ��
2.�������е�һ����ͬ����ĸ

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
			//�����и��ӣ���ĸ�ǲ�����G�ģ���Ϊһ�����ھ�7�죬����G�����ֽ���������Ľ������˲���������
			if (X >= 'A' && X <= 'G' && str1[i] == str2[i])
			{
				v1.push_back(X);
				first = false;
			}
		}
		//�����и��ӣ����ֻ�ж���ͬ���ַ��������������ͣ�����ܳ���©������Ϊ�����������ַ�
		//ֻ��0-9��A-N,Сд��ĸ�������������ַ��������ַ��ǲ�����Ҫ��ģ�N�Ժ�Ĵ�д��ĸҲͬ��������Ҫ��
		//�����Ҫ�����¼�������
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
