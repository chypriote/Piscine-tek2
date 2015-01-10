//
// Box.cpp for ch3 in /home/enjalb_p/project/rush/rush2
// 
// Made by Pierre Enjalbert
// Login   <enjalb_p@epitech.net>
// 
// Started on  Sat Jan 18 12:53:40 2014 Pierre Enjalbert
// Last update Sun Jan 19 01:24:36 2014 Nicolas Temenides
//

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
