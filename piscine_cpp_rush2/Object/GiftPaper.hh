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
