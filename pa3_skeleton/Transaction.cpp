#include "Transaction.h"

#include <cmath>

#include "Flight.h"
#include "Customer.h"


bool Transaction::belongsTo(const string& flightNo) const {
  return *info.ticket->getFlightInfo().flight == flightNo;
}
