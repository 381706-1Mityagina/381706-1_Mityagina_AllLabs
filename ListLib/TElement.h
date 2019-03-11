#pragma once
#include <iostream>

using namespace std;

template <class T>
class TElement
{
protected:
	T data;
	TElement<T>* next;

public:
	TElement<T>(T _data = 0, TElement<T>* n = 0);
	TElement<T>(TElement<T>& A);

	T GetData();
	TElement<T>* GetNext();
	void SetData(T _data);
	void SetNext(TElement<T>* n);
};
//-------------------------------------------------------------------------------------------------
template <class T>
TElement<T>::TElement(T _data, TElement<T>* n)
{
	data = _data;
	next = n;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TElement<T>::TElement(TElement<T>& A)
{
	data = A.data;
	next = A.next;
}
//-------------------------------------------------------------------------------------------------
template <class T>
T TElement<T>::GetData()
{
	return data;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TElement<T>* TElement<T>::GetNext()
{
	return next;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TElement<T>::SetData(T _data)
{
	data = _data;
}
//-------------------------------------------------------------------------------------------------
template <class T>
void TElement<T>::SetNext(TElement<T>* n)
{
	next = n;
}
//------------------------------------------------------------------------------------------------
