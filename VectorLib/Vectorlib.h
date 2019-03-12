#include <iostream>

using namespace std;
#include "../Exception/Exception.h"

template <class T>
class TVector
{
protected:
  int dlina; // размер вектора
  T *vector; // массив элементов вектора
public:
  TVector<T>(int n = 0); // конструктор инициализации
  TVector<T>(const TVector<T> &A); // конструктор копирования
  TVector(T* s, int _dlina); // конструктор инициализации
  virtual ~TVector<T>(); // диструктор

  int GetDlina() const;
  T& operator [](int i);
  bool operator ==(const TVector<T> &A) const;
  bool operator !=(const TVector &v) const;
  TVector& operator =(const TVector<T> &A);
// перегрузка теоретико-множественных операторов
  TVector operator ++();
  TVector operator ++(int);
  TVector operator --();
  TVector operator --(int);
  TVector operator +() const;
  TVector operator -() const;
  TVector operator +(const TVector<T> &A);
  TVector operator -(const TVector<T> &A);

  T operator *(const TVector<T> &A);
  TVector operator *(T A);

  template <class FriendT> friend TVector<FriendT> operator*(FriendT a, const TVector<FriendT> &A);
// операторы ввода-вывода
  template <class FriendT> friend istream& operator>>(istream &in, TVector<FriendT> &A);
  template <class FriendT> friend ostream& operator<<(ostream &out, const TVector<FriendT> &AV);
};
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T>::TVector(int n) 
{
  if (n < 0)
	throw TException("Negative size. Impossible.");
  else
	if (n == 0) 
	{
	  dlina = n;
	  vector = NULL;
	}
	else 
	{
	  dlina = n;
	  vector = new T[dlina];
	  for (int i = 0; i < dlina; i++)
		vector[i] = 0;
	}
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T>::TVector(const TVector<T> &A) 
{
  dlina = A.dlina;
  if (dlina == 0)
	vector = NULL;
  else 
	{
	vector = new T[dlina];
	for (int i = 0; i < dlina; i++)
	  vector[i] = A.vector[i];
  }
}
//-------------------------------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(T* s, int _dlina)
{
	dlina = _dlina;
	vector = new T[dlina];
	for (int i = 0; i < dlina; i++)
		vector[i] = s[i];
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T>::~TVector() 
{
  if (dlina > 0)
	{
	dlina = 0;
	delete[] vector;
	vector = NULL;
  }
}
//-------------------------------------------------------------------------------------------------
template<class T>
int TVector<T>::GetDlina() const
{
  return dlina;
}
//-------------------------------------------------------------------------------------------------
template <class T>
T& TVector<T>::operator[](int i)
{
  if (i < 0 || i >= dlina)
	
	   throw TException("Overflow.");
  else 
	  return vector[i];
  //throw 1;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T>& TVector<T>::operator=(const TVector<T> &A) 
{
  if (this == &A)
	return *this;
	
  delete[] vector;
  dlina = A.dlina;
  
	vector = new T[dlina];
	
  for (int i = 0; i < dlina; i++)
	(*this)[i] = A.vector[i];
  
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
	temporary[i] = -vector[i];
	
  return temporary;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator+(const TVector<T> &A) 
{
  if (dlina != A.dlina)
	throw TException("Different dimensions. Impossible to add.");
  TVector<T> temporary(dlina);
	
  for (int i = 0; i < dlina; i++)
	temporary[i] = (*this)[i] + A.vector[i];
	
  return temporary;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator-(const TVector<T> &A) 
{
  if (dlina != A.dlina)
	throw TException("Different dimensions. Impossible to subtract");
  TVector<T> temporary(dlina);
	
  for (int i = 0; i < dlina; i++)
	temporary[i] = (*this)[i] - A.vector[i];
	
  return temporary;
}
//-------------------------------------------------------------------------------------------------
template<class T>
T TVector<T>::operator*(const TVector <T> &A) 
{
  if (dlina != A.dlina)
	throw TException("Different dimensions. Impossible to multiplicate");
  T temporary = 0;
	
  for (int i = 0; i < dlina; i++)
	temporary += (*this)[i] * A.vector[i];
	
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
	temporary[i] = A.vector[i] * a;
  
	return temporary;
}
//-------------------------------------------------------------------------------------------------
template <class T>
bool TVector<T>::operator!=(const TVector<T> &A) const
{
	if (*this == A)
	{
		return false;
	}
	else
		return true;

}
//-------------------------------------------------------------------------------------------------
template <class T> 
bool TVector<T>::operator==(const TVector<T> &A) const
{
	if (this->dlina == A.dlina)
	{
		bool flag = true;

		for (int i = 0; i < dlina; i++)
		{
			if (this->vector[i] != A.vector[i])
			{
				flag = false;
				break;
			}
		}
		return flag;
	}
	else
		return false;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator++() 
{
  for (int i = 0; i < dlina; i++)
	vector[i] = vector[i] + 1;
	
  return *this;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator++(int) 
{
  TVector<T> temporary(*this);
	
  for (int i = 0; i < dlina; i++)
	vector[i] = vector[i] + 1;
  
	return temporary;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator--() 
{
  for (int i = 0; i < dlina; i++)
	vector[i] = vector[i] - 1;
  
	return *this;
}
//-------------------------------------------------------------------------------------------------
template<class T>
TVector<T> TVector<T>::operator--(int) 
{
  TVector<T> temporary(*this);
  
	for (int i = 0; i < dlina; i++)
	vector[i] = vector[i] - 1;
  
	return temporary;
}
//-------------------------------------------------------------------------------------------------
template<class FriendT>
istream& operator>>(istream &istr, TVector<FriendT> &A)
{
  cout << "\nEnter " << A.dlina << " coordinates: ";
  
	for (int i = 0; i < A.dlina; i++)
	istr >> A.vector[i];
  
	return istr;
}
//-------------------------------------------------------------------------------------------------
template<class FriendT>
ostream& operator<<(ostream &ostr, const TVector<FriendT> &A)
{
  for (int i = 0; i < A.dlina; i++)
	ostr << A.vector[i] << "\t";
  
	return ostr;
}
//-------------------------------------------------------------------------------------------------
