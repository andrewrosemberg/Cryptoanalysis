/*
 * Letter.h
 *
 *  Created on: Nov 27, 2016
 *      Author: andrew
 */

#ifndef LETTER_H_
#define LETTER_H_

#include <iostream>
#include <iostream>
#include <stdlib.h>
#include "Letter.h"
#include <String.h>
#include <vector>  //for std::vector
#include <string>  //for std::string

using namespace std;

class Letter {
private:
	char eletter;
	double freq;

public:
	Letter(char);
	virtual ~Letter();
	double EstimateFrequency(string);

	char getEletter() const {
		return eletter;
}

	void setEletter(char eletter) {
		this->eletter = eletter;
	}

	double getFreq() const {
		return freq;
	}

	void setFreq(double freq) {
		this->freq = freq;
	}
};

#endif /* LETTER_H_ */
