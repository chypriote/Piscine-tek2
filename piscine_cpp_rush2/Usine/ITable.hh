#ifndef		ITABLE_H_
#define		ITABLE_H_

#include	<iostream>
#include	<string>

#include	"../Object/Object.hh"

class	ITable {
public:
  virtual ~ITable() {}

  virtual bool		put(Object *) = 0;
  virtual Object*	take() = 0;
  virtual Object*	take(int) = 0;
  virtual Object**	look() = 0;
};

#endif
