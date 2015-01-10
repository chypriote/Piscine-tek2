#include	"Mixer.h"

Mixer::Mixer() {
  _plugged = false;
  _mixfunc = 0;
}

Mixer::~Mixer() {}

void	Mixer::plugIN() {
  if (!_plugged)
    _plugged = true;
  _mixfunc = &mixage;
}

int	mixage(FruitBox& box) {
  if (box.nbFruits()) {
    FruitNode	*current = box.head();
    int		vita = 0;

    if (!current)
      return 0;
    else {
      while (current->next) {
	vita += current->_fruit->getVitamins();
	current = current->next;
      }
      vita += current->_fruit->getVitamins();
      return vita;
    }
  }
  return 0;
}
