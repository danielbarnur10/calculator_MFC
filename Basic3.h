#pragma once
#include "Basic2.h"

class Basic3 :
	public Basic2
{
private:
	int flag;
	double var1;
	double var2;
public:
	Basic3(double var1 = 0, double var2 = 0, int flag = 0);
	~Basic3();
	double getresult() const
	{
		return pow(var1, var2);
	}
};