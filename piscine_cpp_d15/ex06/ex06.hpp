#ifndef		EX06_H_
#define		EX06_H_

#include	<string>
#include	<sstream>
#include	<iostream>


template<typename T>
std::string	print(T) {
  return std::string("???"); }

template<>
std::string	print(int i) {
  std::stringstream	s;
  s << i;
  return std::string("int:") + s.str();
}

template<>
std::string	print(float f) {
  std::stringstream	s;
  s << f;
  return std::string("float:") + s.str() + "f"; }

template<>
std::string	print(std::string str) {
  return std::string("string:\"") + str + "\""; }

template<typename T1, typename T2 = T1>
class	Tuple {
public:
  T1	a;
  T2	b;

  std::string	toString() const {
    return std::string("[TUPLE [") + print(a) + "] [" + print(b) + "]]";  }
};

#endif
