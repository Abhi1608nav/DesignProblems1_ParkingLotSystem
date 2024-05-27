#include<bits/stdc++.h>
using namespace std;
#include "ParkingLotSystem.h"

// Function definitions for AdminAccount class

bool AdminAccount::addParkingSpot(IParkingSpot *spot) {
    ParkingLotSystem *parkingLot = ParkingLotSystem::getInstance();
    return parkingLot->addParkingSpot(spot);
}

bool AdminAccount::removeParkingSpot(IParkingSpot *spot) {
    ParkingLotSystem *parkingLot = ParkingLotSystem::getInstance();
    return parkingLot->removeParkingSpot(spot);
}

bool AdminAccount::addEntrance(Entrance *entrance) {
    ParkingLotSystem *parkingLot = ParkingLotSystem::getInstance();
    return parkingLot->addEntrance(entrance);
}

bool AdminAccount::addExit(Exit *exit) {
    ParkingLotSystem *parkingLot = ParkingLotSystem::getInstance();
    return parkingLot->addExit(exit);
}

bool AdminAccount::addDisplayboard(Displayboard *board) {
    ParkingLotSystem *parkingLot = ParkingLotSystem::getInstance();
    return parkingLot->addDisplayboard(board);
}
