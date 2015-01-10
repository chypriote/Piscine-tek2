#ifndef		EX04_H_
#define		EX04_H_

#include	<iostream>
#include	<string>

template<typename T>
bool	equal(const T&, const T&);

template<typename T>
class	Tester {
public:
  bool	equal(const T&, const T&);
};

#endif
