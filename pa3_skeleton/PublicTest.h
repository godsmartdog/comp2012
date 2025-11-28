#ifndef __PREDEF_TEST__
#define __PREDEF_TEST__

#include <cassert>

#include "AirlineSystem.h"

template <int ID>
void runTestCase() {
  cout << "wrong test number" << endl;
}

struct MyInt {
  int v;

  MyInt() : v{0} {}
  MyInt(int x): v{x} {}

  bool operator< (const MyInt& m) const { return v < m.v; }
  bool operator== (const MyInt& m) const { return v == m.v; }
  bool operator< (int x) const { return v < x; }
  bool operator== (int x) const { return v == x; }

  string toString() const { return to_string(v); }

  using KeyType = int;
};

#endif

template <>
void runTestCase<0>() {
  Flight* flight = new Flight("CX739", "Hong Kong", "Singapore");
  delete flight;
}

template <>
void runTestCase<1>() {
  Flight* flight1 = new Flight("CX739", "Hong Kong", "Singapore");
  Flight* flight2 = new Flight("CX734" , "Singapore", "Hong Kong");
  assert(*flight1 == *flight1);
  assert(*flight2 < *flight1);
  delete flight1;
  delete flight2;
}

template <>
void runTestCase<2>() {
  Flight* flight = new Flight("CX739", "Hong Kong", "Singapore");
  Ticket* ticket1 = new Ticket(flight, 72, Datetime("2025-10-15 11:15"), 1000);
  Ticket* ticket2 = new Ticket(flight, 72, Datetime("2025-10-19 11:15"), 1000);
  cout << ticket1->toString() << endl;
  cout << ticket2->toString() << endl;
  assert(*ticket1 == *ticket1);
  assert(*ticket1 < *ticket2);
  delete ticket2;
  delete ticket1;
  delete flight;
}

template <>
void runTestCase<3>() {
  Member* member = new Member("John Wick");
  delete member;
}

template <>
void runTestCase<4>() {
  Customer* customer = new Customer("John Wick");
  Member* member = new Member(*customer);
  delete member;
  delete customer;
}

template <>
void runTestCase<5>() {
  Member* member = new Member("John Wick");
  assert(member->getDiscountedPercentage() == 0.95);
  member->buyTicket(nullptr, Datetime("2025-09-15 12:00"));
  assert(member->cancelTransaction(-1) == nullptr);
  delete member;
}

template <>
void runTestCase<6>() {
  Flight* flight = new Flight("CX739", "Hong Kong", "Singapore");
  Ticket* ticket = new Ticket(flight, 72, Datetime("2025-10-15 11:15"), 1000);
  Customer* customer = new Customer("John Wick");
  Transaction* trans = Transaction::makeTransaction(customer, ticket, Datetime("2025-09-30 12:00"));

  delete trans;
  delete customer;
  delete ticket;
  delete flight;
}

template <>
void runTestCase<7>() {
  Flight* flight = new Flight("CX739", "Hong Kong", "Singapore");
  Ticket* ticket1 = new Ticket(flight, 72, Datetime("2025-10-15 11:15"), 1000);
  Ticket* ticket2 = new Ticket(flight, 2, Datetime("2025-10-18 11:15"), 3000);
  Customer* customer = new Customer("John Wick");
  Transaction* trans1 = Transaction::makeTransaction(customer, ticket1, Datetime("2025-09-30 12:00"));
  Transaction* trans2 = Transaction::makeTransaction(customer, ticket2, Datetime("2025-10-01 12:00"));

  assert(*trans1 == *trans1);
  assert(*trans1 < *trans2);

  delete trans1;
  delete trans2;
  delete customer;
  delete ticket1;
  delete ticket2;
  delete flight;
}

