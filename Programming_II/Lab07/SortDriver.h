/**
*	@file : SortDriver.h
*	@author :  Stephen Longofono
*	@date : 04-04-2015
*	Purpose: This class acts as an intermediary to filter the user input in the typical linux style
*		Main will pass a valid array of arguments, and this class will either execute the appropriate
*		functions, or print a help menu.
*/

#ifndef SDRIVE
#define SDRIVE
#include <fstream>
#include "Sorts.h"
#include <string>
#include <functional>


class SortDriver{

public:


/* This method is the final step in the process, and logs the results of the sorts and timing in a text file.
*@pre - argv contains only valid arguments (per the printHelpMenu method), has valid size.
*@post - creates a file to hold timing information, and logs it based on file input and input from sortTimer (Sorts class)
*@return - void
*/
    static void run(int argc, char** argv);


/* This prints a menu for the user detailing acceptable arguments and the order they should be used in.  Follows typical
* linux help format and behavior
*@pre - none
*@post - prints a text menu to stdout
*@return - void
*/
    static void printHelpMenu();


private:


/* This method is used to verify that the input file can be accessed and written.
*@pre - none
*@post - calls the .good() method to verify that the system can access/write the fileName passed
*@return - true if fileName is correctly formatted, exists in the path given, and is accessible.  False otherwise.
*/
    static bool isFileAccessible(std::string fileName);


/* This method is used to check that the sort argument passed matches a sort known to the SortDriver
*@pre - none
*@post - checks that the sortParameter matches one of the seven known options.
*@return - true if the sortParameter matches a sort type, false otherwise.
*/
    static bool isSortValid(std::string sortParameter);
    

/* This method verifies that the sort type and input file are valid parameters.
*@pre - none
*@post - Calls isSortValid() and isFileAccessible()
*@return - True if both of above are true, flase otherwise.
*/
    static bool areParametersValid(std::string sortName, std::string inputFileName);


/* This method retrieves the number of values in a file for use with the sorting algorithms.
*@pre - an inputFile exists as created by the NumberFileGenerator class.
*@post - fetches the integer value from the first line of the input file associated with the input stream passed.
*@return - an integer representing the number of values (lines) in the input file
*/
    static int getFileCount(std::ifstream& inputFile);
 

/* This method creates an array to be sorted from the input file.
*@pre - the input file was created by the NumberFileGenerator class, the size is accurate.
*@post - Creates an array of the given size, and populates each index with a line from the input stream, starting with line 1.
*@return - an integer pointer to the 0th index of an array.
*/
    static int* createArray(std::ifstream& inputFile, int size);

/* This method makes a copy of the unsorted array for use with the "-all" sort parameter.  Each sort type will be passed a copy
* of the same array so that results can be compared in a meaningful way.
*@pre - original is a valid array with accurate size.
*@post - populates copy with the values from the original array
*@return - void
*/
    static void copyArray(int original[], int copy[], int size);

};

#endif
