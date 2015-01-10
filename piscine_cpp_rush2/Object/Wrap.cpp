//
// Wrap.cpp for ch3 in /home/enjalb_p/project/rush/rush2
// 
// Made by Pierre Enjalbert
// Login   <enjalb_p@epitech.net>
// 
// Started on  Sat Jan 18 11:11:16 2014 Pierre Enjalbert
// Last update Sun Jan 19 03:54:56 2014 Nicolas Temenides
//

#include	<string>
#include	<iostream>

#include	"Wrap.hh"
#include	"Box.hh"
#include	"GiftPaper.hh"


//Wrap: constructors-------------------------
Wrap::Wrap() : Object() {
  is_open = true;
  is_wrap = false; }

Wrap::Wrap(Wrap const &W): Object(W)
{
  is_open = W.is_open;
  is_wrap = W.is_wrap;
}

Wrap::~Wrap() { }

Wrap		*Wrap::operator=(Wrap const &W) {
  return new Wrap(W); }

//Wrap: functionss-------------------------
Object*		Wrap::getObject() {
  return object; }

bool		Wrap::wrapMeThat(Object *obj)
{
  if (obj->isWrapped()) {
    std::cout << "The object is already wrapped" << std::endl;
    return false;
  }
  if (!is_open) {
    std::cout << "The box is closed" << std::endl;
    return false;
  }
  if (object) {
    std::cout << "The wrapper is not empty !" << std::endl;
    return false;
  }
  obj->setWrapped(true);
  is_open = false;
  object = obj;
  std::cout << "tuuuut tuuut tuut" << std::endl;
  return true;
}

void		Wrap::closeMe() {
  if (!is_open)
    std::cout << "The box is already closed !" << std::endl;
  else
    is_open = false;
}

void		Wrap::openMe() {
  if (is_open)
    std::cout << "The box is already opened !" << std::endl;
  else
  is_open = true;
}

void		Wrap::isTaken() {
  std::cout << "whistles while working" << std::endl; }

bool		Wrap::isOpen() {
  return is_open; }

Object		*Wrap::MyUnitTests(Object **tab) {
  if (!tab[1]->isOpen())
    tab[1]->openMe();
  tab[1]->wrapMeThat(tab[0]);
  tab[2]->wrapMeThat(tab[1]);
  return tab[2];
}

Object		**Wrap::MyUnitTests() {return NULL;};
std::string	Wrap::getTitle() {return NULL;};
