#ifndef		AWEAPON_H_
#define		AWEAPON_H_

#include	<iostream>
#include	<string>

class AWeapon {
private:
  std::string		_name;
  int			_apcost;
  int			_damage;
public:
  AWeapon(std::string const&, int, int);
  ~AWeapon();

public:
  std::string const&	getName() const;
  int			getAPCost() const;
  int			getDamage() const;
  virtual void		attack() const = 0;

};

#endif
