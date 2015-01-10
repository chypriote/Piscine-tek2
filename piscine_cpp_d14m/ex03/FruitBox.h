#ifndef		FRUITBOX_H_
#define		FRUITBOX_H_

#include	"Fruit.h"
#include	"FruitNode.h"

class	FruitBox {
 protected:
  int		_size;
  int		_nbfruit;
  FruitNode*	_head;

 public:
  FruitBox(int);
  virtual ~FruitBox();
  
  int		nbFruits() const;
  FruitNode*	head() const;

  bool		putFruit(Fruit*);
  Fruit*	pickFruit();
  void		dump();
};

#endif
