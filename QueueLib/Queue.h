#pragma once

#include "Stack.h"

template <class T>
class TQueue : public TStack <T> 
{
protected:
	int Start;
	int Count;
public:
	TQueue(int n = 0);
	TQueue(TQueue <T> &A);
	void PutSmth(T A);
	T GetSmth();
	bool IsFull();
	bool IsEmpty();
};
//-----------------------------------------------------------
template <class T>
TQueue<T>::TQueue(int n) : TStack<T>(n) 
{
	Start = 0; Count = 0; 
}
//-----------------------------------------------------------
template <class T>
TQueue<T>::TQueue(TQueue<T> &A) : TStack<T>(A) 
{
	Start = A.Start; Count = A.Count; 
}
//-----------------------------------------------------------
template <class T>
void TQueue<T>::PutSmth(T A) {
	if (IsFull()) 
		throw "wrong";
	else {
		TStack<T>::Mas[Start] = A;
		Start = (Start + 1) % TStack<T>::Size;
		Count++;
	}	
}
//-----------------------------------------------------------
template <class T>
T TQueue<T>::GetSmth() {
	if (IsEmpty()) 
		throw "wrong";
	else 
	{
		T temporary = TStack<T>::Mas[TStack<T>::TopOne];
		TStack<T>::TopOne = (TStack<T>::TopOne + 1) % TStack<T>::Size;
		Count--;
		return temp;
	}
}
//-----------------------------------------------------------
template <class T>
bool TQueue<T>::IsFull() {
	if (Count == TStack<T>::Size)
		return true;
	else
		return false;
}
//-----------------------------------------------------------
template <class T>
bool TQueue<T>::IsEmpty() {
	if (Count == 0)
		return true;
	else 
		return false;
}
//-----------------------------------------------------------