#ifndef		USERINFO_DISPLAY_H_
#define		USERINFO_DISPLAY_H_

#include	"ADisplay.hpp"

class	UserInfoDisplay : public ADisplay {
public:
  UserInfoDisplay() {}
  ~UserInfoDisplay() {}

  void		showCurses();
};

#endif	/*	USERINFO_DISPLAY_H_	*/
