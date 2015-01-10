#include    "DateHourDisplay.hpp"

void          DateHourDisplay::showQt()
{
  if (_push_layout) {
  _date = new QLabel("Date :");
  _dateData = new QLabel("Datedata");
  _time = new QLabel("Time :");
  _timeData = new QLabel("Timedata");
  
  
  QVBoxLayout *formLayout2 = new QVBoxLayout;
  QHBoxLayout *formLayout = new QHBoxLayout;
  QHBoxLayout *formLayout3 = new QHBoxLayout;
  
  formLayout->addWidget(_date);
  formLayout->addWidget(_dateData);
  formLayout2->addLayout(formLayout);
  formLayout3->addWidget(_time);
  formLayout3->addWidget(_timeData);
  formLayout2->addLayout(formLayout3);
  _layout->addLayout(formLayout2);
  _push_layout = false;
  }
  else {
  std::map<std::string, std::string>::iterator it = _map.begin();
  _dateData->setText((*it).second.c_str());
  ++it;
  _timeData->setText((*it).second.c_str());
  }
}

void            init_design()
{
  attron(A_BOLD);
  mvprintw(9, 1,"[");
  mvprintw(9, 51,"]");
  attroff(A_BOLD);
}

void    DateHourDisplay::showCurses()
{
  erase();
  refresh();
  std::map<std::string, std::string>::iterator it = _map.begin();
  attron(A_BOLD);
  attron(COLOR_PAIR(4));
  mvprintw(1,1,"%s","Date and time:");
  attroff(COLOR_PAIR(4));
  attroff(A_BOLD);
  mvprintw(2,1,"%s", (*it).second.c_str());
  ++it;
  mvprintw(2,12,"%s", (*it).second.c_str());
  init_design();
  refresh();
}
