#include "AirlineSystem.h"

AirlineSystem::AirlineSystem() {
  customerTable = new CustomerHashTable(7);
  flights = new BST<Flight>();
}

AirlineSystem::~AirlineSystem() {
  delete customerTable;
  customerTable = nullptr;
  delete flights;
  flights = nullptr;
}

void AirlineSystem::createCustomer(const string& name, bool isMember) {
    
    if (customerTable->get(name) != nullptr) {
        cout << "Duplicate customer " << name << "." << endl;
        return;
    }
    
    Customer* newCustomer;
    if (isMember) {
        newCustomer = new Member(name);
    } else {
        newCustomer = new Customer(name);
    }
    
    customerTable->add(newCustomer);
}

void AirlineSystem::deleteCustomer(const string& name) {
    Customer* customer = customerTable->get(name);
    if (customer != nullptr) {
        customerTable->remove(customer);
        delete customer; 
    }
}
void AirlineSystem::upgradeCustomer(const string& name) {
    Customer* customer = customerTable->get(name);
    if (customer == nullptr) {
        cout << "Customer " << name << " does not exist." << endl;
        return;
    }
    
  
    Member* tmp = dynamic_cast<Member*>(customer);
    if (tmp != nullptr) {
        cout << name << " is already a member." << endl;
        return;
    }
    

    Member* newMember = new Member(*customer);
    
   
    customerTable->remove(customer);

    customer->detachTransactions(); 
    delete customer;
    
  
    customerTable->add(newMember);
}

void AirlineSystem::createFlight(const string& num, const string& dept, const string& dest) {
 
    if (flights->find(num) != nullptr) {
        cout << "Duplicate flight " << num << "." << endl;
        return;
    }
    
    Flight* newFlight = new Flight(num, dept, dest);
    flights->add(newFlight);
}

void AirlineSystem::deleteFlight(const string& num) {
    const BST<Flight>* flight1= flights->find(num);
    if (flight1 == nullptr) {
        return; 
    }
    
    Flight* flight = flight1->getData();
    if (flight == nullptr) {
        return;
    }
    
   
    CustomerList* all = customerTable->toList();
    if (all != nullptr) {
        all->removeDeadTransactions(num);
        delete all;
    }
 
    flights->remove(flight);
    delete flight;
}

void AirlineSystem::printFlights() const {
    if (flights != nullptr) {
        flights->print();
    }
}


void AirlineSystem::createTicket(const string& flight, int seatNum, const Datetime& time, int price) {
    const BST<Flight>* flightTree = flights->find(flight);
    if (flightTree == nullptr) {
        cout << "Flight " << flight << " does not exist." << endl;
        return;
    }
    
    Flight* flight = flightTree->getData();
    if (flight == nullptr) {
        return;
    }
    
    Ticket* newTicket = new Ticket(flight, seatNum, time, price);
    flight->addTicket(newTicket);
}

void AirlineSystem::makeTransaction(const string& name, const string& flight, int index, const Datetime& time) {
    
    Customer* customer = customerTable->get(name);
    if (customer == nullptr) {
        cout << "Customer " << name << " does not exist." << endl;
        return;
    }
    
    
    const BST<Flight>* flightTree = flights->find(flight);
    if (flightTree == nullptr) {
        cout << "Flight " << flight << " does not exist." << endl;
        return;
    }
    
    Flight* flight = flightTree->getData();
    if (flight == nullptr) {
        return;
    }
    
    Ticket* ticket = flight->sellTicket(index);
    if (ticket == nullptr) {
        cout << "No ticket." << endl;
        return;
    }
    
    customer->buyTicket(ticket, time);
}

void AirlineSystem::cancelTransaction(const string& name, int index) {
    Customer* customer = customerTable->get(name);
    if (customer == nullptr) {
        cout << "Customer " << name << " does not exist." << endl;
        return;
    }
    
  
    Ticket* ticket = customer->cancelTransaction(index);
    if (ticket == nullptr) {
        cout << "Transaction " << index << " does not exist." << endl;
        return;
    }
    
    
    const Flight* flight = ticket->getFlightInfo().flight;
    if (flight != nullptr) {
        
        flight->addTicket(ticket);
    }
}

void AirlineSystem::printTransactions(const string& name) const {
    Customer* customer = customerTable->get(name);
    if (customer == nullptr) {
        cout << "Customer " << name << " does not exist." << endl;
        return;
    }
    
    customer->printTransactions();
}

void AirlineSystem::printRemainingTickets(const string& flight) const {
    const BST<Flight>* flightTree = flights->find(flight);
    if (flightTree == nullptr) {
        cout << "Flight " << flight << " does not exist." << endl;
        return;
    }
    
    Flight* flight = flightTree->getData();
    if (flight != nullptr) {
        flight->showRemainingTickets();
    }
}