#include	<string>
#include	<iostream>
#include	"Box.hh"

Box::Box() {
  is_open = true; 
  object = NULL;
  _type = BOX;
}

Box::~Box() { }

std::string	Box::getTitle() {
  return "a box"; }