template <>
void runTestCase<8>() {
  Flight* flight = new Flight("CX739", "Hong Kong", "Singapore");
  Ticket* ticket1 = new Ticket(flight, 72, Datetime("2025-10-15 11:15"), 1000);
  Ticket* ticket2 = new Ticket(flight, 2, Datetime("2025-10-14 11:15"), 3000);
  Customer* customer = new Customer("John Wick");
  Transaction* trans1 = Transaction::makeTransaction(customer, ticket1, Datetime("2025-10-11 12:00"));
  Transaction* trans2 = Transaction::makeTransaction(customer, ticket2, Datetime("2025-10-12 12:00"));

  assert(*trans2 < *trans1);

  delete trans1;
  delete trans2;
  delete customer;
  delete ticket1;
  delete ticket2;
  delete flight;
}

template <>
void runTestCase<9>() {
  Flight* flight = new Flight("CX739", "Hong Kong", "Singapore");
  Ticket* ticket1 = new Ticket(flight, 72, Datetime("2025-10-15 11:15"), 1000);
  Ticket* ticket2 = new Ticket(flight, 2, Datetime("2025-10-15 11:15"), 3000);
  Customer* customer = new Customer("John Wick");
  Transaction* trans1 = Transaction::makeTransaction(customer, ticket1, Datetime("2025-10-12 12:00"));
  Transaction* trans2 = Transaction::makeTransaction(customer, ticket2, Datetime("2025-10-12 12:00"));

  assert(*trans1 < *trans2);

  delete trans1;
  delete trans2;
  delete customer;
  delete ticket1;
  delete ticket2;
  delete flight;
}

template <>
void runTestCase<10>() {
  CustomerList* list = new CustomerList();
  Customer* customer = new Customer("John Wick");
  list->add(customer);
  assert(list->getSize() == 1);
  delete list;
  delete customer;
}

template <>
void runTestCase<11>() {
  CustomerList* list = new CustomerList();
  Customer** customers = new Customer*[10];

  for (int i = 0; i < 10; ++i) {
    string name = "John Wick No " + to_string(i);
    customers[i] = (i & 1) ? new Customer(name) : new Member(name);
    list->add(customers[i]);
  }

  CustomerList* list2 = new CustomerList(*list);

  assert(list->getSize() == 10);
  assert(list2->getSize() == 10);
  list->clear();
  assert(list->getSize() == 0);
  assert(list2->getSize() == 10);

  for (int i = 0; i < 10; ++i) {
    delete customers[i];
  }

  delete list2;
  delete list;
  delete[] customers;
}

template <>
void runTestCase<12>() {
  CustomerList* list = new CustomerList();
  Customer** customers = new Customer*[10];

  for (int i = 0; i < 10; ++i) {
    string name = "John Wick No " + to_string(i);
    customers[i] = (i & 1) ? new Customer(name) : new Member(name);
    list->add(customers[i]);
  }

  for (int i = 1; i < 10; i += 2) {
    list->remove(customers[i]);
    delete customers[i];
  }

  assert(list->getSize() == 5);

  for (int i = 0; i < 10; i += 2) {
    delete customers[i];
  }

  delete list;
  delete[] customers;
}

template <>
void runTestCase<13>() {
  CustomerList* list = new CustomerList();
  Customer** customers = new Customer*[10];

  for (int i = 0; i < 10; ++i) {
    string name = "John Wick No " + to_string(i);
    customers[i] = (i & 1) ? new Customer(name) : new Member(name);
    list->add(customers[i]);
  }

  for (int i = 0; i < 10; ++i) {
    string name = "John Wick No " + to_string(i);
    assert(list->find(name) == customers[i]);
  }

  for (int i = 0; i < 10; ++i) {
    string name = "Johnny Silverhand No " + to_string(i);
    assert(list->find(name) == nullptr);
  }

  for (int i = 0; i < 10; ++i) {
    delete customers[i];
  }

  delete list;
  delete[] customers;
}

