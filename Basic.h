#pragma once

class Basic
{
private:
	int flag;
	double var1;
	double var2;
public:
	Basic(double var1 = 0, double var2 = 0, int flag = 0);
	~Basic();
	virtual double getresult()const;
};