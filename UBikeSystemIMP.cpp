#include "UBikeSystemIMP.h"
#include <iostream>
// Add your code here
//=================================================================
// read the map and initialize this->priceTable
//=================================================================
void UBikeSystemIMP::InitDistTable
(std::string MapFile)
{
    priceTable.calcAllPairsShortestPath(MapFile);
}

//=================================================================
// add a new bike to the system
//=================================================================
void UBikeSystemIMP::NewBike
(std::string classType, std::string license,
 int mile, std::string station)
{
    UBike* newone = new UBike;
    newone->classType = classType;
    newone->isRented = 0;
    newone->license = license;
    newone->mileage = mile;
    newone->station = station;
    newone->heapIndex = mile;//ubStations[station][classType].number;
    ubStations[station][classType].addUBikePtr(newone);
    ubHashTable.addUBikePtr(newone);
}

//=================================================================
// remove the bike license
//=================================================================
void UBikeSystemIMP::JunkIt
(std::string license)
{
    UBike* ptr=ubHashTable.findUBikePtr(license,1);
    if(ptr)ubStations[ptr->station][ptr->classType].removeUBikePtr(ptr->heapIndex);
    delete ptr;
}

//=================================================================
// rent a bike
//=================================================================
void UBikeSystemIMP::Rent
(std::string classType, std::string station)
{
    UBike* ptr = ubStations[station][classType].removeUBikePtr(ubStations[station][classType][1]->heapIndex);
    ptr->isRented = 1;
    ubStations[station]["Rented"].addUBikePtr(ptr);
        //std::cout<<ptr->heapIndex<<std::endl;
    //std::cout<<ptr->license<<std::endl;
}

//=================================================================
// return the bike
//=================================================================
void UBikeSystemIMP::Return
(std::string station, std::string license, int returnMile)
{
    UBike* ptr = ubHashTable.findUBikePtr(license,0);
    //std::cout<<ptr->heapIndex<<std::endl;

    if(!ptr)return;
    else if(!ptr->isRented)return;
    net+=priceTable.calcPrice(returnMile-ptr->mileage,ptr->classType,ptr->station,station);
    ubStations[ptr->station]["Rented"].removeUBikePtr(ptr->heapIndex);
    ptr->mileage=returnMile;
    ptr->isRented=0;
    ubStations[ptr->station][ptr->classType].addUBikePtr(ptr);
        ptr->mileage=returnMile;
    //ptr->station = station;
    ptr->isRented=0;


    //std::cout<<ptr->license<<std::endl;
        //std::cout<<ptr->license<<std::endl;
    //std::cout<<ptr->classType<<std::endl;
    //std::cout<<std::endl;
}

//=================================================================
// move the ubike license to another station
//=================================================================
void UBikeSystemIMP::Trans
(std::string station, std::string license)
{
    UBike* ptr = ubHashTable.findUBikePtr(license,0);
    if(!ptr)return;
    ubStations[ptr->station][ptr->classType].removeUBikePtr(ptr->heapIndex);
    ubStations[station][ptr->classType].addUBikePtr(ptr);
    ptr->station = station;
}

//=================================================================
// clear all the allocated memories for ubikes
//=================================================================
void UBikeSystemIMP::ShutDown()
{

}
