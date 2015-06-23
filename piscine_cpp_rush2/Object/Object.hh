#ifndef		OBJECT_H_
#define		OBJECT_H_

#include	<string>
#include	<iostream>

#include	"../verbose.h"

typedef	enum	type {
  rBOX,
  rGIFTPAPER,
  rTEDDY,
  rPONY,
  rUNKNOWN
}		type;

class	Object {
public:
  static const type BOX = rBOX;
  static const type GIFTPAPER = rGIFTPAPER;
  static const type TEDDY = rTEDDY;
  static const type PONY = rPONY;
  static const type UNKNOWN = rUNKNOWN;

protected:
  bool		is_wrap;
  type		_type;

public:
  Object();
  Object(Object const &);
  virtual ~Object();

  bool		isWrapped() const;
  void		setWrapped(bool);
  type		getType() const;

  //Toys
  virtual std::string	getTitle() = 0;
  virtual Object**	MyUnitTests() = 0;
  virtual void		isTaken() = 0;

  //Wraps
  virtual bool		isOpen() = 0;
  virtual void		openMe() = 0;
  virtual void		closeMe() = 0;
  virtual Object*	MyUnitTests(Object **) = 0;
  virtual Object*	getObject() = 0;
  virtual bool		wrapMeThat(Object *) = 0;
};

#endif
