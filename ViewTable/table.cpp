#include "..//ViewTableLib/ViewTable.h"
#include <string>
#include <iostream>
#include <locale>

using namespace std;

int main()
{
  TViewTableElem<int> elem_f("a"), elem_s("b"), elem_t("c");
  TViewTableElem<int> elem_fo(elem_f);
  
  TViewTable<int> hey(10);
  
  hey.Put(elem_s, 10);
  hey.Put(elem_t, 100);
  hey.Put(elem_f, 40);

  cout<<t<<"\n";
  
  hey.Put(elem_fo);
  
  return 0;
}
