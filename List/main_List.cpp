#include <iostream>
#include "..//ListLib/TList.h"
#include <time.h>

int main()
{
	std::cout << "An example of using the List will be implemented here" << std::endl;
	TList <int> L1;
	float t1 = 0, t2 = 0, t = 0, tt = 0;
	bool ans;
	L1.AddFirst(60);
	t1 = clock();
	t = t1 / CLOCKS_PER_SEC;
	L1.AddFirst(70);
	L1.AddFirst(85);

	t2 = clock() - t1;
	ans = L1.isFull();
	tt = t2 / CLOCKS_PER_SEC;

	std::cout << L1[1] << "\n" << L1[2] << "\n" << L1[3];
	std::cout << "\n";

	std::cout << "t1 = "<< t << "\n" << "t2 = " << tt << "\n" ;

	std::cout << "\n";
  return 0;
}
