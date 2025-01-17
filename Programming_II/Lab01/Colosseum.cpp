/**
*	@file : Colosseum.cpp
*	@author :  Stephen Longofono
*	@date : 2014.01.28
*	Purpose: Implementation of Colosseum Class
*/

#include <iostream>
#include <string>
#include "Colosseum.h"
#include "Pokemon.h"
#include "Dice.h"

Colosseum::Colosseum(){
	Dice d20(20);	//new Dice object named 'd20' with 20 sides
	Dice d6(6);
}

void Colosseum::userBuild(Pokemon& p){
	std::cout<<"================================\n";
	int h = 0;	//for checking input
	int tempAttack = 0;	//for checking that attack+defense is <=50
	

	std::cout<<"Please name your Pokemon:";
	std::string nameIn;	
	std::cin>> nameIn;
	
	p.setName(nameIn);
	
	while(h<=0){
		std::cout<<"How many hit points will it have? (1-50):";
		std::cin>>h;		
		if((h<=0)||(h>50)){
			std::cout<<"Sorry. The hit points should be between 1 and 50.\n";
			h = 0;
		}
		
	}
	
	p.setHP(h);
	h=0;

	std::cout<<"Split fifty points between attack level and defense level: ";
	std::cout<<"Enter your attack level: (1-49)";

	while(h<=0){
		std::cin>>h;		
		if((h<=0)||(h>49)){
			std::cout<<"Sorry. The attack level must be between 1 and 49:";
			h = 0;
		}
		else{
			tempAttack = h;
		}
	}

	std::cout<<"Enter your defense level: (1-"<<(50-tempAttack)<<")";
	h=0;

	while(h<=0){
		std::cin>>h;
		if((h<=0)||((h+tempAttack)>50)){
			std::cout<<"Sorry.  The defense level must be between 1 and "<<(50-tempAttack)<<":";
			h = 0;
		}
	}
	
	p.setAttack(tempAttack);
	
	p.setDefense(h);
	

}//end userBuild

/**
*Here, note use of the const flag and the & reference flags.  The reference flags indicate that this method is
*directly accessing the object parameters where they are stored (ie not passing a copy).  In the case of the
*attacker, the const flag ensures that the object is not modified by restricting the member methods it can
*access.
*/
bool Colosseum::attack(const Pokemon& attacker, Pokemon& defender){

	//Music::LedZeppelin(play);
	std::cout<<attacker.getName()<<" is attacking "<<defender.getName()<<"\n";
	int atkBonRoll = d20.roll();
	int defBonRoll = d20.roll();
	std::cout<<attacker.getName()<<" rolls an attack bonus of "<<atkBonRoll<<"\n";
	std::cout<<defender.getName()<<" rolls a defense bonus of "<<defBonRoll<<"\n";
	
	int tempAtk = (attacker.getAttack() + atkBonRoll);
	int tempDef = (defender.getDefense() + defBonRoll);
	if(tempAtk > tempDef){
		
		std::cout<<"The attack hits, dealing 3D6 damage!\n";
		int dam1 = d6.roll();
		int dam2 = d6.roll();
		int dam3 = d6.roll();
		int sumDam = (dam1 + dam2 + dam3);
		std::cout<<"The rolls are "<<dam1<<", "<<dam2<<", and "<<dam3<<", totaling : "<<sumDam
<<" damage!\n";
		
		defender.reduceHP(sumDam);
		std::cout<<defender.getName()<<" has "<<defender.getHP()<<" hitpoints left\n";
		if(defender.getHP() <= 0){
			std::cout<<defender.getName()<<" has been defeated!\n\n";
			return true;	//he dead
		}
		else{
			return false;   //he fine
		}
	}
	else{
		std::cout<<"The attack missed!\n";
		return false;
	}
	
	return false;  //this is a catchall in case something doesn't go as planned
	

}//end attack

/**
*Notes for this mess:
*The play method handles the round display per the spec.  The attack method handles all the attack and defeat
*dialogue, so all the play method needs to know is whether or not it should cue another round.  This allows a
*more efficient way to fork this method based on the outcome of the initiative roll.
*/


void Colosseum::play(Pokemon& p1, Pokemon& p2){
	
	int round = 0;
	Dice d2(2);
	int choice = d2.roll();
	std::cout<<"Determining which player will go first:\n";
	if(choice == 0){
		std::cout<<"Player 1 will go first.\n\n";
		while(round<11){
			
			round ++;
			std::cout<<"\nRound "<<round<<"!\n\n";
			if(attack(p1, p2)){
				return;
			}

			if(attack(p2, p1)){
				return;
			}

		}//end while
	}
	else{
		std::cout<<"Player 2 will go first.\n\n";
		while(round<11){

			round++;
			std::cout<<"\n\nRound "<<round<<"!\n\n";

			if(attack(p2,p1)){
				return;
			}

			if(attack(p1,p2)){
				return;
			}

		}//end while
	}

	return;  //another catchall so I don't block here

}//end play
