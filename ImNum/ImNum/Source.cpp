#include"NumClass.h"
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	ImNum A(1, 1), B(3, 3.14), C, D;
	double something;
	cout << "���������:\n";
	cout << "A="; A.print();
	cout << "B="; B.print();
	cout << "C="; C.print();
	cout << "D="; D.print();

	//cout << "\nC=B\n";
	//C = B;
	//C.print();

	//cout << "\nD=A+B\n";
	//D = A + B;
	//D.print();

	//cout << "\n-D\n";
	//D=-D;//�� ��
	//D.print();

	//cout << "\nA=B-C\n";
	//A = B - C;
	//A.print();

	//cout << "\nA=A*B\n";
	//A = A * B;
	//A.print();

	//cout << "\nA=A/B\n";
	//A = A / B;
	//A.print();

	//cout << "\nabs(A)\n";
	//something = A.abs();
	//cout << something << endl;

	//cout << "\nA.Dop\n";
	//A = A.Dop(A);//����� �� ��
	//A.print();

	//cout << "\n++A\n";
	//++A;
	//A.print();

	//cout << "\n--A\n";
	//--A;
	//A.print();

	//if (A == B) {
	//	cout << "�� ����� ((\n";
	//}
	//if (A != B) {
	//	cout << "B���� ))\n";
	//}
	//A = B;
	//if (A == B) {
	//	cout << "B���� ))\n";
	//}
	//if (A != B) {
	//	cout << "�� ����� ((\n";
	//}

	//cout << "\nA+=B\n";
	//A += B;
	//A.print();

	//cout << "\nA-=B\n";
	//A -= B;
	//A.print();

	//cout << "\nA*=B\n";
	//A *= B;
	//A.print();

	//cout << "\nA/=B\n";
	//A /= B;
	//A.print();

	//cout << "\nA+1\n";
	//A = A + 1;
	//A.print();

	//cout << "\nA+=2\n";
	//A+=2;
	//A.print();

	//cout << "\nD=A++\n";
	//D = A++;
	//D.print();

	//cout << "\nA++\n";
	//A++;
	//A.print();

	//cout << "\nD=A--\nA\n";
	//D = A--;
	//D.print();
	//A.print();

	//cout << "\n���� abs\n";
	//something = abs(A);
	//cout << something;

	cout << "\n+int\n";
	A =A+ 3;
	A.print();

	cout << "\n+double\n";
	A = A+3.14;
	A.print();

	cout << "\n+ImNum\n";
	A =A+ B;
	A.print();

}