#ifndef         ADISPLAY_H_
#define         ADISPLAY_H_

#include        <QFormLayout>

#include <QApplication>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include        <map>
#include        "IModuleDisplay.hpp"
#include        "curses.hpp"



class   ADisplay : public IModuleDisplay {
public:
  ADisplay();
  virtual ~ADisplay() {}

  virtual void          show(bool);
  virtual void          showCurses() = 0;
  virtual void          showQt() = 0;

  virtual void          addToMap(std::string, std::string);

  void                  setLayout(QVBoxLayout *layout);
protected:
  std::map<std::string, std::string>    _map;
  bool          _useQt;
  bool		_push_layout;
  QVBoxLayout   *_layout;
};

#endif  /*      ADISPLAY_H_     */
