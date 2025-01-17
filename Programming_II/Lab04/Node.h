/*	Name: Stephen Longofono - 2776831
*	File name: Node.h
*	Date: 02-11-2015
*	Description: This class is a generic container for use in our stack.  For this use, only the getValue, getNext methods are relevant.
*
*	::::NOTE:::: this must be in the makefile with the object that instantiates it! (main, indirectly)
*/

#ifndef NODE_H
#define NODE_H

template<typename T>  //note - the book uses TypeName ItemType in place of class T.  They are equivalent.
class Node{
	public:

/*
* This is the constructor
* @pre - none
* @post - creates a Node object and initializes the value to T(), which is the "copy constructor"
* @return - a Node object with initialized members
*/ 
		Node();


/*
* This is a getter for the node after this node
* @pre - A node exists with accurate values for the m_next pointer (nullptr or another node object) 
* @post - retrieves the value of m_next
* @return - the Node<T> pointer m_next
*/ 
		Node<T>* getNext() const;


/*
* This is a getter for the node prior to this node
* @pre - A node exists with accurate values for the m_previous pointer (nullptr or another node object)
* @post - retrieves the value of m_previous
* @return - the Node<T> pointer m_previous
*/ 
		Node<T>* getPrev() const;


/*
* This is a getter for the value of the Node's m_value member
* @pre - none
* @post - Retrieves the type T m_value of the node
* @return - the T m_value of the node
*/
		T getValue() const;


/*
* This is a setter for the next node in the list
* @pre - The Node<T> pointer passed points to a valid Node
* @post - assigns a value to the m_next Node<T> pointer (either another node or nullptr)
* @return - void
*/ 
		void setNext(Node<T>* n);


/*
* This is a setter for the previous node in the list
* @pre - The Node<T> pointer passed points to a valid Node
* @post - assigns a value to the m_previous Node<T> pointer (either another node or nullptr)
* @return - void
*/
 		void setPrev(Node<T>* n);


/*
* This is a setter for the value of the Node's typedef
* @pre - the value passed matches the type T
* @post - assigns a value to the <T> m_value
* @return - void
*/
		void setValue(T value);
	private:	
		T m_value;		//type assigned at runtime
		Node<T>* m_previous;	//points to the previous node or nullptr
		Node<T>* m_next;	//points to the previous node or nullptr

};

#include "Node.hpp"
#endif
