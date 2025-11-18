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
  
   int sizel = min(one.name.length(), two.name.length());
   
   
    for(int i=0; i < sizel;i++){
        if(one.name[i]<two.name.at(i)){
            return -1;
        }
        if(two.name[i]<one.name[i]){
            return 1;
        }
    }
    if(one.name.length()<two.name.length()){
        return -1;
    }
    else if(one.name.length()>two.name.length()){
        return 1;
    }
    else{
        return 0;
    }
}


/**
 *
 * Returns an integer < 0 if the artist of the first Song is lexicographically before the name of the second,
 * 0 if they are equivalent, or > 0 if the artist of the first Song is lexicographically after the name of the second.
 */
int compare_by_artist(const Song& one, const Song& two){
    int sizel = min(one.artist.length(), two.artist.length());
   
   
    for(int i=0; i < sizel;i++){
        if(one.artist[i]<two.artist.at(i)){
            return -1;
        }
        if(two.artist[i]<one.artist[i]){
            return 1;
        }
    }
    if(one.artist.length()<two.artist.length()){
        return -1;
    }
    else if(one.artist.length()>two.artist.length()){
        return 1;
    }
    else{
        return 0;
}}

BST::BST(int(**compare_funcs)(const Song& ,const Song&),int value):root(nullptr), compare_funcs(compare_funcs),func_length(value){

}