/*#pragma once

#include <iostream>
#include "..//Exception/Exception.h"

using namespace std;

template <class T>
class TStack
{
protected:
  int Size; // Размер стека
  int Top; // элемент,расположенный на вершине стека
  T* Mas; // элементы стека
public:
  int GetSize() { return Size; } // возвращает размер
  TStack(int n = 0); // конструктор инициализации
  TStack(TStack<T> &S); // конструктор копирования
  T Get(); // возвращает элемент, расположенный на вершине стека
  void Put(T A); // положить элемент
  bool IsFull(); // проверка на полноту
  bool IsEmpty(); // проверка на пустоту
  void PrintStack(); // вывод стека на экран
  virtual ~TStack(); // деструктор

  int operator!=(const TStack<T>& stack) const; // проверка на неравенство
  int operator==(const TStack<T>& stack) const; //проверка на равенство
  TStack& operator=(const TStack<T>& stack); // приравнивание
};
//----------------------------------------------------------------------
template <class T>
TStack <T> ::TStack(int n)
{
  if (n < 0) throw TException(" Negative size.");
  else
  if (n == 0)
  {
    Size = Top = 0;
    Mas = NULL;
  }
  else
  {
    Size = n;
    Top = 0;
    Mas = new T[Size];
    for (int i = 0; i < Size; i++)
      Mas[i] = 0;
   }
}
//----------------------------------------------------------------------
template <class T>
TStack <T> ::TStack(TStack <T> &S)
{
  Size = S.Size;
  Top = S.Top;
  if (Size == 0)
    Mas = NULL;
  else
  {
    Mas = new T[Size];
    for (int i = 0; i < Size; i++)
      Mas[i] = S.Mas[i];
  }
}
//----------------------------------------------------------------------
template <class T>
void TStack<T> ::Put(T A)
{
  if (IsFull())
    throw TException("Stack is full");
  else
  {
    Mas[Top] = A;
    Top++;
  }
}
//----------------------------------------------------------------------
template <class T>
T TStack<T> ::Get()
{
  if (IsEmpty())
    throw TException("Stack is empty");
  else
  {
    Top--;
    return Mas[Top];
  }
}
//----------------------------------------------------------------------
template <class T>
bool TStack<T> ::IsFull()
{
  if (Top >= Size)
    return true;
  else
    return false;
}
//----------------------------------------------------------------------
template <class T>
bool TStack<T> ::IsEmpty()
{
  if (Top == 0)
    return true;
  else
    return false;
}
//----------------------------------------------------------------------
template <class T>
TStack<T>& TStack<T> ::operator=(const TStack<T>& stack) 
{
if (this != &stack)
 {
   if (Top != stack.Top) 
    {
      Top = stack.Top;
      delete[] Mas;
      Mas = new T[Top];
    }
    Size = stack.Size;
    for (int i = 0; i < Size; i++) 
    {
      Mas[i] = stack.Mas[i];
    }
  }
return *this;
}

//----------------------------------------------------------------------
template <class T>
int TStack<T> ::operator==(const TStack<T>& stack) const 
{
  if (Top != stack.Top)
    return 0;
  if (Size != stack.Size)
    return 0;
  for (int i = 0; i < Size; i++) 
  {
    if (Mas[i] != stack.Mas[i])
      return 0;
  }
  return 1;
}
//----------------------------------------------------------------------
template <class T>
int TStack<T> ::operator!=(const TStack<T>& stack) const 
{
  return !(*this == stack);
}
//----------------------------------------------------------------------
template <class T>
void TStack<T>:: PrintStack()
{
  for (int i = Top - 1; i >= 0; i--)
    cout << "\t|" << Mas[i] << "|" << endl;
}
//----------------------------------------------------------------------
template<class T>
TStack <T>::~TStack()
{
  Top = 0;
  Size = 0;
  delete[] Mas;
}
*/
#pragma once

#include <iostream>
#include "..//Exception/Exception.h"

using namespace std;

template <class T>
class TStack
{
protected:
  int Size; // Размер стека
  int Top; // элемент,расположенный на вершине стека
  T* Mas; // элементы стека
public:
  int GetSize() { return Size; } // возвращает размер
  TStack(int n = 0); // конструктор инициализации
  TStack(TStack<T> &S); // конструктор копирования
  T Get(); // возвращает элемент, расположенный на вершине стека
  void Put(T A); // положить элемент
  bool IsFull(); // проверка на полноту
  bool IsEmpty(); // проверка на пустоту
  void PrintStack(); // вывод стека на экран

  int operator!=(const TStack<T>& stack) const; // проверка на неравенство
  int operator==(const TStack<T>& stack) const; //проверка на равенство
  TStack& operator=(const TStack<T>& stack); // приравнивание
};
//----------------------------------------------------------------------
template <class T>
TStack <T> ::TStack(int n)
{
  if (n < 0) throw TException(" Negative size.");
  else
	if (n == 0)
	{
	  Size = Top = 0;
	  Mas = NULL;
	}
	else
	{
	  Size = n;
	  Top = 0;
	  Mas = new T[Size];
	  for (int i = 0; i < Size; i++)
		Mas[i] = 0;
	}
}
//----------------------------------------------------------------------
template <class T>
TStack <T> ::TStack(TStack <T> &S)
{
  Size = S.Size;
  Top = S.Top;
  if (Size == 0)
	Mas = NULL;
  else
  {
	Mas = new T[Size];
	for (int i = 0; i < Size; i++)
	  Mas[i] = S.Mas[i];
  }
}
//----------------------------------------------------------------------
template <class T>
void TStack<T> ::Put(T A)
{
  if (IsFull())
	throw TException("Stack is full");
  else
  {
	Mas[Top] = A;
	Top++;
  }
}
//----------------------------------------------------------------------
template <class T>
T TStack<T> ::Get()
{
  if (IsEmpty())
	throw TException("Stack is empty");
  else
  {
	Top--;
	return Mas[Top];
  }
}
//----------------------------------------------------------------------
template <class T>
bool TStack<T> ::IsFull()
{
  if (Top >= Size)
	return true;
  else
	return false;
}
//----------------------------------------------------------------------
template <class T>
bool TStack<T> ::IsEmpty()
{
  if (Top == 0)
	return true;
  else
	return false;
}
//----------------------------------------------------------------------
template <class T>
TStack<T>& TStack<T> ::operator=(const TStack<T>& stack) 
{
		if (this != &stack)
		{
			if (Top != stack.Top) 
			{
				Top = stack.Top;
				delete[] Mas;
				Mas = new T[Top];
			}
			Size = stack.Size;
			for (int i = 0; i < Size; i++) 
			{
				Mas[i] = stack.Mas[i];
			}
		}
		return *this;
	}

//----------------------------------------------------------------------
template <class T>
int TStack<T> ::operator==(const TStack<T>& stack) const 
{
		if (Top != stack.Top)
			return 0;
		if (Size != stack.Size)
			return 0;
		for (int i = 0; i < Size; i++) 
		{
			if (Mas[i] != stack.Mas[i])
				return 0;
		}
		return 1;
}
//----------------------------------------------------------------------
template <class T>
int TStack<T> ::operator!=(const TStack<T>& stack) const 
	{
		return !(*this == stack);
	}
//----------------------------------------------------------------------
template <class T>
void TStack<T>:: PrintStack()
{
	for (int i = Top - 1; i >= 0; i--)
		cout << "\t|" << Mas[i] << "|" << endl;
}
//----------------------------------------------------------------------
