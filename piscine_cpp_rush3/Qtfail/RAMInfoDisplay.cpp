#include    "RAMInfoDisplay.hpp"

void RAMInfoDisplay::showQt(){
  if (_push_layout) {
  _ramname = new QLabel("Ram");
  _ram = new QLabel("Ram:");
  _ramfree = new QLabel("ramfree");
  _sep = new QLabel(" / ");
  _ramtot = new QLabel("ramtot");
  _ramused = new QLabel("Ram used:");
  _ramuseddata = new QProgressBar;
  
  

  QVBoxLayout *formLayout2 = new QVBoxLayout;
  QHBoxLayout *formLayout = new QHBoxLayout;
  QHBoxLayout *formLayout3 = new QHBoxLayout;
  QHBoxLayout *formLayout6 = new QHBoxLayout;
  
  formLayout6->addWidget(_ramname);
  formLayout2->addLayout(formLayout6);
  formLayout->addWidget(_ram);
  formLayout->addWidget(_ramfree);
  formLayout->addWidget(_sep);
  formLayout->addWidget(_ramtot);
  formLayout2->addLayout(formLayout);
  formLayout3->addWidget(_ramused);
  formLayout3->addWidget(_ramuseddata);
  formLayout2->addLayout(formLayout3);
     
  _layout->addLayout(formLayout2);
  _push_layout = false;

  }
  else {
  std::map<std::string, std::string>::iterator it = _map.begin();
  
  _ramfree->setText((*it).second.c_str());
  ++it;
  _ramtot->setText((*it).second.c_str());
  ++it;
  _ramuseddata->setValue(my_stoi((*it).second));
  }
}

void            RAMInfoDisplay::showCurses()
{
  int           i = 0;
  int           nb;

  refresh();
  std::map<std::string, std::string>::iterator it = _map.begin();
  ++it;
  ++it;
  attron(COLOR_PAIR(4));
  mvprintw(9, 53, "%s%% of the memory used.",(*it).second.c_str());
  attroff(COLOR_PAIR(4));
  nb = my_stoi(it->second);
  while (i < nb/2)
    {
      if (i >= 30)
        attron(COLOR_PAIR(1));
      if (i >= 20 && i < 30)
        attron(COLOR_PAIR(2));
      if (i >= 0 && i < 20)
        attron(COLOR_PAIR(3));
      mvprintw(9, i + 2,"|");
      attroff(COLOR_PAIR(1));
      attroff(COLOR_PAIR(2));
      attroff(COLOR_PAIR(3));
      ++i;
    }
  refresh();
}
