#include"NumClass.h"
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	ImNum A(1, 1), B(3, 3.14), C, D;
	double something;
	cout << "создалось:\n";
	cout << "A="; A.print();
	cout << "B="; B.print();
	cout << "C="; C.print();
	cout << "D="; D.print();

	cout << "\nC=B\n";
	C = B;
	C.print();

	cout << "\nD=A+B\n";
	D = A + B;
	D.print();

	cout << "\n-D\n";
	D=-D;//не оч
	D.print();

	cout << "\nA=B-C\n";
	A = B - C;
	A.print();

	cout << "\nA=A*B\n";
	A = A * B;
	A.print();

	cout << "\nA=A/B\n";
	A = A / B;
	A.print();

	cout << "\nabs(A)\n";
	something = A.abs(A);//както не оч
	cout << something << endl;

	cout << "\nA.Dop\n";
	A = A.Dop(A);//както не оч
	A.print();

	cout << "\n++A\n";
	++A;
	A.print();

	cout << "\n--A\n";
	--A;
	A.print();

	if (A == B) {
		cout << "Не вышло ((\n";
	}
	if (A != B) {
		cout << "Bышло ))\n";
	}
	A = B;
	if (A == B) {
		cout << "Bышло ))\n";
	}
	if (A != B) {
		cout << "Не вышло ((\n";
	}

	cout << "\nA+=B\n";
	A += B;
	A.print();

	cout << "\nA-=B\n";
	A -= B;
	A.print();

	cout << "\nA*=B\n";
	A *= B;
	A.print();

	cout << "\nA/=B\n";
	A /= B;
	A.print();
}