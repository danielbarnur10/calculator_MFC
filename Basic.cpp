#include "stdafx.h"
#include "Basic.h"

Basic::Basic(double x, double y, int fflag)
{
	var1 = x;
	var2 = y;
	flag = fflag;
}

Basic::~Basic()
{
}

 double Basic::getresult() const
{
	 if (flag == 1)
		 return (var1 + var2);
	 else if (flag == 2)
		 return (var1 - var2);
}