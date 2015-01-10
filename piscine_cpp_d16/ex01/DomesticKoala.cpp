#include "DomesticKoala.h"


// Constructor / Destructor
DomesticKoala::DomesticKoala() : _methods(), _orders(), _ka(NULL) { }

DomesticKoala::DomesticKoala(const DomesticKoala &ref) : _methods(ref._methods), _orders(ref._orders), _ka(ref._ka)
{ }

DomesticKoala::DomesticKoala(KoalaAction &ka) : _methods(), _orders(), _ka(&ka) { }

DomesticKoala::~DomesticKoala() { }

// Utilities
std::vector<DomesticKoala::methodPointer_t> const * DomesticKoala::getActions() const {
  return &this->_methods; }

void DomesticKoala::learnAction(unsigned char order, DomesticKoala::methodPointer_t method) {
  unlearnAction(order);
  this->_methods.push_back(method);
  this->_orders.push_back(order);
}

void DomesticKoala::unlearnAction(unsigned char order) {
  int index = 0;
  for (std::vector<unsigned char>::iterator iter = this->_orders.begin(); iter != this->_orders.end(); iter++)
    {
      if ((*iter) == order)
	{
	  this->_orders.erase(iter);
	  break;
	}
      index++;
    }
  for (std::vector<DomesticKoala::methodPointer_t>::iterator iter = this->_methods.begin(); iter != this->_methods.end(); iter++)
    {
      if (index-- == 0)
	{
	  this->_methods.erase(iter);
	  break;
	}
    }
}

void DomesticKoala::doAction(unsigned char order, const std::string &msg) {
  if (this->_ka == NULL)
    return;
  int index = 0;
  for (std::vector<unsigned char>::iterator iter = this->_orders.begin(); iter != this->_orders.end(); iter++)
    {
      if ((*iter) == order)
	break;
      index++;
    }
  for (std::vector<DomesticKoala::methodPointer_t>::iterator iter = this->_methods.begin(); iter != this->_methods.end(); iter++)
    {
      if (index-- == 0)
	{
	  (this->_ka->*(*iter))(msg);
	  break;
	}
    }
}

void DomesticKoala::setKoalaAction(KoalaAction &ka) {
  this->_ka = &ka;
  this->_methods.clear();
  this->_orders.clear();
}

// Operators
DomesticKoala &DomesticKoala::operator=(const DomesticKoala &other){
  this->_ka = other._ka;
  this->_orders = other._orders;
  this->_methods = other._methods;
  return *this;
}
