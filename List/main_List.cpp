#include <iostream>
#include "..//ListLib/TList.h"
#include <time.h>

int main()
{
	std::cout << "An example of using the List will be implemented here" << std::endl;
	TList <int> L1;
	float t1 = 0, t2 = 0, t3;
	bool ans;
	L1.AddFirst(60);
	t1 = clock();
	L1.AddFirst(70);
	L1.AddFirst(85);

	ans = L1.isFull();
	t2 = clock() - t1;

	TList<int> A;
	t3 = clock() - t2;

	std::cout << L1[1] << "\n" << L1[2] << "\n" << L1[3];
	std::cout << "\n";

	std::cout << "t1 = "<< t1 / CLOCKS_PER_SEC << "\n" << "t2 = " << t2 / CLOCKS_PER_SEC << "\n" << "t3 = " << t3 / CLOCKS_PER_SEC << "\n";

	std::cout << "\n";
  return 0;
}
