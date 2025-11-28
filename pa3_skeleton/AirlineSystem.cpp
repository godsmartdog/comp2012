#include "AirlineSystem.h"

AirlineSystem::AirlineSystem() {
  customerTable = new CustomerHashTable(7);
  flights = new BST<Flight>();
}

AirlineSystem::~AirlineSystem() {
  delete customerTable;
  customerTable = nullptr;
  delete flights;
  flights = nullptr;
}
