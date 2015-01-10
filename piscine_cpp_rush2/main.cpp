#include	"Usine/ConveyorBelt.hh"
#include	"Usine/Table.hh"
#include	"Elf/ElfOfPePeNoel.hh"
#include	"Object/LittlePony.hh"
#include	"Object/Teddy.hh"
#include	"Object/Box.hh"
#include	"Object/GiftPaper.hh"

int	main() {
  Teddy		*teddy = new Teddy("Winnie");
  Box		*box = new Box();
  GiftPaper	*paper = new GiftPaper();

  Object	**tab = teddy->MyUnitTests();
  std::cout << "objet1: " << tab[0]->getTitle() << std::endl;
  std::cout << "objet2: " << tab[1]->getTitle() << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  Object	**leau = new Object *[3];
  leau[0] = teddy;
  leau[1] = box;
  leau[2] = paper;

  Object	*gift = box->MyUnitTests(leau);

  std::cout << "le gift contient: " << gift->getObject()->getTitle() << std::endl;
  std::cout << "qui contient: " << gift->getObject()->getObject()->getTitle() << std::endl;
  return 0;
}
