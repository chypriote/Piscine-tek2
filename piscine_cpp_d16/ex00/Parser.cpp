#include	"Parser.h"

//Parser---------------------------
Parser::Parser() {
  _result = 0; }

Parser::Parser(const Parser& old) {
  operands = old.operands;
  operators = old.operators;
  _result = old._result;
}

Parser::~Parser() {}

//Funcs----------------------------
int		is_ope(char c) {
  return (c == '*' || c == '+' || c == '-' || c == '/' || c == '%'); }

int		calculate(long int num, long int nb, char op) {
  if (op == '+')
     return num + nb;
  if (op == '-')
    return num - nb;
  if (op == '*')
    return num * nb;
  if (op == '/')
    return num / nb;
  if (op == '%')
    return num % nb;
  return 0;
}

void		Parser::feed(const std::string & str) {
  long int	i = 0;
  long int	nb;
  int		res = 0;

  while (str[i]) {
    if (is_ope(str[i]))
      operators.push(str[i]);
    else if (isdigit(str[i]) && !isdigit(str[i - 1])) {
      nb = atoi(str.substr(i, str.npos).c_str());
      operands.push(nb);
    }
    i++;
  }
  std::stack<char> saveop;
  while (!operators.empty()) {
    saveop.push(operators.top());
    operators.pop();
  }
  std::stack<long int> save;
  while (!operands.empty()) {
    save.push(operands.top());
    operands.pop();
  }
  res = save.top();
  save.pop();
  while (!saveop.empty()) {
    res = calculate(res, save.top(), saveop.top());
    save.pop();
    saveop.pop();
  }
  _result += res;
}

int		Parser::result() const {
  return _result; }

void		Parser::reset() {
  _result = 0;
  while (!operators.empty())
    operators.pop();
  while (!operands.empty())
    operands.pop();
}
