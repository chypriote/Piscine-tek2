#ifndef         RAMINFO_DISPLAY_H_
#define         RAMINFO_DISPLAY_H_

#include <QHBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include        "ADisplay.hpp"

class   RAMInfoDisplay : public ADisplay {
public:
  RAMInfoDisplay() {}
  ~RAMInfoDisplay() {}

  void  showCurses();
  void  showQt();
    private:
     QProgressBar *_ramuseddata;

    QLabel *_ram;
    QLabel *_ramused;
    QLabel *_ramfree;
    QLabel *_sep;
    QLabel *_ramtot;
    QLabel *_ramname;
};

#endif  /*      RAMINFO_DISPLAY_H_      */
