#include "PriceTableIMP.h"
#include <fstream>
#include <iostream>
// Add your code here

//=================================================================
// calculate the all pairs shortest patch and store the results
// in this->distTable
//=================================================================
void PriceTableIMP::calcAllPairsShortestPath(std::string mapFile)
{
    std::ifstream input;
    input.open(mapFile);
    std::string a,b;
    int c;
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            distTable[StationNames[i]][StationNames[j]]=-1;
        }
    }
   for(int i=0;i<12;i++){
        distTable[StationNames[i]][StationNames[i]]=0;
    }
    while(input>>a>>b>>c){
        //std::cout<<a<<" "<<b<<" "<<c<<std::endl;
        this->distTable[a][b]=c;
        this->distTable[b][a]=c;
    }
    for(int k=0;k<12;k++){
        for(int i=0;i<12;i++){
            for(int j=0;j<12;j++){
                    if(distTable[StationNames[i]][StationNames[k]]<0||distTable[StationNames[k]][StationNames[j]]<0)continue;
                    if(distTable[StationNames[i]][StationNames[k]]+distTable[StationNames[k]][StationNames[j]]<distTable[StationNames[i]][StationNames[j]]||distTable[StationNames[i]][StationNames[j]]<0){
                        distTable[StationNames[i]][StationNames[j]]=distTable[StationNames[i]][StationNames[k]]+distTable[StationNames[k]][StationNames[j]];
                        distTable[StationNames[j]][StationNames[i]]=distTable[StationNames[i]][StationNames[k]]+distTable[StationNames[k]][StationNames[j]];
                    }
            }
        }
    }
}

//=================================================================
// calculate and return the rental when an ubike is returned
//=================================================================
int PriceTableIMP::calcPrice(int milageDiff, std::string bClass,std::string from, std::string toStation)
{
    //std::cout<<milageDiff<<" "<<from<<" "<<toStation<<std::endl;
    int discountDist = distTable[from][toStation];
    //std::cout<<discountDist<<" "<<from<<" "<<toStation<<std::endl;
    //std::cout<<std::endl;
    if(bClass=="Electric"){
        //if(milageDiff>=discountDist)return (milageDiff-discountDist)*40+discountDist*25;
        if(milageDiff>=discountDist)return milageDiff*40;
        else return milageDiff*25;
    }
    if(bClass=="Lady"){
        if(milageDiff>=discountDist)return milageDiff*30;
        //if(milageDiff>=discountDist)return (milageDiff-discountDist)*30+discountDist*20;
        else return milageDiff*20;
    }
    if(bClass=="Road"){
        if(milageDiff>=discountDist)return milageDiff*20;
        //if(milageDiff>=discountDist)return (milageDiff-discountDist)*20+discountDist*10;
        else return milageDiff*10;
    }
    if(bClass=="Hybrid"){
        if(milageDiff>=discountDist)return milageDiff*25;
        //if(milageDiff>=discountDist)return (milageDiff-discountDist)*25+discountDist*15;
        else return milageDiff*15;
    }
}
