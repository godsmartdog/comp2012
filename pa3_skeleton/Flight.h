#ifndef __FLIGHT_H__
#define __FLIGHT_H__

#include <iostream>
#include "BST.h"
#include "Ticket.h"

using namespace std;

class Flight {
  private:
    const string flightNumber;
    const string departure;
    const string destination;

    BST<Ticket>* tickets;
  public:
    using KeyType = string;

    // * Task 1.1: constructor
    // * Task 4.1: constructor & destructor for data structures
    Flight(const string& num, const string& dept, const string& dest);

    // * Task 4.1: constructor & destructor for data structures
    ~Flight();
    
    Flight(const Flight&) = delete;
    Flight(Flight&&) = delete;
    Flight& operator= (const Flight&) = delete;
    Flight& operator= (Flight&&) = delete;

    // * Given
    inline bool operator< (const Flight& other) const {
      return *this < other.flightNumber;
    }

    // * Given
    inline bool operator== (const Flight& other) const {
      return *this == other.flightNumber;
    }

    // * Task 1.2: operator overloading
    bool operator< (const KeyType& key) const;
    bool operator== (const KeyType& key) const;

    // * Given
    inline string toString() const {
      return flightNumber + " from " + departure + " to " + destination;
    }

    // * Task 4.2: ticket BST
    void addTicket(Ticket* ticket);
    Ticket* sellTicket(int index);
    void showRemainingTickets() const;

    // * Given
    inline string getFlightNumber() const { return flightNumber; }
};

#endif // __FLIGHT_H__