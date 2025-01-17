/**
*	@file : main
*	@author :  Stephen Longofono - 2776831
*	@date : 02-25-2015
*	Purpose: Testing class for Lab 04
*/
#include "StackInterface.h"
#include "Stack.h"
#include "Node.h"
#include "PreconditionViolationException.h"
#include <iostream>
#include <stdexcept>
#include <string>

void printMenu(){
	
	std::cout<<"\nSelect an action:"
		<<"\n1) Add something to stack 1"
		<<"\n2) Add something to stack 2"
		<<"\n3) See what is at the top of stack 1"
		<<"\n4) See what is at the top of stack 2"
		<<"\n5) Print contents in stack 1"
		<<"\n6) Print contents in stack 2"
		<<"\n7) Remove something from stack 1"
		<<"\n8) Remove something from stack 2"
		<<"\n9) Compare Stacks"
		<<"\n10) Quit"
		<<"\nEnter choice:\n";
}

template<typename T>
void compareStacks(const StackInterface<T>& s1, const StackInterface<T>& s2){

	std::cout	<<"\nComparison of stacks:\n"
			<<"lane 1 < lane 2: " << (s1 < s2) << "\n"
			<<"lane 1 > lane 2: " << (s1 > s2) << "\n"
			<<"lane 1 >= lane 2: " << (s1 >= s2) << "\n"
			<<"lane 1 <= lane 2: " << (s1 <= s2) << "\n"
			<<"lane 1 == lane 2: " << (s1 == s2) << "\n"
			<<"lane 1 != lane2: " << (s1 != s2) << "\n";

}


int main(){

StackInterface<std::string>* lane1 = new Stack<std::string>();
StackInterface<std::string>* lane2 = new Stack<std::string>();

std::cout<<"================STACK PROGRAM================\n\n";
int choice = 0;
std::string input;
bool notDone = true;

while(notDone){

	printMenu();
	std::cin>>choice;
	std::cout<<"You chose: "<<choice<<"\n";
	
	switch(choice){
	case 1: 
		std::cout<<"What is going in stack 1?: \n";
		std::cin>>input;
		lane1->push(input);
		std::cout<<input<<" successfully added to stack 1\n"; break;
	case 2:
		std::cout<<"What is going in stack 2?: \n";
		std::cin>>input;
		lane2->push(input); 
		std::cout<<input<<" successfully added to stack 2\n"; break;
	case 3:
		try{
			std::cout<<lane1->peek()<<"\n";
		}
		catch(std::exception& e){
			std::cout << e.what();
		} break;
	case 4:
		try{
			std::cout<<lane2->peek()<<"\n";
		}
		catch(std::exception& e){
			std::cout << e.what();
		} break;
	case 5:
		lane1->print(); break;
	case 6:
		lane2->print(); break;
	case 7:
		try{
			std::cout<<lane1->pop()<<" removed from stack 1\n";
		}
		catch(std::exception& e){
			std::cout<< e.what();
		} break;
	case 8:
		try{
			std::cout<<lane2->pop()<<" removed from stack 2\n";
		}
		catch(std::exception& e){
			std::cout<< e.what();
		} break;
	case 9:
		compareStacks(*(lane1) , *(lane2)); break;
	case 10:
		notDone = false; break;
	


	default: std::cout<<"\nInvalid Entry\n"; break;
	}

}

std::cout << "Program ending\n";
delete lane1;
delete lane2;

return 0;

}

