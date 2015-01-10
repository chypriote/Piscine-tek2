//
// Teddy.hh for  in /home/gros_j/semestre3/piscine/rush2
// 
// Made by jeremy gros
// Login   <gros_j@epitech.net>
// 
// Started on  Sat Jan 18 12:16:01 2014 jeremy gros
// Last update Sun Jan 19 00:01:37 2014 Nicolas Temenides
//

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
