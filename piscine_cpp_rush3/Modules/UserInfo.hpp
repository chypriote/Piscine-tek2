#ifndef		USERINFO_H_
#define		USERINFO_H_

#include	"AModule.hpp"
#include	"../Display/UserInfoDisplay.hpp"

class	UserInfo : public AModule {
public:
  UserInfo();
  virtual ~UserInfo();

  void		fillMap();
};

#endif
