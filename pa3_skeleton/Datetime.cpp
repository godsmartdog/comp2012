#include "Datetime.h"

#include <string>

// #define TIME_FORMAT "%Y-%m-%d %H:%M:%S"

Datetime::Datetime(const string& ts) : str{ts} {
}

bool Datetime::operator< (const Datetime& other) const {
  return str < other.str;
}

bool Datetime::operator== (const Datetime& other) const {
  return str == other.str;
}  
