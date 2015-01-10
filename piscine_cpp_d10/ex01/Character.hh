#ifndef		CHARACTER_H_
#define		CHARACTER_H_

#include	<iostream>
#include	<string>

#include	"AWeapon.hh"
#include	"AEnemy.hh"

class Character
{
private:
  std::string		_name;
  int			_ap;
  AWeapon*		_weapon;

public:
  Character(std::string const&);
  ~Character();


  std::string const	getName() const;
  int			getAp() const;
  AWeapon*		getWeapon() const;

  void			recoverAP();
  void			equip(AWeapon *);
  void			attack(AEnemy *);
};

std::ostream&		operator<<(std::ostream&, Character const&);

#endif
