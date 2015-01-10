#include	"Ice.hh"

Ice::Ice() : AMateria("ice") { }

Ice::Ice(Ice const & ice): AMateria("ice") {
  this->_xp = ice._xp; }

Ice::~Ice() { }

AMateria*	 Ice::clone() const {
  return new Ice(*this); }

void		Ice::useMateria(ICharacter& user) {
  std::cout << "* shoots an ice bolt at " << user.getName() << " *" << std::endl; }
