#ifndef		NETWORK_DISPLAY_H_
#define		NETWORK_DISPLAY_H_

#include	"ADisplay.hpp"

class	NetworkDisplay : public ADisplay {
public:
  NetworkDisplay() {}
  ~NetworkDisplay() {}

  void		showCurses();
};

#endif	/*	NETWORK_DISPLAY_H_	*/
