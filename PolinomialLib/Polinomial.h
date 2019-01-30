#pragma once
#include <iostream>
#include "..//MonomialLib/Monomial.h"

using namespace std;

class TPolinomial
{
protected:
	TMonomial *mass;
  int sizee, n;
public:
  TPolinomial(int _N = 10);
  TPolinomial(TPolinomial &A);

	int GetSize()
	{
		return sizee;
	}

	TMonomial* GetMass()
	{
		return mass;
	}

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
		TMonomial *temporary = M.mass;
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
  else
  {
    n = _N; 
		sizee = 0;
    mass = 0;
  }
}
//----------------------------------------------------------------------
TPolinomial::TPolinomial(TPolinomial &A)
{
	n = A.n;
	sizee = A.sizee;
	if (A.mass == 0)
		mass = 0;
	else
	{
		mass = new TMonomial(*A.mass);
		TMonomial *a = A.mass, *b = mass;

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

	TMonomial *a = mass, *b = A.mass;
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
    TMonomial *a = mass, *b = mass;
    while (a != 0)
    {
      a = a -> GetNext();
      delete [] b;
      b = a;
    }
    a = A.mass ->GetNext(); b = new TMonomial(*A.mass);
    mass = b;

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

	TMonomial *a = mass, *b = A.mass;
  TPolinomial Rez(n);
  TMonomial *i = Rez.mass;
  while (a != 0 && b != 0)
  {
    TMonomial *tmp = NULL;
    if (*a == *b)
      {
        tmp = new TMonomial(*a + *b);
        a = a -> GetNext();
        b = b -> GetNext();
      }
    if (*a > *b)
      {
        tmp = new TMonomial(*a);
        a = a -> GetNext();
      }
    if (*a < *b)
      {
        tmp = new TMonomial(*b);
        a = b -> GetNext();
      }
    if (i == 0)
    {
      i = tmp;
      Rez.mass = i;
    }
    else 
      i -> SetNext(tmp);
    Rez.sizee++;
  }
  if (a == 0)
    a = b;
  while (a != 0)
  {
    i -> SetNext(new TMonomial(*a));
    Rez.sizee++;
  }
  a = a -> GetNext();
  return Rez;
}
//----------------------------------------------------------------------
TPolinomial TPolinomial:: operator - (TPolinomial &A)
{
  if (this -> n != A.n) 
		throw TException("Different size");
	
	TMonomial *a = mass, *b = A.mass;
  TPolinomial Rez(n);
  TMonomial *i = Rez.mass;
  while (a != 0 && b != 0)
  {
    TMonomial *tmp = NULL;
    if (*a == *b)
      {
        tmp = new TMonomial(*a - *b);
        a = a -> GetNext();
        b = b -> GetNext();
      }
    if (*a > *b)
      {
        tmp = new TMonomial(*a);
        a = a -> GetNext();
      }
    if (*a < *b)
      {
        tmp = new TMonomial(*b);
        b = b -> GetNext();
      }
    if (i == 0)
    {
      i = tmp;
      Rez.mass = i;
    }
    else 
      i -> SetNext(tmp);
    Rez.sizee++;
  }
  if (a == 0)
    a = b;
  while (a != 0)
  {
    i -> SetNext(new TMonomial(*a));
    Rez.sizee++;
  }
  a = a -> GetNext();
  return Rez;
}
//----------------------------------------------------------------------
TPolinomial TPolinomial:: operator * (TPolinomial &A)
{
 if (n != A.n)
	 throw TException("Different size");
 else
 {
   TMonomial* Sum;
   TPolinomial Rez(n);
   TMonomial *a = mass, *b = A.mass;
   while (a != 0) 
   {
		 if (a -> GetCoeff() == 0)
			 continue;
     while (b != 0)
    {
		 TMonomial s = (*a)*(*b);
     Sum = new TMonomial(s);
		 Sum -> SetNext(NULL);
		 Rez += *Sum;
		 b = b -> GetNext();
    }
   a = a -> GetNext();
	 b = A.mass;
   }
 return Rez;
 } 
}
//----------------------------------------------------------------------
TPolinomial &TPolinomial:: operator += (TPolinomial &A)
{
	if (this->n != A.n)
		throw TException("Different size");

	TMonomial *a = mass, *b = A.mass;
	//TPolinomial Rez(n);
	TMonomial *i = mass;
	while (a != 0 && b != 0)
	{
		TMonomial *tmp = NULL;
		if (*a == *b)
		{
			tmp = new TMonomial(*a + *b);
			a = a -> GetNext();
			b = b -> GetNext();
		}
		if (*a > *b)
		{
			tmp = new TMonomial(*a);
			a = a -> GetNext();
		}
		if (*a < *b)
		{
			tmp = new TMonomial(*b);
			a = b -> GetNext();
		}
		if (i == 0)
		{
			i = tmp;
			this -> mass = i;
		}
		else
			i->SetNext(tmp);
		this -> sizee++;
	}
	if (a == 0)
		a = b;
	while (a != 0)
	{
		i -> SetNext(new TMonomial(*a));
		this -> sizee++;
	}
	a = a -> GetNext();
	return *this;
}
//----------------------------------------------------------------------
TPolinomial &TPolinomial::operator+=(TMonomial &M)
{
	if (this-> n != M.GetSize())
		throw TException("Different size");

	if (mass == 0) 
		mass = new TMonomial(M);
	if (M.GetCoeff() == 0)
		return *this;
	
	else
	{
		TMonomial *a = mass, *b = mass->GetNext();
		
		if (*mass < M)
		{
			TMonomial* temporary = new TMonomial(M);
			temporary->SetNext(mass);
			mass = temporary;
		}
		else if (*mass == M)
		{
			*mass += M;
			if (mass->GetCoeff() == 0)
			{
				TMonomial* tmp = mass->GetNext();
				delete[] mass;
				mass = tmp;
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
						mass->SetNext(b->GetNext());
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

	if (mass == 0)
		mass = new TMonomial(M);
	if (M.GetCoeff() == 0)
		return *this;

	else
	{
		TMonomial *a = mass, *b = mass->GetNext();

		if (*mass < M)
		{
			TMonomial* temporary = new TMonomial(M);
			temporary->SetNext(mass);
			mass = temporary;
		}
		else if (*mass == M)
		{
			*mass -= M;
			if (mass->GetCoeff() == 0)
			{
				TMonomial* tmp = mass->GetNext();
				delete[] mass;
				mass = tmp;
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
						mass->SetNext(b->GetNext());
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
