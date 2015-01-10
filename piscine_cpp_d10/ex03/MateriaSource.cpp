#include		"MateriaSource.hh"

MateriaSource::MateriaSource() {
  int i = 0;
  while (i != 4)
    _inventory[i++] = NULL;
}

MateriaSource::~MateriaSource() { }

void		MateriaSource::learnMateria(AMateria* materia) {
  if (materia) {
    int i = 0;
    while (i != 4) {
      if (!_inventory[i]) {
	_inventory[i] = materia;
	return;
      }
      i++;
    }
  }
}

AMateria*	MateriaSource::createMateria(std::string const& type) {
  int i = 0;
  while (i != 4) {
    if (_inventory[i] && _inventory[i]->getType() == type)
      return _inventory[i]->clone();
    i++;
  }
  return NULL;
}
