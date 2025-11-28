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
    cout<< name<<" becomes "<< MEMBER_STATUS_LIST[memberStatus]<<" member !"<<endl;
    return;
  }
  memberStatus=0;
}

