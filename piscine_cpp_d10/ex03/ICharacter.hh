#ifndef		ICHARACTER_H_
#define		ICHARACTER_H_

#include	<string>
#include	<iostream>

#include	"AMateria.hh"

class AMateria;

class ICharacter {
public:
  virtual ~ICharacter() {}

  virtual std::string const&	getName() const = 0;
  virtual void			equip(AMateria*) = 0;
  virtual void			unequip(int) = 0;
  virtual void			use(int, ICharacter&) = 0;

};

#endif
