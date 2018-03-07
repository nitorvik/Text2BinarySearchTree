// ProgAss2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <sstream>


std::ifstream myFile;

int linenum = 0;

tree mytree;

std::string removepunct(std::string str) {
	for (int i = 0; i < str.size(); i++) {
		if (ispunct(str[i])) {
			str.erase(i--, 1);
		}
	}
	return str;
}


int main()
{
	std::string mystring;

	tree::trnode* root = NULL;
	int x = 0;

	myFile.open("C:\\temp\\progass.txt");

	while (myFile) {
		std::getline(myFile,mystring);
		linenum++;
		if (mystring != "#") {
			mystring = removepunct(mystring);
			//std::cout << mystring << std::endl;
			std::istringstream iss(mystring);
			std::string word;
			while (iss >> word) {
				std::string first_ten = word.substr(0, 10);
				if (x < 1) {
					root = mytree.insert(root, first_ten, linenum);
					x++;
				}
				else mytree.insert(root, first_ten, linenum);
			}
			}
		}

	mytree.print(root);

}


