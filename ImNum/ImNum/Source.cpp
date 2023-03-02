#include"NumClass.h"
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	ImNum <int> A(3, 4), B(3, 3);
	ImNum <float> C(2, 2);
	ImNum <short> D(3, 14);
	double something;
	cout << "создалось:\n";

	/*cout << abs(C)<<endl;
	cout << abs(D) << endl;
	cout << C<<endl;*/

	cout<<A.abs()<<endl;

	cout << abs(B)<<endl<<abs(C);
	return 0;
}