#include	"LittleHand.h"

void	LittleHand::sortFruitBox(FruitBox& unsorted, FruitBox& lemons, FruitBox& bananas, FruitBox& limes) {
  Fruit*	fruit;
  FruitBox	tmp(unsorted.nbFruits());
  
  while ((fruit = unsorted.pickFruit()))
    tmp.putFruit(fruit);
  while ((fruit = tmp.pickFruit())) {
    if (fruit->getVitamins() == 5)
      bananas.putFruit(fruit);
    else if (fruit->getVitamins() == 3)
      lemons.putFruit(fruit);
    else if (fruit->getVitamins() == 2)
      limes.putFruit(fruit);
    else
      unsorted.putFruit(fruit);
  }
}

FruitBox * const * LittleHand::organizeCoconut(Fruit const * const * coconuts_packet) {
  int	max = 6;
  int	i = 0;
  int	count = 0;
  int	id;

  while (coconuts_packet[count++]);
  count--;
  FruitBox ** box = new FruitBox*[count / max + 2];
  box[count / max + 1] = NULL;
  while (i < count) {
    id = i % max;
    if (!id)
      box[id] = new FruitBox(max);
    id = i / max;
    box[id]->putFruit(const_cast<Fruit *>(const_cast<Fruit * const *>(coconuts_packet)[i]));
    i++;
  }
  return box;
}

//void		LittleHand::plugMixer(Mixer& mixer) {
//  mixer.plugIN(); }
