/**
*	@file : Colsseum.h
*	@author :  Stephen Longofono
*	@date : 2014.01.28
*	Purpose: Header Colosseum Class - This is effectively the driver for the game, it handles the
*	flow of the game and passes control back to main when an endgame condition is met (10 rounds or
*	dead pokemon).
*/

#ifndef COLOSSEUM_H
#define COLOSSEUM_H
#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Dice.h"

class Colosseum{

	public:


	/**
	*@pre: none
	*@post: Constructor, inits two dice objects for use in the attack method
	*@return: creates two dice objects and returns a colosseum object	
	*/
	Colosseum();


	/**
	*@pre: a Pokemon object
	*@post: This method populates all of the members of the argument from user input.  It filters
	*for proper input as follows: m_name must be non-empty string, m_hp in [1,50], (m_attackLevel + 	*m_defenseLevel) in [1,50]
	*@return: void	
	*/
	void userBuild(Pokemon& p);
	
	/**
	*@pre: two Pokemon objects, both run through the userBuild method
	*@post: This method handles the attack for the first argument on the second.  It will determine
 	*an attack and defense bonus for each respective fighter, determine if the attack was
	*successful(atk+atk bonus > def+def bonus), call the Pokemon.reduceHP method(decrement HP),
 	*and check if the defender died.  There are dice objects used to determine the bonuses and the
 	*damage passed to the reduceHP method.
	*@return: if the defender dies (hp>=0) return true, else return false	
	*/
	bool attack(const Pokemon& attacker, Pokemon&defender);

	/**
	*@pre: two Pokemon objects, both run through the userBuild method
	*@post: This method drives a single game.  It determines the order of play with a coin flip 	 	*(Dice method), and then calls attack for each Pokemon once per round, until ten rounds
	*are complete OR attack returns true.   
	*@return: to main
	*/
	void play(Pokemon& p1, Pokemon& p2);

	private:

	Dice d20;
	Dice d6;


};


#endif

