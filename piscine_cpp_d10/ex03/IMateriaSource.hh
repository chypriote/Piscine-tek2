#ifndef		IMATERIASOURCE_H_
#define		IMATERIASOURCE_H_

#include	<string>

class IMateriaSource {
public:
  virtual ~IMateriaSource() {}
  
  virtual void		learnMateria(AMateria*) = 0;
  virtual AMateria*	createMateria(std::string const&) = 0;
};

#endif
