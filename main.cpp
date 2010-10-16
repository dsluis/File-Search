//string_searcher 1.1
//author: Daniel Sluis
//free to use, copy and change around.
//last updated August 4th, 2006
/* Improvements to be made
	-Indexing: don't index punctuation
		ex: make it so when it see's "coconuts." in the file it will index "coconuts" instead of "coconuts."
	-Searching and Indexing: Be able to show what lines the words where found on
	-use dos2unix so that this can read dos files(I think)
*/
/* Improved
	-Indexing: make the hash array be an array of pointers to nodes that
		can hold info besides the string title like line number and
		how many, the node would alos be part of a linked list in 
		case of hash collision
	-Indexing:  make the indexing a separate function from main
*/
#include <iostream>
#include <string>
#include <fstream>
#include "list.h"

using namespace std;

int hash_algorithm(string);
void load(List*,ifstream &my_ifile);
void search(List*);

int main(int argc, char* argv[])
{
		//1039 is a prime number
	List index[1039];
	ifstream my_ifile(argv[1], ios::in);
	//error checking
			//make sure filename specified on the command line
		if (argc==1)
		{
			cerr<<"no filename specified"<<endl;
			return 1;
		}
			//if could not open
		if(!my_ifile)
		{
			cerr<<"could not open file <"<<argv[1]<<">"<<endl;
			return 1;
		}
	
	cout<<"indexing file "<<argv[1]<<"..."<<endl;	
	load(index,my_ifile);
	cout<<"indexing complete!"<<endl;
		//takes the array of lists
	search(index);
	
	return 0;
}
	//takes strings of input file and puts them into array of Lists using the algorithm to get integer place in the array
void load(List* index,ifstream &my_ifile)
{
		//used when indexing each string in searched file
	string buffer;
		//used as place in array where this string goes
	int placer;
	while (my_ifile>>buffer)
	{
		placer=hash_algorithm(buffer);
		index[placer].insert(buffer);
	}
}
	//takes the array location that holds all the lists.  
	//Puts input into the algorithm and uses resulting number
	//with array of lists to see if node with same string is in the array.
void search(List* index)
{
	string word;

	cout<<"enter the word you want to search for and type 'quit' if you wish to quit, if you want to find the word quit then go write your own search program"<<endl;
	do
	{
		cout<<":";
		cin>>word;
		if(word=="quit")
			break;
		Node* ptr=index[hash_algorithm(word)].search(word);
		if(ptr)
		{
			cout<<word<<" is held within "<<ptr->m_hit_count;
			if(ptr->m_hit_count>1)
				cout<<" times"<<endl;
			else
				cout<<" time"<<endl;
		}
		else
			cout<<word<<" is not within"<<endl;
	}
	while(word!="quit");
}
	//turns a string into a number including and between 0 and 1038
int hash_algorithm(string s)
{
	const char* characters=new char[100];
	int multiple=1;
	characters=s.c_str();
	int length_of_string=s.length();
	for(int i=0; i<length_of_string; i++)
	{
		if(multiple<1000000)
		{
			multiple=multiple*int(characters[i]);
		}
		else
		{	
			multiple=multiple/int(characters[i]);
		}
	}
	multiple=multiple+1039;
	multiple=multiple%1039;
	return multiple;
}







