#ifndef		FEDERATION_H_
#define		FEDERATION_H_

#include	<iostream>
#include	<string>
#include	"Warpsystem.hh"
#include	"Destination.hh"

namespace Federation {
  namespace Starflet {
    class Ship;
    class Captain;
    class Ensign;
  }
  class Ship;
}

namespace Federation {
  namespace Starfleet {
    
    class	Captain {
    private:
      std::string	_name;
      int		_age;

    public:
      Captain(std::string);
      ~Captain();
     
      std::string	getName();
      int		getAge();
      void		setAge(int);
    };

    class	Ship {
    private:
      int		_length;
      int		_width;
      std::string	_name;
      short		_maxWarp;
      WarpSystem::Core	*_core;
      Captain		*_captain;
      Destination	_location;
      Destination	_home;
      
      void		say(std::string);
    public:
      Ship(int, int, std::string, short);
      ~Ship();
      
      int		getLength();
      int		getWidth();
      std::string	getName();
      short		getWarp();
      WarpSystem::Core	*getCore();
      void		setupCore(WarpSystem::Core *);
      void		checkCore();
      bool		isStable();
      void		promote(Captain *);
      bool		move(int, Destination);
      bool		move(int);
      bool		move(Destination);
      bool		move();
    };

    class	Ensign {
    private:
      std::string	_name;

    public:
      Ensign(std::string);
      ~Ensign();
      
      std::string	getName();
    };
  };
  class		Ship {
  private:
    int			_length;
    int			_width;
    std::string		_name;
    WarpSystem::Core	*_core;
    Destination		_home;
    Destination		_location;
    short		_maxWarp;

    void		say(std::string);
  public:
    Ship(int length, int width, std::string name);
    ~Ship();
    
    int			getLength();
    int			getWidth();
    std::string		getName();
    short		getWarp();
    WarpSystem::Core	*getCore();
    void		setupCore(WarpSystem::Core *);
    void		checkCore();
    bool		isStable();
    bool		move(int, Destination);
    bool		move(int);
    bool		move(Destination);
    bool		move();
  };
};

#endif
