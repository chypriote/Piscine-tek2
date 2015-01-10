#ifndef         USERINFO_H_
#define         USERINFO_H_

#include        "AModule.hpp"
#include        "UserInfoDisplay.hpp"

class   UserInfo : public AModule {
public:
  UserInfo();
  ~UserInfo();

  void          fillMap();
};

#endif

