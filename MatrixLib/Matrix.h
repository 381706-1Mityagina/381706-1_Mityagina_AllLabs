#pragma once
#include "..//VectorLib/Vectorlib.h"
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
  bool operator ==(const TMatrix &Matr) const;
  bool operator !=(const TMatrix &Matr) const;
  TMatrix& operator = (TVector<TVector<T> > &Matr);
  TMatrix  operator + (const TMatrix &Matr);
  TMatrix  operator - (const TMatrix &Matr);
												
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
/* template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& Matr)
{
Matrix<T> TmpMatr(Matr.Size);
for (int i=0;i<Matr.Size;i++)
for (int j=0;j<(i+1);j++)
for (int k=j;k<(i+1);k++)
	
TmpMatr[j][i]+=M[j][k]*Matr[k][i];

return TmpMatr;
}
//-------------------------------------------------------------------------------------------------
template <class T>
TMatrix<T>& TMatrix<T>::operator*=(const TMatrix<T>& Matr)
{
TMatrix<T> TmpMatr(TMatr.Size);
for (int i=0;i<Size;i++)
for (int j=0;j<Size;j++)
for (int k=0;k<Size;k++)

TmpMatr[i][j]+=M[i][k]*Matr[k][j];

for (int i=0;i<Size;i++)
for (int j=0;j<Size;j++)
M[i][j]=TmpMatr[i][j];

return *(this);
}
//-------------------------------------------------------------------------------------------------  */
