#include "BST.h"
#include <iostream>

using namespace std;

/**
 * Returns an integer < 0 if the first Song is shorter compared to the second,
 * 0 if they are equivalent, or > 0 if the first Song is longer than the second.
 */
int compare_by_length(const Song& one, const Song& two){
    if(one.length<two.length){
        return -1;
    }
    return (one.length>two.length?1:0);
}

/**
 * Returns an integer < 0 if the name of the first Song is lexicographically before the name of the second,
 * 0 if they are equivalent, or > 0 if the name of the first Song is lexicographically after the name of the second.
 */
int compare_by_name(const Song& one, const Song& two){
   int tmp = compare_by_length(one, two);
   int sizel;
   bool flag=false;
    if(tmp==-1){
        sizel=one.length;
    }
    else if(tmp==1) {
        sizel=two.length;
    }
    else{
        sizel =two.length;
        flag=true;
    }
   
    for(int i=0; i < sizel;i++){
        if(one.name[i]<two.name.at(i)){
            return -1;
        }
        if(two.name[i]<one.name[i]){
            return 1;
        }
    }
    if(flag){
        return 0;
    }
    return (sizel==one.length?-1:1);
}


/**
 *
 * Returns an integer < 0 if the artist of the first Song is lexicographically before the name of the second,
 * 0 if they are equivalent, or > 0 if the artist of the first Song is lexicographically after the name of the second.
 */
int compare_by_artist(const Song&, const Song&){}