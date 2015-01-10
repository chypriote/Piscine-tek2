#include		"Cure.hh"

Cure::Cure() : AMateria("cure") { }

Cure::Cure(Cure const& cure) : AMateria("cure") {
  this->_xp = cure._xp; }

Cure::~Cure() { }

AMateria*	Cure::clone() const {
  return new Cure(*this); }

void		Cure::useMateria(ICharacter& user) {
  std::cout << "* heals " << user.getName() << "'s wounds *" << std::endl; }
