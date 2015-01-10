#ifndef		FRUIT_H_
#define		FRUIT_H_

#include	<string>
#include	<iostream>

class	Fruit {
 protected:
  int		_vitamins;
  std::string	_name;

 public:
  Fruit();
  Fruit(int, std::string const&);

  int			getVitamins() const;
  std::string const&	getName() const;
};

#endif
