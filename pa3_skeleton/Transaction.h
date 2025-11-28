#ifndef __TRANSACTION_H__
#define __TRANSACTION_H__

#include <iostream>
#include <cmath>

#include "Ticket.h"

using namespace std;

class Customer;

class Transaction {
  public:
    struct TransactionInfo {
      const int transID;
      Ticket* ticket;

      TransactionInfo(int id, Ticket* t) :
        transID{id}, ticket{t} {}
    };

    using KeyType = TransactionInfo;
  private:
    TransactionInfo info;
    const Datetime transTime;
    const double discount;

    Transaction(int id, Ticket* ticket, const Datetime& time, double discount) :
      info{id, ticket}, transTime{time}, discount{discount} {}

    // * Task 1.6: static
    static int transNumber;
  public:
    // * Task 1.6: static
    static Transaction* makeTransaction(Customer* customer, Ticket* ticket, const Datetime& time);

    // * Given
    bool operator< (const Transaction& other) const {
      return *this < other.info;
    }
    bool operator== (const Transaction& other) const {
      return *this == other.info;
    }

    // * Task 1.2: operator overloading
    bool operator< (const TransactionInfo& key) const;
    bool operator== (const TransactionInfo& key) const;

    // * Given
    string toString() const {
      string stime = transTime, sticket = info.ticket->toString();
      return "Transaction " + std::to_string(info.transID) + "[" + stime + "]: " + sticket;
    }

    // * Given
    int getPrice() const {
      return ceil(discount * info.ticket->getPrice());
    }

    // * Given
    bool belongsTo(const string& flightNo) const;

    // * Given
    inline Ticket* getTicket() const { return info.ticket; }
};

#endif // __TRANSACTION_H__
