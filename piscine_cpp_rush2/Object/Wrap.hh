//
// Wrap.hh for ch3 in /home/enjalb_p/project/rush/rush2
// 
// Made by Pierre Enjalbert
// Login   <enjalb_p@epitech.net>
// 
// Started on  Sat Jan 18 10:11:33 2014 Pierre Enjalbert
// Last update Sun Jan 19 01:25:39 2014 Nicolas Temenides
//

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
