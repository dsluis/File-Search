#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

class Node
{
	public:
		Node(string);
		Node* m_next;
		string m_word;
		int m_hit_count;
};
#endif
