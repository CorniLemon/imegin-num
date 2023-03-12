#include <cstdarg>
#include <iostream>
using namespace std;

void print(const char* fmtStr, ...)
{
	va_list argList;
	va_start(argList, fmtStr);
	while (*fmtStr)
	{
		switch (*fmtStr)
		{
		case 'i':
			int ia = va_arg(argList, int);
			cout << ia << " ";
			break;
		case 'd':
			double da = va_arg(argList, double);
			cout << da << " ";
			break;
		}
		++fmtStr;
	}
	va_end(argList);
}

void printT()
{
}

char* PrintInStr(const char* fmt, ...)
{
	va_list argList;
	va_start(argList, fmt);
	int cnt = vsnprintf(NULL, 0, fmt, argList);
	char* buf = new char[cnt + 1];
	vsnprintf(buf, cnt + 1, fmt, argList);
	return buf;
}

template<class T>
string PrintInStr(T a)
{
	stringstream ss;
	ss << a;
	return ss.str();
}

template<class T, class... types>
string PrintInStr(T a, types... args)
{
	stringstream ss;
	ss << a << " ";
	return ss.str() + PrintInStr(args...);
}

template<class T, class... types>
void printT(T a, types... args)
{
	cout << a << " ";
	printT(args...);
}

template<class T>
auto sum(T a)
{
	return a;
}

template<class T, class... types>
auto sum(T a, types... args)
{
	return a + sum(args...);
}

void fffff()
{
	print("iiddii", 5, 6, 4.5, 3.6, 8, 9);
	printT(5, 6, 4.5, 3.6, 8, 9);
	sum(4.5, 9, 4.8f);
}