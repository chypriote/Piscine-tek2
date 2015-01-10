#ifndef		CPUINFO_H_
#define		CPUINFO_H_

#include	"AModule.hpp"
#include	"CPUInfoDisplay.hpp"

class	CPUInfo : public AModule {
public:
  CPUInfo();
  virtual ~CPUInfo() {}

  void		fillMap();
  void		getCPUCharge();
  int		refreshValues(std::string, size_t, int *, std::string);

protected:
  std::string	_filename2;
  int		_cpu0[2];
  int		_cpu1[2];
  int		_cpu2[2];
  int		_cpu3[2];
};

#endif
