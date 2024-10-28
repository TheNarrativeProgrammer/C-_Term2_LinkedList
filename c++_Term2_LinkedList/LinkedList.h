#pragma once
#include "Node.cpp" //include Node.cpp to get access to Node Type
class LinkedList
{
	//2. Define a class LINKEDLIST consisting of all the MEMEBER FUNCTIONS for the LinkedList and a HEAD POINTER that will store the reference of a particular linked list.
//Initialize the HEAD to NULL as the linked list is empty initially.

	//HEAD - pointer to 1st node in list
	Node* mHead;
	int mSize;

public:
	//CONSTRUCTOR & DESTRUCTOR - linked list
	LinkedList();
	~LinkedList();

	//FUNCTIONS

	//ADD - to head

	void addToHead_aka_addToBeginning(int inData); //add to Head (beginning)
	void addToHead(int inData);
	void addToBeginning(int inData);

	//ADD - to tail
	void addToTail_aka_addToEnd(int inData);		//to to tail (end)
	void addToTail(int inData);

	//REMOVE - head, tail or index
	void RemoveAtIndex(const int& index);

	//GET (head or tail)
	Node* getHead();
	Node* getTail();
	void GetDataAtIndex(int index);
	int GetIndexSize();

	//PRINT
	void PrintAllDataInListDetailed();
	void PrintAllDataInListStanard();

	//REMOVE
	void RemoveAt(const int& nIndex);
};

