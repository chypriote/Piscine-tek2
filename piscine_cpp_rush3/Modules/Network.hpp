#ifndef		NETWORK_H_
#define		NETWORK_H_

#include	"AModule.hpp"
#include	"../Display/NetworkDisplay.hpp"

class	Network : public AModule {
public:
  Network();
  virtual ~Network() {}

  void		fillMap();

protected:
  int		_old[2];
};

#endif
