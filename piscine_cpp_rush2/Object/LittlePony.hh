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
