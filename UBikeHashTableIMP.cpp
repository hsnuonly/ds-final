#include "UBikeHashTableIMP.h"
#include <forward_list>
#include <array>
#include <iostream>

// Add your code here
//=================================================================
// add the ubike pointer to the hash table
//=================================================================
void UBikeHashTableIMP::addUBikePtr(UBike* ubptr)
{
    int addr = 0;
    for(int i=0;i<5;i++){
        char c = ubptr->license[i];
        addr=addr*29+(isdigit(c)?c-'0':c-'A'+10);
    }
    addr = (addr>>5)%256;
    (*this)[addr].push_front(ubptr);
}

//=================================================================
// find the ubike pointer in the hash table given ubike license
// if toRemove is true, remove the the pointer from the hash table
// return the ubike pointer that points to the ubike "license"
//=================================================================
UBike* UBikeHashTableIMP::findUBikePtr(std::string license, bool toRemove)
{
    int addr = 0;
    for(int i=0;i<5;i++){
        char c = license[i];
        addr=addr*29+(isdigit(c)?c-'0':c-'A'+10);
    }
    addr = (addr>>5)%256;
    UBike* ptr = 0;
    for(auto i:this->at(addr)){
        if(i->license==license){
            ptr = i;
            break;
        }
    }
    if(toRemove&&ptr!=0){
        (*this)[addr].remove(ptr);
    }
    return ptr;
}
