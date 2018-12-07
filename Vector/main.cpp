#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Vectorlib.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "\t <<< An example of using the Vector will be implemented here >>>" << "\n\n";
  double a[] = { 0.6, 5.7, 0.4 };
	double b[] = { 0.85, 1.3, 5.8 };
	int c[] = { 4, 5, 7 };
  
  TVector<int> Sum;
	TVector<double> Razn;
  TVector<double> A(a, 3);
	TVector<double> B(b, 3);
 	TVector<int> C(c, 3);

	Razn = B - A;
	Sum = C + C;
	Sum++;
	
	std::cout << A << "\n" << B << "\n" << C << "\n" << Razn << "\n" << Sum << "\n";

	// Проверка работы операторов ввода-вывода
	/*cout << "\n\t<<< Ввод вектора >>>\n";
	cout << "Введите размер вектора\n";
	int n;
	cin >> n;
	
	TVector<int> _vector(n);
	
	cout << "Введите элементы вектора\n";
	cin >> _vector;
	cout << "\nВывод элементов вектора\n";
	cout << _vector << "\n"; */
	
return 0;
}
