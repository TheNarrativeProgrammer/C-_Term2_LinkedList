#include "LinkedList.h"
#include "Utils.h"

LinkedList::LinkedList()
{
	mHead = nullptr;
	mSize = 0;
}

LinkedList::~LinkedList()
{
}


//ADD TO HEAD

void LinkedList::addToHead_aka_addToBeginning(int inData)
{
	Node* newNode = new Node();					//a) Create a new Node memory block
													//Object type: Node pointer

	newNode->mData = inData;					//b) set mData of newNode to arguement inData

	newNode->mNext = mHead;						//c) Set mNext of newNode to current mHead (mHead now 2nd position)

	mHead = newNode;							//d) Set mHead of LinkedList to newNode

	
}

void LinkedList::addToHead(int inData)
{
	Node* newNode = new Node(inData);			//a) Create a new Node memory block - param constructor
														//Object type: Node pointer
												// & b) set mData of newNode to arguement inData using param constructor

	newNode->mNext = mHead;						//c) Set mNext of newNode to current mHead (mHead now 2nd position)

	mHead = newNode;							//d) Set mHead of LinkedList to newNode
}

void LinkedList::addToBeginning(int inData)
{
	mHead = new Node(inData, mHead);			//a) Create a new Node memory block - param constructor
														//Object type: Node pointer
												// & b) set mData of newNode to arguement inData using param constructor
												
												// & c) Set mNext of newNode to current mHead (mHead now 2nd position) 
													// new Node(inData, mHead); mHead is param that set mNext of newNode being constructed
												//d) Set mHead of LinkedList to newNode
													//code runs right to left so "mHead" in "new Node(inData, mHead)" is current mHead, which becomes 2nd position
														//on right side, "mHead =" is set to newNode, making newNode the 1st position node.

	// 
	//new Node(data, mHead) where inData sets the member varaible mData, and mHead sets mNext for the nextly created Node
	// mHead = then sets the head of the linkedList to the newly created node address.
}


//ADD TO TAIL

void LinkedList::addToTail_aka_addToEnd(int inData)
{
	Node* newNode = new Node();					//a) Create a new Node memory block 
													//Object type: Node pointer

	newNode->mData = inData;					// b) set mData of newNode to arguement inData

	newNode->mNext = nullptr;					//c) set new Node's mNext to NULL

	if (!mHead)									//d) check if list is empty. If empty, set mHead to point a new Node
	{
		mHead = newNode;							//set mHead of LL to newNode
		return;
	}
												//e) Iterator - find Node at END
	Node* iterator = mHead;							//create iterator set to mhead (starting point of iteration)
													//Object type: Node pointer

	while (iterator->mNext != nullptr)				//Traverse to LAST node  (mNext of Last Node = Nullptr)
														//If current iteration mNext is NOT null - set iterator to mNext.
	{
		iterator = iterator->mNext; 
	}												//Exit loop when current iteration is last node & mNext is null

	iterator->mNext = newNode;						//set iterator->mNext to newNode (moves iterator from last to 2nd last)
														//b/c newNode.mNext is null, newNode is now last node 

	mSize++;										//increase size by 1

}

void LinkedList::addToTail(int inData)
{
	Node* newNode = new Node(inData);			//a) Create a new Node memory block - Param constructor to mData
													//Object type: Node pointer
												// & b) set mData of newNode to arguement inData
												// & c) set new Node's mNext to NULL - DEFAULT in constructor

	if (mHead == nullptr)						//d) check if list is empty. If empty, set mHead to point a new Node - call addToHead
	{
		addToHead(inData);							//call addToHead since functionally same as tail for empty list
		return;
	}
												//e) Iterator - find Node at END
	Node* iterator = mHead;							//create iterator set to mhead (starting point of iteration)
														//Object type: Node pointer

	while (iterator->mNext != nullptr)				//Traverse to LAST node  (mNext of Last Node = Nullptr)	
	{													//If current iteration mNext is NOT null - set iterator to mNext.
		iterator = iterator->mNext;
	}												//Exit loop when current iteration is last node & mNext is null

	iterator->mNext = newNode;						//set iterator->mNext to newNode (moves iterator from last to 2nd last)
														//b/c newNode.mNext is null, newNode is now last node 

	mSize++;										//increase size by 1
}

//GET - Node or Data
Node* LinkedList::getHead()
{
	return mHead;
}

Node* LinkedList::getTail()
{
	if (mHead == nullptr)							//a) check if list is empty 
	{
		return mHead;									//return mHead if empty
	}
													//b) Iterator - find Node at END
	Node* iterator = mHead;							//create iterator set to mhead (starting point of iteration)
														//Object type: Node pointer

	while (iterator->mNext != nullptr)				//Traverse to LAST node  (mNext of Last Node = Nullptr)	
	{													//If current iteration mNext is NOT null - set iterator to mNext.
		iterator = iterator->mNext;
	}												//Exit loop when current iteration is last node & mNext is null

	return iterator;								//c) Return the last node (iterator's current iteration)
}

void LinkedList::GetDataAtIndex(int index)
{
	LOG_LN_EMPTY;
	LOG_LN("======================================================");
	LOG_LN("index : " + index);

	if (index < 0 || index > GetIndexSize())
	{
		LOG_LN("index is outside range");
		return;
	}

	Node* iterator = mHead;

	for (int i = 0; i < index; i++)
	{
		iterator = iterator->mNext;
	}
	LOG_LN(iterator->mData);

}

int LinkedList::GetIndexSize()
{
	int indexSize = 0;							//a) set size to 0	

	if (mHead == nullptr)						//b) Check if list is empty
	{
		return indexSize;							//return 0 if empty
	}
												//c) Iterator - find Node at END & increment indexSize
	Node* iterator = mHead;
	while (iterator->mNext != nullptr)
	{
		iterator = iterator->mNext;
		indexSize++;								//increment indexSize
	}
	return indexSize;							//d) return indexSize (while loop exits when iterator reaches end of list, and indexSize at current size)

}

void LinkedList::PrintAllDataInListDetailed()
{
	LOG_LN_EMPTY;
	LOG_LN("======================================================");
	int indexSize = GetIndexSize();

	if (indexSize == 0)
	{
		LOG_LN("List is empty");
		return;
	}

	Node* iterator = mHead;
	int indexCount = 0;

	while (iterator->mNext != nullptr)
	{
		if (iterator == mHead)
		{
			LOG_LN(indexCount + ". Head : " + iterator->mData);
			iterator = iterator->mNext;
			indexCount++;
		}
		else
		{
			LOG_LN(indexCount + ". " + iterator->mData);
			iterator = iterator->mNext;
			indexCount++;
		}
		LOG_LN(indexCount + ". Tail : " + iterator->mData);
		LOG_LN("======================================================");
		LOG_LN("Length of LL Index : " + indexCount);
		LOG_LN("Size of LL : " + mSize);
		LOG_LN("======================================================");

	}

}

void LinkedList::PrintAllDataInListStanard()
{
	LOG_LN_EMPTY;
	LOG_LN("======================================================");
	int indexSize = GetIndexSize();

	if (indexSize == 0)
	{
		LOG_LN("List is empty");
		return;
	}

	Node* iterator = mHead;

	while (iterator->mNext != nullptr)
	{
		LOG_LN(iterator->mData);
		iterator = iterator->mNext;
	}
		LOG_LN(iterator->mData);
		LOG_LN("======================================================");
}


