#include "UBikeHashTableIMP.h"
#include <forward_list>
#include <array>

// Add your code here
//=================================================================
// add the ubike pointer to the hash table
//=================================================================
void UBikeHashTableIMP::addUBikePtr(UBike* ubptr)
{
    this->at(ubptr->license[0]).push_front(ubptr);
}

//=================================================================
// find the ubike pointer in the hash table given ubike license
// if toRemove is true, remove the the pointer from the hash table
// return the ubike pointer that points to the ubike "license"
//=================================================================
UBike* UBikeHashTableIMP::findUBikePtr(std::string license, bool toRemove)
{
    UBike* ptr = 0;
    for(auto i:this->at(license[0])){
        if(i->license==license){
            ptr = i;
        }
    }
    if(toRemove){
        this->at(license[0]).remove(ptr);
    }
    return ptr;
}
