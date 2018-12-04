#pragma once
#pragma once

#include "TElement.h"

template <class T>
class TList 
{
protected:
	TElement <T>* begin;
public:
	TList(); 
	TList(TList<T> &List); 
	virtual ~TList();

	void PutBegin(T A); 
	void PutEnd(T A); 
	T GetBegin(); 
				
	bool IsFull();
	bool IsEmpty();
};

//-----------------------------------------------------------
template <class T>
TList<T>::TList()
{
	begin = 0;
}
//-----------------------------------------------------------
template <class T>
TList<T>::TList(TList<T> &List)
{
	TElement<T>* A = List.Begin, B;
	if (List.begin == 0)
		begin = 0;
	else {
		begin = new TElement<T>(*List.begin); 
		B = begin;
		while (a->GetNext() != 0) {
			B->SetNext(new TElem<T>(*(A->GetNext()))); 
			A = A->GetNext();
			B = B->GetNext();
		}
	}
}
//-----------------------------------------------------------
template <class T>
TList<T>::~TList() 
{
	while (begin != 0)          
	{
		TElement <T> *temporary = begin->GetNext();   
		delete begin;                
		begin = temporary;
	}
}
//-----------------------------------------------------------
template <class T>
void TList<T>::PutBegin(T A)
{
	if (begin == 0) {
		TElement <T>* temporary = new TElement <T>(A, 0);
		begin = temporary;
	}
	else 
	{
		TElement <T>* temporary = new TElement <T>(A, begin);
		begin = temporary;
	}
}
//-----------------------------------------------------------
template <class T>
void TList<T>::PutEnd(T A)
{
	if (begin != 0) {
		TElement <T> *B = begin;
		while (a->GetNext() != 0)
			B = B->GetNext();
		B->SetNext(new TElement <T>(A, 0));
	}
	else
		begin = new TElement <T>(A, 0);
}
//-----------------------------------------------------------
template <class T>
T TList<T>::GetBegin()
{
	if (IsEmpty())
		throw "List's empty";
	else 
	{
		TElement<T> *A = begin;
		T temporary = begin->TElement<T>::GetData();
		begin = begin->TElement<T>::GetNext();
		delete A;
		return temporary;
	}
}
//-----------------------------------------------------------
template <class T>
bool TList<T>::IsFull()
{
	try
	{
		TElement<T>* A = new TElement<T>();
		if (A == 0)
			return false;
		else {
			delete A;
			return true;
		}
	}
	catch (...)
	{
		return false;
	}
	//return true; 
 //do i really need this line? that's the question.-.
}
//-----------------------------------------------------------
template <class T>
bool TList<T>::IsEmpty()
{
	if (begin == 0)
		return true;
	else
		return false;
}
//-----------------------------------------------------------
