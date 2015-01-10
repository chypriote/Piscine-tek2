#ifndef		SUPERMUTANT_H_
#define		SUPERMUTANT_H_

#include	"AEnemy.hh"

class SuperMutant : virtual public AEnemy {
public:
  SuperMutant();
  ~SuperMutant();

  void	TakeDamage(int);
};

#endif
