#ifndef         CPUINFO_DISPLAY_H_
#define         CPUINFO_DISPLAY_H_

#include   <QProgressBar>
#include  <QHBoxLayout>
#include <QLabel>
#include "Monitor.hpp"
#include        "ADisplay.hpp"

class   CPUInfoDisplay : public ADisplay {
public:
  CPUInfoDisplay() {}
   ~CPUInfoDisplay() {}

  void  showCurses();
  void  showQt();
private:
 QProgressBar *_ptr1;
 QProgressBar *_ptr2;
 QProgressBar *_ptr3;
 QProgressBar *_ptr4;
QLabel *_cpu1;
QLabel *_cpu2;
QLabel *_cpu3;
QLabel *_cpu4;
QLabel *_cpuname;
};

#endif  /*      CPUINFO_DISPLAY_H_      */

