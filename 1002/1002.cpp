#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{

	vector<int> A1, A2,  A4, A5, A;
	int N, one,tmp, a3=0;

	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> one;
		A.push_back(one);
	}

	for (vector<int>::iterator i = A.begin(); i != A.end(); i++)
	{
		tmp = *i;
		if (tmp % 5 == 1) A2.push_back(tmp);
		else if (tmp % 5 == 2) a3++;
		else if (tmp % 5 == 3) A4.push_back(tmp);
		else if (tmp % 5 == 4) A5.push_back(tmp);
		else if (tmp % 10 == 0) A1.push_back(tmp);
	}

	if (!A1.empty()) {
		int a1 = accumulate(A1.begin(), A1.end(), 0);
		cout << a1 << " ";
	}
	else cout << "N ";
	
	if (!A2.empty()) {
		int a2 = 0;
		for (size_t i = 0; i < A2.size(); i++)
			a2 += A2[i] * (i % 2 == 0 ? 1 : -1);
		cout << a2 << " ";
	}
	else cout << "N ";

	cout << a3 << " ";

	if (!A4.empty()) {
		double a4 = (double)accumulate(A4.begin(), A4.end(), 0) / (double)A4.size();
		printf("%.1f ", a4);
	}
	else cout << "N ";

	if (!A5.empty())
	{
		int a5 = *((max_element(A5.begin(), A5.end())));
		cout << a5;
	}
	else cout << "N";

	return 0;
}