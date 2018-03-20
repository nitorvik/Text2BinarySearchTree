README

Programming Assignment #2 - Cross Reference Index for Text File
CSCI 362

************************************
Description
************************************
This program creates a cross-reference index output for a given text file input.  To do this, the program 
reads the given text file, collects each word, and stores the numbers of the lines in which each word 
occurred.  After the program runs and the scan is terminated, the output window displays a table showing 
all collected words in alphabetical order with each entry followed by a list of line numbers where they 
occurred in the input text.  Each word utilizes only one row in the output table.  To complete this, the 
text is loaded into a binary search tree.  A binary search tree used in this way is called a lexicographic
tree. While containing a key and pointers to left and right child nodes, each node also contains a head 
pointing to a list of line numbers. 

************************************
Included Files:
************************************
Header.h
ProgAss2.cpp
progass.txt

************************************
Operation
************************************
TO RUN: g++ ProgAss2.cpp -o prog  
	./prog progass.txt

i. Program Initiation
	The program must be initialized using a command line argument to tell the program which text file to 
	use. In this case, the text file included with the project (progass.txt) needs to be used. Without 
	the command line argument, the program will not run. Once initiated, the program will take the text 
	file specified and begin parsing the text in that file. It is assumed that the text file only contains 
	lower case letters and is terminated by a '#'.

ii. Entry into Binary Tree
	The program considers one word at a time. First, an entire line of the text file is grabbed. Then, 
	each word within that line is considered individually. Punctuation is removed and the word is then
	entered into a binary search tree (BST). To do this, the word is compared to the root to find how 
	it compares alphabetically to that root. Then, the program recursively goes on to the left or right 
	node to continue comparing and eventually creating a new node for the input word. Organized in this 
	way, the tree can be printed in alphabetical order using an inorder transversal. Each node contains
	the word, a pointer to the left and right child nodes (NULL is they don't exist), and a linked list 
	that contains the numbers of lines in which the word in that node appears.

iii. Output
	After the text file is finished being loaded into a BST (once the program sees a '#' in the text file),
	the process of traversing and printing the contents of the text file begins. An inorder transversal is 
	performed on the BST and the keys are printed in alphabetical order with the numbers of the lines in 
	which each word appears also listed on the same line. 
	
iv. Termination
	The program terminates after the inorder transversal in complete and all words stored in the BST have 
	been printed