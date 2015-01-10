#include	"AssaultTerminator.hh"

AssaultTerminator::AssaultTerminator() {
  std::cout << "* teleports from space *"<< std::endl; }

AssaultTerminator::AssaultTerminator(AssaultTerminator const& marine) {
  (void) marine;
  std::cout << "* teleports from space *"<< std::endl;
}

AssaultTerminator::~AssaultTerminator() {
  std::cout << "I'll be back ..."<< std::endl; }

//-------------------------AssaultTerminator: functions-------------------------------//

ISpaceMarine*	AssaultTerminator::clone() const {
  return new AssaultTerminator(*this); }

void		AssaultTerminator::battleCry() const {
  std::cout << "This code is unclean. PURIFY IT !"<< std::endl; }

void		AssaultTerminator::rangedAttack() const {
  std::cout << "* does nothing *"<< std::endl; }

void		AssaultTerminator::meleeAttack() const {
  std::cout << "* attacks with chainfists *"<< std::endl; }
