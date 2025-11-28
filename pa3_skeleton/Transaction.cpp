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

int Transaction:: transNumber=0;
 Transaction* Transaction:: makeTransaction(Customer* customer, Ticket* ticket, const Datetime& time){
    if(customer==nullptr|| ticket == nullptr){
        cout<< "Invalid transaction!"<<endl;
        return nullptr;
    }
    Transaction *tmp= new Transaction(transNumber, ticket,time,customer->getDiscountedPercentage());
    
    cout<<"[Transaction "<<transNumber<<"]: "<< ticket->toString() <<" by "<< customer->getName()<<endl;
    transNumber++;
    return tmp;
}