#include <iostream>
#include <string>
#include "..//PolandLib/Poland.h"

using namespace std;

int main()
{
		cout << "\n\t<<< An example of using reverse polish notation will be implemented here >>>" << endl;
		
		char a[] = "(44-25)*17+9"; 
	TString Example(a);
		cout << "\t\t";
		Example.Print();
	
		TQueue<char> B;
		B = ToPolish(Example);
		B.Show();
		cout << GettingRez(B) << "\n";
	
	return 0;
}
