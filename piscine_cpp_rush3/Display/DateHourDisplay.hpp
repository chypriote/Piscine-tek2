#ifndef		DATEHOUR_DISPLAY_H_
#define		DATEHOUR_DISPLAY_H_

#include	"ADisplay.hpp"

class	DateHourDisplay : public ADisplay {
public:
  DateHourDisplay() {}
  ~DateHourDisplay() {}

  void		showCurses();
};

#endif	/*	DATEHOUR_DISPLAY_H_	*/
