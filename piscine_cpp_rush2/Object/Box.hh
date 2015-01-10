//
// Box.hh for ch3 in /home/enjalb_p/project/rush/rush2
// 
// Made by Pierre Enjalbert
// Login   <enjalb_p@epitech.net>
// 
// Started on  Sat Jan 18 10:40:26 2014 Pierre Enjalbert
// Last update Sun Jan 19 01:22:13 2014 Nicolas Temenides
//

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
