#include "stdafx.h"
#include "Basic3.h"

Basic3::Basic3(double x, double y, int fflag):Basic2(x, y, fflag)
{
	var1 = x;
	var2 = y;
	flag = fflag;
}

Basic3::~Basic3() 
{
}