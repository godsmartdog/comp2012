#ifndef __CUSTOMER_HASH_TABLE_H__
#define __CUSTOMER_HASH_TABLE_H__

#include "CustomerList.h"

class CustomerHashTable {
  private: 
    CustomerList* table;
    int size;

    // * Task 2.5: hashing
    int hash(const string& name) const;

  public:
    // * Given
    explicit CustomerHashTable(int size) : size(size) {
      table = new CustomerList[size];
    }

    // * Given
    ~CustomerHashTable() {
      clear();
      delete[] table;
    }

    // * Task 2.6: hash insertion
    void add(Customer* customer);

    // * Task 2.7: hash searching
    Customer* get(const string& name) const;

    // * Task 2.8: hash remove
    void remove(Customer* customer);

    // * Task 2.8: hash remove
    void clear();

    // * Given
    int getSize() const {
      int sum = 0;
      for (int i = 0; i < size; ++i) {
        sum += table[i].getSize();
      }

      return sum;
    }

    // * Given
    void printNames() const {
      for (int i = 0; i < size; ++i) {
        table[i].printNames();
        cout << "---" << endl;
      }
    }

    // * Task 2.9: hash iteration
    CustomerList* toList() const;
};

#endif // __CUSTOMER_HASH_TABLE_H__
