#ifndef		BOX_HH_
# define	 BOX_HH_

#include	"Wrap.hh"

class	Box : public Wrap {
public :
  Box();
  ~Box();

  std::string	getTitle();
};


#endif	/* !BOX_HH_ */
