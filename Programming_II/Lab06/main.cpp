/**
*	@file : main.cpp
*	@author :  Stephen Longofono
*	@date : 03-28-2015
*	Purpose: This class is a testing class for sorting algorithms.  It is responsible for generating arrays of random
*		numbers, calling sorting method to sort them, and timing the process.  ***NOTE*** Bogo sort has the 
*		potential to run indefinitely.  There are measures in place to limit this from happening, but it remains
*		a possibility.
*/


# include <iostream>
#include <ctime>
#include <random>
#include <chrono>
#include "Sorts.h"


// This method is provided by Dr. Gibbons for use with the main class.

void printMenu()
{
	std::cout 	<< "\n\nSelect a sort:\n"
			<< "1) Bubble Sort\n"
			<< "2) Insertion Sort\n"
			<< "3) Selection Sort\n"
			<< "4) Bogo Sort (use only with very small arrays!)\n"
			<< "Enter choice: ";
}

/* This method prints a standard array
*@pre - a valid array exists, with accurate size value, and the type can be printed to stdout
*@post - prints each element of the array with formatting
*@return- void
*/

void printIntArray(int arr[], int size){

	std::cout<<"[";
	for(int i = 0; i< size-1; i++){
		std::cout<<arr[i]<<", ";
	}
	std::cout<<arr[size-1]<<"]\n";

}


/* This method creates and populates an integer array with pseudorandom values.  Note that system time is used to seed
* the random number generator.
*@pre - size is non-negative
*@post - creates an array and populates it with values pulled from a uniformly distributed pseudorandom number generator
*@return- a pointer to the first index in the array
*/
int* createRandomArray(int size, int min, int max){
	std::default_random_engine generator(time(nullptr)); //seeds a random engine with time
	std::uniform_int_distribution<int> distr(min, max); //uniform distribution of expected values
	int* arr = new int [size]; 
	for(int i = 0; i<size; i++){
		arr[i] = distr(generator); //grab a number from the distribution using the generator
	}
	return arr;
}

int main(){
	bool notDone = true;
	char again = 'y';
	char print = 'y';
	int choice = 0;
	int arraySize = 0;	//for random array generation
	int arrayMax =0;	//ditto
	int arrayMin = 0;	//ditto

	std::chrono::system_clock::time_point start;	//stores system time
	std::chrono::system_clock::time_point end;	//ditto
	std::chrono::duration<double> elapsed;		//used to measure time elapsed between above

	Sorts<int>* sorter = new Sorts<int>();		//TODO deleteme...done
	while(notDone){
		printMenu();
		std::cin>>choice;
		while(choice<1||choice>4){
			std::cout<<"Invalid entry.  Enter a choice (1-4): \n";
			printMenu();
			std::cin>>choice;
		}
////////////////////////////////////////////ARRAY GENERATION INFO

		
		std::cout<<"Input a size for the random array: \n";
		std::cin>>arraySize;
		std::cout<<"Input a lower bound on the range of random numbers:\n";
		std::cin>>arrayMin;
		std::cout<<"Input an upper bound on the range of random numbers:\n";
		std::cin>>arrayMax;
		if(choice==4 && arraySize>15){
			std::cout<<"The array is too large to sort in a timely manner.\n";
			std::cout<<"Bogo sort should only be used with size less than 15.\n"; 
			arraySize = -1;
		}
		
		int* temp = createRandomArray(arraySize, arrayMin, arrayMax); //TODO deleteme...done

		std::cout<<"Do you want to print the unsorted array? (y/n): \n";
		std::cin>>print;
		if(print=='Y'||print=='y'){
			std::cout<<"Here is the unsorted array:\n";
			printIntArray(temp, arraySize);
		}

///////////////////////////////////////////		


		switch(choice){
		
			case 1: std::cout<<"\nSorting with bubble sort...\n";
				std::cout<<"Do you want to print the sorted array? (y/n): \n";
				std::cin>>print;
				
				start = std::chrono::system_clock::now();	//grab time
				sorter->bubbleSort(temp, arraySize);		//do stuff
				end = std::chrono::system_clock::now();		//grab time
				elapsed = (end-start);				//difference
				
				if(print=='Y'||print=='y'){
					std::cout<<"Here is the sorted array:\n";
					printIntArray(temp, arraySize);
				}
	
				std::cout<<"\n"<<arraySize<<" numbers were sorted in "
						<<elapsed.count()<<" seconds\n\n";//formats time
				break;


			case 2: std::cout<<"\nSorting with insertion sort...\n";
				std::cout<<"Do you want to print the sorted array? (y/n): \n";
				std::cin>>print;
				
				start = std::chrono::system_clock::now();	
				sorter->insertionSort(temp, arraySize);		
				end = std::chrono::system_clock::now();		
				elapsed = (end-start);				
				
				if(print=='Y'||print=='y'){
					std::cout<<"Here is the sorted array:\n";
					printIntArray(temp, arraySize);
				}
	
				std::cout<<"\n"<<arraySize<<" numbers were sorted in "
						<<elapsed.count()<<" seconds\n\n";
				break;


			case 3: std::cout<<"\nSorting with selection sort...\n";
				std::cout<<"Do you want to print the sorted array? (y/n): \n";
				std::cin>>print;
				
				start = std::chrono::system_clock::now();	
				sorter->selectionSort(temp, arraySize);		
				end = std::chrono::system_clock::now();		
				elapsed = (end-start);				
				
				if(print=='Y'||print=='y'){
					std::cout<<"Here is the sorted array:\n";
					printIntArray(temp, arraySize);
				}
	
				std::cout<<"\n"<<arraySize<<" numbers were sorted in "
						<<elapsed.count()<<" seconds\n\n";
				break;


			case 4: std::cout<<"\nSorting with bogo sort...\n";
				std::cout<<"Do you want to print the sorted array? (y/n): \n";
				std::cin>>print;
				
				start = std::chrono::system_clock::now();	
				sorter->bogoSort(temp, arraySize);		
				end = std::chrono::system_clock::now();		
				elapsed = (end-start);				
				
				if(print=='Y'||print=='y'){
					std::cout<<"Here is the sorted array:\n";
					printIntArray(temp, arraySize);
				}
	
				std::cout<<"\n"<<arraySize<<" numbers were sorted in "
						<<elapsed.count()<<" seconds\n\n";
				break;

		}
		std::cout<<"Do you want to quit? (y/n): ";
		std::cin>>again;
		if(again=='y'||again=='Y'){
			notDone = false;
		}
		delete [] temp;
	}//end while
	std::cout<<"Exiting......\n\n\n";
	delete sorter;
}//end main
