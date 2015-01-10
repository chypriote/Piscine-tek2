#ifndef		HUNTER_H_
#define		HUNTER_H_

#include	"Character.hh"

class Hunter : public Character {
protected:
  Hunter();
public:

  explicit Hunter(std::string const& name, int level);
  ~Hunter();

  virtual int	RangeAttack();
protected:  
  void		sayCreation();
  void		sayCloseAttack();
  void		sayRangeAttack();
  void		sayPowerRestore();
  void		sayHeal();
};

#endif
