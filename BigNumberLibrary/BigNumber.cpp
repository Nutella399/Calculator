#include "stdafx.h"
#include "BigNumber.h"

BigNumber::BigNumber() {
}


BigNumber::~BigNumber() {

}

void BigNumber::operator +(BigNumber num) {
	int i = number.size() - 1;
	int j = num.size() - 1;
	while (i >= 0 && j >= 0) {
		number.at(i) += num.getAt(j);
		additionRedistrubute(i);
		i--;
		j--;
	}
	while (j >= 0) {
		number.insert(number.begin(), num.getAt(j));
		i++;
		j--;
		additionRedistrubute(i);
	}
}

void BigNumber::operator -(BigNumber num) {
	std::vector<short> num_vector = num.getNumber();
	int i = number.size() - 1;
	int j = num.size() - 1;
	int temp = 0;

	if (isSmaller(num)) {
		number.swap(num_vector);
		temp = i;
		i = j;
		j = temp;

	}

	while (i >= 0 && j >= 0) {
		number.at(i) -= num.getAt(j);
		if (number.at(i) < 0) {
			number.at(i) += 10;
			number.at(i - 1) -= 1;
		}
		i--;
		j--;
	}


}

void BigNumber::operator *(BigNumber num) {
	std::vector<short> temp;
	int temp_size = num.size() + number.size();
	temp.assign(temp_size, 0);
	int carry = 0;
	int counter = temp_size - 1;
	int offset = 1;
	for (int i = number.size() - 1; i >= 0; i--) {
		carry = 0;
		for (int j = num.size() - 1; j >= 0; j--) {
			temp.at(counter) += carry + (number.at(i) * num.getAt(j));
			carry = temp.at(counter) / 10;
			temp.at(counter) = temp.at(counter) % 10;
			counter--;

		}
		temp.at(counter) = carry;
		offset++;
		counter = temp_size - offset;

	}
	number.swap(temp);
}

void BigNumber::operator /(BigNumber num) {

}

void BigNumber::operator %(BigNumber a) {

}



std::vector<short> BigNumber::getNumber() {
	return number;
}

void BigNumber::setNumber(short num) {
	number.push_back(num);
}

void BigNumber::printNumber() {
	int length = number.size();
	for (int i = 0; i < length; i++) {
		std::cout << number.at(i) << " ";
	}

}

int BigNumber::size() {
	return number.size();
}

short BigNumber::getAt(int i) {
	return number.at(i);
}

void BigNumber::additionRedistrubute(int i) {
	while (number.at(i) > 9) {
		number.at(i) -= 10;
		if (i - 1 < 0) {
			number.insert(number.begin(), 1);
			i++;
		}
		else {
			number.at(i - 1) += 1;
		}
	}
}

bool BigNumber::isSmaller(BigNumber num) {
	int size_1 = number.size();
	int size_2 = num.size();
	std::cout << size_1 << " " << size_2 << " \n";

	if (size_1 < size_2) {
		return true;
	}
	else if (size_1 > size_2) {
		return false;
	}

	for (int i = 0; i < size_1; i++) {
		if (number.at(i) < num.getAt(i)) {
			return true;
		}
		else if (num.getAt(i) < number.at(i)) {
			return false;
		}
		return false; 
	}
}