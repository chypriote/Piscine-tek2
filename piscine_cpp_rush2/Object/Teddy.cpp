#include <iostream>
#include <string>

#include "Teddy.hh"

/******** INIT ****************/

Teddy::Teddy(std::string Title): Toy(Title) {
  _type = TEDDY; }

Teddy::Teddy(Teddy const &ted): Toy(ted)
{ }



/********** DESTROY ***********/

Teddy::~Teddy()
{ }


/*********** FUNCTIONS ***********/

Teddy*	Teddy::operator=(Teddy const &ted)
{
  return new Teddy(ted);
}

void	Teddy::isTaken() {
  std::cout << "gra hu" << std::endl; }
