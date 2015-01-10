#ifndef		RATATOUILLE_H_
#define		RATATOUILLE_H_

#include	<string>
#include	<sstream>
#include	<iostream>

class	Ratatouille {
 protected:
  std::string		flux;

 public:
  Ratatouille();
  Ratatouille(const Ratatouille&);
  virtual ~Ratatouille();
  Ratatouille&		operator=(const Ratatouille&);

  Ratatouille&		addVegetable(unsigned char);
  Ratatouille&		addCondiment(unsigned int);
  Ratatouille&		addSpice(double);
  Ratatouille&		addSauce(const std::string &);

  std::string kooc();
};

#endif
