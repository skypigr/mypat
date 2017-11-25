// 1016 部分A+B
#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
int main()
{
	long long A, B;
	int dA, dB;
	cin >> A >> dA >> B >> dB;

	char strA[10], strB[10];
	int da = 0, db = 0;
	memset(strA, 0, sizeof(char) * 10);
	memset(strB, 0, sizeof(char) * 10);
	int digit = 0;
	while (A) {
		digit = A % 10; //保留个位
		if (digit == dA) strA[da++] = digit + '0';
		A /= 10;
	}

	while (B) {
		digit = B % 10;
		if (digit == dB) strB[db++] = digit + '0';
		B /= 10;
	}

	cout << atoi(strA) + atoi(strB);

	//for (size_t i = 0; i < da; i++) cout << strA[i];
	//for (size_t i = 0; i < db; i++) cout << strB[i];
	return 0;
}