template <>
void runTestCase<14>() {
  CustomerList* list = new CustomerList();
  Customer** customers = new Customer*[10];

  for (int i = 0; i < 10; ++i) {
    string name = "John Wick No " + to_string(i);
    customers[i] = (i & 1) ? new Customer(name) : new Member(name);
    list->add(customers[i]);
  }

  list->printNames();

  for (int i = 0; i < 10; ++i) {
    delete customers[i];
  }

  delete list;
  delete[] customers;
}

template <>
void runTestCase<15>() {
  CustomerHashTable* table = new CustomerHashTable(5);
  Customer* customer1 = new Customer("A");
  Customer* customer2 = new Customer("B");
  Customer* customer3 = new Customer("C");
  Customer* customer4 = new Customer("D");
  Customer* customer5 = new Customer("E");
  Customer* customer6 = new Customer("F");

  table->add(customer1);
  table->add(customer2);
  table->add(customer3);
  table->add(customer4);
  table->add(customer5);
  table->add(customer6);

  table->printNames();

  delete table;
  delete customer1;
  delete customer2;
  delete customer3;
  delete customer4;
  delete customer5;
  delete customer6;
}

template <>
void runTestCase<16>() {
  CustomerHashTable* table = new CustomerHashTable(5);
  Customer* customer1 = new Customer("A");
  Customer* customer2 = new Customer("B");
  Customer* customer3 = new Customer("C");
  Customer* customer4 = new Customer("D");
  Customer* customer5 = new Customer("E");
  Customer* customer6 = new Customer("F");

  table->add(customer1);
  table->add(customer2);
  table->add(customer3);
  table->add(customer4);
  table->add(customer5);
  table->add(customer6);

  assert(table->get("A") == customer1);
  assert(table->get("C") == customer3);
  assert(table->get("E") == customer5);
  assert(table->get("G") == nullptr);

  delete table;
  delete customer1;
  delete customer2;
  delete customer3;
  delete customer4;
  delete customer5;
  delete customer6;
}

template <>
void runTestCase<17>() {
  CustomerHashTable* table = new CustomerHashTable(5);
  Customer* customer1 = new Customer("A");
  Customer* customer2 = new Customer("B");
  Customer* customer3 = new Customer("C");
  Customer* customer4 = new Customer("D");
  Customer* customer5 = new Customer("E");
  Customer* customer6 = new Customer("F");

  table->add(customer1);
  table->add(customer2);
  table->add(customer3);
  table->add(customer4);
  table->add(customer5);
  table->add(customer6);

  table->remove(customer1);
  table->remove(customer2);
  table->remove(customer5);
  table->remove(customer6);

  table->printNames();

  delete table;
  delete customer1;
  delete customer2;
  delete customer3;
  delete customer4;
  delete customer5;
  delete customer6;
}

template <>
void runTestCase<18>() {
  CustomerHashTable* table = new CustomerHashTable(5);
  Customer* customer1 = new Customer("A");
  Customer* customer2 = new Customer("B");
  Customer* customer3 = new Customer("C");
  Customer* customer4 = new Customer("D");
  Customer* customer5 = new Customer("E");
  Customer* customer6 = new Customer("F");

  table->add(customer1);
  table->add(customer2);
  table->add(customer3);
  table->add(customer4);
  table->add(customer5);
  table->add(customer6);

  CustomerList* list = table->toList();
  list->printNames();

  delete list;
  delete table;
  delete customer1;
  delete customer2;
  delete customer3;
  delete customer4;
  delete customer5;
  delete customer6;
}

template <>
void runTestCase<19>() {
  CustomerHashTable* table = new CustomerHashTable(5);
  Customer* customer1 = new Customer("E");
  Customer* customer2 = new Customer("J");
  Customer* customer3 = new Customer("O");
  Customer* customer4 = new Customer("T");

  table->add(customer1);
  table->add(customer2);
  table->add(customer3);
  table->add(customer4);

  table->printNames();
  CustomerList* list = table->toList();
  list->printNames();

  delete list;
  delete table;
  delete customer1;
  delete customer2;
  delete customer3;
  delete customer4;
}

