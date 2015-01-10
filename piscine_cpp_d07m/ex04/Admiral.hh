#ifndef		ADMIRAL_H_
#define		ADMIRAL_H_

#include	<string>
#include	<iostream>
#include	"Federation.hh"
#include	"Borg.hh"
#include	"Destination.hh"


namespace Federation {
  namespace Starfleet {
    class Admiral;
  }
}

namespace Federation {
  namespace Starfleet {
    class Admiral {
    private:
      std::string	_name;

    public:
      bool		(Federation::Starfleet::Ship::*movePtr)(Destination d);
      void		(Federation::Starfleet::Ship::*firePtr)(Borg::Ship *ship);

      Admiral(std::string);
      ~Admiral();
      
      bool		move(Federation::Starfleet::Ship *ship, Destination d);
      void		fire(Federation::Starfleet::Ship *ship, Borg::Ship *target);
    };
  }; 
};

#endif
