#include "node.h"

using namespace std;

Node::Node(string word)
{
	m_word=word;
	m_hit_count=1;
	m_next=NULL;
}
