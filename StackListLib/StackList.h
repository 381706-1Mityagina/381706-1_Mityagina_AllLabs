#pragma once
#include <iostream>

#include "..//ListLib/TList.h"
#include "../Exception/Exception.h"

template <class T>
class TStackUsingList : public TList<T>
{
protected:
	int st_size;
public:
	TStackUsingList <T>(int _size = 5);
	TStackUsingList <T>(TStackUsingList<T> &A);
	~TStackUsingList();

	T Get();
	void Put(T A);
	void Show();
	int GetSize();
	int GetMSize();
	bool IsFull();
	bool IsEmpty();
};
//-------------------------------------------------------------------------
template <class T>
TStackUsingList <T>::TStackUsingList(int _size)
{
	if (_size <= 0)
		throw TException("Unacceptable size");
	st_size = _size;
}
//-------------------------------------------------------------------------
template <class T>
TStackUsingList <T>::TStackUsingList(TStackUsingList<T> &A) : TList<T>(A)
{
	TList<T>::size = A.size;
}
//-------------------------------------------------------------------------
template <class T>
TStackUsingList <T>::~TStackUsingList()
{}
//-------------------------------------------------------------------------
template <class T>
void TStackUsingList <T>::Put(T A)
{
	if (this->IsFull())
		throw TException("Stack is full. Cannot put anything.");
	TList<T>::AddFirst(A);
}
//-------------------------------------------------------------------------
template <class T>
T TStackUsingList <T>::Get()
{
	if (this->IsEmpty())
		throw TException("Stack is empty. Nothing to get.");
	TList<T>::delFirst();
}
//-------------------------------------------------------------------------
template <class T>
int TStackUsingList <T>::GetMSize()
{
	return st_size;
}
//-------------------------------------------------------------------------
template <class T>
int TStackUsingList <T>::GetSize()
{
	return TList<T>::size;
}
//-------------------------------------------------------------------------
template <class T>
bool TStackUsingList <T>::IsEmpty()
{
	if (TList<T>::size == 0)
		return true;
	return false;
}
//-------------------------------------------------------------------------
template <class T>
bool TStackUsingList <T>::IsFull()
{
	if (TList<T>::size == st_size)
		return true;
	return false;
}
//-------------------------------------------------------------------------
template <class T>
void TStackUsingList <T>::Show()
{
	if (this -> IsEmpty())
		throw TException("Stack is empty. Cannot show it.");
	TList<T>::Show();
}
//-------------------------------------------------------------------------
