//
// Giftpaper.hh for ch3 in /home/enjalb_p/project/rush/rush2
// 
// Made by Pierre Enjalbert
// Login   <enjalb_p@epitech.net>
// 
// Started on  Sat Jan 18 11:08:48 2014 Pierre Enjalbert
// Last update Sun Jan 19 01:24:40 2014 Nicolas Temenides
//

#ifndef		GIFTPAPER_HH_
# define	GIFTPAPER_HH_

#include	"Wrap.hh"

class	GiftPaper : public Wrap {
public :
  GiftPaper();
  ~GiftPaper(); 

  std::string	getTitle();
};

#endif	/* !GIFTPAPER_HH_ */
