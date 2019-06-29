#include "..//ViewTableLib/ViewTable.h"
#include <string>
#include <iostream>
#include <locale>

using namespace std;

int main()
{  
  TViewTable<int> hey(10);
  
  hey.Put('b', 10);
  hey.Put('c', 100);
  hey.Put('a', 40);

  cout<<hey<<"\n";
  
  hey.Put(a, 40);
  
  return 0;
}
