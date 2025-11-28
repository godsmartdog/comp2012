#include "Transaction.h"

#include <cmath>

#include "Flight.h"
#include "Customer.h"


bool Transaction::belongsTo(const string& flightNo) const {
  return *info.ticket->getFlightInfo().flight == flightNo;
}

bool Transaction::operator< (const TransactionInfo& key) const {
   
    if (info.ticket->getFlightInfo().departureTime == key.ticket->getFlightInfo().departureTime) {
        return info.transID < key.transID;
    }
    return info.ticket->getFlightInfo().departureTime < key.ticket->getFlightInfo().departureTime;
}

bool Transaction::operator== (const TransactionInfo& key) const {
    return info.ticket->getFlightInfo().departureTime == key.ticket->getFlightInfo().departureTime &&
           info.transID == key.transID;
}