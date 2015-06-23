#ifndef		WRAP_HH_
#define		WRAP_HH_

#include	"Object.hh"

class	Wrap : public Object {
protected :
  bool		is_open;
  Object	*object;

public :
  Wrap();
  ~Wrap();

  Wrap(Wrap const &);
  Wrap*		operator=(Wrap const &);
  virtual Object*	getObject();
  virtual bool		wrapMeThat(Object *);
  virtual bool		isOpen();
  virtual void		openMe();
  virtual void		closeMe();
  virtual Object*	MyUnitTests(Object **);
  virtual void		isTaken();

  //Useless
  virtual Object**	MyUnitTests();
  virtual std::string	getTitle();
};


#endif	/* !WRAP_HH_ */
