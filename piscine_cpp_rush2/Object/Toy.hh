//
// Toy.hh for  in /home/gros_j/semestre3/piscine/rush2
// 
// Made by jeremy gros
// Login   <gros_j@epitech.net>
// 
// Started on  Sat Jan 18 11:54:48 2014 jeremy gros
// Last update Sun Jan 19 00:17:46 2014 Nicolas Temenides
//

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
