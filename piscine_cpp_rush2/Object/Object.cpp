//
// Object.cpp for  in /home/gros_j/semestre3/piscine/rush2
// 
// Made by jeremy gros
// Login   <gros_j@epitech.net>
// 
// Started on  Sat Jan 18 11:17:14 2014 jeremy gros
// Last update Sun Jan 19 00:16:03 2014 Nicolas Temenides
//

#include	<iostream>
#include	<string>

#include	"Object.hh"


/************* INIT *****************/

Object::Object() : is_wrap(false) { 
  _type = UNKNOWN; }

Object::Object(Object const &obj) {
  is_wrap = obj.is_wrap; 
  _type = obj._type;
}

Object::~Object()
{ }


/****************GET FUNCTIONS*********/

bool		Object::isWrapped() const {
  return is_wrap; }

type		Object::getType() const {
  return _type; }

void		Object::setWrapped(bool wrap) {
  is_wrap = wrap; }
