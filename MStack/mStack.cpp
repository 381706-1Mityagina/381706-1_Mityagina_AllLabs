#include "..//MStackLib/MStack.h"
#include "..//Exception/Exception.h"
#include <iostream>

using namespace std;

int main()
{
	std::cout << "An example of using the MStack will be implemented here" << std::endl;
	TMStack <int> MS(10, 3);
//	MS.Print();
	MS.Set(2, 1);
	MS.Set(2, 2);
	MS.Set(2, 3);
//	MS.Print();
	MS.Set(2, 4);
	TMStack <int> M2(MS);
	try 
	{
		std::cout << "\tMS.Get(2): " << MS.Get(2);
		std::cout << MS.Get(2);
		std::cout << MS.Get(2);
		std::cout << MS.Get(2);
		// std::cout << MS.Get(2);
	}
	catch (TException exp) {
		exp.Show();
	}
	//system("pause");
	return 0;
}
