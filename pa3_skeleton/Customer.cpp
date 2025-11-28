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

Member::void updateMembershipStatus(){
  int totalSpending = getTotalSpending();  
  
  if(totalSpending>MEMBER_REQUIREMENT[2]-1){
    memberStatus=3;
    cout<< name<<" becomes "<< MEMBER_STATUS_LIST[memberStatus]<<" member !"<<endl;
    return;
  }
  if(totalSpending>MEMBER_REQUIREMENT[1]-1){
    memberStatus=2;
    cout<< name<<" becomes "<< MEMBER_STATUS_LIST[memberStatus]<<" member !"<<endl;
    return;
  }
  if(totalSpending>MEMBER_REQUIREMENT[0]-1){
    memberStatus=1;
    cout<< getName()<<" becomes "<< MEMBER_STATUS_LIST[memberStatus]<<" member !"<<endl;
    return;
  }
  memberStatus=0;
}

Member::Member(const string& name):Customer(name),memberStatus(0){
 cout<< "Hello new member "<<name<<"!"<<endl;
}
Member::Member(const Customer& customer):Customer(customer){
  updateMembershipStatus();

}

virtual double Customer:: getDiscountedPercentage() const{
  return 1;
}

void Member:: buyTicket(Ticket* ticket, const Datetime& time) override{
 Customer::buyTicket(ticket,time);
 updateMembershipStatus();
}
// * Task 1.5: virtual functions and overriding
Ticket* Member ::cancelTransaction(int index) override{
  Ticket* ticket=Customer:: cancelTransaction(index);
  updateMembershipStatus();
  return ticket;
}
// * Task 1.5: virtual functions and overriding
double Member ::getDiscountedPercentage() const override{
  switch(memberStatus):
    case 0:
    return 0.95;
    case 1: return 0.9;
    case 2: return 0.88;
    case 3: return 0.85
}

