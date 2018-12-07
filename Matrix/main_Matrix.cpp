#include <iostream>
#include "..//MatrixLib/Matrix.h"

using namespace std;

//---------------------------------------------------------------------------
//#pragma argsused
int main(int argc, char* argv[]) 
{
  cout << "\t <<< An example of using the Matrix will be implemented here >>>" << endl;
  TMatrix <int> Matr1(5), Matr2(5), Matr3(5), Result1(5), Result2(5), Result3(5);
  int i, j;
  for (i = 0; i < 5; i++)
	for (j = 0; j < 5 - i; j++) 
	{
	  Matr1[i][j] = (i + 1) * (j + 1);
	  Matr2[i][j] = (i * 10 + j + 3 + i) * 100;
	  Matr3[i][j] = i + j;
	}
	
  Result1 = Matr1 + Matr2;
  Result2 = Matr1 - Matr2;

  cout << "\t || Matr1 ||" << "\n" << Matr1 << "\n";
  cout << "\t || Matr2 ||" << "\n" << Matr2 << "\n";
  cout << "\t || Matr3 ||" << "\n" << Matr3 << "\n";
  cout << "\t ||Result1 ||" << "\n" << Result1 << "\n";
  cout << "\t ||Result2 ||" << "\n" << Result2 << "\n";

  //system("pause");  
  return 0;
}
//--------------------------------------------------------------------------- 
