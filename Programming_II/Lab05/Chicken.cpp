/**
*	@file : Chicken.cpp
*	@author :  Stephen Longofono
*	@date : 03-04-2015
*	Purpose: Implementation of the Chicken class
*/
#include "FarmAnimal.h"
#include "Chicken.h"


Chicken::Chicken(): FarmAnimal(){
	setName("Chicken");
	setSound("Cluck.");
}

int Chicken::getEggs() const{
	return m_eggs;
}

void Chicken::setEggs(int eggs){
	m_eggs = eggs;
}
