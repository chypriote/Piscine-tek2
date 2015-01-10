#ifndef		CONVEYORBELT_H_
#define		CONVEYORBELT_H_

#include	"IConveyorBelt.hh"

class	ConveyorBelt : public IConveyorBelt {
protected:
  Object*	_object;

public:
  ConveyorBelt();
  ~ConveyorBelt();

  Object*	getObject();

  bool		put(Object *);
  Object*	take();
  std::string	look();
  Wrap*		IN();
  void		OUT();
};

#endif
