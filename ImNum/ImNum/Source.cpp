#include"NumClass.h"
#include <iostream>
#include <vector>

template <class T>
using CompType = int (*)(const T&, const T&);

template<class T>
void SortInc(vector<ImNum<T>>& mass, CompType<ImNum<T>> comp/*int (*comp)(const ImNum<T>&, const ImNum<T>&)*/)
{
	ImNum<T> C;
	size_t len = mass.size();
	cout << "в массиве " << len << " элементов" << endl;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1; j++) {
			if (comp(mass[j], mass[j + 1]) == 1) {
				C = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = C;
			}
		}
	}
}

typedef int (*TCompDouble)(const ImNum<double>&, const ImNum<double>&);

void SortIncDouble(vector<ImNum<double>>& mass, TCompDouble comp)
{
	ImNum<double> C;
	size_t len = mass.size();
	cout << "в массиве " << len << " элементов" << endl;
	for (size_t i = 0; i < len; i++) {
		for (size_t j = 0; j < len - 1; j++) {
			if (comp(mass[j], mass[j + 1]) == 1) {
				C = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = C;
			}
		}
	}
}

//template<class T, class T1>
//void SortIncAbs(vector<ImNum<T>>& mass)
//{
//
//	ImNum<T> C;
//	size_t len = mass.size();
//	cout << "в массиве " << len << " элементов" << endl;
//	for (int i = 0; i < len; i++) {
//		for (int j = 0; j < len - 1; j++) {
//			if (comp(mass[j], mass[j + 1]) == 1) {
//				C = mass[j];
//				mass[j] = mass[j + 1];
//				mass[j + 1] = C;
//			}
//		}
//	}
//}

//class SortInc
//{
//public:
//	template<class T, class T1>
//	void operator()(vector<ImNum<T>>& mass, T1 comp)
//	{
//		ImNum<T> C;
//		size_t len = mass.size();
//		cout << "в массиве " << len << " элементов" << endl;
//		for (int i = 0; i < len; i++) {
//			for (int j = 0; j < len - 1; j++) {
//				if (comp(mass[j], mass[j + 1]) == 1) {
//					C = mass[j];
//					mass[j] = mass[j + 1];
//					mass[j + 1] = C;
//				}
//			}
//		}
//	}
//} SortInc;
// 
//class CompAbs
//{
//public:
//	template<class T>
//	int operator()(const ImNum<T>& v1, const ImNum<T>& v2)
//	{
//		typename AbsType<T>::type a1 = abs(v1), a2 = abs(v2);
//		return a1 > a2 ? 1 : (a1 < a2 ? -1 : 0);
//	}
//}CompAbs;
// 
//class CompReal
//{
//public:
//	template<class T>
//	int operator()(const ImNum<T>& v1, const ImNum<T>& v2)
//	{
//		return v1.giveR() > v2.giveR() ? 1 : (v1.giveR() < v2.giveR() ? -1 : 0);
//	}
//}CompReal;
// 
//class CompIm
//{
//public:
//	template<class T>
//	int operator()(const ImNum<T>& v1, const ImNum<T>& v2)
//	{
//		return v1.giveI() > v2.giveI() ? 1 : (v1.giveI() < v2.giveI() ? -1 : 0);
//	}
//}CompIm;

//template<class T, class T1>
//void SortInc(vector<ImNum<T>> & mass, T1 comp)
//{
//	ImNum<T> C;
//	size_t len = mass.size();
//	cout << "в массиве " << len << " элементов" << endl;
//	for (int i = 0; i < len; i++) {
//		for (int j = 0; j < len - 1; j++) {
//			if (comp(mass[j], mass[j+1]) == 1) {
//				C = mass[j];
//				mass[j] = mass[j + 1];
//				mass[j + 1] = C;
//			}
//		}
//	}
//}
//
template<class T>
int CompAbs(const ImNum<T>& v1, const ImNum<T>& v2) //сравнение 2 элем по модулю
{
	typename AbsType<T>::type a1 = abs(v1), a2 = abs(v2);
	return a1 > a2 ? 1 : (a1 < a2 ? -1 : 0);
}

int main() {

	//template<class T>
	//auto CompAbs = [](const ImNum<T>& v1, const ImNum<T>& v2) //сравнение 2 элем по модулю
	//{
	//	typename AbsType<T>::type a1 = abs(v1), a2 = abs(v2);
	//	return a1 > a2 ? 1 : (a1 < a2 ? -1 : 0);
	//};
	//
	//template<class T>
	//auto CompReal = [](const ImNum<T>& v1, const ImNum<T>& v2) //сравнение 2 элем по модулю
	//{
	//	return v1.giveR() > v2.giveR() ? 1 : (v1.giveR() < v2.giveR() ? -1 : 0);
	//};
	//
	//template<class T>
	//auto CompIm = [](const ImNum<T>& v1, const ImNum<T>& v2) //сравнение 2 элем по модулю
	//{
	//	return v1.giveI() > v2.giveI() ? 1 : (v1.giveI() < v2.giveI() ? -1 : 0);
	//};

	setlocale(LC_ALL, "Russian");
	vector<ImNum<double>> mass;
	ImNum<double> C;
	ImNum<double> v1,v2;

	/*заполнение массива*/ {
		mass.push_back(ImNum<double>(1, 1));//без указания типа видит только первое число
		mass.push_back(ImNum<double>(5.58, 1.7));
		mass.push_back(ImNum<double>(8.1, 678));
		mass.push_back(ImNum<double>(8, 1));
		mass.push_back(ImNum<double>(1, 0.0004));
		mass.push_back(ImNum<double>(0.7584, 0.54));}

	//{
	//	mass.push_back(ImNum<double>(1, 1));//без указания типа видит только первое число
	//	mass.push_back(ImNum<double>(6, 6));
	//	mass.push_back(ImNum<double>(2, 2));
	//	mass.push_back(ImNum<double>(4, 4)); }

	SortInc(mass, CompAbs<double>); //работает//функции
	//SortInc(mass, CompAbs); //работает//классы

	//SortInc(mass, CompReal<double>); //работает//функции
	//SortInc(mass, CompReal); //работает//классы

	//SortInc(mass, CompIm<double>); //работает//функции
	//SortInc(mass, CompIm); //работает//классы

	/*auto SortInc = [&](auto comp) {
		size_t len = mass.size();
		cout << "в массиве " << len << " элементов" << endl;
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len - 1; j++) {
				if (comp(mass[j], mass[j + 1]) == 1) {
					C = mass[j];
					mass[j] = mass[j + 1];
					mass[j + 1] = C;
				}
			}
		}
	};*/

	//SortInc(CompAbs<double>);//работает//лямбда
	//SortInc(CompReal<double>);//работает//лямбда
	//SortInc(CompIm<double>);//работает//лямбда

	for (ImNum<double> n : mass)
		cout << endl << n ;

	return 0;
}