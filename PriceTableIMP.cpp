#include "PriceTableIMP.h"
#include <fstream>

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
    while(input>>a>>b>>a){
        this->distTable[a][b]=c;
        this->distTable[b][a]=c;
    }
}

//=================================================================
// calculate and return the rental when an ubike is returned
//=================================================================
int PriceTableIMP::calcPrice(int milageDiff, std::string bClass,std::string from, std::string toStation)
{
    int discountDist = distTable[from][toStation];
    if(bClass=="Electric"){
        if(milageDiff>=discountDist)return (milageDiff-discountDist)*40+discountDist*25;
        else return milageDiff*25;
    }
    if(bClass=="Lady"){
        if(milageDiff>=discountDist)return (milageDiff-discountDist)*30+discountDist*20;
        else return milageDiff*20;
    }
    if(bClass=="Road"){
        if(milageDiff>=discountDist)return (milageDiff-discountDist)*20+discountDist*10;
        else return milageDiff*10;
    }
    if(bClass=="Hybrid"){
        if(milageDiff>=discountDist)return (milageDiff-discountDist)*25+discountDist*15;
        else return milageDiff*15;
    }
}
