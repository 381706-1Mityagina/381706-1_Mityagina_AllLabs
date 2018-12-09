#include <iostream>
#include "..//StackLib/Stack.h"

using namespace std;

int main()
{	
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите кол-во элементов в стеке\n";
	cin >> n;
	TStack<char> symbolStack(n);
	char symbol;
	cout << "Введите элементы стека\n";
	for (int i = 0; i < n; i++)
	{
		cin >> symbol;
		symbolStack.Put(symbol); // помещаем элементы в стек
	}

	cout << "\n";

	symbolStack.PrintStack(); // печать стека

	cout << "\n\nУдалим элемент из стека\n";
	symbolStack.Get();

	symbolStack.PrintStack(); // печать стека

	TStack<char> newOne(symbolStack);

	cout << "\n\nКонструктор копирования в действии:\n";
	newOne.PrintStack();

	return 0;
}
