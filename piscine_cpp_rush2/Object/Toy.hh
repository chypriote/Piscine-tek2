#ifndef		 __TOY_HH_
# define	 __TOY_HH_

#include	 "Object.hh"

class	Toy : public Object
{
protected:
  std::string	title;

public:
  Toy(std::string);
  ~Toy();

  Toy(Toy const &);
  virtual std::string	getTitle();
  virtual Object**	MyUnitTests();
  virtual void		isTaken() = 0;

  //Useless
  virtual bool		isOpen();
  virtual void		openMe();
  virtual void		closeMe();
  virtual Object*	MyUnitTests(Object**);
  virtual Object*	getObject();
  virtual bool		wrapMeThat(Object *);
};

#endif
