#ifndef		EX05_H_
#define		EX05_H_

#include	<iostream>
#include	<exception>

template<typename T>
class	array {
protected:
  unsigned int	_size;
  T*		tab;

public:
  //Construction------------------------
  array(): _size(0), tab(NULL) {}
  array(unsigned int size): _size(size) {
    tab = new T[_size];
  }
  array(const array<T>& array) {
    _size = array._size;
    tab = new T[_size];
    unsigned int	i = 0;
    while (i < _size) {
      tab[i] = array.tab[i];
      i++;
    }
  }
  virtual ~array() {
    if (tab)
      delete [] tab;
}

  array<T>&	operator=(const array<T>& array) {
    if (tab)
      delete[] tab;
    _size = array._size;
    tab = new T[_size];
    unsigned int	i = 0;
    while (i < _size) {
      tab[i] = array.tab[i];
      i++;
    }
    return *this;
  }

  //Getters---------------------------
  unsigned int	size() const {
    return _size; }

  void		dump() const {
    unsigned int	i = 0;
    std::cout << "[";
    while (i < _size) {
      std::cout << tab[i];
      i++;
      if (i != _size)
	std::cout << ", ";
    }
    std::cout << "]" << std::endl;
  }

  //Operators------------------------
  T&	operator[](unsigned int id) {
    if (id >= _size) {
      T*	cpy = new T[id + 1];
      unsigned int	i = 0;
      while (i < _size) {
	cpy[i] = tab[i];
	i++;
      }
      delete[] tab;
      tab = cpy;
      _size = id + 1;
    }
    return tab[id];
};

  T&	operator[](unsigned int id) const {
    if (id >= _size)
      throw std::exception();
    return tab[id];
  }

  //Functions------------------------------
  template<typename U>
  array<U>	convertTo(U(*convert)(const T&)) const {
    array<U>	dup(_size);
    unsigned int	i = 0;
    while (i < _size) {
      dup[i] = (*convert)(tab[i]);
      i++;
    }
    return dup;
  }
};

  //Template------------------------------
template<>
  void		array<bool>::dump() const {
    unsigned int	i = 0;
    std::cout << "[";
    while (i < _size) {
      std::cout << (tab[i] ? "true" : "false");
      i++;
      if (i != _size)
	std::cout << ", ";
    }
    std::cout << "]" << std::endl;
  }

#endif