template<>
void runTestCase<20>() {
  BST<MyInt>* t1 = new BST<MyInt>();
  MyInt p = 42;
  t1->add(&p);
  t1->add(nullptr);

  BST<MyInt>* t2 = new BST<MyInt>(*t1);
  t1->print();
  t2->print();
 
  delete t1;
  delete t2;
}

template<>
void runTestCase<21>() {
  BST<MyInt>* t = new BST<MyInt>();
  MyInt arr[8] { 24, 8, 27, 2, 16, 29, 1, 28 };

  for (int i = 0; i < 8; ++i) {
    t->add(&arr[i]);
  }

  t->print();
 
  delete t;
}

template<>
void runTestCase<22>() {
  BST<MyInt>* t = new BST<MyInt>();
  MyInt arr[10];

  for (int i = 0; i < 10; ++i) {
    arr[i] = 42 - i;
    t->add(&arr[i]);
  }

  BST<MyInt>* t2 = new BST<MyInt>(*t);
  t2->print();
 
  delete t2;
  delete t;
}

template<>
void runTestCase<23>() {
  BST<MyInt>* t = new BST<MyInt>();
  MyInt arr[8] { 24, 8, 27, 2, 16, 29, 1, 28 };

  for (int i = 0; i < 8; ++i) {
    t->add(&arr[i]);
  }

  BST<MyInt>* t2 = new BST<MyInt>(*t);
  t->clear();
  t->print();
  t2->print();
 
  delete t2;
  delete t;
}

template<>
void runTestCase<24>() {
  BST<MyInt>* t = new BST<MyInt>();
  MyInt arr[8] { 24, 8, 27, 2, 16, 29, 1, 28 };

  for (int i = 0; i < 8; ++i) {
    t->add(&arr[i]);
  }

  for (int i = 0; i < 8; ++i) {
    assert(t->find(arr[i].v)->getData() == &arr[i]);
  }

  assert(t->find(114) == nullptr);
  assert(t->find(-1) == nullptr);

  t->print();
 
  delete t;
}

template<>
void runTestCase<25>() {
  BST<MyInt>* t = new BST<MyInt>();
  MyInt arr[10];

  assert(t->getData() == nullptr);

  for (int i = 0; i < 10; ++i) {
    arr[i] = 42 - i;
    t->add(&arr[i]);
  }

  for (int i = 0; i < 10; ++i) {
    assert(t->find(arr[i].v)->getData() == &arr[i]);
  }

  assert(t->find(114) == nullptr);
  assert(t->find(-1) == nullptr);

  t->print();
 
  delete t;
}

template<>
void runTestCase<26>() {
  BST<MyInt>* t = new BST<MyInt>();
  MyInt arr[8] { 24, 8, 27, 2, 16, 29, 1, 28 };
  int res[8] { 1, 2, 8, 16, 24, 27, 28, 29 };

  for (int i = 0; i < 8; ++i) {
    t->add(&arr[i]);
  }

  for (int i = 0; i < 8; ++i) {
    assert(t->getKth(i)->getData()->v == res[i]);
  }

  t->print();
 
  delete t;
}

template<>
void runTestCase<27>() {
  BST<MyInt>* t = new BST<MyInt>();
  MyInt arr[10];
  int res[10] { 33, 34, 35, 36, 37, 38, 39, 40, 41, 42 };

  for (int i = 0; i < 10; ++i) {
    arr[i] = 42 - i;
    t->add(&arr[i]);
  }

  for (int i = 0; i < 10; ++i) {
    assert(t->getKth(i)->getData()->v == res[i]);
  }

  t->print();
 
  delete t;
}

