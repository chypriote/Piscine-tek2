#include "Warpsystem.hh"

//------------------------------Reactor-----------------------------------//

WarpSystem::QuantumReactor::QuantumReactor() {
  _stability = true; }

WarpSystem::QuantumReactor::~QuantumReactor()
{ }

void WarpSystem::QuantumReactor::setStability(bool stability) {
  _stability = stability; }

bool WarpSystem::QuantumReactor::getStability() {
  return _stability; }

bool WarpSystem::QuantumReactor::isStable() {
  return getStability(); }

//------------------------------Core-----------------------------------//

WarpSystem::Core::Core(QuantumReactor* reactor) {
  _coreReactor = reactor; }

WarpSystem::Core::~Core()
{ }

bool WarpSystem::Core::getStability() {
  if (_coreReactor)
    return _coreReactor->getStability();
  return false;
}

WarpSystem::QuantumReactor *WarpSystem::Core::getQuantumReactor() {
  return _coreReactor; }

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor() {
  return getQuantumReactor(); }

bool WarpSystem::Core::isStable() {
  return getStability(); }
