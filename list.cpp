#include "list.h"

using namespace std;

	//constructor
List::List()
{
	m_head=NULL;
}

void List::insert(string s)
{
	Node* ptr=m_head;
	if(m_head==NULL)
	{
		m_head=new Node(s);
	}
	else
	{
		while (ptr!=NULL)	
		{
			if(ptr->m_word==s)
			{
				ptr->m_hit_count++;
				break;
			}
			else if(ptr->m_next==NULL)
			{
				ptr->m_next=new Node(s);
				break;
			}
			ptr=ptr->m_next;
		}
	}
}

Node* List::search(string s)
{
	Node* ptr;
	for(ptr=m_head; ptr!=NULL; ptr=ptr->m_next)
	{
		if(ptr->m_word==s)
			return ptr;
	}
	return NULL;
}


