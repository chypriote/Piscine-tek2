#ifndef		FIND_H_
#define		FIND_H_

#include	<algorythm>

template<Container>
Container::iterator	do_find(Container& container, int i) {
  return std::find(container.begin(), container.end(), i); }

#endif
