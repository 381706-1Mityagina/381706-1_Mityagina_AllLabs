#pragma once

#include <iostream>
#include <stdlib.h>
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
	friend istream& operator >> (istream &in, TString &A);
};
//-----------------------------------------------------------//
//                                                           //
//                  other methods                            //
//                                                           //
//-----------------------------------------------------------//

int GetPriority(const char operation);
bool IsOperation(char symbol);
TQueue<char> ToPolish(TString str);
double GettingRez(TQueue<char> queue);
