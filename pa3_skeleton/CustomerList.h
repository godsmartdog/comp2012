#ifndef __CUSTOMER_LIST_H__
#define __CUSTOMER_LIST_H__

#include <iostream>

#include "Customer.h"

class CustomerList {
  private:
    struct CustomerNode {
      Customer* data;
      CustomerNode* next;
      CustomerNode* prev;
      CustomerNode(Customer* d) : data{d}, next{nullptr}, prev{nullptr} {}
    };

    CustomerNode* head;
    CustomerNode* tail;
    int size;

  public:
    // * Given
    CustomerList() : head{nullptr}, tail{nullptr}, size{0} {}
    ~CustomerList() { clear(); }

    // * Task 2.1: insertion
    CustomerList(const CustomerList& other);

    CustomerList(CustomerList&&) = delete;
    CustomerList& operator= (const CustomerList&) = delete;
    CustomerList& operator= (CustomerList&&) = delete;

    // * Task 2.1: insertion
    void add(Customer* customer);
    void add(const CustomerList* customers);

    // * Task 2.2: remove
    void remove(Customer* customer);
    void clear();

    // * Task 2.3: searching
    Customer* find(const string& name) const;

    // * Task 2.4: iteration
    void printNames() const;

    // * Given
    void removeDeadTransactions(const string& flightNo) {
      for (CustomerNode* cur = head; cur != nullptr; cur = cur->next) {
        cur->data->removeDeadTransactions(flightNo);
      }
    }

    // * Given
    inline int getSize() const { return size; }
};

#endif // __CUSTOMER_LIST_H__
