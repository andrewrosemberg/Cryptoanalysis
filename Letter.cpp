/*
 * Letter.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: andrew
 */

#include <iostream>
#include <iostream>
#include <stdlib.h>
#include "Letter.h"
#include <String.h>
#include <vector>  //for std::vector
#include <string>  //for std::string
using namespace std;

Letter::Letter(char a){
	// TODO Auto-generated constructor stub
	this->eletter = a;
	this->freq = 0;
}

double Letter::EstimateFrequency(string message){		//Frequency of letter in message
	int sum = 0;
	char l;
	for(unsigned int i=0; i<message.size();i++){
		l = message[i];
		if(l == this->eletter){
			sum++;
		}
	}
	this->freq =double(sum)/double(message.size());
	return this->freq;
}

Letter::~Letter() {
	// TODO Auto-generated destructor stub
}
