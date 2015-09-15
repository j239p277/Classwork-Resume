/**
*	@file : Chicken.h
*	@author :  Stephen Longofono
*	@date : 03-04-2015
*	Purpose: This class is a child of the FarmAnimal class.  It has the narrower traits of eggs but
*		does not allow setting and getting the eggs.  It inherits the public and
*		protected members of the FarmAnimal class
*	########NOTE - the setEggs() method does no filtering, per the specifications given.  This doesn't matter
*			here, but it will in the derived cyberchicken class
*/

#ifndef CHIX
#define CHIX
#include <string>
#include "FarmAnimal.h"

class Chicken: public FarmAnimal{

	protected:
		
	/*This method is a getter for the amount of eggs this chicken has
	*@pre - a Chicken object exists and m_eggs has been initialized
	*@post - retrieves the m_eggs member variable
	*@return - the value of m_eggs
	*/
		int getEggs() const;


	/*This method is a setter for the amount of eggs this chicken has
	*@pre - a Chicken object exists
	*@post - sets m_eggs to the argument passed in
	*@return - void
	*/
		void setEggs(int eggs);


		int m_eggs;

	public:

	/*This constructor sets the animal's name to "Chicken" and sound to "Cluck" using inherited setter methods
	*@pre - none
	*@post - calls this.setName("Chicken"), this.setSound("Cluck")
	*@return - none
	*/
		Chicken();

};

#endif
