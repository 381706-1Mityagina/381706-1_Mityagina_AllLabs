#pragma once
#include <iostream>
#include "..//MonomialLib/Monomial.h"

using namespace std;

class TPolinomial
{
protected:
	TMonomial *begin;
  int sizee, n;
public:
  TPolinomial(int _N = 10);      // конструктор
  TPolinomial(TPolinomial &A);   // конструктор копирования

  // "геттеры"
	int GetSize()                 
	{
		return sizee;
	}

	int GetN()
	{
		return n;
	}

	TMonomial* GetBegin()
	{
		return begin ;
	}

	// перегрузки операторов
  TPolinomial operator + (TPolinomial &A);
  TPolinomial operator - (TPolinomial &A);
  TPolinomial operator * (TPolinomial &A);
  TPolinomial &operator = (TPolinomial &A);
  TPolinomial &operator += (TPolinomial &A);
	TPolinomial &operator += (TMonomial &M);
	TPolinomial &operator -= (TMonomial &M);

	bool operator==(TPolinomial &A);

	friend ostream& operator<<(ostream& out, TPolinomial& M)
	{
		TMonomial *temporary = M.begin ;
		if (temporary != 0)
		{
			out << *temporary;
			temporary = temporary->GetNext();
		}
		while (temporary != 0)
		{
			if (temporary->GetCoeff() != 0)
				out << " + " << *temporary;
			temporary = temporary-> GetNext();
		}
		return out;
	}
};
//----------------------------------------------------------------------
TPolinomial::TPolinomial(int _N)
{
  if (_N < 0)
    throw TException("Negative number of el");
  
    n = _N; 
		sizee = 0;
    begin = 0;
  
}
//----------------------------------------------------------------------
TPolinomial::TPolinomial(TPolinomial &A)
{
	n = A.n;
	sizee = A.sizee;
	if (A.begin == 0)
		begin = 0;
	else
	{
		begin = new TMonomial(*A.begin );
		TMonomial *a = A.begin , *b = begin ;

		while (a -> GetNext() != 0)
		{
			b -> SetNext(new TMonomial(*(a -> GetNext())));
			b = b -> GetNext();
			a = a -> GetNext();
		}
		b -> SetNext(NULL);
	}
}
//----------------------------------------------------------------------
bool TPolinomial::operator == (TPolinomial &A)
{
	if (A.n != this->n)
		throw TException("Different size");

	if (this->sizee != A.sizee)
		return false;

	TMonomial *a = begin , *b = A.begin ;
	while (a != 0)
	{
		if (!(*a == *b))
			return false;
		if (a -> GetCoeff() != b -> GetCoeff())
			return false;
		a = a -> GetNext();
		b = b -> GetNext();
	}
	return true;
}
//----------------------------------------------------------------------
TPolinomial &TPolinomial:: operator = (TPolinomial &A)
{
  if (*this == A)
    return *this;
  if (A.n != this -> n) 
		throw TException("Different size");

  else 
  {
		sizee = A.sizee;
    TMonomial *a = begin , *b = begin ;
    while (a != 0)
    {
      a = a -> GetNext();
      delete [] b;
      b = a;
    }
    a = A.begin ->GetNext(); b = new TMonomial(*A.begin );
    begin = b;

    while (a != 0)
    {
     b -> SetNext(new TMonomial(*a));
		 b = b -> GetNext();
     a = a -> GetNext();
    }
    return *this;
  }
}
//----------------------------------------------------------------------
TPolinomial TPolinomial:: operator + (TPolinomial &A)
{
  if (this -> n != A.n) 
		throw TException("Different size");

	TMonomial *a = begin , *b = A.begin ;
  TPolinomial Rez(n);
  TMonomial *i = Rez.begin ;

  while (a != 0 && b != 0)
  {
    TMonomial *tmp;
    if (*a == *b)
      {
			TMonomial g = (*a);
			g += (*b);
			tmp = new TMonomial(g);
			if (tmp->GetCoeff() == 0)
				continue;
			a = a->GetNext();
			b = b->GetNext();
      }
    if (*a > *b)
      {
			tmp = new TMonomial((*a));
			if (tmp->GetCoeff() == 0)
				continue;
			a = a->GetNext();
      }
    if (*a < *b)
      {
			tmp = new TMonomial(*b);
			if (tmp->GetCoeff() == 0)
				continue;
			b = b->GetNext();
      }
    if (i == 0)
    {
			i = tmp;
			Rez.begin = tmp;
			Rez.sizee++;
		}
		else
		{
			i->SetNext(tmp);
			Rez.sizee++;
			i = i->GetNext();
		}
  }
	if (a == 0)
		a = b;

	while (a != 0)
	{
		if (a->GetCoeff() == 0)
			continue;
		i->SetNext(new TMonomial(*a));
		a = a->GetNext();
		Rez.sizee++;
		i = i->GetNext();
	}

	return Rez;
}
//----------------------------------------------------------------------
TPolinomial TPolinomial:: operator - (TPolinomial &A)
{
  if (this -> n != A.n) 
		throw TException("Different size");
	
  TMonomial *a = begin , *b = A.begin ;
  TPolinomial Rez(n);
  TMonomial *i = Rez.begin;
  while (a != 0 && b != 0)
  {
    TMonomial *tmp;
    if (*a == *b)
      {
	TMonomial smth;
	smth = (*a);
	smth -= (*b);
        tmp = new TMonomial(smth);
        a = a -> GetNext();
        b = b -> GetNext();
      }
    if (*a > *b)
      {
        tmp = new TMonomial(*a);
				if (tmp->GetCoeff() == 0)
					continue;
        a = a -> GetNext();
      }
    if (*a < *b)
      {
        tmp = new TMonomial(*b);
				if (tmp->GetCoeff() == 0)
					continue;
				tmp->SetCoeff(tmp -> GetCoeff() * (-1));
        b = b -> GetNext();
      }
    if (i == 0)
    {
      i = tmp;
      Rez.begin = tmp;
			Rez.sizee++;
    }
		else
		{
			i -> SetNext(tmp);
			Rez.sizee++;
			i -> GetNext();
		}
  }
 
  while (a != 0)
  {
		if (a->GetCoeff() == 0)
			continue;
    i -> SetNext(new TMonomial(*a));
		a = a->GetNext();
    Rez.sizee++;
		i = i->GetNext();
  }

	while (b != 0)
	{
		if (b->GetCoeff() == 0)
			continue;
		TMonomial temp(*b);
		temp.SetCoeff(temp.GetCoeff()*(-1));
		b = b->GetNext();
		Rez.sizee++;
		i = i->GetNext();
	}

  return Rez;
}
//----------------------------------------------------------------------
TPolinomial TPolinomial:: operator * (TPolinomial &A)
{
 if (n != A.n)
	 throw TException("Different size");
   TMonomial* Sum;
   TPolinomial Rez(n);
   TMonomial *a = begin , *b = A.begin ;
   while (a != 0) 
   {
		 if (a -> GetCoeff() == 0)
			 continue;
     while (b != 0)
    {
		 TMonomial smth = (*a);
	     smth *= (*b)
     Sum = new TMonomial(smth);
		 Sum -> SetNext(NULL);
		 Rez += *Sum;
		 b = b -> GetNext();
    }
   a = a -> GetNext();
	 b = A.begin ;
   }

 return Rez;
}
//----------------------------------------------------------------------
TPolinomial &TPolinomial:: operator += (TPolinomial &A)
{
	if (this->n != A.n)
		throw TException("Different size");

	TMonomial *a = begin , *b = A.begin ;
	TMonomial *i = begin ;

	while (a != 0 && b != 0)
	{
		TMonomial *tmp;
		if (*a == *b)
		{
			TMonomial g = (*a);
			g += (*b);
			tmp = new TMonomial(g);
			if (tmp->GetCoeff() == 0)
				continue;
			a = a->GetNext();
			b = b->GetNext();
		}
		if (*a > *b)
		{
			tmp = new TMonomial((*a));
			if (tmp->GetCoeff() == 0)
				continue;
			a = a->GetNext();
		}
		if (*a < *b)
		{
			tmp = new TMonomial(*b);
			if (tmp->GetCoeff() == 0)
				continue;
			b = b->GetNext();
		}
		if (i == 0)
		{
			i = tmp;
			begin = tmp;
			sizee++;
		}
		else
		{
			i->SetNext(tmp);
			sizee++;
			i = i->GetNext();
		}
	}
	if (a == 0)
		a = b;

	while (a != 0)
	{
		if (a->GetCoeff() == 0)
			continue;
		i->SetNext(new TMonomial(*a));
		a = a->GetNext();
		sizee++;
		i = i->GetNext();
	}

	return *this;
}
//----------------------------------------------------------------------
TPolinomial &TPolinomial::operator += (TMonomial &M)
{
	if (this-> n != M.GetSize())
		throw TException("Different size");
	if (M.GetCoeff() == 0)
		return *this;
	if (begin == 0) 
		begin = new TMonomial(M);
	
	else
	{
		TMonomial *a = begin , *b = begin ->GetNext();
		
		if (*begin < M)
		{
			TMonomial* temporary = new TMonomial(M);
			temporary->SetNext(begin );
			begin = temporary;
		}
		else if (*begin == M)
		{
			*begin += M;
			if (begin ->GetCoeff() == 0)
			{
				TMonomial* tmp = begin ->GetNext();
				delete[] begin ;
				begin = tmp;
			}
		}
		else
		{
			while (b != 0)
			{
				if (*b == M)
				{
					*b += M;
					if (b->GetCoeff() == 0)
					{
						begin ->SetNext(b->GetNext());
						delete[] b;
					}
					return *this;
				}
				if (*b < M)
				{
					TMonomial* tmp = new TMonomial(M);
					a->SetNext(tmp);
					tmp->SetNext(b);
					sizee++;
					return *this;
				}
				a = b;
				b = b->GetNext();
			}
			a -> SetNext(new TMonomial(M));
		}
	}
	sizee++;
	return *this;
}
//----------------------------------------------------------------------
TPolinomial &TPolinomial::operator-=(TMonomial &M)
{
	if (this->n != M.GetSize())
		throw TException("Different size");

	M.SetCoeff(M.GetCoeff()*(-1));
	if (begin == 0)
		begin = new TMonomial(M);
	if (M.GetCoeff() == 0)
		return *this;

	else
	{
		TMonomial *a = begin , *b = begin ->GetNext();

		if (*begin < M)
		{
			TMonomial* temporary = new TMonomial(M);
			temporary->SetNext(begin );
			begin = temporary;
		}
		else if (*begin == M)
		{
			*begin -= M;
			if (begin ->GetCoeff() == 0)
			{
				TMonomial* tmp = begin->GetNext();
				delete[] begin ;
				begin = tmp;
			}
		}
		else
		{
			while (b != 0)
			{
				if (*b == M)
				{
					*b -= M;
					if (b->GetCoeff() == 0)
					{
						begin->SetNext(b->GetNext());
						delete[] b;
					}
					return *this;
				}
				if (*b < M)
				{
					TMonomial* tmp = new TMonomial(M);
					a->SetNext(tmp);
					tmp->SetNext(b);
					sizee++;
					return *this;
				}
				a = b;
				b = b->GetNext();
			}
			a->SetNext(new TMonomial(M));
		}
	}
	sizee++;
	return *this;
}
//----------------------------------------------------------------------
