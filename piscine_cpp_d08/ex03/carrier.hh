#ifndef		CARRIER_H_
#define		CARRIER_H_

#include	<string>
#include	<iostream>
#include	"droid.hh"

class Carrier {
private:
  std::string	Id;
  size_t	Energy;
  size_t const	Attack;
  size_t const	Toughness;
  size_t	Speed;
  Droid		**Droids;

public:
  Carrier(std::string id);
  ~Carrier();

  std::string	getId() const;
  size_t	getEnergy() const;
  size_t	getAttack() const;
  size_t	getToughness() const;
  size_t	getSpeed() const;
  size_t	getNbDroids() const;

  void		setId(std::string);
  void		setEnergy(size_t);
  
  Carrier&	operator<<(Droid *);
  Carrier&	operator>>(Droid *);
  Carrier&	operator<<(size_t&);
  Carrier&	operator~();
  Droid*&	operator[](int) const;
};

std::ostream& operator<<(std::ostream&, Carrier const&);

#endif
