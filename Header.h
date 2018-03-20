#include<iostream>
#include <stdio.h>
#include <string>

struct node //node structure for linked list that is included in each tree node
{
public:
	int info;
	struct node *next;
	node() : next(NULL) {};
};

class llist {  //linked list class, contains all functions needed for linked list to work

	struct node *start;

public:

	llist() : start(NULL) {};

	void push(int &lines) {  //push function to push line numbers as integers to the list in a node
		struct node *p = new node;

		p = newnode(lines);
		if (start == NULL) {
			start = p;
			start->next = NULL;

		}
		else {
			p->next = start;
			start = p;
		}
	}

	void reverse() {  //reverse the list so that it can be printed with the lines each word appears on in ascending order
		struct node* next, *temp, *current;
		struct node* prev = NULL;
		while (start != NULL) {
			current = start;
			next = start->next;
			start->next = prev;
			prev = start;
			start = next;
		}
		start = prev;
	}

	void display()  //display function for linked list, called after reversing
	{
		struct node *temp;
		if (start == NULL)
		{
			std::cout << "List is Empty" << std::endl;
			return;
		}
		temp = start;
		while (temp != NULL)
		{
			std::cout << temp->info<< " ";
			temp = temp->next;
		}
		std::cout << " " << std::endl;
	}

	node *newnode(int &value) {  //create new node for a linked list
		struct node *temp = new(struct node);
		temp->info = value;
		temp->next = NULL;
		return temp;
	}

};
	


class tree {  //binary search tree class

public:  
	struct trnode  //structure for tree node
	{
	public:
		std::string key;  //key, stores each word as a string
		llist list;		//linked list to store the line numbers
		struct trnode *left;  //node pointer for left child
		struct trnode *right;  //node pointer for right child
	};

	trnode * newnode(std::string &str, int &value) {  //function for creating new binary tree node, returns a new node containing what info is available
		struct trnode *temp = new(struct trnode);
		temp->key = str;  //new node key stores the word as string
		temp->left = NULL; //don't know left and right children locations yet, set to NULL
		temp->right = NULL;
		temp->list.push(value);  //push the line number to the list
		return temp;
	}

	bool search(std::string &val, trnode* root, int &num) {  //function to search the BST for an existing value - checks for duplicate words

		if ((root == NULL)) {	//if there is nothing in the node					
			return false;
		}
		if (root->key == val) {  //if the value is found in a node, push the line number to the linked list in that node and do not add a new node to the BST
			root->list.push(num);
			return true;
		}
		if (root->key < val) {  //if the key string is alphabetically less than the value you're searching for, move to the right node
			return search(val, root->right,num);
		}
		if (root->key > val) {  //if the key string is alphabetically greater than the value you're searching for, move to the left node
			return search(val, root->left,num);
		}
	}

	trnode* insert(trnode* root, std::string &word, int num) { //insert function, used to search/check if a word exists already in the BST, then creates a new node
		if (!(search(word, root, num))) {  
			if (root == NULL) {
				root = newnode(word, num); //create the root node if root == NULL
				return root;
			}
			if (word < root->key) root->left = insert(root->left, word, num); //compare the word passed to the function, if it is less alphabetically, move to the left child
			else if (word > root->key) root->right = insert(root->right, word, num);//if it is greater than alphabetically, move to the right child recursively

			return root; //return the root to be kept track of
		}
	}

	void print(trnode* root, int indent) { //function to print the formatted output
		int x;
		if (root != NULL) { 
			if (root->left) print(root->left,0); //if there is a left child, print it, call function recursively
			x = 10 - (root->key.length()); //subtraction to line up the linked lists
			std::cout << root->key << " "; //add a a space after the word being printed
			while (x > 0) {  //add number of spaces to line up the text file line numbers
				std::cout << " ";
				x--;
			}
			root->list.reverse(); //reverse the linked list to diaply properly
			root->list.display(); //print the linked list containing the line numbers
			if (root->right) print(root->right,0); //print the right node, call recursively

		}
	}
};