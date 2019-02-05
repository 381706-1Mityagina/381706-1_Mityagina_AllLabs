#include "..//PolinomialLib/Polinomial.h"

int main()
{
	cout << "\n   <<< An example of using the List will be implemented here >>>" << "\n\n";

	int example1[5] = { 3, 2, 1, 4, 9 }, example2[5] = { 3, 9, 2, 0, 1 }, example3[5] = { 0, 1, 4, 6, 7 };
	
	TMonomial Moly1(5, example1, 2), Moly2(5, example2, 0), Moly3(5, example3, 1), moly(5, example3, 0);
	
	// проверка перегрузки оператора вывода
	cout << "\tMonom 1: " << Moly1 << "\n";
	cout << "\tMonom 2: " << Moly2 << "\n";
	cout << "\tMonom 3: " << Moly3 << "\n";

	TPolinomial Poly(5);
	Poly += Moly1;
	Poly += Moly3;
	// проверка перегрузки оператора вывода
	cout << "\n\tPolynom = Moly1 + Moly3 = " << Poly << "\n";

	// проверка перегрузки оператора ввода для мономов
	cin >> moly;
	cout << "\n\tyour monom : " << moly << "\n\n";

	return 0;
}