
#ifndef         RAMINFO_H_
#define         RAMINFO_H_

#include        <sstream>
#include        "AModule.hpp"
#include        "RAMInfoDisplay.hpp"

class   RAMInfo : public AModule {
public:
  RAMInfo();
  ~RAMInfo();

  void          fillMap();
};

#endif

