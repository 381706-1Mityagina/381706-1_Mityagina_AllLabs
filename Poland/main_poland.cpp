#include <iostream>
#include <string>
#include "..//PolandLib/Poland.cpp"

using namespace std;

int main()
{
  //try
   {
    cout << "\n\t<<< An example of using reverse polish notation will be implemented here >>>" << endl;

    cout << "\n\t\t||| An example, written by me |||\n" << endl;
    char a[] = "(-1*7+9/3)";
    TString example(a), example2;
    TQueue<char> B, C;
    cout << "\t" << example << "\n\n";
    B = ToPolish(example); 

    cout << "\t"; B.ShowQ();
    cout << " = " << GettingRez(B) << "\n";

    cout << "\n\t\t||| An example, written by you |||" << endl;
    cout << "\n\t||| Write an arithmetic expression, follow the following format: ( expression ) IMPORTANT |||" << endl;
    cout << "\n\t||| brackets are extremly needed |||" << endl;
    //cout << "\t"; cin >> example2;
    //cout << "\n";
    //C = ToPolish(example2);
    //cout << "\t"; C.ShowQ();
    //cout << " = " << GettingRez(C) << "\n\n";
   }

  /*catch (TException exc)
   {
    exc.Show();
   }*/
	
  return 0;
}
