//============================================================================
// Name        : Hello_w.cpp
// Author      : Andrew
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include <stdlib.h>
#include "Letter.h"
#include <String.h>
#include <vector>  //for std::vector
#include <string>  //for std::string
using namespace std;

int IsInSymbols(vector<Letter>  sym, char l){
	for(unsigned int i=0; i<sym.size();i++){
		if(sym[i].getEletter() == l)
			return 1;
	}
	return 0;
}
int id_char(char a){
	if(int(a)< int('Z')){
		return int(a) - int('A');
	}
	return int(a) - int('a')+26;
}
char char_id(unsigned int n){
	if(n < 26){
		return char(int('A')+ n);
	}
	return char(int('a')+ n%26);
}
//{A B ... a b ...}
char shift(char a, unsigned int n){
	return char_id((id_char(a)+n)%52);
}

int main(void) {
	vector<Letter> symbols = vector<Letter>();
	vector<Letter> symbols_2 = vector<Letter>();

	string message = "SYNTPrfneVfPbbyOhgAbgFrpher"; 	//27 characters

	string message_decrypted = "Some martian message";	//20 characters

	for(unsigned int i=0; i<message.size();i++){		//organizes each encrypted character
			if(IsInSymbols(symbols, message[i])== 0){	//into a list of objects that saves
			Letter aux = Letter(message[i]);			//the character and its frequency
			aux.EstimateFrequency(message);
			symbols.push_back(aux);

		}
	}

	for(unsigned int i=0; i<message_decrypted.size();i++){		//organizes each encrypted character
				if(IsInSymbols(symbols_2, message_decrypted[i])== 0){	//into a list of objects that saves
				Letter aux = Letter(message_decrypted[i]);			//the character and its frequency
				aux.EstimateFrequency(message_decrypted);
				symbols_2.push_back(aux);

			}
		}
/*
	for(unsigned int i=0; i< symbols.size();i++){		//prints
		cout << symbols[i].getEletter() << " ";
		cout << symbols[i].getFreq()*100 << endl;
	}
*/
/*
	for(unsigned int i=0; i< symbols_2.size();i++){		//prints
		cout << symbols_2[i].getEletter() << " ";
		cout << symbols_2[i].getFreq()*100 << endl;
	}
*/
/*
	    int l = 0; // number of bytes
	    for(unsigned int i = 0; i < message.length(); i++){
	        unsigned char c = (int)message[i];
	        if (c <= 0x007f) l += 1;
	        else if (c <= 0x07ff) l += 2;
	        else if (c >= 0xd800 && c <= 0xdfff)  l += 2;  // surrogates
	        else l += 3;
	    }
	        cout << "Encrypted message size (bites): " << l << endl;

	        l = 0; // number of bytes
	        for(unsigned int i = 0; i < message_decrypted.length(); i++){
	        	 unsigned char c = (int)message_decrypted[i];
	        	 if (c <= 0x007f) l += 1;
	        	 else if (c <= 0x07ff) l += 2;
	             else if (c >= 0xd800 && c <= 0xdfff)  l += 2;  // surrogates
	        	 else l += 3;
	        }
	        cout << "Decrypted message size (bites): " << l << endl;

*/
	for(unsigned int j = 1; j <= 26; j++){
		for(unsigned int i = 0; i < message.length(); i++){
			cout << shift(message[i], j);
		}
		cout << endl;
	}
	return EXIT_SUCCESS;
}


