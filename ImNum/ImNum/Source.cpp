#include"NumClass.h"
#include <iostream>
#include <vector>

template<class T, class T1>
void SortInc(vector<ImNum<T>> & mass, T1 comp)
{
	ImNum<T> C;
	size_t len = mass.size();
	cout << "� ������� " << len << " ���������" << endl;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1; j++) {
			if (comp(mass[j], mass[j+1]) == 1) {
				C = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = C;
			}
		}
	}
}

template<class T>
int CompAbs(const ImNum<T>& v1, const ImNum<T>& v2) //��������� 2 ���� �� ������
{
	typename AbsType<T>::type a1 = abs(v1), a2 = abs(v2);
	return a1 > a2 ? 1 : (a1 < a2 ? -1 : 0);
}

int main() {
	setlocale(LC_ALL, "Russian");
	vector<ImNum<double>> mass;
	ImNum<double> C;
	//cout << "������� �������� �������, ��� ���������� ������� �����\n";
	//while (type(of cin>>A))

	/*���������� �������*/ {
		mass.push_back(ImNum<double>(1, 1));//��� �������� ���� ����� ������ ������ �����
		mass.push_back(ImNum<double>(5.58, 1.7));
		mass.push_back(ImNum<double>(8.1, 678));
		mass.push_back(ImNum<double>(8, 1));
		mass.push_back(ImNum<double>(1, 0.0004));
		mass.push_back(ImNum<double>(0.7584, 0.54));}

	//{
	//	mass.push_back(ImNum<double>(1, 1));//��� �������� ���� ����� ������ ������ �����
	//	mass.push_back(ImNum<double>(6, 6));
	//	mass.push_back(ImNum<double>(2, 2));
	//	mass.push_back(ImNum<double>(4, 4)); }

	//SortInc(mass, CompAbs<double>); //��������

	//SortInc(mass, CompReal<double>); //��������

	//SortInc(mass, CompIm<double>); //��������

	for (ImNum<double> n : mass)
		cout << endl << n ;

	return 0;
}