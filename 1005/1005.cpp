#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <set>       // std::vector
//此题涉及到大量数据的排序，对性能有要求
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

///*
//if a<b,return true
//*/
//bool mycomp(info a, info b)
//{
//	if (a.cls != b.cls)			return a.cls > b.cls;
//	else if (a.sum != b.sum)	return a.sum < b.sum;
//	else if (a.D != b.D)		return a.D < b.D;
//	else						return a.id > b.id;
//}

int main()
{
	int N, L, H;
	cin >> N >> L >> H;


	set<info> vData;
	int id, d, c;
	info data;
	for (size_t i = 0; i < N; i++)
	{
		cin >> id >> d >> c;		
		if (d >=L && c>=L)
		{
			//计算class，保存数据
			data.setData(id, d, c);

			//class
			//if (d >= H && c >= H) data.setClass(0); //1
			//else if (d >= H && c < H) data.setClass(1);
			//else if (d < H && c<H && d>c) data.setClass(2);
			//else data.setClass(3);
			if (d >= H && c >= H) data.setClass(0); //1
			else if (d >= H ) data.setClass(1);
			else if (d < H && c<H && d>=c) data.setClass(2);
			else data.setClass(3);
			vData.insert(data);
		}
	}

	//sort
	//sort(vData.begin(), vData.end());
	//reverse(vData.begin(), vData.end());

	//just for testing
	//cout << "---------------" << endl;
	//for (size_t i = 0; i < vData.size(); i++)
	//{
	//	info data = vData[i];		
	//	cout << data.id << " "
	//		<< data.D << " "
	//		<< data.C << " "
	//		<< data.cls << endl;
	//}


	cout << vData.size() << endl;
	for (set<info>::reverse_iterator iter = vData.rbegin(); iter != vData.rend(); iter++) 
		cout << (*iter).id << " " << (*iter).D << " " << (*iter).C << endl;

	//for (size_t i = 0; i < vData.size(); i++)
	//{
	//	info data = vData[vData.size() - 1 - i];
	//	cout << data.id << " "
	//		<< data.D << " "
	//		<< data.C << endl;
	//}
	return 0;
}

//#include <iostream>
//#include <set>
//
//using namespace std;
//
//class Student
//{
//public:
//	int id, morality, ability, sum, level;
//	Student(int id, int morality, int ability) {
//		this->id = id;
//		this->morality = morality;
//		this->ability = ability;
//		this->sum = morality + ability;
//		level = 4;//默认为第4等级，可改
//	}
//	bool operator <(const Student& another)const {
//		if (level != another.level) {
//			return level>another.level;
//		}
//		else if (sum != another.sum) {
//			return another.sum>sum;
//		}
//		else if (morality != another.morality) {
//			return another.morality>morality;
//		}
//		else {
//			return id>another.id;
//		}
//	}
//};
//
//int main()
//{
//	// 基本变量
//	int N, L, H;
//	cin >> N >> L >> H;
//	set<Student> student;
//
//	// 分类划级
//	for (int i = 0; i<N; i++) {
//		int id, morality, ability;
//		cin >> id >> morality >> ability;
//		Student stu(id, morality, ability);
//		if (stu.morality<L || stu.ability<L) {
//			continue;
//		}
//		else if (stu.morality >= H && stu.ability >= H) {
//			stu.level = 1;
//		}
//		else if (stu.morality >= H) {
//			stu.level = 2;
//		}
//		else if (morality >= ability) {
//			stu.level = 3;
//		}
//		else {
//			stu.level = 4;
//		}
//		student.insert(stu);
//	}
//
//	// 输出结果
//	set<Student>::reverse_iterator iter;
//	cout << student.size() << endl;
//	for (iter = student.rbegin(); iter != student.rend(); iter++) {
//		cout << (*iter).id << " " << (*iter).morality << " " << (*iter).ability << endl;
//	}
//	return 0;
//}