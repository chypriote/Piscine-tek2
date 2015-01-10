#ifndef         USERINFO_DISPLAY_H_
#define         USERINFO_DISPLAY_H_

#include        <QLabel>
#include        "ADisplay.hpp"

class   UserInfoDisplay : public ADisplay {
public:
  UserInfoDisplay() {}
  ~UserInfoDisplay() {}

  void  showCurses();
  void  showQt();

private:
  QLabel *_name;
  QLabel *_username;
  QLabel *_machine;
  QLabel *_machinename;
};

#endif  /*      USERINFO_DISPLAY_H_     */
