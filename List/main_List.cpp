#include <iostream>
#include "..//ListLib/TList.h"

int main()
{
	std::cout << "An example of using the List will be implemented here" << std::endl;
	TList <int> L1;
	L1.PutBegin(60);
	L1.PutBegin(40);
	L1.PutBegin(50);
	std::cout << L1.GetBegin();
	std::cout << "\n";
	system("pause");
  return 0;
}