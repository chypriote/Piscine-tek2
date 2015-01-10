#ifndef		PRIEST_H_
#define		PRIEST_H_

#include	"Mage.hh"

class Priest : public Mage {
protected:
  Priest();
public:

  explicit Priest(std::string const& name, int level);
  ~Priest();

  virtual int	CloseAttack();
  virtual void	Heal();
protected:  
  void		sayCreation();
  void		sayCloseAttack();
  void		sayRangeAttack();
  void		sayPvRestore();
};

#endif
