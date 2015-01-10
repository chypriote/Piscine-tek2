#include    <iostream>
#include <QTime>
#include <QTimer>
#include <QApplication>
#include <QWidget>
#include	"Monitor.hpp"
#include    "DateHour.hpp"
#include    "OSKernel.hpp"
#include    "UserInfo.hpp"
#include    "RAMInfo.hpp"
#include     "CPUInfo.hpp"

Monitor::Monitor(bool useQt): QWidget(), _use_Qt(useQt) {
  AModule*	date = new DateHour;
  AModule*	user = new UserInfo;
  AModule*	os = new OSKernel;
  AModule*	ram = new RAMInfo;
  AModule*	cpu = new CPUInfo;

  _modules.push_back(date);
  _modules.push_back(user);
  _modules.push_back(os);
  _modules.push_back(ram);
  _modules.push_back(cpu);
  /*  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(Monitor::show_window()));
  timer->start(1000);*/
  // std::cout << "lol" << std::endl;
  // show_window();
}

Monitor::~Monitor() {}

void	Monitor::refresh() {
  std::vector<AModule*>::iterator it = _modules.begin();
  std::vector<AModule*>::iterator it_end = _modules.end();

  while (it != it_end)
    {
      (*it)->fillMap();
      ++it;
    }
}

void Monitor::addWindowLayout(QVBoxLayout *layout)
{
    std::vector<AModule*>::iterator it = _modules.begin();
    std::vector<AModule*>::iterator it_end = _modules.end();
    while (it != it_end)
    {
        (*it)->getDisplay().setLayout(layout);
        (*it)->getDisplay().show(true);
        ++it;
    }
}

void	Monitor::display() {
  std::vector<AModule*>::iterator it = _modules.begin();
  std::vector<AModule*>::iterator it_end = _modules.end();
  while (it != it_end)
    {
      (*it)->getDisplay().show(_use_Qt);
      ++it;
    }
  it = _modules.begin();
  sleep(2);
}

  // show_window();

void	Monitor::show_window()
{
  display();
}
