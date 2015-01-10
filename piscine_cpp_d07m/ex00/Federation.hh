#ifndef		FEDERATION_H_
#define		FEDERATION_H_

#include	<iostream>
#include	<string>
#include	"Warpsystem.hh"

namespace Federation {
  namespace Starflet {
    class Ship;
  }
  class Ship;
}


namespace Federation {
  namespace Starfleet {
    class	Ship {
    private:
      int		_length;
      int		_width;
      std::string	_name;
      short		_maxWarp;
      WarpSystem::Core	*_core;
      
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
    };
  };
  class		Ship {
  private:
    int			_length;
    int			_width;
    std::string		_name;
    WarpSystem::Core	*_core;
    
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
  };
};

#endif
