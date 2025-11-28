#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include <iostream>

#include "Transaction.h"
#include "BST.h"

using namespace std;

enum class MembershipStatus {
  BRONZE = 0,
  SILVER,
  GOLD,
  DIAMOND
};

const string MEMBER_STATUS_LIST[4] = { "BRONZE", "SILVER", "GOLD", "DIAMOND" };
constexpr int MEMBER_REQUIREMENT[3] = { 10000, 50000, 100000 };

class Customer {
  private:
    const string name;
    BST<Transaction>* transactions;
    int totalSpending;

  protected:
    // * Task 4.1: constructor & destructor for data structures
    Customer(const Customer& other);
    inline int getTotalSpending() const { return totalSpending; }
  
  public:
    // * Task 4.1: constructor & destructor for data structures
    explicit Customer(const string& name);
    // * Task 4.1: constructor & destructor for data structures
    virtual ~Customer();

    Customer(Customer&&) = delete;
    Customer& operator= (const Customer&) = delete;
    Customer& operator= (Customer&&) = delete;

    // * Task 4.3: transaction BST
    virtual void buyTicket(Ticket* ticket, const Datetime& time);
    // * Task 4.3: transaction BST
    virtual Ticket* cancelTransaction(int index);

    // * Task 1.5: virtual functions and overriding
    virtual double getDiscountedPercentage() const;

    // * Given
    inline string getName() const { return name; }

    // * Task 4.3: transaction BST
    void printTransactions() const;

    // * Task 4.3: transaction BST
    void removeDeadTransactions(const string& flightNo);

    // * Given
    void detachTransactions() {
      delete transactions;
      transactions = new BST<Transaction>();
    }
};

class Member : public Customer {
  private:
    MembershipStatus memberStatus;

    // * Task 1.3: functions
    void updateMembershipStatus();

  public:
    // * Task 1.4: inheritance
    Member(const string& name);
    // * Task 1.4: inheritance
    Member(const Customer& customer);
    ~Member() override = default;

    // * Task 1.5: virtual functions and overriding
    void buyTicket(Ticket* ticket, const Datetime& time) override;
    // * Task 1.5: virtual functions and overriding
    Ticket* cancelTransaction(int index) override;
    // * Task 1.5: virtual functions and overriding
    double getDiscountedPercentage() const override;
};


#endif // __CUSTOMER_H__
