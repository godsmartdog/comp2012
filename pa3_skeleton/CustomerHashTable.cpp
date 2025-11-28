#include "CustomerHashTable.h"

int CustomerHashTable:: hash(const string& name) const{
    int n=name.length();
    int sum=0;
    for (int i =0;i<n;i++){
        sum+= int(name[i]);
    }
    sum= sum%size;
    return sum;
}

void CustomerHashTable:: add(Customer* customer){
    if(customer==nullptr)
    return;
    int place = hash(customer->getName());
    if(table[place].find(customer->getName())!=nullptr){
        return;
    }
    table[place].add(customer);
}

Customer* CustomerHashTable:: get(const string& name) const{
    int place = hash(name);
    return table[place].find(name);
}

void CustomerHashTable:: remove(Customer* customer){
    if(customer==nullptr)
    return;
    int place = hash(customer->getName());
    if(table[place].find(customer->getName())==nullptr){
        return;
    }
    table[place].remove(customer);
}

    // * Task 2.8: hash remove
void CustomerHashTable:: clear(){
    for (int i =0;i<size;i++){
        table[i].clear();
    }
   
}
CustomerList* CustomerHashTable:: toList() const{
    CustomerList *result= new CustomerList;
    for (int i =0;i<size;i++){
        result->add(table[i]);
    }
    
}