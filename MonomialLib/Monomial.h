#pragma once

template <class T>
class TMonomial
{
protected:
	int* power;      // массив степеней
	int size;        // кол-во пер-ых в каждом мономе
	double coeff;    // коэффициент
	TMonomial *next; // указатель на следующий моном полинома
public:
	TMonomial(int _Size, int *M, double _Coeff);  // конструктор
	TMonomial(TMonomial<T> &A);                   // конструктор копирования

	// "сеттеры"
	void SetPower(int *M);                        
	void SetSize(int _Size);                      
	void SetCoeff(double _Coeff);                 
	void SetNext(TMonomial* _Next);               

	// "геттеры"
	int *GetPower();                              
	int GetSize();                                
	double GetCoeff();                            
	TMonomial* GetNext();      

	// перегрузка арифметических операторов 
	TMonomial &operator = (TMonomial &A);         
	TMonomial operator + (TMonomial &A);          
	TMonomial operator += (TMonomial &A);         
	TMonomial operator - (TMonomial &A);          
	TMonomial operator -= (TMonomial &A);          
	TMonomial operator * (TMonomial &A);          
	TMonomial operator *= (TMonomial &A);         

	// операторы сравнения 
	bool operator == (TMonomial &A);              
	bool operator < (TMonomial &A);               
	bool operator > (TMonomial &A);              

	// операторы ввода-вывода
	friend istream& operator>>(istream &in, TMonomial &m)
	{
		in >> m.coeff >> m.power;
		return in;
	}
	friend ostream& operator<<(ostream &out, TMonomial &m)
	{
		out << m.GetCoeff() << ' ' << m.GetPower();
		return out;
	}
};

