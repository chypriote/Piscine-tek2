#ifndef		CHARACTER_H_
#define		CHARACTER_H_

#include	<string>
#include	<iostream>

#include	"ICharacter.hh"
#include	"AMateria.hh"

class Character : public ICharacter {
protected:
  AMateria*		_inventory[4];
  std::string		_name;

public:
  Character(std::string const&);
  Character(Character const&);
  ~Character();

  virtual std::string const&	getName() const;
  virtual void			equip(AMateria*);
  virtual void			unequip(int);
  virtual void			use(int, ICharacter&);
};

#endif
