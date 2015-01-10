//
// Teddy.cpp for  in /home/gros_j/semestre3/piscine/rush2
// 
// Made by jeremy gros
// Login   <gros_j@epitech.net>
// 
// Started on  Sat Jan 18 12:19:57 2014 jeremy gros
// Last update Sun Jan 19 00:51:55 2014 Nicolas Temenides
//


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
