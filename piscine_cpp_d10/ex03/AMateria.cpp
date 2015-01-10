#include		"AMateria.hh"

AMateria::AMateria(std::string const& type) : _type(type), _xp(0) { }

AMateria::~AMateria() { }

unsigned int		AMateria::getXP() const {
  return _xp; }

std::string const&	AMateria::getType() const {
  return _type; }

void		AMateria::use(ICharacter& user) {
  _xp += 10;
  useMateria(user);
}

void		AMateria::useMateria(ICharacter& user) {
  (void) user; }
