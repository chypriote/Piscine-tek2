#include	"Fruit.h"

//---------------------Coplien
Fruit::Fruit() {}

Fruit::Fruit(int vit, std::string const& name): _vitamins(vit), _name(name) {}

//------------------Getters
int		Fruit::getVitamins() const {
  return _vitamins; }

std::string const&	Fruit::getName() const {
  return _name; }
