/**
*	@file : MazeWalker.cpp
*	@author :  Stephen Longofono - 2776831
*	@date : 04 - 19 - 2015
*	Purpose: Implementation of MazeWalker.h
*/

#include "MazeWalker.h"

MazeWalker::MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs){

	m_visited = new bool*[rows];

	for(int i = 0; i<rows; i++){
		m_visited[i] = new bool[cols];
		for(int j = 0; j<cols; j++){
			m_visited[i][j] = false;
		}
	}
	m_visited[startRow][startCol] = true;
	m_curPos.setRow(startRow);
	m_curPos.setCol(startCol);
	m_startPos.setRow(startRow);
	m_startPos.setCol(startCol);
	m_isDFS = dfs;
	m_rows = rows;
	m_cols = cols;
	m_maze = mazePtr;

}

MazeWalker::~MazeWalker(){

	for(int i = 0; i< m_rows; i++){
		delete [] m_visited[i];
	}
	delete [] m_visited;
	while(!m_moveQueue.empty()){
		m_moveQueue.pop();
	}
	while(!m_moveStack.empty()){
		m_moveStack.pop();
	}

}

void MazeWalker::walkMaze(){

	bool notDone = true;
	bool success = false;

	while(notDone){
		storeValidMoves();
		if(isGoalReached()){
			notDone = false;
			success = true;
		}
		else{
			if(m_isDFS){
				if(m_moveStack.empty()){
					notDone = false;
				}
				else{
					move(m_moveStack.top());
				}		
			}
			else{
		
				if(m_moveQueue.empty()){
					notDone = false;
				}
				else{
					move(m_moveQueue.front());
				}		

			}
		}

	}

	if(success){
		std::cout<<"Exit Found!\n";
	}
	else{
		std::cout<<"No way out!\n";
	}


}//runs the algo

void MazeWalker::storeValidMoves(){

	//check right
	if((m_curPos.getCol()+1)<m_cols){//if within bounds
		 //if not visited
		if(!(m_visited[m_curPos.getRow()][m_curPos.getCol()+1])){

			if(m_maze[m_curPos.getRow()][(m_curPos.getCol()+1)]=='P' ||
				m_maze[m_curPos.getRow()][m_curPos.getCol()+1]=='E'){
	
				if(m_isDFS){	
					Position temp(m_curPos.getRow(), m_curPos.getCol()+1);
					m_moveStack.push(temp);
				}
				else{
					Position temp(m_curPos.getRow(), m_curPos.getCol()+1);
					m_moveQueue.push(temp);
				}
			}
		}
	}


	//check down

	if((m_curPos.getRow()+1)<m_rows){//if within bounds
		 //if not visited
		if(!(m_visited[m_curPos.getRow()+1][m_curPos.getCol()])){
			if(m_maze[m_curPos.getRow()+1][m_curPos.getCol()]=='P' ||
				m_maze[m_curPos.getRow()+1][m_curPos.getCol()]=='E'){
				if(m_isDFS){
					Position temp(m_curPos.getRow()+1, m_curPos.getCol());
					m_moveStack.push(temp);
				}
				else{
					Position temp(m_curPos.getRow()+1, m_curPos.getCol());
					m_moveQueue.push(temp);
				}
			}
		}

	}

	//check left

	if((m_curPos.getCol()-1)>=0){//if within bounds
		 //if not visited
		if(!(m_visited[m_curPos.getRow()][m_curPos.getCol()-1])){
			if(m_maze[m_curPos.getRow()][m_curPos.getCol()-1]=='P' ||
				m_maze[m_curPos.getRow()][m_curPos.getCol()-1]=='E'){
				if(m_isDFS){
					Position temp(m_curPos.getRow(), m_curPos.getCol()-1);
					m_moveStack.push(temp);
				}
				else{
					Position temp(m_curPos.getRow(), m_curPos.getCol()-1);
					m_moveQueue.push(temp);
				}
			}
		}

	}


	//check up
	if((m_curPos.getRow()-1)>=0){//if within bounds
		 //if not visited
		if(!(m_visited[m_curPos.getRow()-1][m_curPos.getCol()])){
			if(m_maze[m_curPos.getRow()-1][m_curPos.getCol()]=='P' ||
				m_maze[m_curPos.getRow()-1][m_curPos.getCol()]=='E'){
				if(m_isDFS){
					Position temp(m_curPos.getRow()-1, m_curPos.getCol());
					m_moveStack.push(temp);
				}
				else{
					Position temp(m_curPos.getRow()-1, m_curPos.getCol());
					m_moveQueue.push(temp);
				}
			}
		}

	}

}//check all adjacents and load up the ADT

void MazeWalker::move(Position& p){//change position, update visited, pop move
	printMaze(m_visited, m_rows, m_cols);	
	m_curPos.setRow(p.getRow());
	m_curPos.setCol(p.getCol());
	m_visited[m_curPos.getRow()][m_curPos.getCol()] = true;
	std::cout<<"Visiting position: "<<m_curPos.getRow()<<", "<<m_curPos.getCol()<<"\n";
	std::cout<<"--------------------------\n\n";
	
	if(m_isDFS){
		m_moveStack.pop();
	}
	else{
		m_moveQueue.pop();
	}
	
}

bool MazeWalker::isGoalReached() const{//check after validating array bounds

	if(m_maze[m_curPos.getRow()][m_curPos.getCol()]=='E'){		
		return true;
	}
	return false;	

}

void MazeWalker::printMaze(bool** arr, int rows, int cols){


	for(int i = 0; i< rows; i++){
		for(int j = 0; j<cols; j++){
			std::cout<<arr[i][j]<<" ";
		}
		std::cout<<"\n";
	}

}


