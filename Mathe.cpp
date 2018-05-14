/*
 * Mathe.cpp
 *
 *  Created on: May 9, 2018
 *      Author: owner
 */
//#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>
#include <algorithm>

//
//struct Number {
////	num as string
//	std::string numData = "";
////	base to conv to
//	int base = 0;
//
////	calc power of num
//	int powerOf(int val, int power) {
//		if (power == 0) {
//			return 1;
//		}
//		int res = val;
//		for (int i = 1; i < power; i++) {
//			res *= val;
//		}
//		return res;
//	}
//
//
//
//public:
//	Number(std::string num, int baseOf) :
//			numData(num), base(baseOf) {
//	}
//
//
//
//
//
//
//	int getBase() const {
//		return base;
//	}
//
//	const std::string& getData() const {
//		return numData;
//	}
//
////	gets deimal val of interal num
//	int getDecVal() {
//		int decVal = 0;
//		for (int i = numData.size() - 1; i >= 0; i--) {
//			if (numData[i] >= 'A' && numData[i] <= 'Z') {
//				decVal += (numData[i] - 'A' + 10)
//						* powerOf(base, (numData.size() - 1 - i));
//			} else {
//				decVal += (numData[i]
//						- '0' * powerOf(base, (numData.size() - 1 - i)));
//			}
//		}
//		return decVal;
//	}
//
//	bool convertToBase(int nBase) {
//		if (nBase > 35) {
//			throw std::invalid_argument("Can't do more than 35 there bro.");
//		}
//
//		int decVal = getDecVal();
//		std::string newVal = "";
//		while (decVal > 0) {
//			int rem = decVal % nBase;
//			decVal /= nBase;
//			char nChar = '0' + rem;
//			if (nChar > '9') {
//				nChar = 'A' + (nChar - '9') - 1;
//			}
//			newVal += nChar;
//		}
//		std::reverse(newVal.begin(), newVal.end());
//		numData = newVal;
//		base = nBase;
//		return true;
//	}
//
//};
int val(char c) {
	if (c >= '0' && c <= '9') {
		return (int) c - '0';
	} else {
		return (int) c - 'A' + 10;
	}
}

int toDec(std::string numData, int base) {
	int len = numData.length();
	int power = 1;
	int num = 0;
	int i;

	for (i = len - 1; i >= 0; i--) {
		if (val(numData[i]) >= base) {
			std::cout << "Inbalid" << std::endl;
			return -1;
		}
		num += val(numData[i]) * power;
		power *= base;
	}
	return num;
}

char reVal(int num) {
	if (num >= 0 && num <= 9) {
		return (char) (num + '0');
	} else {
		return (char) (num - 10 + 'A');
	}
}

std::string fromDec(std::string res, int base, int inNum) {
	while (inNum > 0) {
		res += reVal(inNum % base);
		inNum /= base;
	}
	std::reverse(res.begin(), res.end());
	return res;
}

int main() {
	bool go = true;
	while (go) {
		std::string inp;
		int inNum;
		int convBase;
		std::cout << "Enter the value of the number: " << std::endl;
		std::cin >> inp;

		go = inp.empty();
		if (go) {
			std::transform(inp.begin(), inp.end(), inp.begin(), ::toupper);
			char way;
			std::cout << "To decimal (t) or from (f)" << std::endl;
			std::cin >> way;
			std::cout << "Enter the base in integer form: " << std::endl;
			std::cin >> inNum;

			if (way == 'f') {
				std::cout << fromDec("", inNum, int(inp)) << std::endl;
			}
			if (way == 't') {
			std::cout << std::to_string(toDec(inp, inNum)) << std::endl;
			}
		}
	}
	return 0;
}
