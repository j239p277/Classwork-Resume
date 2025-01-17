/**
*	@file : MazeWalker.h
*	@author :  Stephen Longofono - 2776831
*	@date : 04 - 19 - 2015
*	Purpose: This class navigates the maze using a stack/queue, an array of boolean values representing visited positions,
*		and an array of chars representing the maze read with the MazeReader class.  
*/

#ifndef MWALK
#define MWALK
#include "Position.h"
#include <stack>
#include <queue>
#include <iostream>

class MazeWalker{

	public:

 /**	Constructor
*	@pre  - The mazePtr pointer is to a valid maze.
*	@post  - A maze walker if created with all needed flags set and the visited array contains 
*		all false.
*	@return - void
*/
		MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs);

/**	Deconstructor - This is to clean up the arrays and such
*	@pre - a MazeWalker exists
*	@post - deletes heap-allocated members
*	@return - void
*/
		~MazeWalker();


/**	This actually does the work, this is a driver.
*	@pre - The maze is a valid maze.
*	@post - The maze is traversed until (either dfs or bfs) the end is reached or all moves are
*		 exhausted. The visited array printed during the traversal.
*	@return - void
*/
		void walkMaze();

	protected:

/**	This method stores all remaining moves associated with a given position
*	@pre - The current position is valid.
*	@post - Either the stack (dfs) or queue (bfs) is loaded with valid moves from the current
*		 position.
*	@return - void
*/
		void storeValidMoves();
		

/**	This method changes the current position and updates members appropriately.
*	@pre - The position is valid.
*	@post - The current position is set to p and the position is updated as marked.
*	@return - void
*/
		void move(Position&p);

/**
*	@pre - A valid maze exists
*	@post - checks the current character in m_maze.
*	@return - True if the current position has value 'E', false otherwise.
*/		
		bool isGoalReached() const;

/**	This method is a helper that prints out the visited block, effectively showing what the mazewalker
*	can see at any time
*	@pre - m_visited is valid and properly initialized, rows and cols are accurate to dimensions
*	@post - prints the array as a grid
*	@return - void
*/
	void printMaze(bool** arr, int rows, int cols);

		
		bool m_isDFS;
		char** m_maze;//populated by the reader, holds path values
		bool** m_visited;//keeps track of where you've been
		int m_rows;
		int m_cols;
		Position m_curPos;
		Position m_startPos;

		std::stack<Position> m_moveStack;
		std::queue<Position> m_moveQueue;
};

#endif
