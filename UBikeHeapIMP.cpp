#include "UBikeHeapIMP.h"
#include <array>
#include "readonly/UBike.h"

// Add your code here

//=================================================================
// add the ubike pointer to the heap
//=================================================================
void UBikeHeapIMP::addUBikePtr(UBike* ubptr)
{
    this->at(number++)=ubptr;
    for(int i=number-1;i>0;i=i>>1){
        if(this->at(i)->heapIndex<this->at(i>>1)->heapIndex){
            auto temp = this->at(i);
            this->at(i) = this->at(i>>1);
            this->at(i>>1) = temp;
        }else break;
    }
}

//=================================================================
// remove the ubike pointer in this heap at "index"
//=================================================================
UBike* UBikeHeapIMP::removeUBikePtr(int heapIndex)
{
    UBike* ptr;
    for(int i=0;i<number;i++){
        if(this->at(i)->heapIndex==heapIndex){
            ptr = this->at(i);
            while(i<number){
                UBike* head = this->at(i);
                UBike* l = this->at(i*2);
                UBike* r = this->at(i*2+1);
                if(l){
                    if(r){
                        if(l->heapIndex<r->heapIndex&&l->heapIndex<head->heapIndex){
                            this->at(i) = this->at(i*2);
                            i=i*2;
                        }
                        else if(r->heapIndex<l->heapIndex&&r->heapIndex<head->heapIndex){
                            this->at(i) = this->at(i*2+1);
                            i=i*2+1;
                        }
                    }
                    else if(l->heapIndex<head->heapIndex){
                        this->at(i) = this->at(i*2);
                        i=i*2;
                    }
                }
                else if(r&&r->heapIndex<head->heapIndex){
                    this->at(i) = this->at(i*2+1);
                }
                else break;
            }
            break;
        }
    }
    return ptr;
}
