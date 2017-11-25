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
	//两个较小数另外处理  
	if (num == 2 || num == 3)
		return 1;
	//不在6的倍数两侧的一定不是质数  
	if (num % 6 != 1 && num % 6 != 5)
		return 0;
	int tmp = sqrt(num);
	//在6的倍数两侧的也可能不是质数  
	for (int i = 5; i <= tmp; i += 6)
		if (num %i == 0 || num % (i + 2) == 0)
			return 0;
	//排除所有，剩余的是质数  
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
	int tstart, tstop; //分别记录起始和结束时间  
					   //测试第一个判断质数函数  
					   //tstart = clock();
					   //for (int i = 1; i <= test_num; i++)
					   //	isPrime_1(i);
					   //tstop = clock();
					   //cout << "方法(1)时间(ms):" << tstop - tstart << endl;//ms为单位  

					   //测试第二个判断质数函数  
	tstart = clock();
	bool rst;
	for (int i = 1; i <= test_num; i++) {
		rst = isPrime_2(i);
	}

	tstop = clock();
	cout << "方法(2)时间(ms):" << tstop - tstart << endl;
	//测试第三个判断质数函数  
	tstart = clock();
	for (int i = 1; i <= test_num; i++) {
		rst = isPrime_3(i);
	}
	tstop = clock();
	cout << "方法(3)时间(ms):" << tstop - tstart << endl;
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
	//int tstart, tstop; //分别记录起始和结束时间  
	//				   //测试第一个判断质数函数  
	////tstart = clock();
	////for (int i = 1; i <= test_num; i++)
	////	isPrime_1(i);
	////tstop = clock();
	////cout << "方法(1)时间(ms):" << tstop - tstart << endl;//ms为单位  
	//												 
	////测试第二个判断质数函数  
	//tstart = clock();
	//bool rst;
	//for (int i = 1; i <= test_num; i++) {
	//	 rst = isPrime_2(i);
	//}
	//
	//tstop = clock();
	//cout << "方法(2)时间(ms):" << tstop - tstart << endl;
	////测试第三个判断质数函数  
	//tstart = clock();
	//for (int i = 1; i <= test_num; i++) {
	//	rst = isPrime_3(i);
	//}
	//tstop = clock();
	//cout << "方法(3)时间(ms):" << tstop - tstart << endl;
	//cout << endl;
	////system("pause");
	return 0;
}