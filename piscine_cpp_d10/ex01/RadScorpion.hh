#ifndef		RADSCORPION_H_
#define		RADSCORPION_H_

#include	"AEnemy.hh"

class RadScorpion : virtual public AEnemy {
public:
  RadScorpion();
  ~RadScorpion();

  void	TakeDamage(int);
};

#endif
