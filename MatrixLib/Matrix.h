#pragma once
#include "..//VectorLib/Vector.h"
#include <iostream>

#define MAX_SIZE 10000;

using namespace std;

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
  TMatrix(int n = 10);
  TMatrix(const TMatrix &Matr);                    
  TMatrix(const TVector<TVector<T> > &Matr);			
  bool operator==(const TMatrix &Matr);
  bool operator!=(const TMatrix &Matr) const;
  //TMatrix& operator= (TMatrix &MT); 
  TMatrix& operator= (TVector<TVector<T> > &Matr);
  TMatrix  operator+ (const TMatrix &Matr);
  TMatrix  operator- (const TMatrix &Matr);
  //TMatrix operator* (const TMatrix &Matr);
												
  template <class FriendT> friend istream& operator>>(istream &istr, TMatrix<FriendT> &Matr);
 
  template <class FriendT> friend ostream & operator<<(ostream &ostr, const TMatrix<FriendT> &Matr);
 
};
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(int n) : TVector<TVector<T> >(n)
{
  int a = MAX_SIZE;
  if (n < 0 || n > a)
	throw 1;
  else
	for (int i = 0; i < n; i++)
	  this->Vector[i]= TVector <T>(n - i);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TMatrix<T> &Matr) : TVector<TVector<T> >(Matr) {}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T> > &Matr) : TVector<TVector<T> >(Matr) {}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TMatrix<T>::operator==(const TMatrix<T> &Matr) 
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
	throw 1;
  else
	return TVector<TVector<T> > :: operator+(Matr);
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &Matr)
{
  if (this->dlina != Matr.dlina)
	throw 1;
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
//template <class T>
//TMatrix<T> TMatrix<T>::operator*(const TMatrix<T> &Matr)
//{
//	if (this->dlina != Matr.dlina) 
//	{
//	  throw "Matrix of different size";
//	}
//	int dlina = this->dlina;
//	TVector<TVector<T>> matr = Matr, a = *this;
//	TVector<TVector<T>> res(dlina);
//	for (int i = 0; i < dlina; i++)
//	  for (int j = i; j < dlina; j++)
//		for (int k = 0; k <= j; k++)
//		  res[i][j] = res[i][j] + (a[i][k])*(matr[k][j]);
//	TMatrix<T> result = res;
//	return result;
//  }
//-------------------------------------------------------------------------------------------------