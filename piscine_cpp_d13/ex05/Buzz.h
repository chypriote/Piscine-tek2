#ifndef		BUZZ_H_
#define		BUZZ_H_

#include	"Toy.h"

class	Buzz: public Toy {
 public:
  Buzz(std::string const&);
  Buzz(std::string const&, std::string const&);

  bool	speak(std::string const&);
  bool	speak_es(std::string const&);
};

#endif
