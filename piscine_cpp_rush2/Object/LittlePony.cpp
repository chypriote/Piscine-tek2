//
// LittlePony.cpp for  in /home/gros_j/semestre3/piscine/rush2
// 
// Made by jeremy gros
// Login   <gros_j@epitech.net>
// 
// Started on  Sat Jan 18 12:42:13 2014 jeremy gros
// Last update Sun Jan 19 04:00:56 2014 Nicolas Temenides
//

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