template<>
void runTestCase<28>() {
  BST<MyInt>* t = new BST<MyInt>();
  MyInt arr[10] { 0, -10, 22, -8, 19, -11, 24, -6, 1, -3 };

  for (int i = 0; i < 10; ++i) {
    t->add(&arr[i]);
  }

  t->remove(nullptr);

  for (int i = 0; i < 10; ++i) {
    t->print();
    cout << "---" << endl;
    t->remove(&arr[i]);
  }

  assert(t->getSize() == 0);
 
  delete t;
}

template<>
void runTestCase<29>() {
  BST<MyInt>* t = new BST<MyInt>();
  MyInt arr[10] { 0, -10, 22, -8, 19, -11, 24, -6, 1, -3 };

  for (int i = 0; i < 10; ++i) {
    t->add(&arr[i]);
  }

  for (int i = 9; i > -1; --i) {
    t->print();
    cout << "---" << endl;
    t->remove(&arr[i]);
  }

  assert(t->getSize() == 0);
 
  delete t;
}

template<>
void runTestCase<30>() {
  Flight* flight = new Flight("CX739", "Hong Kong", "Singapore");
  Datetime time[10] { "2025-10-15 11:15", "2025-10-01 11:15", "2025-10-30 11:15", "2025-10-12 11:15", "2025-10-20 11:15",
    "2025-10-10 11:15", "2025-10-14 11:15", "2025-10-16 11:15", "2025-10-28 11:15", "2025-10-31 11:15"};
  Ticket** tickets = new Ticket*[10];

  for (int i = 0; i < 10; ++i) {
    tickets[i] = new Ticket(flight, 42, time[i], 3000);
    flight->addTicket(tickets[i]);
  }

  flight->showRemainingTickets();

  for (int i = 8; i > -1; i -= 2) {
    Ticket* t = flight->sellTicket(i);
    delete t;
  }

  flight->showRemainingTickets();
  delete[] tickets;
  delete flight;
}

template<>
void runTestCase<31>() {
  Flight* flight = new Flight("CX739", "Hong Kong", "Singapore");
  Datetime time[10] { "2025-10-15 11:15", "2025-10-01 11:15", "2025-10-30 11:15", "2025-10-12 11:15", "2025-10-20 11:15",
    "2025-10-10 11:15", "2025-10-14 11:15", "2025-10-16 11:15", "2025-10-28 11:15", "2025-10-31 11:15"};
  Ticket** tickets = new Ticket*[10];
  Customer* member = new Member("John Wick");

  for (int i = 0; i < 10; ++i) {
    tickets[i] = new Ticket(flight, i + 1, time[i], 3000);
    flight->addTicket(tickets[i]);
  }

  for (int i = 9; i > -1; i -= 2) {
    Ticket* t = flight->sellTicket(i);
    member->buyTicket(t, Datetime("2025-10-03 09:00"));
  }

  member->printTransactions();
  Ticket* t = member->cancelTransaction(0);
  delete t;

  flight->showRemainingTickets();
  delete member;
  delete[] tickets;
  delete flight;
}

template<>
void runTestCase<32>() {
  Flight* flight = new Flight("CX739", "Hong Kong", "Singapore");
  Customer* member = new Member("John Wick");

  for (int i = 0; i < 10; ++i) {
    Ticket* ticket = new Ticket(flight, i + 1, Datetime("2025-10-15 11:15"), 3000);
    flight->addTicket(ticket);
  }

  for (int i = 0; i < 10; ++i) {
    Ticket* t = flight->sellTicket(0);
    member->buyTicket(t, Datetime("2025-10-03 09:00"));
  }

  member->removeDeadTransactions("CX114");
  member->printTransactions();

  member->removeDeadTransactions("CX739");
  member->printTransactions();

  delete flight;

  delete member;
}

