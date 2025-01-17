/*	Name: Stephen Longofono - 2776831
*	File name: main.cpp
*	Date: 02-11-2015
*	Description: the main class will serve as a driver to interact with the double 
*	linked list class.  Note use of try/catch blocks in place of hard-coded filters.
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include "Node.h"
#include "DoubleLinkedList.h"

/*
*	The method below was written by John Gibbons for use in our lab.  It is a helper method to display a
*	menu for the user to navigate and manipulate the DoubleLinkedList class with.
*/

void printMenu()
{
	std::cout << 	"\n\nMake choice\n"
		<<	"1) push value onto front\n"
		<<	"2) push value onto back\n"
		<<	"3) insert behind a value\n"
		<<	"4) insert ahead of a value\n"
		<<	"5) remove value\n"
		<<	"6) print list\n"
		<<	"7) Quit\n"
		<< 	"Your choice: ";
}




int main(){
	DoubleLinkedList<int> ll1;
	int choice = 0;
	int innerChoice = 0;
	int inner2 = 0;
	printMenu();
	std::cin>>choice;
	std::cout<<"You chose: "<<choice<<"\n";
	while(choice != 7){
		while((choice > 7)||(choice < 1)){
			std::cout<<"\nInvalid entry.  Please enter a number from the menu (1-7):";
			std::cin>>choice;
			std::cout<<"You chose: "<<choice<<"\n";
		}
		
		
		switch(choice){

			case 1: std::cout<<"Give a value.\n";
				std::cin>>innerChoice;				
				ll1.pushFront(innerChoice);
				std::cout<<"\n"<<innerChoice<<" added to front of list.\n";
				break;


			case 2: std::cout<<"Give a value.\n";
				std::cin>>innerChoice;				
				ll1.pushBack(innerChoice);
				std::cout<<"\n"<<innerChoice<<" added to back of list.\n";
				break;


			case 3: std::cout<<"Give a value to insert.\n";
				std::cin>>innerChoice;
				inner2 = 0;
				std::cout<<"Pick a value to insert behind.\n";
				std::cin>>inner2;				
				std::cout<<"\nAttempting to insert "<<innerChoice<<" behind "<<inner2<<"\n";
				try{
					ll1.insertBehind(inner2, innerChoice);
					std::cout<<"\n"<<innerChoice<<" inserted behind "<<inner2<<"\n";
				}
				catch(std::runtime_error& e){//we are not using the exception here, just catching it
					std::cout<<"\n"<<innerChoice<<" could not be inserted.\n";
				}
				break;


			case 4: std::cout<<"Give a value to insert.\n";
				std::cin>>innerChoice;
				inner2 = 0;
				std::cout<<"Pick a value to insert ahead of.\n";
				std::cin>>inner2;				
				std::cout<<"\nAttempting to insert "<<innerChoice<<" ahead of "<<inner2<<"\n";
				try{
					ll1.insertAhead(inner2, innerChoice);
					std::cout<<"\n"<<innerChoice<<" inserted ahead of "<<inner2<<"\n";
				}
				catch(std::runtime_error& e){
					std::cout<<"\n"<<innerChoice<<" could not be inserted.\n";	
				}
				break;


			case 5: std::cout<<"Give a value to remove.\n";
				std::cin>>innerChoice;
				std::cout<<"You gave "<<innerChoice<<"\n";				
				try{
					bool temp = ll1.remove(innerChoice);
					if(temp){
						std::cout<<"\n"<<innerChoice<<" removed from list.\n";
					}
				}
				catch(std::runtime_error& e){
					std::cout<<"\n"<<innerChoice<<" could not be removed from list.\n";
				}
				break;
			

			case 6: ll1.printList();
				std::cout<<"\n";
				break;


			case 7: break;


			default: break;
			
		}//end switch
		printMenu();
		std::cin>>choice;
		while((choice > 7)||(choice < 1)){
			std::cout<<"\nInvalid entry.  Please enter a number from the menu (1-7):";
			std::cin>>choice;
		}
		std::cout<<"\nYou chose: "<<choice<<"\n";
	}//end while
	std::cout<<"Program ending...\n\n";
	return 0;
}

