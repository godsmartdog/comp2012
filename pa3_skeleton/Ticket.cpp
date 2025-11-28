#include "Ticket.h"

#include "Flight.h"


string Ticket::toString() const {
  string stime = info.departureTime;
  return info.flight->toString() + ", seat No.: " + to_string(info.seatNumber) + ", departure time: " 
    + stime + ", price: " + to_string(price);
}

Ticket:: Ticket(Flight* flight, int seatNum, const Datetime& time, int price):info(flight,seatNum,time),price(price){

}

bool Ticket:: operator< (const FlightInfo& key) const{
  if(info.departureTime==key.departureTime){
    if(*(info.flight)==*(key.flight)){
      return info.seatNumber<key.seatNumber;
    }
    return *(info.flight)==*(key.flight);
  }
  return info.departureTime<key.departureTime;
}
bool Ticket:: operator== (const FlightInfo& key) const{
  if(info.departureTime==key.departureTime){
    if(*(info.flight)==*(key.flight)){
      return info.seatNumber==key.seatNumber;

    }
    
  }
  return false;
}