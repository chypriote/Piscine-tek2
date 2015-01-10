#ifndef         DATEHOUR_DISPLAY_H_
#define         DATEHOUR_DISPLAY_H_

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include        <iostream>
#include        "ADisplay.hpp"

class   DateHourDisplay : public ADisplay {
public:
  DateHourDisplay() {}
  ~DateHourDisplay() {}

  void  showCurses();
  void  showQt();

private:
  QLabel *_date;
  QLabel *_dateData;
  QLabel *_time;
  QLabel *_timeData;
};

#endif  /*      DATEHOUR_DISPLAY_H_     */
