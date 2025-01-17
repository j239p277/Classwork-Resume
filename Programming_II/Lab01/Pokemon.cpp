/**
*	@file : Pokemon.cpp
*	@author :  Stephen Longofono
*	@date : 2014.01.28
*	Purpose: Implementation of Pokemon Class
*/

#include <string>
#include "Pokemon.h"

Pokemon::Pokemon(){
	m_hp = 0;
	m_attackLevel = 0;
	m_defenseLevel = 0;
	m_name = "";
}

void Pokemon::reduceHP(int amount){
	m_hp -= amount;
}

//#######################################GETSET###########################################

int Pokemon::getHP() const{
	return m_hp;
}

int Pokemon::getAttack() const{
	return m_attackLevel;
}

int Pokemon::getDefense() const{
	return m_defenseLevel;
}

std::string Pokemon::getName() const{
	return m_name;
}

void Pokemon::setName(std::string nameIn){
	m_name = nameIn;
}

void Pokemon::setHP(int life){
	m_hp = life;
}

void Pokemon::setAttack(int attackLvl){
	m_attackLevel = attackLvl;
}

void Pokemon::setDefense(int defenseLvl){
	m_defenseLevel = defenseLvl;
}
//############################################################################################

