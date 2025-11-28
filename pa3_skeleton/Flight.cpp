#include "Flight.h"
Flight::Flight(const string& num, const string& dept, const string& dest):flightNumber(num), departure(dept), destination(dest), tickets(new BST<Ticket>()){
   
   cout<< toString()<<" has been created"<<endl;
}

bool Flight:: operator< (const KeyType& key) const{
   return flightNumber<key;
}
bool Flight:: operator== (const KeyType& key) const{
   return flightNumber==key;
}


Flight:: ~Flight(){
    if (tickets != nullptr) {
        
        while (tickets->getSize() > 0) {
            const BST<Ticket>*tmp = tickets->getKth(0);
            if (tmp != nullptr) {
                Ticket* ticket = tmp->getData();
                if (ticket != nullptr) {
                    tickets->remove(ticket);
                    delete ticket;
                }
            }
        }
        delete tickets;
        tickets = nullptr;
    }
}

void Flight:: addTicket(Ticket* ticket){
   if (ticket != nullptr)
   tickets->add(ticket);
}
Ticket* Flight:: sellTicket(int index){
    if (tickets == nullptr || index < 0 || index >= tickets->getSize()) {
        return nullptr;
    }
    
    
    const BST<Ticket>* tmp = tickets->getKth(index);
    if (tmp == nullptr) {
        return nullptr;
    }
    
    Ticket* ticket = tmp->getData();
    if (ticket != nullptr) {
       
        tickets->remove(ticket);
    }
    
    return ticket;
}
void Flight::showRemainingTickets() const {
    if (tickets != nullptr) {
        tickets->print();
    }
}