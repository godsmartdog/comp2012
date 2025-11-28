#include "Flight.h"
Flight::Flight(const string& num, const string& dept, const string& dest):flightNumber(num), departure(dept), destination(dest), tickets(nullptr){
   
   cout<< toString()<<" has been created"<<endl;
}