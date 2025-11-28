#include "CustomerList.h"

CustomerList:: CustomerList(const CustomerList& other):head(nullptr),tail(nullptr),size(other.size){
    CustomerNode *cur = other.head;
    while(cur != nullptr){
        add(cur->data);
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

void CustomerList::remove(Customer* customer){
    if(customer==nullptr)
    return;
    CustomerNode* current = head;
    while (current != nullptr) {
        if(current->data==customer) {
            break;
        } 
        current = current->next;
    }
    if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                
                head = current->next;
            }
            
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                
                tail = current->prev;
            }


    delete current;
    size--;
}
void CustomerList:: clear(){
    CustomerNode* current = head;
    while (current != nullptr) {
        CustomerNode *tmp=current->next;
        delete current;
        current =tmp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

Customer* CustomerList:: find(const string& name) const{
    CustomerNode* current = head;
    while (current != nullptr) {
        if(current->data->getName()==name) {
            return current->data;
        } 
        current = current->next;
    }
    return nullptr;
}

void CustomerList:: printNames() const{
    CustomerNode* current = head;
    while (current != nullptr) {
        cout<< current->data->getName()<<endl;
        current = current->next;
    }
}