template<>
void runTestCase<33>() {
  Flight* flight = new Flight("CX739", "Hong Kong", "Singapore");
  Datetime time[10] { "2025-10-15 11:15", "2025-10-01 11:15", "2025-10-30 11:15", "2025-10-12 11:15", "2025-10-20 11:15",
    "2025-10-10 11:15", "2025-10-14 11:15", "2025-10-16 11:15", "2025-10-28 11:15", "2025-10-31 11:15"};
  Ticket** tickets = new Ticket*[10];
  CustomerList* list = new CustomerList();
  Customer** customers = new Customer*[10];

  for (int i = 0; i < 10; ++i) {
    tickets[i] = new Ticket(flight, 20 - i, time[i], 3000);
    flight->addTicket(tickets[i]);
  }

  assert(Transaction::makeTransaction(nullptr, tickets[0], Datetime("2024-12-30 12:00")) == nullptr);
  assert(Transaction::makeTransaction(customers[0], nullptr, Datetime("2024-12-30 12:00")) == nullptr);

  for (int i = 0; i < 10; ++i) {
    string name = "John Wick No " + to_string(i);
    customers[i] = (i & 1) ? new Customer(name) : new Member(name);
    Ticket* t = flight->sellTicket((i == 9) ? 0 : 1);
    customers[i]->buyTicket(t, Datetime("2025-10-01 04:30"));
    list->add(customers[i]);
    customers[i]->printTransactions();
    flight->showRemainingTickets();
  }

  list->removeDeadTransactions("CX739");

  for (int i = 0; i < 10; ++i) {
    delete customers[i];
  }

  delete list;
  delete[] customers;
  delete flight;
  delete[] tickets;
}

template<>
void runTestCase<34>() {
  AirlineSystem* system = new AirlineSystem();

  for (int i = 0; i < 10; ++i) {
    string name = "John Wick No " + to_string(i);
    system->createCustomer(name, false);
  }

  for (int i = 0; i < 10; i += 2) {
    string name = "John Wick No " + to_string(i);
    system->upgradeCustomer(name);
  }

  for (int i = 0; i < 10; ++i) {
    string name = "John Wick No " + to_string(i);
    system->deleteCustomer(name);
  }

  delete system;
}

template<>
void runTestCase<35>() {
  AirlineSystem* system = new AirlineSystem();

  for (int i = 0; i < 10; ++i) {
    string name = "CX79" + to_string(i);
    string from = "city" + to_string(i);
    string to = "city" + to_string(i + 1);
    system->createFlight(name, from, to);
  }

  system->printFlights();

  for (int i = 0; i < 10; ++i) {
    string name = "CX79" + to_string(i);
    system->deleteFlight(name);
  }

  delete system;
}

template<>
void runTestCase<36>() {
  AirlineSystem* system = new AirlineSystem();
  string flights[6] = {
    "CX796", "CX793", "CX795", "CX797", "CX798", "CX794"
  };
  Datetime time[5] = {
    "2025-10-15 11:15", "2025-10-17 11:15", "2025-10-19 11:15", "2025-10-16 11:15", "2025-10-14 11:15"
  };

  for (int i = 0; i < 6; ++i) {
    string from = "city" + to_string(i);
    string to = "city" + to_string(i + 1);
    system->createFlight(flights[i], from, to);

    for (int j = 0; j < 5; ++j) {
      system->createTicket(flights[i], 70 + j, time[j], 4000 + j * 100);
    }
  }

  for (int i = 0; i < 6; ++i) {
    system->printRemainingTickets(flights[i]);
    cout << "---" << endl;
  }

  for (int i = 0; i < 6; ++i) {
    system->deleteFlight(flights[i]);
  }

  delete system;
}

