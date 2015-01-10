#ifndef		TOYSTORY_H_
#define		TOYSTORY_H_

#include	<cstring>
#include	"Toy.h"

typedef	bool	(Toy::*toy_speak)(std::string const& str);

class ToyStory {
public:
  ToyStory();
  ~ToyStory();
  
  static bool	tellMeAStory(std::string const&, Toy&, toy_speak, Toy&, toy_speak);
};

#endif
