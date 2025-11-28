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