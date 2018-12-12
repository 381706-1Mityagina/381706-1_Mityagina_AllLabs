#include <iostream>
#include <locale.h>
#include "..//MatrixLib/Matrix.h"

using namespace std;

//---------------------------------------------------------------------------
//#pragma argsused
int main(int argc, char* argv[]) 
{
  setlocale(LC_ALL, "Russian");
  cout << "\t <<< An example of using the Matrix will be implemented here >>>" << "\n\n";
  TMatrix <int> Matr1(5), Matr2(5), Matr3(5), Matr4(5), Result1(5), Result2(5), Result3(5), Result4(5);
  int i, j;
  for (i = 0; i < 5; i++)
	for (j = 0; j < 5 - i; j++) 
	{
	  Matr1[i][j] = (i + 1) * (j + 1);
	  Matr2[i][j] = (i * 10 + j + 3 + i) * 100;
	  Matr3[i][j] = i + j;
	  Matr4[i][j] = 2*i + 2*j;
	}
  Result1 = Matr1 + Matr2;
  Result2 = Matr1 - Matr2;
  Result3 = Matr3 * Matr3;
  Result4 = Matr3/Matr4;

  cout << "\t || Matr1 ||" << endl << Matr1 << endl;
  cout << "\t || Matr2 ||" << endl << Matr2 << endl;
  cout << "\t || Matr3 ||" << endl << Matr3 << endl;
  cout << "\t ||Result1 ||" << endl << Result1 << endl;
  cout << "\t ||Result2 ||" << endl << Result2 << endl;
  cout << "\t ||Result3 ||" << endl << Result3 << endl;
  cout << "\t ||Result4 ||" << endl << Result4 << endl;


	// Проверка работы операторов ввода-вывода
	/*cout << "\n\t<<< Ввод матрицы >>>\n";
	cout << "Введите размер матрицы\n";
	int n;
	cin >> n;
	TMatrix <int> _matrix(n);
	cout << "Введите элементы матрицы\n";
	cin >> _matrix;
	cout << "\nВывод элементов матрицы\n";
	cout << _matrix << "\n";*/

  //system("pause");  
  return 0;
}
//--------------------------------------------------------------------------- 
