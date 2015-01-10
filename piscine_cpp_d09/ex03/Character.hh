#ifndef		CHARACTER_H_
#define		CHARACTER_H_

#include	<string>
#include	<iostream>

typedef	enum	AttackRange {
  r_CLOSE,
  r_RANGE
}	AttackRange;

class Character {
public:
  static const	AttackRange CLOSE = r_CLOSE;
  static const	AttackRange RANGE = r_RANGE;

  AttackRange	Range;

protected:
  //infos
  std::string	_name;
  std::string	_race;
  int		_level;
  int		_pv;
  int		_power;
  std::string	_weaponName;
  //caracs
  int		_strength;
  int		_stamina;
  int		_intelligence;
  int		_spirit;
  int		_agility;
  //numbers
  int		_costClose;
  int		_costRange;
  int		_dmgClose;
  int		_dmgRange;
  int		_pvRestore;
  int		_powerRestore;
  int		_maxPv;
  int		_maxPower;
  int		_null;
  int		Character::*_statClose;
  int		Character::*_statRange;
  int		Character::*_statPower;

public:
  explicit Character(std::string name, int level);
  ~Character();

public:
  //infos getters
  std::string const	&getName() const;
  int			getLvl() const;
  int			getPv() const;
  int			getPower() const;
  //caracs getters
  int			getStrength() const;
  int			getStamina() const;
  int			getIntelligence() const;
  int			getSpirit() const;
  int			getAgility() const;
  //combat
  int			CloseAttack();
  int			RangeAttack();
  void			Heal();
  void			RestorePower();
  void			TakeDamage(int);

protected:
  //say
  virtual void			sayCreation();
  virtual void			sayNoPower();
  virtual void			sayOutCombat();
  virtual void			sayCloseAttack();
  virtual void			sayRangeAttack();
  virtual void			sayPvRestore();
  virtual void			sayPowerRestore();
  virtual void			sayTakeDamage(int);
};

#endif
