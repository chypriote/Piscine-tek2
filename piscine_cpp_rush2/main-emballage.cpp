#include	"Usine/ConveyorBelt.hh"
#include	"Usine/Table.hh"
#include	"Elf/ElfOfPePeNoel.hh"
#include	"Object/LittlePony.hh"
#include	"Object/Teddy.hh"
#include	"Object/Box.hh"
#include	"Object/GiftPaper.hh"

int	main() {
  Elf		*dobby = new Elf("Dobby");


  Teddy		*teddy = new Teddy("Winnie");
  Box		*box = new Box();
  GiftPaper	*paper = new GiftPaper();

  std::cout << "\033[1;30;34m";
  std::cout << "--- Prend un Teddy, le met dans une Box, l'emballe dans un GiftPaper et l'envoie au Pere Noel" << std::endl << std::endl;
  std::cout << "\033[1;30;00m";
  dobby->takeObject(teddy);
  dobby->putInWrap(box);
  dobby->putInWrap(paper);
  dobby->putOnConveyor();
  dobby->pressButtonOUT();
  std::cout << std::endl;
  std::cout << std::endl;


  GiftPaper	*giftppr = new GiftPaper();
  Box		*xob = new Box();
  std::cout << "\033[1;30;34m";
  std::cout << "--- Prend un GiftPaper et le met dans une Box (impossible)" << std::endl << std::endl;
  std::cout << "\033[1;30;00m";
  dobby->takeObject(giftppr);
  dobby->putInWrap(xob);
  dobby->putOnTable();
  std::cout << std::endl;
  std::cout << std::endl;

  LittlePony	*pony = new LittlePony("Rainbow Dash");
  Box		*boite = new Box();
  std::cout << "\033[1;30;34m";
  std::cout << "--- Prend une Boite, la ferme, essaye de mettre un Pony dedans, l'ouvre, mets le Pony" << std::endl << std::endl;
  std::cout << "\033[1;30;00m";
  dobby->takeObject(boite);
  dobby->closeWrap();
  dobby->putOnTable();
  dobby->takeObject(pony);
  dobby->putInWrap(boite);
  dobby->putOnTable();
  //  dobby->lookOnTable();
  dobby->takeOnTable(1);
  dobby->openWrap();
  dobby->putOnTable();
  dobby->takeOnTable(2);
  dobby->putInWrap(boite);

  return 0;
}
