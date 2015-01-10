#ifndef		MATERIASOURCE_H_
#define		MATERIASOURCE_H_

#include	<string>
#include	<iostream>

#include	"AMateria.hh"
#include	"IMateriaSource.hh"

class MateriaSource : public IMateriaSource {
protected:
  AMateria	*_inventory[4];

public:
  MateriaSource();
  ~MateriaSource();

  virtual void		learnMateria(AMateria *);
  virtual AMateria*	createMateria(std::string const&);
};

#endif
