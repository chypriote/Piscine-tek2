#include	"Character.hh"

Character::Character(std::string const& name) : _name(name) {
  int i = 0;
  while (i != 4)
    _inventory[i++] = NULL;
}

Character::Character(Character const& user) {
  _name = user._name;
  int i = 0;
  while (i != 4) {
    _inventory[i] = NULL;
    if (user._inventory[i])
      _inventory[i] = user._inventory[i]->clone();
    i++;
  }
}

Character::~Character() { }

std::string const&	Character::getName() const {
  return _name; }

void		Character::equip(AMateria* materia) {
  if (materia) {
    int i = 0;
    while (i != 4) {
      if (_inventory[i] == NULL) {
	_inventory[i] = materia;
	return;
      }
      i++;
    }
  }
}

void		Character::unequip(int idx) {
  if (idx >= 0 && idx < 4)
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& user) {
  if (idx >= 0 && idx < 4 && _inventory[idx] != NULL) {
    _inventory[idx]->use(user);
  }
}
