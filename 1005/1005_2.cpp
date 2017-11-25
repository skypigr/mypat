#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace std;
class info
{
public:

	int id, D, C, cls, sum;
	info() {};
	void setData(int _id, int _D, int _C)
	{
		id = _id;
		D = _D;
		C = _C;
		sum = C + D;
		cls = 0;
	}

	void setClass(int n)
	{
		cls = n;
	}

	bool operator <(const info& A) const
	{
		if (cls != A.cls)		return cls > A.cls;
		else if (sum != A.sum)	return sum < A.sum;
		else if (D != A.D)		return D < A.D;
		else					return id > A.id;

	}

};


int main()
{
	int N, L, H;
	cin >> N >> L >> H;


	vector<info> vData;
	int id, d, c;
	info data;
	for (size_t i = 0; i < N; i++)
	{
		cin >> id >> d >> c;
		if (d >= L && c >= L)
		{
			//计算class，保存数据
			data.setData(id, d, c);

			//class
			if (d >= H && c >= H) data.setClass(0); //1
			else if (d >= H && c < H) data.setClass(1);
			else if (d < H && c<H && d>=c) data.setClass(2);
			else data.setClass(3);

			vData.push_back(data);
		}
	}

	//sort
	sort(vData.begin(), vData.end());
	//reverse(vData.begin(), vData.end());


	cout << vData.size() << endl;
	for (vector<info>::reverse_iterator iter = vData.rbegin(); iter != vData.rend(); iter++)
		cout << (*iter).id << " " << (*iter).D << " " << (*iter).C << endl;


	return 0;
}