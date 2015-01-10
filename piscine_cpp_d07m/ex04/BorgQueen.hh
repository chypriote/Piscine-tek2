#ifndef		BORGQUEEN_H_
#define		BORGQUEEN_H_

#include	<string>
#include	<iostream>
#include	"Borg.hh"
#include	"Federation.hh"
#include	"Destination.hh"

namespace Borg {
class BorgQueen;
}

namespace Borg {
	class BorgQueen {
	private:

	public:
	bool		(Borg::Ship::*movePtr)(Destination d);
	void		(Borg::Ship::*firePtr)(Federation::Starfleet::Ship *ship);
	void		(Borg::Ship::*destroyPtr)(Federation::Ship *ship);

	BorgQueen();
	~BorgQueen();

	bool		move(Borg::Ship* ship, Destination d);
	void		fire(Borg::Ship* ship, Federation::Starfleet::Ship* target);
	void		destroy(Borg::Ship* ship, Federation::Ship* target);
	};
}

#endif
