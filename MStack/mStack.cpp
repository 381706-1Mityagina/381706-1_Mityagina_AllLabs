#include "..//MStackLib/MStack.h"
#include "..//Exception/Exception.h"
#include <time.h>
#include <iostream>

using namespace std;

int main()
{
	std::cout << "\nAn example of using the MStack will be implemented here" << std::endl;
	TMStack <int> MS(3, 11);
//	MS.Print();
	MS.Set(2, 1);
	MS.Set(2, 2);
	MS.Set(2, 3);
//	MS.Print();
	float t1 = 0, t2 = 0;
	t1 = clock();
	MS.Set(2, 4);
	t2 = (clock() - t1) / CLOCKS_PER_SEC;
	std::cout << t2 << "\n";
	TMStack <int> M2(MS);
	try 
	{
		std::cout << "\tMS.Get(2): " << MS.Get(2);
		std::cout << MS.Get(2);
		std::cout << MS.Get(2);
		std::cout << MS.Get(2);
		// std::cout << MS.Get(2);
	}
	catch (TException exp) 
	{
		exp.Show();
	}
	//system("pause");
	std::cout << "\n";
	return 0;
}
