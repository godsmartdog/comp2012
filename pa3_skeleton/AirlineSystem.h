#ifndef __AIRLINE_SYSTEM_H__
#define __AIRLINE_SYSTEM_H__

#include "BST.h"
#include "CustomerHashTable.h"
#include "Flight.h"

class AirlineSystem {
  private:
    CustomerHashTable* customerTable;
    BST<Flight>* flights;

  public:
    // * Given
    AirlineSystem();
    ~AirlineSystem();
    // * ---

    AirlineSystem(const AirlineSystem&) = delete;
    AirlineSystem(AirlineSystem&&) = delete;
    AirlineSystem& operator= (const AirlineSystem&) = delete;
    AirlineSystem& operator= (AirlineSystem&&) = delete;

    // * Task 4.4: customer table
    void createCustomer(const string& name, bool isMember);
    void deleteCustomer(const string& name);
    void upgradeCustomer(const string& name);
    // * ---

    // * Task 4.5: flight BST
    void createFlight(const string& num, const string& dept, const string& dest);
    void deleteFlight(const string& num);
    void printFlights() const;
    // * ---

    // * Task 4.6: ticket and transaction
    void createTicket(const string& flight, int seatNum, const Datetime& time, int price);
    void makeTransaction(const string& name, const string& flight, int index, const Datetime& time);
    void cancelTransaction(const string& name, int num);
    void printTransactions(const string& name) const;
    void printRemainingTickets(const string& flight) const;
    // * ---
};

#endif // __AIRLINE_SYSTEM_H__
