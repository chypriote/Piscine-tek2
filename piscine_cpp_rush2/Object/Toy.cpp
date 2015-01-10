//
// Toy.cpp for  in /home/gros_j/semestre3/piscine/rush2
// 
// Made by jeremy gros
// Login   <gros_j@epitech.net>
// 
// Started on  Sat Jan 18 12:08:31 2014 jeremy gros
// Last update Sun Jan 19 03:54:36 2014 Nicolas Temenides
//

#include <iostream>
#include <string>

#include	"Toy.hh"
#include	"LittlePony.hh"
#include	"Teddy.hh"

/*********** INIT *********************/

Toy::Toy(std::string Title): Object()
{ 
  title = Title;
  is_wrap = false;
}

Toy::Toy(Toy const &toy) : Object(toy)
{ 
  title = toy.title;
  is_wrap = false;
}

/************* DESTTROY ****************/

Toy::~Toy() { }


/************* FUNCTIONS *****************/

std::string     Toy::getTitle() {
  return title; }

Object**	Toy::MyUnitTests() {
  Object **tab = new Object*[2];

  tab[0] = new LittlePony("gay pony");
  tab[1] = new Teddy("bisounours");
  return tab;
}

Object*		Toy::MyUnitTests(Object **obj) { (void) obj; return NULL; }
void		Toy::openMe() {}
void		Toy::closeMe() {}
bool		Toy::isOpen() {return true;}
Object*		Toy::getObject() {return NULL;}
bool		Toy::wrapMeThat(Object *) {return true;}
