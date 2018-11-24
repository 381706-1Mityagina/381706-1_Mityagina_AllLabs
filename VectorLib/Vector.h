#pragma once
#include <iostream>

using namespace std;

template <class T>
class TVector
{
protected:
  int dlina;
  T *Vector;
public:
  TVector<T>(int n = 0);
  TVector<T>(const TVector<T> &A);
  virtual ~TVector<T>();

  int getDlina() const;
  T& operator[](int i);
  bool operator==(const TVector<T> &A);
  TVector& operator=(const TVector<T> &A);

  TVector operator++();
  TVector operator++(int);
  TVector operator--();
  TVector operator--(int);
  TVector operator+() const;
  TVector operator-() const;
  TVector operator+(const TVector<T> &A);
  TVector operator-(const TVector<T> &A);

  T operator*(const TVector<T> &A);
  TVector operator*(T A);
  template <class FriendT> friend TVector<FriendT> operator*(FriendT a, const TVector<FriendT> &A);

  template <class FriendT> friend istream& operator>>(istream &in, TVector<FriendT> &A);
  template <class FriendT> friend ostream& operator<<(ostream &out, const TVector<FriendT> &AV);
};
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T>::TVector(int n) 
{
  if (n < 0)
	throw "Impossible";
  else
	if (n == 0) 
	{
	  dlina = n;
	  Vector = NULL;
	}
	else 
	{
	  dlina = n;
	  Vector = new T[dlina];
	  for (int i = 0; i < dlina; i++)
		Vector[i] = 0;
	}
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T>::TVector(const TVector<T> &A) 
{
  dlina = A.dlina;
  if (dlina == 0)
	Vector = NULL;
  else {
	Vector = new T[dlina];
	for (int i = 0; i < dlina; i++)
	  Vector[i] = A.Vector[i];
  }
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T>::~TVector() 
{
  if (dlina > 0) {
	dlina = 0;
	delete[] Vector;
	Vector = NULL;
  }
}
//-------------------------------------------------------------------------------------------------
template<class T>
int TVector<T>::getDlina() const
{
  return dlina;
}
//-------------------------------------------------------------------------------------------------
template <class T>
T& TVector<T>::operator[](int i)
{
  if (i >= 0 && i <= dlina)
	return Vector[i];
  //throw 1;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T>& TVector<T>::operator=(const TVector<T> &A) 
{
  if (this == &A)
	return *this;
  delete[] Vector;
  dlina = A.dlina;
  Vector = new T[dlina];
  for (int i = 0; i < dlina; i++)
	(*this)[i] = A.Vector[i];
  return *this;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator+() const 
{
  TVector<T> temporary(*this);
  return temporary;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator-() const 
{
  TVector<T> temporary(dlina);
  for (int i = 0; i < dlina; i++) 
	temporary[i] = -Vector[i];
  return temporary;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator+(const TVector<T> &A) 
{
  if (dlina != A.dlina)
	throw "different dimensions. Impossible to add.";
  TVector<T> temporary(dlina);
  for (int i = 0; i < dlina; i++)
	temporary[i] = (*this)[i] + A.Vector[i];
  return temporary;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator-(const TVector<T> &A) 
{
  if (dlina != A.dlina)
	throw "different dimensions. Impossible to subtract";
  TVector<T> temporary(dlina);
  for (int i = 0; i < dlina; i++)
	temporary[i] = (*this)[i] - A.Vector[i];
  return temporary;
}
//-------------------------------------------------------------------------------------------------
template<class T>
T TVector<T>::operator*(const TVector <T> &A) 
{
  if (dlina != A.dlina)
	throw "different dimensions. Impossible to multiplicate";
  T temporary = 0;
  for (int i = 0; i < dlina; i++)
	temporary += (*this)[i] * A.Vector[i];
  return temporary;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator*(T A) 
{
  TVector<T> temporary(dlina);
  for (int i = 0; i < dlina; i++)
	temporary[i] = (*this)[i] * A;
  return temporary;
}
//-------------------------------------------------------------------------------------------------
template<class FriendT>
TVector<FriendT> operator*(FriendT a, const TVector<FriendT> &A)
{
  TVector<FriendT> temporary(A.dlina);
  for (int i = 0; i < A.dlina; i++)
	temporary[i] = A.Vector[i] * a;
  return temporary;
}
//-------------------------------------------------------------------------------------------------
template<class T>
bool TVector<T>::operator==(const TVector<T> &A) 
{
  if (dlina != A.dlina) 
	return false;
  else 
  {
	T diff = 0.0001;
	for (int i = 0; i < dlina; i++)
		if (Vector[i]-A.Vector[i] > diff)
		return false;
  }
  return true;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator++() 
{
  for (int i = 0; i < dlina; i++)
	Vector[i] = Vector[i] + 1;
  return *this;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator++(int) 
{
  TVector<T> temporary(*this);
  for (int i = 0; i < dlina; i++)
	Vector[i] = Vector[i] + 1;
  return temporary;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator--() 
{
  for (int i = 0; i < dlina; i++)
	Vector[i] = Vector[i] - 1;
  return *this;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator--(int) 
{
  TVector<T> temporary(*this);
  for (int i = 0; i < dlina; i++)
	Vector[i] = Vector[i] - 1;
  return temporary;
}
//-------------------------------------------------------------------------------------------------
template<class FriendT>
istream& operator>>(istream &istr, TVector<FriendT> &A)
{
  cout << "\nEnter the " << A.dlina << " coordinates: ";
  for (int i = 0; i < A.dlina; i++)
	istr >> A.Vector[i];
  return istr;
}
//-------------------------------------------------------------------------------------------------
template<class FriendT>
ostream& operator<<(ostream &ostr, const TVector<FriendT> &A)
{
  for (int i = 0; i < A.dlina; i++)
	ostr << A.Vector[i] << "\t";
  return ostr;
}
//-------------------------------------------------------------------------------------------------
