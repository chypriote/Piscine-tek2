#include "FruitBox.h"

FruitBox::FruitBox(int size): _size(size), _head(NULL) {}

FruitBox::~FruitBox() {
}

int		FruitBox::nbFruits() const {
  return _nbfruit; }

FruitNode*	FruitBox::head() const {
  return _head; }

bool		FruitBox::putFruit(Fruit * fruit) {
  if (_nbfruit < _size) {
    FruitNode * current = _head;
    FruitNode * node = new FruitNode();
    node->_fruit = fruit;
    if (!_head) {
      _head = node;
    }
    else {
      while (current->next) {
	if (current->_fruit == fruit) {
	  return false;
	}
	current = current->next;
      }
      current->next = node;
    }
    _nbfruit++;
    return true;
  }
  return false;
}

Fruit*		FruitBox::pickFruit() {
  if (_nbfruit) {
    Fruit * fruit = _head->_fruit;
    FruitNode * del = _head;
    _head = _head->next;
    delete del;
    _nbfruit--;
    return fruit;
  }
  return NULL;
}
