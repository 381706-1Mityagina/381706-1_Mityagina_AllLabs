#pragma once
#include "ViewTableElem.h"
#include "..//Exception/Exception.h"
template <class T>
class TViewTable
{
protected:
	TViewTableElem<T>* mas;
	unsigned size;
	unsigned count;
public:
	TViewTableElem<T> not_found;
	TViewTableElem<T>& Search(TString k);
	TViewTable(int n = 0);
	TViewTable(TViewTable<T>& A);
	T& operator[](TString k);
	~TViewTable();

	void Put(TString k, T d);
	void Del(TString k);
	int GetCount() { return count; }

	template <class T1>
	friend ostream& operator<<(ostream& ostr, const TViewTable<T1> &A);
};
//------------------------------------------------------------------------------------
template <class T>
TViewTable<T>::TViewTable(int n)
{
	if (n <= 0)
		throw TException("negative size");
	mas = new TViewTableElem<T>[n];
	size = n;
	count = 0;
	TString notfound("not_found");
	not_found.SetKey(notfound);
}
//------------------------------------------------------------------------------------
template <class T>
TViewTable<T>::TViewTable(TViewTable<T>& A)
{
	size = A.size;
	count = A.count;
	mas = new TViewTableElem<T>[size];
	for (int i = 0; i < size; i++)
		mas[i] = A.mas[i];
	TString notfound("not_found");
	not_found.SetKey(notfound);
}
//------------------------------------------------------------------------------------
template <class T>
void TViewTable<T>::Put(TString k, T d)
{
	if (size == count)
		throw TException("Table is full");
	if (!(Search(k) == not_found))
		throw TException("Element exist already");
	mas[count].SetKey(k);
	mas[count].SetData(d);
	count++;
}
//------------------------------------------------------------------------------------
template <class T>
void TViewTable<T>::Del(TString k)
{
	int tmp = -1;
	if (count == 0)
		throw TException("Table is empty");
	for (int i = 0; i < count; i++)
		if (mas[i].GetKey() == k)
		{
			tmp = i;
			break;
		}
	if (tmp == -1)
		throw TException("Element doesn't exist");
	mas[tmp] = mas[count - 1];
	mas[count - 1].SetData((T)0);
	TString no("no");
	mas[count - 1].SetKey(no);
	count--;
}
//------------------------------------------------------------------------------------
template <class T>
TViewTableElem<T>& TViewTable<T>::Search(TString k)
{
	for (int i = 0; i < count; i++)
		if (mas[i].GetKey() == k)
			return mas[i];
	return not_found;
}
//------------------------------------------------------------------------------------
template <class T>
T& TViewTable<T>::operator[](TString k)
{
	TViewTableElem<T>& tmp = Search(k);
	if (tmp == not_found)
	{
		Put(k, (T)0);
		return mas[count - 1]();
	}
	return tmp();
}
//------------------------------------------------------------------------------------
template <class T>
TViewTable<T>::~TViewTable()
{
	if (size != 0)
	{
		delete[] mas;
		count = 0;
		size = 0;
	}
}
//------------------------------------------------------------------------------------
template <class T1>
ostream& operator<<(ostream& ostr, const TViewTable<T1> &A)
{
	ostr << "key\t\tdata" << endl;
	for (int i = 0; i < A.count; i++)
		ostr << "| " << A.mas[i] << "\t |" << endl;
	return ostr;
}
//------------------------------------------------------------------------------------
