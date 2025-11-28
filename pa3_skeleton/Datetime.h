#ifndef __DATETIME_H__
#define __DATETIME_H__

#include <iostream>
// #include <ctime>

using namespace std;

// * Given
class Datetime {
  private:
    // time_t time;
    const string str;

  public:
    explicit Datetime(const string& time);
    Datetime(const char* s) : Datetime{std::string{s}} {}
    inline operator string() const { return str; }

    bool operator< (const Datetime& other) const;
    bool operator== (const Datetime& other) const;
};

#endif // __DATETIME_H__
