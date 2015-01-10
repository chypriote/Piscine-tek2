#include "Event.h"

//Constructor----------------------------------------
Event::Event() : _time(0), _event() { }

Event::Event(const Event &ref) : _time(ref._time), _event(ref._event) { }

Event::Event(unsigned int time, const std::string &event) : _time(time), _event(event) { }

Event::~Event() { }

//Getters--------------------------------------------
unsigned int	Event::getTime() const {
  return _time; }

const std::string& Event::getEvent() const {
  return _event; }

void		Event::setTime(unsigned int time) {
  _time = time; }

void		Event::setEvent(const std::string &event) {
  _event = event; }

//Operators-----------------------------------------
Event&		Event::operator=(const Event &other) {
  _time = other._time;
  _event = other._event;
  return *this;
}

bool		Event::operator<(const Event &other) {
  return (_time < other._time); }

bool		Event::operator>(const Event &other) {
  return (_time > other._time); }

bool		Event::operator==(const Event &other) {
  return (_time == other._time); }

bool		Event::operator<(unsigned int t) {
  return (_time < t); }

bool Event::operator>(unsigned int t) {
  return (_time > t); }

bool Event::operator==(unsigned int t) {
  return (_time == t); }
