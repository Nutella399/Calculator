#pragma once
#include <iostream>
#include <vector>


class BigNumber {

private:
	std::vector<short> number;

public:
	BigNumber();
	~BigNumber();

	void operator +(BigNumber num);
	void operator -(BigNumber num);
	void operator *(BigNumber num);
	void operator /(BigNumber num);
	void operator %(BigNumber num);

	std::vector<short> getNumber();
	void setNumber(short num);
	void printNumber();
	void additionRedistrubute(int i);
	int size();
	short getAt(int i);
	bool isSmaller(BigNumber num);
};

