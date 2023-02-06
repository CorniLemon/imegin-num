#include"NumClass.h"
#include <iostream>
using namespace std;

int main() {
	ImNum A(1, 1), B(3, 3.14), C;
	A.print();
	B.print();
	C.print();

	C = A + B;
	C.print();
}