//有两个测试用例超时，因此要考虑提高效率
//能提高的主要是排序，考虑对不同的等级分别排序看看效果

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
//#include <vector>       // std::vector

using namespace std;
const int M = 1000010;
struct info
{
public:

	int id, sum;
	short D, C, cls;
	//info() {};
	//void setData(int _id, int _D, int _C, int _cls)
	//{
	//	id = _id;
	//	D = _D;
	//	C = _C;
	//	sum = C + D;
	//	cls = _cls;
	//}

	bool operator <(const info& A) const
	{
		if (cls != A.cls)		return cls < A.cls;
		else if (sum != A.sum)	return sum > A.sum;
		else if (D != A.D)		return D > A.D;
		else					return id < A.id;

	}

}v0[M], v1[M], v2[M], v3[M];


int main()
{
	int N, L, H;
	cin >> N >> L >> H;


	//vector<info> vData, v0, v1, v2, v3;
	int id, d, c;
	int tot1 = 0, tot2 = 0, tot3 = 0, tot0 = 0;
	info data;
	for (size_t i = 0; i < N; i++)
	{
		cin >> id >> d >> c;

		if (d < L || c < L) continue;

		if (d >= L && c >= L)
		{
			//计算class，保存数据
			//data.setData(id, d, c);

			//class
			if (d >= H && c >= H) {
				v0[tot0].id = id;
				v0[tot0].D = d;
				v0[tot0].C = c;
				v0[tot0].sum = d + c;
				v0[tot0++].cls = 0;

				//data.setData(id, d, c, 0);  v0.push_back(data);
			}
			else if (d >= H) {
				v1[tot1].id = id;
				v1[tot1].D = d;
				v1[tot1].C = c;
				v1[tot1].sum = d + c;
				v1[tot1++].cls = 1;
				//data.setData(id, d, c, 1);  v1.push_back(data);
			}
			else if (d >= c) {
				v2[tot2].id = id;
				v2[tot2].D = d;
				v2[tot2].C = c;
				v2[tot2].sum = d + c;
				v2[tot2++].cls = 2;
				//data.setData(id, d, c, 2);  v2.push_back(data);
			}
			else {
				v3[tot3].id = id;
				v3[tot3].D = d;
				v3[tot3].C = c;
				v3[tot3].sum = d + c;
				v3[tot3++].cls = 3;
				//data.setData(id, d, c, 3);  v3.push_back(data);
			}

			//vData.push_back(data);
		}
	}

	//sort
	//sort(vData.begin(), vData.end());
	sort(v0, v0 + tot0); 
	sort(v1, v1 + tot1);
	sort(v2, v2 + tot2);
	sort(v3, v3 + tot3);
	//reverse(v0, v0 + tot0);
	//reverse(v1, v1 + tot1);
	//reverse(v2, v2 + tot2);
	//reverse(v3, v3 + tot3);
	cout << tot0 + tot1 + tot2 + tot3 << endl;
	for (int i = 0; i < tot0; i++) {
		printf("%d %d %d\n", v0[i].id, v0[i].D, v0[i].C);
	}
	for (int i = 0; i < tot1; i++) {
		printf("%d %d %d\n", v1[i].id, v1[i].D, v1[i].C);
	}
	for (int i = 0; i < tot2; i++) {
		printf("%d %d %d\n", v2[i].id, v2[i].D, v2[i].C);
	}
	for (int i = 0; i < tot3; i++) {
		printf("%d %d %d\n", v3[i].id, v3[i].D, v3[i].C);
	}

	//sort(v1.begin(), v1.end());
	//sort(v2.begin(), v2.end());
	//sort(v3.begin(), v3.end());
	//reverse(vData.begin(), vData.end());


	//cout << v0.size() + v1.size() + v2.size() + v3.size() << endl;
	//for (vector<info>::reverse_iterator iter = v0.rbegin(); iter != v0.rend(); iter++)
	//	cout << (*iter).id << " " << (*iter).D << " " << (*iter).C << endl;

	//for (vector<info>::reverse_iterator iter = v1.rbegin(); iter != v1.rend(); iter++)
	//	cout << (*iter).id << " " << (*iter).D << " " << (*iter).C << endl;

	//for (vector<info>::reverse_iterator iter = v2.rbegin(); iter != v2.rend(); iter++)
	//	cout << (*iter).id << " " << (*iter).D << " " << (*iter).C << endl;

	//for (vector<info>::reverse_iterator iter = v3.rbegin(); iter != v3.rend(); iter++)
	//	cout << (*iter).id << " " << (*iter).D << " " << (*iter).C << endl;

	//for (vector<info>::reverse_iterator iter = vData.rbegin(); iter != vData.rend(); iter++)
	//	cout << (*iter).id << " " << (*iter).D << " " << (*iter).C << endl;

	return 0;
}