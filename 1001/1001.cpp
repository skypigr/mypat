#include <iostream>
#include <string>

//https://www.nowcoder.com/pat/6/problem/4077

int main()
{
	long a[10], b[10],c[10];
	int T = 0;
	std::cin >> T;

	for (int i = 0; i < T; i++)
		std::cin >> a[i] >> b[i] >> c[i];

	bool rst = true;
	for (int i = 0; i < T; i++)
	{
		rst = a[i] + b[i] > c[i] ? true : false;
		std::cout << "Case #" <<i+1<<": "<< (rst ? "true" : "false") << std::endl;
	}
	return 0;
}