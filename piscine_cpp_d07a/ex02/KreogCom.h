#ifndef		KREOGCOM_H_
#define		KREOGCOM_H_

#include	<string>
#include	<iostream>

class KreogCom {
public:
  KreogCom(int x, int y, int serial);
  ~KreogCom();

 public:
  void		addCom(int, int, int);
  KreogCom	*getCom();
  void		removeCom();
  
  void		ping() const;
  void		locateSquad() const;

private:
  int		m_serial;
  int		_x;
  int		_y;
  KreogCom	*next;
};

#endif
