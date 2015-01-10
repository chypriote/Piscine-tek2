#ifndef		BORG_H_
#define		BORG_H_

#include	<string>
#include	<iostream>
#include	"Warpsystem.hh"
#include	"Destination.hh"

namespace Borg {
  class Ship;
}

namespace Borg {
  class Ship {
  private:
    int			_side;
    short		_maxWarp;
    WarpSystem::Core	*_core;
    Destination		_home;
    Destination		_location;

    void		say(std::string);
  public:
    Ship();
    ~Ship();
    
    int			getSide();
    short		getWarp();
    WarpSystem::Core	*getCore();
    bool		isStable();
    void		setupCore(WarpSystem::Core *);
    void		checkCore();
    bool		move(int, Destination);
    bool		move(int);
    bool		move(Destination);
    bool		move();
  };
};

#endif
