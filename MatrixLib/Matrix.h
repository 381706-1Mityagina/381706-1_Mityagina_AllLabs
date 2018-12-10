#pragma once
#include "..//VectorLib/Vectorlib.h"
#include <iostream>

#define MAX_SIZE 10000;

using namespace std;

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
  TMatrix(int n = 10); // конструктор инициализации
  TMatrix(const TMatrix &Matr);  // конструктор копирования, принимающий ссылку на объект класса TMatrix                  
  TMatrix(const TVector<TVector<T> > &Matr);  // конструктор копирования, принимающий ссылку на объект класса TVector<TVector<T>		
  bool operator ==(const TMatrix &Matr) const; // перегрузка оператора сравнения (на равенство)
  bool operator !=(const TMatrix &Matr) const; // перегрузка оператора сравнения (на неравенство)
  TMatrix& operator = (TVector<TVector<T> > &Matr); // перегрузка оператора =
  TMatrix  operator + (const TMatrix &Matr); // перегрузка оператора +
  TMatrix  operator - (const TMatrix &Matr); // перегрузка оператора -
  TMatrix operator*(TMatrix<T> &A); // перегрузка оператора *
	
// операторы ввода-вывода												
  template <class FriendT> friend istream& operator>>(istream &istr, TMatrix<FriendT> &Matr);
 
  template <class FriendT> friend ostream & operator<<(ostream &ostr, const TMatrix<FriendT> &Matr);
 
};
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(int n) : TVector<TVector<T> >(n)
{
  int a = MAX_SIZE;
  if (n < 0 || n > a)
	throw TException("Overflow");
  else
	for (int i = 0; i < n; i++)
	  this->Vector[i]= TVector <T>(n - i);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TMatrix<T> &Matr) :TVector<TVector<T> >(Matr) { }
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > &Matr) : TVector<TVector<T> >(Matr) { }
//-------------------------------------------------------------------------------------------------
template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &Matr) const
{
  return TVector<TVector<T> >::operator==(Matr);
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TMatrix<T>::operator!=(const TMatrix<T> &Matr) const
{
  return TVector<TVector<T> >::operator!=(Matr);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>& TMatrix<T>::operator=(TVector<TVector<T> > &Matr)
{
  TVector<TVector<T> >::operator=(Matr);
  return *this;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &Matr)
{
  if (this -> dlina != Matr.dlina)
	throw TException("Different dimensions.");
  else
	return TVector<TVector<T> > :: operator+(Matr);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &Matr)
{
  if (this->dlina != Matr.dlina)
	throw TException("Different dimensions.");
  else
	return TVector<TVector<T> > :: operator-(Matr);
}
//-------------------------------------------------------------------------------------------------
template <class FriendT>  istream& operator>>(istream &istr, TMatrix<FriendT> &Matr)
{
  for (int i = 0; i < Matr.dlina; i++)
	istr >> Matr.Vector[i];
  return istr;
}
//-------------------------------------------------------------------------------------------------
template <class FriendT>  ostream & operator<<(ostream &ostr, const TMatrix<FriendT> &Matr)
{
  for (int i = 0; i < Matr.dlina; i++)
	ostr << Matr.Vector[i] << endl;
  return ostr;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator*(TMatrix<T> &A)
{
	if (dlina != A.dlina)
		throw TException("Error! Differen dimentions.");
		//throw 0;

	TMatrix<T> Matr1 = *this, result(dlina);

	for (int row = 0; row  < dlina; ++row) // проходим по строкам
	{
		for (int col = 0; col  < dlina - i; ++col) // проходим по столбцам
		{
			int needed_sum = 0, temp = j;
			for (int inner = 0; inner <= j; inner++) // внутренние элементы
			{
				needed_sum = needed_sum + Matr1[i][m] * A[m][temp];
				temp--;
			}
			result[row][col] = needed_sum;
		}
	}
	return result;
}
//-------------------------------------------------------------------------------------------------
