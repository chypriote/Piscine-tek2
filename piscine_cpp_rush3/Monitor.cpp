#include	"Monitor.hpp"
#include        "Modules/DateHour.hpp"
#include        "Modules/OSKernel.hpp"
#include        "Modules/UserInfo.hpp"
#include        "Modules/RAMInfo.hpp"
#include        "Modules/CPUInfo.hpp"
#include        "Modules/Network.hpp"


Monitor::Monitor(bool useQt): _use_Qt(useQt) {
  AModule*	date = new DateHour;
  AModule*	user = new UserInfo;
  AModule*	os = new OSKernel;
  AModule*	ram = new RAMInfo;
  AModule*	cpu = new CPUInfo;
  AModule*	net = new Network;

  _modules.push_back(date);
  _modules.push_back(user);
  _modules.push_back(os);
  _modules.push_back(ram);
  _modules.push_back(cpu);
  _modules.push_back(net);
}

Monitor::~Monitor() {
  //  delete [] _modules;
}


void	Monitor::refresh() {
  std::vector<AModule*>::iterator it = _modules.begin();
  std::vector<AModule*>::iterator it_end = _modules.end();

  while (it != it_end) {
    (*it)->fillMap();
    ++it;
  }
}

void	Monitor::display() {
  std::vector<AModule*>::iterator it = _modules.begin();
  std::vector<AModule*>::iterator it_end = _modules.end();

  while (it != it_end) {
    (*it)->_display->show(_use_Qt);
    ++it;
  }
}
