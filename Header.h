#pragma once

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ostream>
#include <stdio.h>
#include <string>
#include <iomanip> //remove for submission
#include <vector>

struct node
{
public:
	int info;
	struct node *next;
	node() : next(nullptr) {};
};

class llist {

	struct node *start;

public:

	llist() : start(nullptr) {};

	void push(int &lines) {
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

	void reverse() {
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

	void display()

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

	node *newnode(int &value) {
		struct node *temp = new(struct node);
		temp->info = value;
		temp->next = NULL;
		return temp;
	}

};
	


class tree {

public:
	struct trnode
	{
	public:
		std::string key;
		llist list;
		struct trnode *left;
		struct trnode *right;
	};

	//struct trnode *root = NULL;


	trnode * newnode(std::string &str, int &value) {
		struct trnode *temp = new(struct trnode);
		temp->key = str;
		temp->left = NULL;
		temp->right = NULL;
		temp->list.push(value);
		return temp;
	}

	bool search(std::string &val, trnode* root, int &num) {

		if ((root == NULL)) {						
			return false;
		}
		if (root->key == val) {
			root->list.push(num);
			return true;
		}
		if (root->key < val) {
			return search(val, root->right,num);
		}
		if (root->key > val) {
			return search(val, root->left,num);
		}
	}

	trnode* insert(trnode* root, std::string &word, int num) {
		//trnode* n = new trnode;
		//trnode* idx = new trnode;
		//n->left = NULL;
		//n->right = NULL;
		//n->key = word;

		//idx = root;
		if (!(search(word, root, num))) {
			if (root == NULL) {
				root = newnode(word, num);
				return root;
			}
			if (word < root->key) root->left = insert(root->left, word, num);
			else if (word > root->key) root->right = insert(root->right, word, num);

			return root;
		}
	}

	void print(trnode* root/*, int indent*/) {
		if (root != NULL) {
			if (root->left) print(root->left);
			if (root->right) print(root->right);
			int x = 10 - (root->key.length());
			std::cout << root->key << " ";
			while (x > 0) {
				std::cout << " ";
				x--;
			}
			root->list.reverse();
			root->list.display();
		}
		//if (p != NULL) {
		//	if (p->right) {
		//		print(p->right, indent + 4);
		//	}
		//	if (indent) {
		//		std::cout << std::setw(indent) << ' ';
		//	}
		//	if (p->right) std::cout << " /\n" << std::setw(indent) << ' ';
		//	std::cout << p->key << "\n ";
		//	if (p->left) {
		//		std::cout << std::setw(indent) << ' ' << " \\\n";
		//		print(p->left, indent + 4);
		//	}
		//}
	}
};