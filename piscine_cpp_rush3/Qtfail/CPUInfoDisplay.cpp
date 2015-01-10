#include    "CPUInfoDisplay.hpp"

void          CPUInfoDisplay::showQt() {
  if (_push_layout) {
  _cpuname = new QLabel("name");
  _cpu1 = new QLabel("Cpu1:");
  _ptr1 = new QProgressBar;
  _cpu2 = new QLabel("Cpu2:");
  _ptr2 = new QProgressBar;
  _cpu3 = new QLabel("Cpu3:");
  _ptr3 = new QProgressBar;
  _cpu4 = new QLabel("Cpu4:");
  _ptr4 = new QProgressBar;


  QVBoxLayout *formLayout2 = new QVBoxLayout;
  QHBoxLayout *formLayout = new QHBoxLayout;
  QHBoxLayout *formLayout3 = new QHBoxLayout;
  QHBoxLayout *formLayout4 = new QHBoxLayout;
  QHBoxLayout *formLayout5 = new QHBoxLayout;
  QHBoxLayout *formLayout6 = new QHBoxLayout;
  
  formLayout6->addWidget(_cpuname);
formLayout2->addLayout(formLayout6);
 formLayout->addWidget(_cpu1);
 formLayout->addWidget(_ptr1);
 formLayout2->addLayout(formLayout);
 formLayout3->addWidget(_cpu2);
 formLayout3->addWidget(_ptr2);
 formLayout2->addLayout(formLayout3);
 formLayout4->addWidget(_cpu3);
 formLayout4->addWidget(_ptr3);
 formLayout2->addLayout(formLayout4);
 formLayout5->addWidget(_cpu4);
 formLayout5->addWidget(_ptr4);
 formLayout2->addLayout(formLayout5);
 _layout->addLayout(formLayout2);
 _push_layout = false;
  }
  else {
  std::map<std::string, std::string>::iterator it = _map.begin();

_ptr1->setValue(my_stoi((*it).second));
++it;
  _ptr2->setValue(my_stoi((*it).second));
    ++it;
  _ptr3->setValue(my_stoi((*it).second));
    ++it;
  _ptr4->setValue(my_stoi((*it).second));
    ++it;
  _cpuname->setText((*it).second.c_str());
  }
}

void    CPUInfoDisplay::showCurses()
{
  refresh();
  std::map<std::string, std::string>::iterator it = _map.end();
  it--;
  attron(A_BOLD);
  attron(COLOR_PAIR(4));
  mvprintw(10,1,"%s","CPU information:");
  attroff(COLOR_PAIR(4));
  attroff(A_BOLD);
  mvprintw(11,1,"%s",(*it).second.c_str());
  refresh();
}
