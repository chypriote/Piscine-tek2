#ifndef		BORG_H_
#define		BORG_H_

#include	<string>
#include	<iostream>
#include	"Warpsystem.hh"
#include	"Federation.hh"

namespace Federation {
  namespace Starfleet {
    class Ship;
    class Captain;
    class Ensign;
  }
  class Ship;
}

namespace Borg {
  class Ship;
}

namespace Borg {
  class Ship {
  private:
    int			_side;
    short		_maxWarp;
    WarpSystem::Core	*_core;
    Destination		_location;
    Destination		_home;
    int			_shield;
    int			_weaponFrequency;
    short		_repair;
    
    void		say(std::string message);

  public:
    Ship(int weaponFrenquency, short repair = 3);
    ~Ship();
    
    int			getSide();
    short		getMaxWarp();
    WarpSystem::Core	*getCore();
    Destination		getLocation();
    Destination		getHome();
    int			getShield();
    int			getWeaponFrequency();
    short		getRepair();

    void		setCore(WarpSystem::Core *core);
    void		setLocation(Destination location);
    void		setHome(Destination home);
    void		setShield(int shield);
    void		setWeaponFrequency(int weaponFrequency);
    void		setRepair(short repair);
    void		setupCore(WarpSystem::Core *core);

    bool		isStable();
    void		checkCore();

    bool		move(int warp, Destination d);
    bool		move(int warp);
    bool		move(Destination d);
    bool		move();
    
    void		fire(Federation::Starfleet::Ship *ship);
    void		fire(Federation::Ship *ship);
    void		stricken(int damage);
    void		repair();
  };
}

#endif
