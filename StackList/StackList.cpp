#include <iostream>
#include "../StackListLib/StackList.h"

using namespace std;

int main()
{
  cout << "An example of using the StackList will be implemented here" << endl;
  
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "\t <<< Введите кол-во элементов в стеке >>>\n";
	do
		cin >> n; while (n < 0);
	TStackUsingList<char> symbolStack(n);
	char symbol;

	cout << "\t <<< Введите элементы стека >>> \n";
	for (int i = 0; i < n; i++)
	{
		cin >> symbol;
		symbolStack.Put(symbol); // помещаем элементы в стек
	}

	cout << "\n";

	symbolStack.Show(); // печать стека

	cout << "\n\t <<< Удалим элемент из стека >>>\n";
	symbolStack.Del();

	symbolStack.Show(); // печать стека

	cout << "\n\n";

	return 0;
}
