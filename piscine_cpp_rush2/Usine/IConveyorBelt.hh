#ifndef		ICONVEYORBELT_H_
#define		ICONVEYORBELT_H_

#include	<string>
#include	<iostream>
#include	<cstdlib>

#include	"../Object/Object.hh"
#include	"../Object/Box.hh"
#include	"../Object/GiftPaper.hh"

class	IConveyorBelt {
public:
  virtual ~IConveyorBelt() {}

  virtual bool		put(Object *) = 0;
  virtual Object	*take() = 0;
  virtual std::string	look() = 0;
};

#endif
