#include	"SuperMutant.hh"

SuperMutant::SuperMutant() : AEnemy(170, "Super Mutant") {
  std::cout << "Gaaah. Me want smash heads !" << std::endl; }

SuperMutant::~SuperMutant() {
  std::cout << "Aaargh ..." << std::endl; }

void	SuperMutant::TakeDamage(int dmg)
{
  if (_hp >= (dmg-3))
    _hp -= (dmg-3);
}

