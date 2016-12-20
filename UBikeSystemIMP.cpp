#include "UBikeSystemIMP.h"

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
    ubHashTable.addUBikePtr(newone);
}

//=================================================================
// remove the bike license
//=================================================================
void UBikeSystemIMP::JunkIt
(std::string license)
{
    UBikeHashTableIMP.findUBikePtr(license,1);
}

//=================================================================
// rent a bike
//=================================================================
void UBikeSystemIMP::Rent
(std::string classType, std::string station)
{

}

//=================================================================
// return the bike
//=================================================================
void UBikeSystemIMP::Return
(std::string station, std::string license, int returnMile);

//=================================================================
// move the ubike license to another station
//=================================================================
void UBikeSystemIMP::Trans
(std::string station, std::string license);

//=================================================================
// clear all the allocated memories for ubikes
//=================================================================
void UBikeSystemIMP::ShutDown();
