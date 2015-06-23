#include <iostream>
#include <string>

#include "LittlePony.hh"

/**************** INIT ****************/

LittlePony::LittlePony(std::string title): Toy(title) {
  _type = PONY;
}

LittlePony::LittlePony(LittlePony const &poney): Toy(poney.title)
{ }



/***************** DESTROY *************/

LittlePony::~LittlePony()
{ }


/************** FUNCTIONS ***********/

LittlePony*		LittlePony::operator=(LittlePony const &poney)
{
  return new LittlePony(poney);
}

void		LittlePony::isTaken() {
  std::cout << "yo man" << std::endl; }
