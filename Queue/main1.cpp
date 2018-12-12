#include <iostream>
#include "..//QueueLib/Queue.h"

using namespace std;

int main( )
{
 TQueue<int> test(10);
 int temporary;
 cout << "Testing Queue Type Structure Support Programs" << endl;
  
 for ( int i = 0; i < 10; i++ ) 
 {
 while (!test.IsFull())
   test.Put(i);
 cout << "\tPut value  " << i << endl;
 cout << "\tGet value: " << test.Get() << endl;
 }
 cout << endl;
 
 TQueue<int> test1(10);
 test1.Put(55);
 test1.Put(44);
 test1.Put(66);
 cout << "\tGet 1 value:" << test1.Get() << endl;
 cout << "\tGet 2 value:" << test1.Get() << endl;

 return 0;
}  
