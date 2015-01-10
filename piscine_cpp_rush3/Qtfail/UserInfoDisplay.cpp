#include    "UserInfoDisplay.hpp"

void UserInfoDisplay::showQt() {
  if (_push_layout) {
  _name = new QLabel("Username :");
  _username = new QLabel("username");
  _machine = new QLabel("Machine name :");
  _machinename = new QLabel("machinename");
  
  QVBoxLayout *formLayout2 = new QVBoxLayout;
  QHBoxLayout *formLayout = new QHBoxLayout;
  QHBoxLayout *formLayout3 = new QHBoxLayout;
  
  formLayout->addWidget(_name);
  formLayout->addWidget(_username);
  formLayout2->addLayout(formLayout);
  formLayout3->addWidget(_machine);
  formLayout3->addWidget(_machinename);
  formLayout2->addLayout(formLayout3);
  _layout->addLayout(formLayout2);
  _push_layout = false;
  }
  else {
  std::map<std::string, std::string>::iterator it = _map.begin();
  _username->setText((*it).second.c_str());
  ++it;
  _machinename->setText((*it).second.c_str());
  }
}


void            UserInfoDisplay::showCurses()
{
  refresh();
  std::map<std::string, std::string>::iterator it = _map.begin();
  ++it;
  attron(COLOR_PAIR(4));
  attron(A_BOLD);
  mvprintw(6,1,"%s","User information:");
  attroff(COLOR_PAIR(4));
 attroff(A_BOLD);
  mvprintw(7,1,"%s", (*it).second.c_str());
  it = _map.begin();
  mvprintw(8,1,"%s", (*it).second.c_str());
  refresh();
}
