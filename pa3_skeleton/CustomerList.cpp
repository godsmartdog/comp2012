#include "CustomerList.h"

CustomerList:: CustomerList(const CustomerList& other):head(nullptr),tail(nullptr),size(other.size){
    CustomerNode *cur = other->head;
    while(cur != nullptr){
        add(other->data);
        cur=cur->next;
    }
}
void CustomerList::add(Customer* customer) {
    CustomerNode* newNode = new CustomerNode(customer);
    
    if (head == nullptr) {
      
        head = newNode;
        tail = newNode;
    } else {
      
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void CustomerList::add(const CustomerList* customers) {
    if (customers == nullptr) return;
    
    CustomerNode* current = customers->head;
    while (current != nullptr) {
        add(current->data);  
        current = current->next;
    }
}