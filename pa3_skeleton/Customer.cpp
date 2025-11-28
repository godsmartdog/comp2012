#include <iostream>

#include "Customer.h"
#include "Ticket.h"

using namespace std;

// * Task 4.1: constructor & destructor for data structures
Customer::Customer(const string& name) : name{name}, totalSpending{0}, transactions{nullptr} {
  cout << "Create customer " << name << "." << endl;
}

// * Task 4.1: constructor & destructor for data structures
Customer::Customer(const Customer& other) : name{other.name}, totalSpending{other.totalSpending}, transactions{nullptr} {
  cout << "Copy customer data from " << name << "." << endl;
}
