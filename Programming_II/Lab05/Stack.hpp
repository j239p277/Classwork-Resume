/**
*	@file : Stack.hpp
*	@author :  Stephen Longofono -2776831
*	@date : 02-25-2015
*	Purpose: Implementation of Stack.h
*/
#include "Node.h"
#include "StackInterface.h"
#include "PreconditionViolationException.h"


template<typename T>
Stack<T>::Stack(){
	
	m_size = 0;
	m_top = nullptr;

}

template<typename T>
bool Stack<T>::isEmpty()const{
	return (m_size == 0);
}

template<typename T>
void Stack<T>::push(const T& newEntry){
	Node<T>* n = new Node<T>();
	n->setValue(newEntry);
	m_size++;
	n->setNext(m_top);
	m_top = n;
}

template<typename T>
T Stack<T>::pop() throw(PreconditionViolationException){
	
	if(isEmpty()){
		throw(PreconditionViolationException("Exception: Pop attempted on an empty stack\n"));
	}
	else{

		Node<T>* n = (m_top->getNext());
		T temp = (m_top->getValue());
		delete m_top;
		m_size--;
		m_top = n;
		return temp;
	}
}

template <typename T>
T Stack<T>::peek() const throw(PreconditionViolationException){

	if(isEmpty()){
		throw(PreconditionViolationException("Exception: Peek attempted on an empty stack\n"));
	}

	else{
		return (m_top->getValue());
	}
}

template<typename T>
int Stack<T>::size() const{
	return m_size;
}


template<typename T>
void Stack<T>::print()const{
	Node<T>* temp = m_top;
	Node<T>* back = getBack();
	if(m_size==0){
		std::cout<<"\n\n\n\n\n\n\n\nStack Empty\n";
	}
	else if(temp==back){
		std::cout<<temp->getValue();
	}
	else{
		while(temp!=back){
			std::cout<<temp->getValue()<<", ";
			temp = temp->getNext();
		}
		std::cout<<temp->getValue();
	}
	std::cout<<"\n";
}

template<typename T>
Node<T>* Stack<T>::getBack()const{
	if(m_size==0){
		return nullptr;
	}
	else if (m_top->getNext()==nullptr){
		return m_top;
	}	
	else{
		bool notDone = true;
		Node<T>* temp = m_top;
		while(notDone){
			if(temp->getNext() == nullptr){
				return temp;
				notDone = false;
			}
			temp = temp->getNext();
		}
	}	
	return nullptr;	
}

template<typename T>
bool Stack<T>::operator>(const StackInterface<T>& rhs) const{

	return(size()>(rhs.size()));
//note - this is ok as an argument, because we know all stackinterfaces have a size regardless of the data type.	
}

template<typename T>
bool Stack<T>::operator>=(const StackInterface<T>& rhs) const{

	return(size()>=(rhs.size()));
	//note: we can't use m_size becuase it is a member of the child class.  Instead, we use the result of the size method, which must exist in all child classes.
}

template<typename T>
bool Stack<T>::operator<(const StackInterface<T>& rhs)const{

	return(size()<(rhs.size()));
}

template<typename T>
bool Stack<T>::operator<=(const StackInterface<T>& rhs)const{

	return(size()<=(rhs.size()));
}

template<typename T>
bool Stack<T>::operator==(const StackInterface<T>& rhs)const{
	return(size()==(rhs.size()));
}

template<typename T>
bool Stack<T>::operator!=(const StackInterface<T>& rhs)const{
	return(size()!=(rhs.size()));
}

template<typename T>
Stack<T>::~Stack(){
	while(size()!=0){
		pop();
	}
	m_top = nullptr;
}




