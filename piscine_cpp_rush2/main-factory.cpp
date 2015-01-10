#include	"Usine/ConveyorBelt.hh"
#include	"Usine/Table.hh"
#include	"Elf/ElfOfPePeNoel.hh"
#include	"Object/LittlePony.hh"
#include	"Object/Teddy.hh"
#include	"Object/Box.hh"
#include	"Object/GiftPaper.hh"

int	main() {
  Elf		*elf = new Elf();
  Teddy		*ted1 = new Teddy("Bear");
  GiftPaper	*spr = new GiftPaper();  
  Box		*box = new Box();

  srand(time(NULL));

  std::cout << "\033[1;30;34m";
  std::cout << "--- Prends trois objets, les pose sur la table et regarde la table" << std::endl << std::endl;
  std::cout << "\033[1;30;00m";
  elf->takeObject(ted1);
  elf->putOnTable();
  elf->takeObject(spr);
  elf->putOnTable();
  elf->takeObject(box);
  elf->putOnTable();
  elf->lookOnTable();
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "\033[1;30;34m";
  std::cout << "--- Appuie sur 'IN', mets l'objet sur la table, recommence 2 fois et regarde la table" << std::endl << std::endl;
  std::cout << "\033[1;30;00m";
  elf->pressButtonIN();
  elf->putOnTable();
  elf->pressButtonIN();
  elf->putOnTable();
  elf->pressButtonIN();
  elf->putOnTable();
  elf->lookOnTable();
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "\033[1;30;34m";
  std::cout << "--- Prend un objet sur la table, le met sur le tapis, prend un autre objet, essaye de le mettre sur le tapis, appuie deux fois sur 'OUT', met le 2e objet sur le tapis" << std::endl << std::endl;
  std::cout << "\033[1;30;00m";
  elf->takeOnTable(1);
  elf->putOnConveyor();
  elf->takeOnTable(2);
  elf->putOnConveyor();
  elf->pressButtonOUT();
  elf->pressButtonOUT();
  elf->putOnConveyor();
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "\033[1;30;34m";
  std::cout << "--- Prend plusieurs objets, et en met trop sur la table" << std::endl << std::endl;
  std::cout << "\033[1;30;00m";
  LittlePony	*pony1 = new LittlePony("Rainbow Dash");
  LittlePony	*pony2 = new LittlePony("Fluttershy");
  LittlePony	*pony3 = new LittlePony("Pinkie Pie");
  LittlePony	*pony4 = new LittlePony("Rarity");
  LittlePony	*pony6 = new LittlePony("Red Poney");
  LittlePony	*pony5 = new LittlePony("Applejack");
  LittlePony	*pony7 = new LittlePony("Spike");
  LittlePony	*pony8 = new LittlePony("Poney Magique");
  LittlePony	*pony9 = new LittlePony("Poney-Ecureuil");
  Teddy		*ted = new Teddy("Tueur de poney");

  elf->takeObject(pony1);
  elf->putOnTable();
  elf->takeObject(pony2);
  elf->putOnTable();
  elf->takeObject(pony3);
  elf->putOnTable();
  elf->takeObject(pony4);
  elf->putOnTable();
  elf->takeObject(pony5);
  elf->putOnTable();
  elf->lookOnTable();
  elf->takeObject(pony6);
  elf->putOnTable();
  elf->takeObject(pony7);
  elf->putOnTable();
  elf->takeObject(pony8);
  elf->putOnTable();
  elf->takeObject(pony9);
  elf->putOnTable();
  elf->takeObject(ted);
  elf->putOnTable();
  elf->lookOnTable();
  std::cout << std::endl;
  std::cout << std::endl;

  return 0;
}
