#ifndef		CURE_H_
#define		CURE_H_

#include	<string>
#include	<iostream>

#include	"AMateria.hh"
#include	"ICharacter.hh"

class Cure : public AMateria {
public:
  Cure();
  Cure(Cure const&);
  ~Cure();

  virtual AMateria*	clone() const;
  virtual void		useMateria(ICharacter&);
};

#endif
