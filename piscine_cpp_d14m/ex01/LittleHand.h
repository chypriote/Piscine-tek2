#ifndef		LITTLEHAND_H_
#define		LITTLEHAND_H_

#include	"FruitBox.h"
//#include	"Mixer.h"

class	LittleHand {
public:
  static void	sortFruitBox(FruitBox&, FruitBox&, FruitBox&, FruitBox&);
  FruitBox* const* organizeCoconut(Fruit const * const *);
  //  static void	plugMixer(Mixer& mixer);
};

#endif
