#pragma once
 
template <class T>
class TElement 
{
public:
	T data; 
	TElement <T>* next;
	
	TElement(T _data = 0, TElement <T>* _next = 0);
	TElement(TElement<T> &Elem);
	virtual ~TElement();

	TElement* GetNext();
	T GetData();
	void Set(T Elem);
	void SetNext(TElement <T>* n);
};

//------------------------------------------------------------
template <class T>
TElement<T>::TElement(T _data, TElement<T>* _next)
{
	data = _data;
	next = _next;
}
//------------------------------------------------------------
template <class T>
TElement<T>::TElement(TElement<T> &Elem)
{
	data = Elem.data;
	next = Elem.next;
}
//------------------------------------------------------------
template <class T>
TElement<T>::~TElement() {}
//------------------------------------------------------------
template <class T>
T TElement<T>::GetData()
{
	return data;
}
//------------------------------------------------------------
template <class T>
TElement<T>* TElement<T>::GetNext()
{
	return next;
}
//------------------------------------------------------------
template <class T>
void TElement<T>::Set(T Elem)
{
	data = Elem;
}
//------------------------------------------------------------
template <class T>
void TElement<T>::SetNext(TElement<T>* _n)
{
	next = _n;
}
//------------------------------------------------------------
