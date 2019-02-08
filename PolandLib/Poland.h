#pragma once

#include <iostream>
#include <stdlib.h>
#include "..//Exception/Exception.h"
#include "..//QueueLib/Queue.h"

using namespace std;

class TString
{
protected:
	int size;
	char *mas;
public:
	TString();
	TString(TString &A);
	TString(char *str);
	~TString();

	TString operator + (TString &A);
	TString & operator = (TString &A);
	char & operator [] (int n);
	void Print();

	int GetSize();

	friend ostream & operator << (ostream &out, TString &A);
};
//-------------------------------------------------------------
TString::TString()
{
	mas = 0; size = 0;
}
//-------------------------------------------------------------
TString::TString(TString &A)
{
	size = A.size;
	if (size != 0)
	{
		mas = new char[size];
		for (int i = 0; i < size; i++)
			mas[i] = A.mas[i];
	}
	else mas = 0;
}
//-------------------------------------------------------------
TString::TString(char *str)
{
	if (str == 0)
		throw TException("String is empty.");
	if (str[0] == '\0')
		return;
	char smth = 1;
	int s = 0;

	while (smth != '\0')
	{
		s++; smth = str[s];
	}

	size = s + 1;
	mas = new char[size];
	for (int i = 0; i < size - 1; i++)
		mas[i] = str[i];
	mas[size - 1] = 0;
}
//-------------------------------------------------------------
TString::~TString()
{
	if (mas != 0)
		delete[]mas;
}
//-------------------------------------------------------------
int TString::GetSize()
{
	return size;
}
//-------------------------------------------------------------
TString &TString::operator = (TString &A)
{
	if (this != &A)
	{
		size = A.size;

		if (size != 0)
		{
			if (mas != 0)
				delete[]mas;
			mas = new char[A.size];
			for (int i = 0; i < A.size; i++)
				mas[i] = A.mas[i];
		}
		else
		{
			if (mas != 0)
				delete[]mas;
			size = 0;
		}
	}
	return *this;
}
//-------------------------------------------------------------
TString TString::operator + (TString &A)
{
	TString res;

	res.mas = new char[size + A.size - 1];

	for (int i = 0; i < size - 1; i++)
		res.mas[i] = mas[i];
	for (int i = size - 1; i < size + A.size - 1; i++)
		res.mas[i] = A.mas[i - (size - 1)];
	return res;
}
//-------------------------------------------------------------
char &TString::operator[](int n)
{
	if ((n < 0) && (n >= size))
		throw TException("Unacceptable index");
	return mas[n];
}
//-------------------------------------------------------------
ostream &operator << (ostream &out, TString &A)
{
	out << A.mas; 
	return out;
}
//-------------------------------------------------------------
void TString::Print()
{
	for (int i = 0; i < size; i++)
		cout << mas[i];
	cout << "\n";
}
//-----------------------------------------------------------//
//                                                           //
//                  other methods                            //
//                                                           //
//-----------------------------------------------------------//

int GetPriority(const char operation);
bool IsOperation(char symbol);
TQueue<char> ToPolish(TString str);
double GettingRez(TQueue<char> queue);

int GetPriority(const char operation)
{
	switch (operation)
	{
	case '(': return 1;
	case ')': return 1;
	case '+': return 2;
	case '-': return 2;
	case '*': return 3;
	case '/': return 3;
	default: return -1;
	}
}
//-------------------------------------------------------------
bool IsOperation(char symbol)
{
	return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '(' || symbol == ')');
}
//-------------------------------------------------------------
TQueue<char> ToPolish(TString str)
{
	int op_sk = 0, cl_sk = 0;
	TQueue<char> Qu(str.GetSize() * 3);
	TStack<char> St(str.GetSize() * 3);

	for (int i = 0; i < str.GetSize(); i++)
	{
		if (i == 0)
		{
			if (str[0] == '-')
			{
				Qu.Put('[');
				Qu.Put('0');
				Qu.Put(']');
			}
			else if (IsOperation(str[0]))
				if (GetPriority(str[0]) != 1)
					throw TException("Ruins logic of math. expr.");
		}
		else if (!IsOperation(str[i])) 
		{
			Qu.Put('[');
			while ((!IsOperation(str[i + 1])) && (i < str.GetSize()))
			{
				Qu.Put(str[i]);
				i++;
			}
			Qu.Put(str[i]);
			Qu.Put(']');
		}

		else if (St.IsEmpty())
		{
			if (IsOperation(str[i]))
			{
				St.Put(str[i]);
				if (str[i] == '(')
					op_sk++;
				if (str[i] == ')')
					throw TException("Shouldn't be here. Ruins logic of math. expr.");
			}
		}

		else if (IsOperation(str[i]))
		{
			if (str[i] == '(')
			{
				St.Put(str[i]);
				op_sk++;
			}
			else if (str[i] == ')')
			{
				cl_sk++;
				while (St.GetButDontDel() != '(')
					Qu.Put(St.Get());
				St.Get();
			}
			/*else if (St.IsEmpty())
				St.Put(str[i]);*/
			else
			{
				int pr = GetPriority(str[i]);
				if (pr <= GetPriority(St.GetButDontDel()))
				{
					while (pr <= GetPriority(St.GetButDontDel()) && !St.IsEmpty())
						Qu.Put(St.Get());
					St.Put(str[i]);
				}
				else if (pr > GetPriority(St.GetButDontDel()))
					St.Put(str[i]);
			}
		}
		else if (str[i] != '\0')
			throw TException("Ruins logic of math. expr  .-.");
	}
	while (!St.IsEmpty())
		Qu.Put(St.Get()); 
	if (op_sk != cl_sk)
		throw TException("Ruins logic of math. expr  .-.");

	return Qu;
	}
//-------------------------------------------------------------	
double GettingRez(TQueue<char> queue)
{
	double r;
	TStack <double> St(queue.GetSize());
	if (IsOperation(queue.GetButDontDelQ()))
		throw TException("Shouldnt be here. Queue is uncurr.");
	
	while (!queue.IsEmpty())
	{
		char A = queue.Get();
		if (A == '[')
		{
			A = queue.Get();
			double temporary = atof(&A);
			while (!queue.IsEmpty() && queue.GetButDontDelQ() != ']')
			{
				A = queue.Get();
				temporary = temporary * 10 + atof(&A);
			}
			queue.Get();
			St.Put(temporary);
		}
		else if (IsOperation(A))
		{
			double Fi = St.Get(), Sec = St.Get(), Th = 0;

			if (A == '+') Th = Sec + Fi;
			if (A == '-') Th = Sec - Fi;
			if (A == '*') Th = Sec * Fi;
			if (A == '/') Th = Sec / Fi;
			St.Put(Th);
		}
		else
			throw TException("Shouldnt be here .-.");

	}
	r = St.Get();
	if (!St.IsEmpty())
		throw TException("Shouldnt be here. Queue is uncurr.");
	return r;
}
//-------------------------------------------------------------