template<>
void runTestCase<37>() {
  AirlineSystem* system = new AirlineSystem();
  string flights[6] = {
    "CX796", "CX793", "CX795", "CX797", "CX798", "CX794"
  };
  Datetime time[5] = {
    "2025-10-15 11:15", "2025-10-17 11:15", "2025-10-19 11:15", "2025-10-16 11:15", "2025-10-14 11:15"
  };

  for (int i = 0; i < 5; ++i) {
    string name = "John Wick No " + to_string(i);
    system->createCustomer(name, i & 1);
  }

  for (int i = 0; i < 6; ++i) {
    string from = "city" + to_string(i);
    string to = "city" + to_string(i + 1);
    system->createFlight(flights[i], from, to);

    for (int j = 0; j < 5; ++j) {
      system->createTicket(flights[i], 70 + j, time[j], 4000 + i * 100);
    }
  }

  for (int i = 0; i < 5; ++i) {
    string customer = "John Wick No " + to_string(i);
    system->makeTransaction(customer, flights[i], i, Datetime("2024-10-15 11:15"));
  }

  for (int i = 0; i < 5; ++i) {
    string name = "John Wick No " + to_string(i);
    system->printTransactions(name);
    system->deleteCustomer(name);
  }

  for (int i = 0; i < 6; ++i) {
    system->printRemainingTickets(flights[i]);
    system->deleteFlight(flights[i]);
  }

  delete system;
}

template<>
void runTestCase<38>() {
  AirlineSystem* system = new AirlineSystem();
  string flights[6] = {
    "CX796", "CX793", "CX795", "CX797", "CX798", "CX794"
  };
  Datetime time[5] = {
    "2025-10-15 11:15", "2025-10-17 11:15", "2025-10-19 11:15", "2025-10-16 11:15", "2025-10-14 11:15"
  };

  for (int i = 0; i < 5; ++i) {
    string name = "John Wick No " + to_string(i);
    system->createCustomer(name, i & 1);
  }

  for (int i = 0; i < 6; ++i) {
    string from = "city" + to_string(i);
    string to = "city" + to_string(i + 1);
    system->createFlight(flights[i], from, to);

    for (int j = 0; j < 5; ++j) {
      system->createTicket(flights[i], 70 + j, time[j], 10000 + i * 400);
    }
  }

  for (int i = 0; i < 5; ++i) {
    string customer = "John Wick No " + to_string(i);
    system->makeTransaction(customer, flights[i], i, Datetime("2024-10-15 11:15"));
  }

  for (int i = 0; i < 6; ++i) {
    system->deleteFlight(flights[i]);
  }

  for (int i = 0; i < 5; ++i) {
    string name = "John Wick No " + to_string(i);
    system->printTransactions(name);
    system->deleteCustomer(name);
  }

  delete system;
}

template<>
void runTestCase<39>() {
  AirlineSystem* system = new AirlineSystem();
  string flights[6] = {
    "CX796", "CX793", "CX795", "CX797", "CX798", "CX794"
  };
  Datetime time[5] = {
    "2025-10-15 11:15", "2025-10-17 11:15", "2025-10-19 11:15", "2025-10-16 11:15", "2025-10-14 11:15"
  };

  for (int i = 0; i < 5; ++i) {
    string name = "John Wick No " + to_string(i);
    system->createCustomer(name, i & 1);
  }

  for (int i = 0; i < 6; ++i) {
    string from = "city" + to_string(i);
    string to = "city" + to_string(i + 1);
    system->createFlight(flights[i], from, to);

    for (int j = 0; j < 5; ++j) {
      system->createTicket(flights[i], 70 - j, time[j], 4500);
    }
  }

  for (int i = 0; i < 5; ++i) {
    string customer = "John Wick No " + to_string(i);
    system->makeTransaction(customer, flights[i], 2, Datetime("2024-10-15 11:15"));
    system->makeTransaction(customer, flights[i], 3, Datetime("2024-10-16 11:15"));
    system->makeTransaction(customer, flights[i], 0, Datetime("2024-10-17 11:15"));
    system->cancelTransaction(customer, 1);
    system->printTransactions(customer);
  }

  for (int i = 0; i < 5; ++i) {
    string name = "John Wick No " + to_string(i);
    system->deleteCustomer(name);
  }

  for (int i = 0; i < 6; ++i) {
    system->deleteFlight(flights[i]);
  }

  delete system;
}

