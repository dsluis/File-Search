#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include "node.h"

using namespace std;
	//linked list that holds the strings in a hash table bucket
class List
{
	public:
		List();
		void insert(string);
		Node* search(string);
		Node* m_head;
	private:
};
#endif





