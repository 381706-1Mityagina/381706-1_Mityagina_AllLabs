#include <iostream>
#include "..//ArrayListLib/TArrayList.h"

int main()
{
	std::cout << "An example of using the List will be implemented here" << std::endl;
	TArrayList <int> L1;
	L1.PutStart(60);
	L1.PutStart(40);
	std::cout << L1.GetStart();
	std::cout << "\n";
	//system("pause");
  return 0;
}
