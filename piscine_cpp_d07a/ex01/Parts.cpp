#include "Parts.h"

//---------------------------Arms---------------------------/

Arms::Arms(std::string serial, bool functionnal)
{
  this->_serial = serial;
  this->_functionnal = functionnal;
}

std::string Arms::serial() const {
  return _serial; }

bool Arms::isFunctionnal() const {
  return _functionnal; }

void Arms::informations() const {
  std::cout << "\t[Parts] Arms " << _serial << " status : ";
  if (_functionnal)
    std::cout << "OK" << std::endl;
  else
    std::cout << "KO" << std::endl;
}

//---------------------------Legs---------------------------/

Legs::Legs(std::string serial, bool functionnal)
{
  this->_serial = serial;
  this->_functionnal = functionnal;
}

std::string Legs::serial() const {
  return _serial; }

bool Legs::isFunctionnal() const {
  return _functionnal; }

void Legs::informations() const {
  std::cout << "\t[Parts] Legs " << _serial << " status : ";
  if (_functionnal)
    std::cout << "OK" << std::endl;
  else
    std::cout << "KO" << std::endl;
}

//---------------------------Head---------------------------/

Head::Head(std::string serial, bool functionnal)
{
  this->_serial = serial;
  this->_functionnal = functionnal;
}

std::string Head::serial() const {
  return _serial; }

bool Head::isFunctionnal() const {
  return _functionnal; }

void Head::informations() const {
  std::cout << "\t[Parts] Head " << _serial << " status : ";
  if (_functionnal)
    std::cout << "OK" << std::endl;
  else
    std::cout << "KO" << std::endl;
}
