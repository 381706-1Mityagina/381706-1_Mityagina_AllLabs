#include "..//ViewTableLib/ViewTable.h"
#include <string>
#include <iostream>
#include <locale>

using namespace std;

int main()
{  
  cout << "\t<<< Creating new table >>>" << endl;
	TViewTable<int> hey(10);
  
	cout << "\t---Do: add key & data ---" << endl;
	string key_f ("f");
	hey.Put(key_f, 1);
  
	string key_s("s");
	hey.Put(key_s, 2);

  string key_t("t");
	hey.Put(key_t, 3);

  string key_fo ("fo");
	hey.Put(key_fo, 4);
  
	cout << "\t<<< View table >>>" << endl;
	cout << hey << endl;
  
	cout << "\t<<< Delete one of the elements >>>" << endl;
	hey.Del(key_f);
  
  cout << hey << endl;
  
	return 0;
}
