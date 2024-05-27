#include <bits/stdc++.h>
#include "ParkingLotSystem.h"
using namespace std;

int main() {
    // Create a ParkingLotSystem instance
    ParkingLotSystem* parkingLot = ParkingLotSystem::getInstance();

    // Create a person
    Person person("John Doe", "123 Main St", "john.doe@example.com", "555-1234");

    // Create a vehicle
    IVehicle* car = new Car();
    car->setLicenseNo(12345);

    // Get a parking ticket
    ParkingTicket* ticket = parkingLot->getParkingTicket(car, person);

    // Validate the ticket and print the rate
    parkingLot->validateAndPrintTicket(ticket);

    delete car;
    return 0;
}
