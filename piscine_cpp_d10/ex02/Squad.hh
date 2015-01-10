#ifndef		SQUAD_H_
#define		SQUAD_H_

#include	<string>
#include	<iostream>

#include	"ISquad.hh"
#include	"ISpaceMarine.hh"

class Squad : public ISquad {
protected:
  int		_count;
  int		_size;
  ISpaceMarine **_unit;
  
public:
  Squad();
  Squad(Squad const&);
  virtual ~Squad();
  
  int		getCount() const;
  ISpaceMarine	*getUnit(int);
  int		push(ISpaceMarine *);
  
protected:
  void		resizeUnit();

};

#endif
