//��Pi��ʾ��i�����������θ�����������M <= N <= 10000�������PM��PN������������
//https://www.nowcoder.com/pat/6/problem/4079

#include <iostream>
#include <vector>
#include <cmath>

#include <Windows.h>
//#include <Mmsystem.h> //������ͷ�ļ� 
using namespace std;

//���ܶ�ʱ���ṹ��
struct myACRT
{
	LARGE_INTEGER tmpLI;
	LONGLONG tmStart, tmEnd, tmFreq;
	double time;

	//��ʼ��
	BOOL Init()
	{
		tmStart = 0;
		tmEnd = 0;
		tmFreq = 0;
		time = 0;

		if (!QueryPerformanceFrequency(&tmpLI))
			return FALSE;
		else
		{
			tmFreq = tmpLI.QuadPart;
			return TRUE;
		}
	}
	//��ʼ��ʱ
	BOOL Start()
	{
		if (QueryPerformanceCounter(&tmpLI))
		{
			tmStart = tmpLI.QuadPart;
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	//ֹͣ��ʱ
	BOOL Stop()
	{
		if (QueryPerformanceCounter(&tmpLI))
		{
			tmEnd = tmpLI.QuadPart;
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}

	//tick
	double Tick()
	{
		if (QueryPerformanceCounter(&tmpLI))
		{
			LONGLONG tmEnd;
			tmEnd = tmpLI.QuadPart;
			return time = (double)(tmEnd - tmStart) / (double)tmFreq;;
		}
		else
			return 0;
	}
	//���ؼ�ʱ���
	double GetTime()
	{
		time = (double)(tmEnd - tmStart) / (double)tmFreq;
		return time;
	}

};

//�и����ǵ�ͬѧ����ôд��
bool isPrime_2(int n)
{
	int i = 2;
	for (i = 2; i <= n / i; i++) {
		if (n % i == 0)
			return false;
	}

	return true;
}

bool isPrime_1(int n)
{

	if (n==2||n == 3 ) return true;
	else{
		
		if (n > 5) {
			int t = n % 10;
			if(t!=1 &&t!=3 && t != 7 && t != 9)
				return false;
		}
			

	//int N = sqrt(n);
	for (int i = 2; i <= n/i; i++)
		if (n%i == 0)
			return false;
	return true;
	}
	
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



/////////////////////////////////////////////
//��һ���߼���
typedef long long int LL;

const int S = 2;///�жϼ��� (8~12)  

				/// (a*b)%c  
LL mult_mod(LL a, LL b, LL c)
{
	a %= c; b %= c;
	LL ret = 0; LL temp = a;
	while (b)
	{
		if (b & 1)
		{
			ret += temp;
			if (ret>c) ret -= c;
		}
		temp <<= 1;
		if (temp>c) temp -= c;
		b >>= 1LL;
	}
	return ret;
}

/// (a^n)%mod  
LL pow_mod(LL a, LL n, LL mod)
{
	LL ret = 1;
	LL temp = a%mod;
	while (n)
	{
		if (n & 1) ret = mult_mod(ret, temp, mod);
		temp = mult_mod(temp, temp, mod);
		n >>= 1LL;
	}
	return ret;
}

/// check a^(n-1)==1(mod n)  
bool check(LL a, LL n, LL x, LL t)
{
	LL ret = pow_mod(a, x, n);
	LL last = ret;
	for (int i = 1; i <= t; i++)
	{
		ret = mult_mod(ret, ret, n);
		if (ret == 1 && last != 1 && last != n - 1) return true;
		last = ret;
	}
	if (ret != 1) return true;
	return false;
}

bool Miller_Rabin(LL n)
{
	if (n<2) return false;
	if (n == 2) return true;
	if ((n & 1) == 0) return false;
	LL x = n - 1;
	LL t = 0;
	while ((x & 1) == 0) { x >>= 1; t++; }
	//srand(time(NULL));

	for (int i = 0; i<S; i++)
	{
		LL a = rand() % (n - 1) + 1;
		if (check(a, n, x, t)) return false;
	}
	return true;
}

bool isPrime_4(LL n)
{
	return Miller_Rabin(n);
}

/////////////////////////////////////////////
int main(int argc, char **argv)
{
	int M, N;
	if (argc == 3)
	{
		M = atoi(argv[1]);
		N = atoi(argv[2]);
	}
	else 
	cin >> M>>N;

	int count = 0, n=2;
	vector<int> v,v3;
	v.reserve(10000);
	v3.reserve(10000);
	myACRT t;

	t.Init(); t.Start();
	while(true)
	{
		if (isPrime_1(n)) {
			v.push_back(n);
			count++;
		}
		n++;
		if (count == N) break;
		//if (n > ((1 << 31)-1)) cout << "�������:" << n<<endl;
	}
	double t1 = t.Tick();
	cout << t1 <<":"<< *(v.end()-1)<<endl;

	count = 0,n = 2;
	
	while (true)
	{
		if (isPrime_3(n)) {
			v3.push_back(n);
			count++;
		}
		n++;
		if (count == N) break;
	}
	double t2 = t.Tick();
	cout << t2 - t1 << ":" << *(v3.end()-1) << endl;

	//count = 0, n = 2;
	//while (true)
	//{
	//	if (isPrime_4(n)) {
	//		//v3.push_back(n);
	//		count++;
	//	}
	//	n++;
	//	if (count == N) break;
	//}
	//double t3 = t.Tick();
	//cout << t3 - t2 << endl;

	cout << "done!" << endl;
	return 0;

	if(N)
	for (size_t i = M-1,q=0; i < N; i++,q++)
	{
		cout << v[i];
		if (q%10 != 9 && i != N- 1) 
			cout << " ";
		else if(i != N - 1) 
			cout << endl;
	}



	return 0;
}