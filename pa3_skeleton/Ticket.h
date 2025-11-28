#ifndef __TICKET_H__
#define __TICKET_H__

#include "Datetime.h"

using namespace std;

class Flight;

class Ticket {
  public:
    struct FlightInfo {
      const Flight* flight;
      const int seatNumber;
      const Datetime departureTime;

      FlightInfo(Flight* flight, int seatNum, const Datetime& time) :
        flight{flight}, seatNumber{seatNum}, departureTime{time} {}
    };

    using KeyType = FlightInfo;
  private:
    const FlightInfo info;
    const int price;

  public:
    // * Task 1.1: constructor
    Ticket(Flight* flight, int seatNum, const Datetime& time, int price);

    // * Given
    inline bool operator< (const Ticket& other) const {
      return *this < other.getFlightInfo();
    }

    // * Given
    inline bool operator== (const Ticket& other) const {
      return *this == other.getFlightInfo();
    }


    //  *Task 1.2: operator overloading
    bool operator< (const FlightInfo& key) const;
    bool operator== (const FlightInfo& key) const;

    // * Given
    string toString() const;

    // * Given
    inline const FlightInfo& getFlightInfo() const { return info; };
    inline int getPrice() const { return price; }
};

#endif // __TICKET_H__
