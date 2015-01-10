//
// LittlePony.hh for  in /home/gros_j/semestre3/piscine/rush2
// 
// Made by jeremy gros
// Login   <gros_j@epitech.net>
// 
// Started on  Sat Jan 18 12:51:51 2014 jeremy gros
// Last update Sun Jan 19 00:01:22 2014 Nicolas Temenides
//

#ifndef		__LITTLEPONY_HH_
#define		 __LITTLEPONY_HH_


#include	"Toy.hh"

class	LittlePony : public Toy
{
public:
  LittlePony(std::string);
  LittlePony(LittlePony const &);
  ~LittlePony();

  LittlePony*	operator=(LittlePony const&);
  void		isTaken();
};

#endif
