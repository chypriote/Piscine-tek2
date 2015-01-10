#ifndef		PARSER_H_
#define		PARSER_H_

#include	<stack>
#include	<iostream>
#include	<string>
#include	<cstdlib>

class	Parser {
 protected:
  std::stack<long int>	operands;
  std::stack<char>	operators;
  int			_result;
 
 public:
  Parser();
  Parser(const Parser&);
  ~Parser();

  void		feed(const std::string &);
  int		result() const;
  void		reset();
};

#endif
