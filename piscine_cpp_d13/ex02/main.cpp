#include <iostream>
#include "Toy.h"
#include "Woody.h"
#include "Buzz.h"

 int main()
 {
   Toy toto;
   Toy ET(Toy::ALIEN, "green", "./alien.txt");
   Woody	w("wood");
   Buzz		b("buzzi");

   toto.setName("TOTO !");

   std::cout << b.getName() << "->" << b.getAscii() << std::endl;
   std::cout << w.getName() << "->" << w.getAscii() << std::endl;
   return 1337;
 }
