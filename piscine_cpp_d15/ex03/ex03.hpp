#ifndef		EX03_H_
#define		EX03_H_

#include <iostream>

template<typename T>
void	foreach(const T* tab, void (func)(const T&), int size) {
  int	i = 0;
  while (i < size) {
    (*func)(tab[i]);
    i++;
  }
}

template<typename T>
void print(const T& c) {
  std::cout << c << std::endl; }

#endif
