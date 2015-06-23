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
