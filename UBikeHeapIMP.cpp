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
    //std::cout<<ubptr->heapIndex<<std::endl;
    int tmp_index;

    for(int i=number;i>1;i=i>>1){
        if(this->at(i)->mileage<this->at(i>>1)->mileage){
            tmp_index = this->at(i)->heapIndex;
            this->at(i)->heapIndex =  this->at(i>>1)->heapIndex;
            this->at(i>>1)->heapIndex = tmp_index;
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
            ptr->heapIndex=heapIndex;
            break;
        }
    }
    if(!found)return 0;
    int tmp_index;
    for(int i=pos;i<=number>>1;){
        UBike* now = this->at(i);
        UBike* l = this->at(i*2);
        UBike* r = this->at(i*2+1);
        if(l){
            if(r){
                if(l->mileage<r->mileage&&l->mileage<now->mileage){
                        tmp_index = this->at(i)->heapIndex;
                        this->at(i)->heapIndex =  this->at(i*2)->heapIndex;
                         this->at(i*2)->heapIndex = tmp_index;
                    std::swap(this->at(i*2),this->at(i)),i=i*2;
                }
                else if(r->mileage<=l->mileage&&r->mileage<now->mileage){
                        tmp_index = this->at(i)->heapIndex;
                       this->at(i)->heapIndex = this->at(i*2+1)->heapIndex;
                        this->at(i*2+1)->heapIndex = tmp_index;
                        std::swap(this->at(i*2+1),this->at(i)),i=i*2+1;
                }
                else break;
            }
            else if(l->mileage<now->mileage){
                        tmp_index = this->at(i)->heapIndex;
                        this->at(i)->heapIndex =  this->at(i*2)->heapIndex;
                         this->at(i*2)->heapIndex = tmp_index;
                    std::swap(this->at(i*2),this->at(i)),i=i*2;
            }
            else break;
        }
        else break;
    }
    return ptr;
}
