#pragma once

#include <iostream>
#include "..//Exception/Exception.h"

using namespace std;

template <class T>
class TStack
{
protected:
	int size;
	int top;
	T* mas;
public:
	int GetSize() { return size; }
	TStack(int n = 0);
	TStack(TStack<T> &S);
	T Get();
	T GetButDontDel();
	void PrintStack();
	void Put(T A);
	bool IsFull();
	bool IsEmpty();
	int operator!=(const TStack<T>& stack) const;
	int operator==(const TStack<T>& stack) const;
	TStack& operator=(const TStack<T>& stack);
};
//----------------------------------------------------------------------
template <class T>
TStack <T> ::TStack(int n)
{
	if (n < 0)
		throw 1;
	else
		if (n == 0)
		{
			size = top = 0;
			mas = NULL;
		}
		else
		{
			size = n;
			top = 0;
			mas = new T[size];
			for (int i = 0; i < size; i++)
				mas[i] = 0;
		}
}
//----------------------------------------------------------------------
template <class T>
TStack <T> ::TStack(TStack <T> &S)
{
	size = S.size;
	top = S.top;
	if (size == 0)
		mas = NULL;
	else
	{
		mas = new T[size];
		for (int i = 0; i < size; i++)
			mas[i] = S.mas[i];
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
		mas[top] = A;
		top++;
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
	top--;
	return mas[top];
  }
}
//----------------------------------------------------------------------
template <class T>
T TStack<T> ::GetButDontDel()
{
	if (IsEmpty())
		throw "Stack is empty.-.";
	return mas[top - 1];
}
//----------------------------------------------------------------------
template <class T>
bool TStack<T> ::IsFull()
{
	if (top >= size)
		return true;
	else
		return false;
}
//----------------------------------------------------------------------
template <class T>
bool TStack<T> ::IsEmpty()
{
	if (top == 0)
		return true;
	return false;
}
//----------------------------------------------------------------------
template <class T>
TStack<T>& TStack<T> ::operator=(const TStack<T>& stack)
{
	if (this != &stack)
	{
		delete[]mas;
		top = stack.top;
		size = stack.size;
		mas = new T[size];
		for (int i = 0; i < size; i++)
		{
			mas[i] = stack.mas[i];
		}
	}
	return *this;
}

//----------------------------------------------------------------------
template <class T>
int TStack<T> ::operator==(const TStack<T>& stack) const
{
	if (top != stack.top)
		return 0;
	if (size != stack.size)
		return 0;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] != stack.mas[i])
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
void TStack<T>::PrintStack()
{
	for (int i = top - 1; i >= 0; i--)
		cout << "\t|" << mas[i] << "|" << endl;
}
//----------------------------------------------------------------------
