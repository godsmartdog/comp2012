#include <iostream>

#include "Customer.h"
#include "Ticket.h"

using namespace std;

// * Task 4.1: constructor & destructor for data structures
Customer::Customer(const string& name) : name{name}, totalSpending{0}, transactions{new BST<Transaction> } {
  cout << "Create customer " << name << "." << endl;
}

// * Task 4.1: constructor & destructor for data structures
Customer::Customer(const Customer& other) : name{other.name}, totalSpending{other.totalSpending}, transactions{new BST<Transaction>(*(other.transactions))} {
  cout << "Copy customer data from " << name << "." << endl;
}

Customer::~Customer() {
    if (transactions != nullptr) {
        // Delete all transactions and their tickets manually
        while (transactions->getSize() > 0) {
            const BST<Transaction>* node = transactions->getKth(0);
            if (node != nullptr) {
                Transaction* trans = node->getData();
                if (trans != nullptr) {
                    // Get the ticket before removing transaction
                    Ticket* ticket = trans->getTicket();
                    // Remove from BST
                    transactions->remove(trans);
                    // Delete the ticket and transaction
                    delete ticket;
                    delete trans;
                }
            }
        }
        delete transactions;
        transactions = nullptr;
    }
}

void Member:: updateMembershipStatus(){
  int totalSpending = getTotalSpending();  
  
  if(totalSpending>MEMBER_REQUIREMENT[2]-1){
    memberStatus = static_cast<MembershipStatus>(3);
    cout<< getName()<<" becomes "<< MEMBER_STATUS_LIST[3]<<" member!"<<endl;
    return;
  }
  if(totalSpending>MEMBER_REQUIREMENT[1]-1){
    memberStatus = static_cast<MembershipStatus>(2);
    cout<< getName()<<" becomes "<< MEMBER_STATUS_LIST[2]<<" member!"<<endl;
    return;
  }
  if(totalSpending>MEMBER_REQUIREMENT[0]-1){
    memberStatus = static_cast<MembershipStatus>(1);
    cout<< getName()<<" becomes "<< MEMBER_STATUS_LIST[1]<<" member!"<<endl;
    return;
  }
  memberStatus = static_cast<MembershipStatus>(0);
  cout<< getName()<<" becomes "<< MEMBER_STATUS_LIST[0]<<" member!"<<endl;
}

Member::Member(const string& name):Customer(name),memberStatus(static_cast<MembershipStatus>(0)){
 cout<< "Hello new member "<<name<<"!"<<endl;
}
Member::Member(const Customer& customer):Customer(customer){
  updateMembershipStatus();

}

double Customer:: getDiscountedPercentage() const{
  return 1;
}

void Member:: buyTicket(Ticket* ticket, const Datetime& time){
 Customer::buyTicket(ticket,time);
 updateMembershipStatus();
}
// * Task 1.5: virtual functions and overriding
Ticket* Member ::cancelTransaction(int index) {
  Ticket* ticket=Customer:: cancelTransaction(index);
  updateMembershipStatus();
  return ticket;
}
// * Task 1.5: virtual functions and overriding
double Member ::getDiscountedPercentage() const{
  switch(memberStatus){
    case  static_cast<MembershipStatus>(0):
    return 0.95;
    case  static_cast<MembershipStatus>(1): return 0.9;
    case  static_cast<MembershipStatus>(2): return 0.88;
    case  static_cast<MembershipStatus>(3): return 0.85;}
}


void Customer::buyTicket(Ticket* ticket, const Datetime& time) {
    if (ticket == nullptr) {
        return;
    }
    
   
    Transaction* transaction = Transaction::makeTransaction(this, ticket, time);
    if (transaction != nullptr) {
        
        transactions->add(transaction);

        int price = transaction->getPrice();
        totalSpending += price;
        
        cout << name << " spent " << price << "." << endl;
    }
}

Ticket* Customer::cancelTransaction(int index) {
    if (transactions == nullptr || index < 0 || index >= transactions->getSize()) {
        return nullptr;
    }
    
 
    const BST<Transaction>* transTree = transactions->getKth(index);
    if (transTree == nullptr) {
        return nullptr;
    }
    
    Transaction* transaction = transTree->getData();
    if (transaction == nullptr) {
        return nullptr;
    }
    

    transactions->remove(transaction);
   
    int price = transaction->getPrice();
    totalSpending -= price;

    Ticket* ticket = transaction->getTicket();
    
    delete transaction;
    
    return ticket;
}
    // * Task 4.3: transaction BST

void Customer::printTransactions() const{
  if(transactions!=nullptr){
    transactions->print();
  }
}

void Customer::removeDeadTransactions(const string& flightNo) {
    if (transactions == nullptr) return;
    
    
    for (int i = transactions->getSize() - 1; i >= 0; i--) {
        const BST<Transaction>* transTree = transactions->getKth(i);
        if (transTree != nullptr) {
            Transaction* trans = transTree->getData();
            if (trans != nullptr && trans->belongsTo(flightNo)) {
                transactions->remove(trans);
                Ticket* ticket = trans->getTicket();
                delete trans;
                delete ticket;
            }
        }
    }
}