#include <iostream>  
#include <string>  
#include <ctime>  
#include <vector>  
#include <thread>
using namespace std;

bool isPrime_2(int num)
{
	//if (num > 1000000) cout << "hello" << endl;
	if (num == 2 || num == 3) return true;

	//int tmp = sqrt(num);
	for (int i = 2; i <= num/i; i++)
		if (num %i == 0)
			return 0;
	
	return 1;
}

bool isPrime_3(int num)
{
	//������С�����⴦��  
	if (num == 2 || num == 3)
		return 1;
	//����6�ı��������һ����������  
	if (num % 6 != 1 && num % 6 != 5)
		return 0;
	int tmp = sqrt(num);
	//��6�ı��������Ҳ���ܲ�������  
	for (int i = 5; i <= tmp; i += 6)
		if (num %i == 0 || num % (i + 2) == 0)
			return 0;
	//�ų����У�ʣ���������  
	return 1;
}

bool isPrime_4(int num, vector<int>& primeV)
{
	return 1;
}

void testBench(int circles)
{
	//int test_num = 10000 * 1000;
	int test_num = circles;
	int tstart, tstop; //�ֱ��¼��ʼ�ͽ���ʱ��  
					   //���Ե�һ���ж���������  
					   //tstart = clock();
					   //for (int i = 1; i <= test_num; i++)
					   //	isPrime_1(i);
					   //tstop = clock();
					   //cout << "����(1)ʱ��(ms):" << tstop - tstart << endl;//msΪ��λ  

					   //���Եڶ����ж���������  
	tstart = clock();
	bool rst;
	for (int i = 1; i <= test_num; i++) {
		rst = isPrime_2(i);
	}

	tstop = clock();
	cout << "����(2)ʱ��(ms):" << tstop - tstart << endl;
	//���Ե������ж���������  
	tstart = clock();
	for (int i = 1; i <= test_num; i++) {
		rst = isPrime_3(i);
	}
	tstop = clock();
	cout << "����(3)ʱ��(ms):" << tstop - tstart << endl;
	//cout << endl;
}

int main()
{
	int test_num = 10000 * 500;
	vector<thread> thrdV;
	for (size_t i = 0; i < 4; i++)
		thrdV.push_back(thread(testBench, test_num));

	for (auto& thread : thrdV)
		thread.join();
	//testBench(test_num);
	//int tstart, tstop; //�ֱ��¼��ʼ�ͽ���ʱ��  
	//				   //���Ե�һ���ж���������  
	////tstart = clock();
	////for (int i = 1; i <= test_num; i++)
	////	isPrime_1(i);
	////tstop = clock();
	////cout << "����(1)ʱ��(ms):" << tstop - tstart << endl;//msΪ��λ  
	//												 
	////���Եڶ����ж���������  
	//tstart = clock();
	//bool rst;
	//for (int i = 1; i <= test_num; i++) {
	//	 rst = isPrime_2(i);
	//}
	//
	//tstop = clock();
	//cout << "����(2)ʱ��(ms):" << tstop - tstart << endl;
	////���Ե������ж���������  
	//tstart = clock();
	//for (int i = 1; i <= test_num; i++) {
	//	rst = isPrime_3(i);
	//}
	//tstop = clock();
	//cout << "����(3)ʱ��(ms):" << tstop - tstart << endl;
	//cout << endl;
	////system("pause");
	return 0;
}