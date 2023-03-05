#include"NumClass.h"
#include <iostream>
#include <vector>
using namespace std;

#pragma pack(push,1)
struct S
{
	char c1;
	char c2;
};

#pragma pack(push,4)
struct S1
{
	char c1;
	char c2;
};
#pragma pack(pop)
struct S3
{
	char c1;
	char c2;
};
#pragma pack(pop)

//template<class T, class T1>
//T Min(T v1, T v2, T1 comp)
//{
//	return comp(v1, v2) > 0 ? v2 : v1;
//}

template <class T>
using CompType = int (*)(const T &, const T &);

typedef int (*ttt)(int, double);

template<class T, class T1>
T Min(T v1, T v2, T1 comp)
{
	return comp(v1, v2) > 0 ? v2 : v1;
}

template<class T, class T1>
void Sort(T* arr, size_t count, T1 comp)
{

}

template<class T>
int ImNumComp(const ImNum<T>& v1, const ImNum<T>& v2)
{
	typename AbsType<T>::type a1 = abs(v1), a2 = abs(v2);
	return a1 > a2 ? 1 : (a1 < a2 ? -1 : 0);
}

extern S1* CreateS();

extern void DeleteS(S1*);

class CS
{
	S1* ss;
public:
	CS(S1 * ss) : ss(ss) {}
	~CS() { DeleteS(ss); }
	operator S1* () { return ss; }
};

void f()
{
	int a = 5;
	double b = 5.5;
	
	//class _C
	//{
	//	int a;
	//	double b;
	//public:
	//	_C(int a, double b)
	//		: a(a), b(b)
	//	{}

	//	void operator()() const
	//	{
	//		cout << a + b;
	//	}
	//} c(a, b);

	//auto l = [a, b]() { cout << a + b; };

	//class _C
	//{
	//	int a;
	//	double b;
	//public:
	//	_C(int a, double b)
	//		: a(a), b(b)
	//	{}

	//	void operator()() const
	//	{
	//		cout << a + b;
	//	}
	//} c(a, b);

	//auto l = [=]() { cout << a + b; };

	//class _C
	//{
	//	int &a;
	//	double &b;
	//public:
	//	_C(int &a, double &b)
	//		: a(a), b(b)
	//	{}

	//	void operator()() const
	//	{
	//		cout << a + b;
	//	}
	//} c(a, b);

	//auto l = [&a, &b]() { cout << a + b; };

	//class _C
	//{
	//	int& a;
	//	double& b;
	//public:
	//	_C(int& a, double& b)
	//		: a(a), b(b)
	//	{}

	//	void operator()() const
	//	{
	//		cout << a + b;
	//	}
	//} c(a, b);

	//auto l = [&]() { cout << a + b; };
	//auto l = [&, a]() { cout << a + b; };
	//auto l = [=, &b]() { cout << a + b; };

	class _C
	{
		int a;
		double b;
	public:
		_C(int a, double b)
			: a(a), b(b)
		{}

		void operator()()
		{
			cout << a + b;
			b += a;
		}
	} c(a, b);

	auto l = [=]() mutable { cout << a + b; b += a; };
}

template<class T>
class AutoPtr
{
	T* ptr;
public:
	AutoPtr(T * ptr = 0)
		: ptr(ptr)
	{}

	void Delete()
	{
		if (ptr)
		{
			delete ptr;
			ptr = NULL;
		}
	}

	~AutoPtr()
	{
		Delete();
	}

	operator T *()
	{
		return ptr;
	}
};

template<class T>
class AutoPtr<T[]>
{
	T* ptr;
public:
	AutoPtr(T* ptr = 0)
		: ptr(ptr)
	{}

	void Delete()
	{
		if (ptr)
		{
			delete[] ptr;
			ptr = NULL;
		}
	}

	~AutoPtr()
	{
		Delete();
	}

	operator T *()
	{
		return ptr;
	}
};

class AutoFile
{
	FILE* file;
public:
	AutoFile(FILE * file)
		: file(file)
	{}

	operator FILE* ()
	{
		return file;
	}

	void Close()
	{
		if (file)
		{
			fclose(file);
			file = NULL;
		}
	}

	~AutoFile()
	{
		Close();
	}
};

int main() {
	AutoPtr<int> p1 = new int(5);
	*p1 += 2;
	AutoPtr<int[]> p2 = new int[5];
	for (int i = 0; i < 5; i++)
		p2[i] = 0;
	p2.Delete();
	//AutoFile f = fopen("1.bmp", "rb");
	//int (*pMain)() = main;
	unique_ptr<int> pp(new int(5));
	*pp.get();
	*pp = 0;
	unique_ptr<int[]> ppp(new int[5]);
	ppp[4] = 0;
	ppp[0] = 9;
	AutoPtr<AutoPtr<int>[]> qwerty = new AutoPtr<int>[10];
	for (int i = 0; i < 10; i++)
		qwerty[i] = new int(i);

	vector<unique_ptr<int>> qwerty1(10);
	for (int i = 0; i < 10; i++)
		qwerty1[i].reset(new int(i));

	vector<unique_ptr<int>> qwerty1;
	for (int i = 0; i < 10; i++)
		qwerty1.push_back(unique_ptr<int>(new int(i)));

	vector<AutoPtr<int>> qwerty2;
	for (int i = 0; i < 10; i++)
		qwerty2.push_back(new int(i));

	memset(qwerty2.data(), 0, 10 * sizeof(AutoPtr<int>));

	//class MyClass
	//{
	//	ostream & stream;
	//public:
	//	MyClass(ostream & stream)
	//		: stream(stream)
	//	{}

	//	void operator()(int a)
	//	{
	//		stream << a;
	//	}
	//} myClass(cout);

	//myClass(5);

	//class _CCC
	//{
	//public:
	//	int operator()(int a) const
	//	{
	//		return a;
	//	}
	//} l;

	auto l = [](int a) -> int
	{
		return a;
	};

	//MyClass qwe;
	//qwe(3);
	//qwe(3, 5.5);

	setlocale(LC_ALL, "Russian");
	ImNum <int> A(3, 4), B(3, 3);
	cout << Min(A, B, ImNumComp<int>) << endl;

	class _RRR
	{
	public:
		int operator() (const ImNum<int>& v1, const ImNum<int>& v2) const
		{
			typename AbsType<int>::type a1 = abs(v1), a2 = abs(v2);
			return a1 > a2 ? 1 : (a1 < a2 ? -1 : 0);
		}
	} rrr;

	cout << Min(A, B, [](const ImNum<int>&v1, const ImNum<int>&v2)
	{
		typename AbsType<int>::type a1 = abs(v1), a2 = abs(v2);
		return a1 > a2 ? 1 : (a1 < a2 ? -1 : 0);
	}) << endl;

	cout << Min(A, B, rrr) << endl;

	auto ll = [](const ImNum<int>& v1, const ImNum<int>& v2)
	{
		typename AbsType<int>::type a1 = abs(v1), a2 = abs(v2);
		return a1 > a2 ? 1 : (a1 < a2 ? -1 : 0);
	};

	cout << Min(A, B, ll) << endl;

	ImNum <float> C(2, 2);
	ImNum <short> D(3, 14);
	//ImNum<ImNum<int>> E(A, B);
	ImNum<int> E(4000000, 3000000);
	cout << abs(E) << endl << E[0] << " " << E[1];
	//cout << abs(E);
	double something;
	cout << "создалось:\n";

	/*cout << abs(C)<<endl;
	cout << abs(D) << endl;
	cout << C<<endl;*/

	//cout<<A.abs()<<endl;

	cout <<abs(C);
	return 0;
}