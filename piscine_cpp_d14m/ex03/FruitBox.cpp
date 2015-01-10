#include	"FruitBox.h"

FruitBox::FruitBox(int size): _size(size), _nbfruit(0), _head(NULL) {}

FruitBox::~FruitBox() {}

int		FruitBox::nbFruits() const {
  return _nbfruit; }

FruitNode*	FruitBox::head() const {
  return _head; }

bool		FruitBox::putFruit(Fruit* f) {
  if (_nbfruit < _size) {
    FruitNode*	current = _head;
    FruitNode*	node = new FruitNode();

    node->_fruit = f;
    if (!_head)
      _head = node;
    else {
      while (current->next)
	current = current->next;
      current->next = node;
    }
    _nbfruit++;
    return true;
  }
  return false;
}

Fruit*		FruitBox::pickFruit() {
  if (_nbfruit) {
    Fruit*	fruit = _head->_fruit;
    _head = _head->next;
    _nbfruit--;
    return fruit;
  }
  return NULL;
}

void            FruitBox::dump() {
  FruitNode     *current = _head;

  if (_head) {
    while (current->next) {
      std::cout << current->_fruit->getName() << std::endl;
      current = current->next;
    }
    std::cout << current->_fruit->getName() << std::endl;
    std::cout << std::endl;
  }
  else
    std::cout << "vide" << std::endl << std::endl;;
}
