#ifndef         AMODULE_H_
#define         AMODULE_H_

#include        <fstream>
#include        "IMonitorModule.hpp"
#include        "ADisplay.hpp"

class   AModule : public IMonitorModule {
public:
  AModule() {}
  virtual ~AModule() {}

  virtual void  fillMap() = 0;
  ADisplay &getDisplay()
  {
    return *_display;
  }

protected:
  bool          _refresh;
  std::string   _filename;
  ADisplay*     _display;
};

#endif          /*      !AMODULE_H_     */



