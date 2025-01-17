/*	Name: Stephen Longofono - 2776831
*	File name: Node.cpp
*	Date: 02-04-2015
*	Description: Implementation of the Node class.
*/
#include "Node.h"

Node::Node(){
	m_value = 0;
	m_next = nullptr;
}

void Node::setValue(int val){
	m_value = val;
}

int Node::getValue() const{
	return m_value;
}

void Node::setNext(Node* prev){	//sets the pointer to point to the passed node (typically the top of list)
	m_next = prev;
}

Node* Node::getNext() const{
	return m_next;
}
