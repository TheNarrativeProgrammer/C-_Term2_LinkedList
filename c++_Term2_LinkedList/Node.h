#pragma once
//1. Define a structure NODE having two members DATA and a NEXT pointer.

	//Eachnode of the linked list will be represented as a structure having two members data and next where:
		//DATA: Represents the value stored in the node.
		//NEXT POINTER: Stores the reference to the next node in the sequence. Type is pointer of a Node, which holds the address of the next Node.

class Node
{
public:
	//constructor
	Node();
	Node(const int& inValue);
	Node(const int& inValue, Node* inNextNode); //param constructor takign in data memember var, and Node pointer to Next

	//GETTERS AND SETTERS
	int getData() const;

public:
	int mData;
	Node* mNext;
};

