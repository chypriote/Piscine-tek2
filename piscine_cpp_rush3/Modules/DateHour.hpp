#ifndef		DATEHOUR_H_
#define		DATEHOUR_H_

#include	"AModule.hpp"
#include	"../Display/DateHourDisplay.hpp"

class	DateHour : public AModule {
public:
  DateHour();
  virtual ~DateHour();

  void		fillMap();
};

#endif
