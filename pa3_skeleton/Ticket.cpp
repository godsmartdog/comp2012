#include "Ticket.h"

#include "Flight.h"


string Ticket::toString() const {
  string stime = info.departureTime;
  return info.flight->toString() + ", seat No.: " + to_string(info.seatNumber) + ", departure time: " 
    + stime + ", price: " + to_string(price);
}
