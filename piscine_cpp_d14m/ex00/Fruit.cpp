#include	"Fruit.h"

//---------------------Coplien
Fruit::Fruit(): _vitamins(0), _name("fruit") {}

Fruit::Fruit(int vit, std::string const& name): _vitamins(vit), _name(name) {}

//------------------Getters
int		Fruit::getVitamins() const {
  return _vitamins; }

std::string const&	Fruit::getName() const {
  return _name; }
