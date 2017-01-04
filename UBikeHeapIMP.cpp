#include "UBikeHeapIMP.h"
#include <array>
#include "readonly/UBike.h"
#include <iostream>
// Add your code here

//=================================================================
// add the ubike pointer to the heap
//=================================================================
void UBikeHeapIMP::addUBikePtr(UBike* ubptr)
{
    this->at(++number)=ubptr;
    ubptr->heapIndex = number;

    for(int i=number;i>1;i=i>>1){
        if(this->at(i)->mileage<this->at(i>>1)->mileage){
            this->at(i)->heapIndex =  i>>1;
            this->at(i>>1)->heapIndex = i;
            std::swap(this->at(i),this->at(i>>1));
        }else break;
    }

}

//=================================================================
// remove the ubike pointer in this heap at "index"
//=================================================================
UBike* UBikeHeapIMP::removeUBikePtr(int heapIndex)
{
    if(heapIndex>number)return 0;
    UBike* ptr = this->at(heapIndex);
    if(number==heapIndex){
        number--;
        this->at(heapIndex) = 0;
        return ptr;
    }
    this->at(heapIndex) = this->at(number--);
    this->at(number+1) = 0;
    this->at(heapIndex)->heapIndex = heapIndex;
    bool up = 0;
    if(heapIndex>1){
        if(this->at(heapIndex)->mileage<this->at(heapIndex>>1)->mileage)up = 1;
    }
    if(up){
        for(int i=heapIndex;i>1;i=i>>1){
            if(this->at(i)->mileage<this->at(i>>1)->mileage){
                this->at(i)->heapIndex =  i>>1;
                this->at(i>>1)->heapIndex = i;
                std::swap(this->at(i),this->at(i>>1));
            }else break;
        }
        return ptr;
    }
    for(int i=heapIndex;i*2+1<=number;){
        UBike* now = this->at(i);
        UBike* l = this->at(i*2);
        UBike* r = this->at(i*2+1);
        if(l){
            if(r){
                if(l->mileage<=r->mileage&&l->mileage<now->mileage){
                    this->at(i)->heapIndex =  i*2;
                    this->at(i*2)->heapIndex = i;
                    std::swap(this->at(i*2),this->at(i)),i=i*2;
                }
                else if(r->mileage<l->mileage&&r->mileage<now->mileage){
                    this->at(i)->heapIndex = i*2+1;
                    this->at(i*2+1)->heapIndex = i;
                    std::swap(this->at(i*2+1),this->at(i)),i=i*2+1;
                }
                else break;
            }
            else if(l->mileage<now->mileage){
                    this->at(i)->heapIndex =  i*2;
                    this->at(i*2)->heapIndex = i;
                    std::swap(this->at(i*2),this->at(i)),i=i*2;
            }
            else break;
        }
        else break;
    }
    return ptr;
}
