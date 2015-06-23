#ifndef		__TEDDY_HH_
# define	__TEDDY_HH_

#include	"Toy.hh"

class	Teddy : public Toy {
public:
  Teddy(std::string);
  Teddy(Teddy const &);
  ~Teddy();

  Teddy*	operator=(Teddy const &);
  void		isTaken();
};

#endif
