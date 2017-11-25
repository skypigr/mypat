//有两个测试用例超时，因此要考虑提高效率
//能提高的主要是排序，考虑对不同的等级分别排序看看效果

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace std;
struct info
{
public:

	int id, sum;
	short D, C, cls;
	info() {};
	void setData(int _id, int _D, int _C, int _cls)
	{
		id = _id;
		D = _D;
		C = _C;
		sum = C + D;
		cls = _cls;
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


	vector<info> vData, v0, v1, v2, v3;
	int id, d, c;
	info data;
	for (size_t i = 0; i < N; i++)
	{
		cin >> id >> d >> c;
		if (d >= L && c >= L)
		{
			//计算class，保存数据
			//data.setData(id, d, c);

			//class
			if (d >= H && c >= H) {
				data.setData(id, d, c, 0);  v0.push_back(data);
			}
			else if (d >= H ) {
				data.setData(id, d, c, 1);  v1.push_back(data);
			}
			else if ( d >= c) {
				data.setData(id, d, c, 2);  v2.push_back(data);
			}
			else {
				data.setData(id, d, c, 3);  v3.push_back(data);
			}

			//vData.push_back(data);
		}
	}

	//sort
	//sort(vData.begin(), vData.end());
	sort(v0.begin(), v0.end());
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	sort(v3.begin(), v3.end());
	//reverse(vData.begin(), vData.end());


	cout << v0.size() + v1.size() + v2.size()+v3.size() << endl;
	for (vector<info>::reverse_iterator iter = v0.rbegin(); iter != v0.rend(); iter++)
		cout << (*iter).id << " " << (*iter).D << " " << (*iter).C << endl;

	for (vector<info>::reverse_iterator iter = v1.rbegin(); iter != v1.rend(); iter++)
		cout << (*iter).id << " " << (*iter).D << " " << (*iter).C << endl;

	for (vector<info>::reverse_iterator iter = v2.rbegin(); iter != v2.rend(); iter++)
		cout << (*iter).id << " " << (*iter).D << " " << (*iter).C << endl;

	for (vector<info>::reverse_iterator iter = v3.rbegin(); iter != v3.rend(); iter++)
		cout << (*iter).id << " " << (*iter).D << " " << (*iter).C << endl;

	//for (vector<info>::reverse_iterator iter = vData.rbegin(); iter != vData.rend(); iter++)
	//	cout << (*iter).id << " " << (*iter).D << " " << (*iter).C << endl;

	return 0;
}