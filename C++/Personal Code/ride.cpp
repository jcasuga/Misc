#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "ride.h"

Ride::Ride(){
    rideName = "Failure Management";
    ticketCost = -3;
}

Ride::Ride(const Ride& old){
    rideName = old.rideName;
    ticketCost = old.ticketCost;
}
