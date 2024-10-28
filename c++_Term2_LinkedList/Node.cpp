

#include "Node.h"

Node::Node()
{
    mData = 0;
    mNext = nullptr;
}

Node::Node(const int& inValue)
{
    mData = inValue;
    mNext = nullptr;
}

Node::Node(const int& inValue, Node* inNextNode)
{
    mData = inValue;
    mNext = inNextNode;
}

int Node::getData() const
{
    return mData;
}
