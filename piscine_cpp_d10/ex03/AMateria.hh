#ifndef		AMATERIA_H_
#define		AMATERIA_H_

#include	<string>
#include	<iostream>

#include	"ICharacter.hh"

class ICharacter;

class AMateria {
protected:
  std::string		_type;
  unsigned int		_xp;

public:
  AMateria(std::string const&);
  ~AMateria();

  std::string const&	getType() const;
  unsigned int		getXP() const;

  virtual AMateria*	clone() const = 0;
  virtual void		use(ICharacter & target);
  virtual void		useMateria(ICharacter & target);
};

#endif
