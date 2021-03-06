// ProgAss2.cpp : Project 2 for CSCI 362 - Text File Cross-reference index

#include "Header.h"
#include <fstream>
#include <sstream>


std::ifstream myFile;

int linenum = 0;

tree mytree;

std::string removepunct(std::string str) { //remove punctuation from a line of text
	for (int i = 0; i < str.size(); i++) { //iterate through the letters
		if (ispunct(str[i])) {  //if it is punctuation, erase it
			str.erase(i--, 1);
		}
	}
	return str; //return cleaned string
}


int main(int argc, char** argv)
{
	std::string mystring;

	tree::trnode* root = NULL;
	int x = 0;

	myFile.open(argv[1]); //grab command line argument

	while (myFile) { //while a file is successfully opened
		std::getline(myFile,mystring); //grab a line of text
		linenum++; //increment line to keep track for adding to the linked list in a node
		if (mystring != "#") { //check for the terminating character
			mystring = removepunct(mystring); //remove punctuation
			std::istringstream iss(mystring); //grab the line and start looking at individual words
			std::string word; //grab the next word in the stream
			while (iss >> word) { //while there are words available
				if (isalpha(word[0])) { //check that the first character in a potential word is not numeric (see requirements)
					std::string first_ten = word.substr(0, 10); //create a substring that only stores the first 10 letters of a word (see requirements)
					if (x < 1) {
						root = mytree.insert(root, first_ten, linenum); //insert root node
						x++;
					}
					else mytree.insert(root, first_ten, linenum); //insert nodes
				}
			}
			}
		}

	mytree.print(root,0); //print the tree

}


