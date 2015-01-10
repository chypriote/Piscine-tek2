#ifndef		ICE_H_
#define		ICE_H_

#include	<string>
#include	<iostream>

#include	"AMateria.hh"
#include	"ICharacter.hh"

class Ice : public AMateria {
public:
  Ice();
  Ice(Ice const&);
  ~Ice();

  virtual AMateria*	clone() const;
  virtual void		useMateria(ICharacter&);

};

#endif
