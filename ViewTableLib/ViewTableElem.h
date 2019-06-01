#pragma once
#include "String.h"
#include <iostream>
using namespace std;

template <class T>
class TViewTableElem
{
protected:
	TString key;
	T data;
public:
	TViewTableElem();
	TViewTableElem(TString k, T d);
	TViewTableElem(TViewTableElem<T>& A);
	TViewTableElem<T>& operator=(TViewTableElem<T>& A);

	T GetData();
	T& operator()();
	TString GetKey();
	void SetData(T d);
	void SetKey(TString k);
	bool operator==(TViewTableElem<T>& A);
	bool operator>(TViewTableElem<T>& A);
	bool operator< (TViewTableElem<T>& A);

	template <class T1>
	friend ostream& operator<<(ostream& ostr, const TViewTableElem<T1> SE);
};
//------------------------------------------------------------------------------------
template<class T>
TViewTableElem<T>::TViewTableElem()
{
	TString no("no");
	key = no;
	data = (T)0;
}
//------------------------------------------------------------------------------------
template <class T>
TViewTableElem<T>::TViewTableElem(TString k, T d)
{
	key = k;
	data = d;
}
//------------------------------------------------------------------------------------
template <class T>
TViewTableElem<T>::TViewTableElem(TViewTableElem& A)
{
	key = A.key;
	data = A.data;
}
//------------------------------------------------------------------------------------
template <class T>
TViewTableElem<T>& TViewTableElem<T>::operator=(TViewTableElem<T>& A)
{
	key = A.key;
	data = A.data;
	return *this;
}
//------------------------------------------------------------------------------------
template <class T>
TString TViewTableElem<T>::GetKey()
{
	return key;
}
//------------------------------------------------------------------------------------
template <class T>
T TViewTableElem<T>::GetData()
{
	return data;
}
//------------------------------------------------------------------------------------
template <class T>
bool TViewTableElem<T>::operator>(TViewTableElem<T>& A)
{
	return key > A.key;
}
//------------------------------------------------------------------------------------
template <class T>
bool TViewTableElem<T>::operator<(TViewTableElem<T>& A)
{
	return key < A.key;
}
//------------------------------------------------------------------------------------
template <class T>
void TViewTableElem<T>::SetKey(TString k)
{
	key = k;
}
//------------------------------------------------------------------------------------
template <class T>
void TViewTableElem<T>::SetData(T d)
{
	data = d;
}
//------------------------------------------------------------------------------------
template<class T>
T& TViewTableElem<T>::operator()()
{
	return data;
}
//------------------------------------------------------------------------------------
template <class T>
bool TViewTableElem<T>::operator==(TViewTableElem<T>& A)
{
	return key == A.key;
}
//------------------------------------------------------------------------------------
template <class T1>
ostream& operator<<(ostream& ostr, const TViewTableElem<T1> el)
{
	ostr << el.key << "\t|" << el.data;
	return ostr;
}
//------------------------------------------------------------------------------------
