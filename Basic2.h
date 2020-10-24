#pragma once
#include "Basic.h"

class Basic2 :
	public Basic
{
private:
	double var1;
	double var2;
	int flag;
public:
	Basic2(double var1 = 0, double var2 = 0, int flag = 0);
	~Basic2();
	double getresult() const
	{
		if (flag == 3)
			return (var1 * var2);
		else if (flag == 4)
			return (var1 / var2);
	}
};