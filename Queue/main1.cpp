#include <iostream>
#include "..//QueueLib/Queue.h"

using namespace std;

int main( )
{
 TQueue<int> test(10);
	int temporary;
	cout << "\n\tTesting Queue Type Structure Support Programs" << endl;

	for (int i = 0; i < 10; i++)
	{
		if (!test.IsFull())
			test.Put(i);
		cout << "\t\tPut value  " << i << endl;
		cout << "\t\tGet value: " << test.Get() << endl << endl;
	}
	cout << endl;

	TQueue<int> test1(10);
	test1.Put(55);
	test1.Put(44);
	test1.Put(66);
	cout << "\t\tGet 1 value:" << test1.Get() << endl;
	cout << "\t\tGet 2 value:" << test1.Get() << endl;
	cout << endl;

	return 0;
}  
