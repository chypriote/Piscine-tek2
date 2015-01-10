#ifndef		OSKERNEL_H_
#define		OSKERNEL_H_

#include	"AModule.hpp"
#include	"../Display/OSKernelDisplay.hpp"

class	OSKernel : public AModule {
public:
  OSKernel();
  virtual ~OSKernel();

  void		fillMap();

private:
  std::string	_filename2;
};

#endif
