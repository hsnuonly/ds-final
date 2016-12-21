#include "UBikeHeapIMP.h"
#include <array>
#include "readonly/UBike.h"

// Add your code here

//=================================================================
// add the ubike pointer to the heap
//=================================================================
void UBikeHeapIMP::addUBikePtr(UBike* ubptr)
{
    this->at(++number)=ubptr;
    for(int i=number;i>1;i=i>>1){
        if(this->at(i)->heapIndex<this->at(i>>1)->heapIndex){
            std::swap(this->at(i),this->at(i>>1));
        }else break;
    }
}

//=================================================================
// remove the ubike pointer in this heap at "index"
//=================================================================
UBike* UBikeHeapIMP::removeUBikePtr(int heapIndex)
{
    UBike* ptr;
    int pos;
    bool found = 0;
    for(int i=1;i<=number;i++){
        if(this->at(i)->heapIndex==heapIndex){
            pos = i;
            ptr = this->at(i);
            this->at(i) = this->at(this->number);
            this->at(number) = 0;
            number--;
            found = 1;
            break;
        }
    }
    if(!found)return 0;
    for(int i=pos;i<=number>>1;){
        UBike* now = this->at(i);
        UBike* l = this->at(i*2);
        UBike* r = this->at(i*2+1);
        if(l){
            if(r){
                if(l->heapIndex<r->heapIndex&&l->heapIndex<now->heapIndex)std::swap(this->at(i*2),this->at(i)),i=i*2;
                else if(r->heapIndex<=l->heapIndex&&r->heapIndex<now->heapIndex)std::swap(this->at(i*2+1),this->at(i)),i=i*2+1;
                else break;
            }
            else if(l->heapIndex<now->heapIndex)std::swap(this->at(i*2),this->at(i)),i=i*2;
            else break;
        }
        else break;
    }
    return ptr;
}