//------------------------------------------------------------------
template <class T>
TMonomial::TMonomial(int _size, int* _power, double _coeff)
{
	if (_size < 0)
		throw TException("Negative size.-. Sorry");
	else if (_size == 0)
	{
		power = NULL; next = NULL;
		coeff = _coeff; size = _size; 
	}
	else
	{
		size = _size; coeff = _coeff; next = NULL;
		power = new int[_size];
		for (int i = 0; i < _size; i++)
		{
			if (_power[i] >= 0)
				power[i] = _power[i];
			else
				throw TException("Negative power.-. Sorry");
		}
	}
}
//------------------------------------------------------------------
template <class T>
TMonomial<T>::TMonomial(TMonomial<T> &A)
{
	size = A.size;
	power = new int[size];
	for (int i = 0; i < size; i++)
		power[i] = A.power[i];
	coeff = A.coeff;
	next = A.next;
}
//------------------------------------------------------------------
template <class T>
void TMonomial<T>::SetPower(int *M)
{
	try
	{
		for (int i = 0; i < size; i++)
		{
			if (M[i] >= 0)
				power[i] = M[i];
			else
				throw - 1;
		}
	}
	catch (..)
	{
		throw - 2;
	}
}
//------------------------------------------------------------------
template <class T>
void TMonomial<T>::SetSize(int _Size)
{
	if (_Size <= 0)
		throw TException("Negative size.-. Sorry");
	else
	{
		size = _Size;
		TMonomial temp;
		if (_Size == size)
		{
			temp = *this;
		}
		else if (_Size < size)
		{
			temp.power = new int[_Size];
			for (int i = 0; i < _Size; i++)
				temp.power[i] = power[i];
			delete[]power;
			size = _Size;
			power = new int[size];
			for (int i = 0; i < size; i++)
				power[i] = temp.power[i];
		}
		else if (_Size > size)
		{
			temp.power = new int[size];
			for (int i = 0; i < size; i++)
				temp.power[i] = power[i];
			delete[]power;
			size = _Size;
			power = new int[size];
			for (int i = 0; i < size; i++)
				power[i] = temp.power[i];
		}
	}
}
//------------------------------------------------------------------
template <class T>
void TMonomial<T>::SetCoeff(double _Coeff)
{
	coeff = _Coeff;
}
//------------------------------------------------------------------
template <class T>
void TMonomial<T>::SetNext(TMonomial* _Next)
{
	next = _Next;
}
//------------------------------------------------------------------
template <class T>
int *TMonomial<T>::GetPower()
{
	return power;
}
//------------------------------------------------------------------
template <class T>
int TMonomial<T>::GetSize()
{
	return size;
}
//------------------------------------------------------------------
template <class T>
double TMonomial<T>::GetCoeff()
{
	return coeff;
}
//------------------------------------------------------------------
template <class T>
TMonomial* TMonomial<T>::GetNext()
{
	return next;
}
//------------------------------------------------------------------
template <class T>
TMonomial &TMonomial<T>::operator = (TMonomial &A)
{
	if (size != A.size)
		throw TException("Different size.-. Sorry");
	coeff = A.coeff;
	size = A.size;
	next = A.next;
	delete[] power;
	power = new int[size];
	for (int i = 0; i < size; i++)
		power[i] = A.power[i];
	return *this;
}
//------------------------------------------------------------------
template <class T>
TMonomial TMonomial<T>::operator + (TMonomial &A)
{
	TMonomial temporary(A);
	if (size != A.size)
		throw TException("Different size.-. Sorry");
	if (!(*this == A))
		throw TException("Different power.-. Sorry");
	temporary.coeff = coeff + A.coeff;
	return temporary;
}
//------------------------------------------------------------------
template <class T>
TMonomial TMonomial::operator+=(TMonomial & A)
{
	if (size != A.size)
		throw TException("Different size.-. Sorry");
	if (!(*this == A))
		throw TException("Different power.-. Sorry");
	coeff += A.coeff;
	return *this;
}
//------------------------------------------------------------------
template <class T>
TMonomial TMonomial<T>::operator - (TMonomial &A)
{
	TMonomial temporary(A);
	if (size != A.size)
		throw TException("Different size.-. Sorry");
	if (!(*this == A))
		throw TException("Different power.-. Sorry");
	temporary.coeff = coeff - A.coeff;
	return temporary;
}
//------------------------------------------------------------------
template <class T>
TMonomial TMonomial::operator-=(TMonomial & A)
{
	if (size != A.size)
		throw TException("Different size.-. Sorry");
	if (!(*this == A))
		throw TException("Different power.-. Sorry");
	coeff -= A.coeff;
	return *this;
}
//------------------------------------------------------------------
template <class T>
TMonomial TMonomial<T>::operator * (TMonomial &A)
{
	TMonomial temporary(A);
	if (size != A.size)
		throw TException("Different size.-. Sorry");
	else
	{
		temporary.coeff = coeff * A.coeff;
		for (int i = 0; i < size; i++)
			temporary.power[i] = power[i] + A.power[i];
		return temporary;
	}
}
//------------------------------------------------------------------
template <class T>
TMonomial TMonomial::operator *= (TMonomial & A)
{
	if (size != A.size)
		throw TException("Different size.-. Sorry");
	coeff = coeff * A.coeff;
	for (int i = 0; i < size; i++)
		power[i] += A.power[i];
	return *this;
}
//------------------------------------------------------------------
template <class T>
bool TMonomial<T>::operator == (TMonomial &A)
{
	if (size == A.size)
	{
		for (int i = 0; i < size; i++)
			if (power[i] != A.power[i])
				return false;
		return true;
	}
	else
		return false;
}
//------------------------------------------------------------------
template <class T>
bool TMonomial::operator > (TMonomial& A)
{
	if (*this == A)
		throw TException("Monomials are equal.-. Sorry");
	if (size != A.size)
		throw TException("Different size.-. Sorry");
	for (int i = 0; i < size; i++)
	{
		if (power[i] == A.power[i])
			continue;
		else if (power[i] > A.power[i])
			return true;
		else
			return false;
	}
	return true;
	// smth is not right, is it?
}
//------------------------------------------------------------------
template <class T>
bool TMonomial::operator < (TMonomial& A)
{
	if (*this == A)
		throw TException("Monomials are equal.-. Sorry");
	if (size != A.size)
		throw TException("Different size.-. Sorry");
	for (int i = 0; i < size; i++)
	{
		if (power[i] == A.power[i])
			continue;
		else if (power[i] < A.power[i])
			return true;
		else
			return false;
	}
	if (coeff > A.coeff)
		return false;
	return true;
}
//------------------------------------------------------------------
