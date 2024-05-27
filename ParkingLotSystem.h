#ifndef PARKINGLOTSYSTEM_H
#define PARKINGLOTSYSTEM_H

#include <bits/stdc++.h>
#include "randomString.h"

using namespace std;

// Forward Declarations
class Entrance;
class IPayment; // Interface
class ParkingTicket;
class Exit;
class PaymentStatus;
class ParkingRate;
class IAccount; // Interface
class AccountStatus;
class Person;
class Displayboard;
class ParkingLotSystem;

// IVehicle Interface
class IVehicle {
private:
    int licenseNo;
public:
    virtual void getTicket() = 0;
    void setLicenseNo(int license) {
        licenseNo = license;
    }
    int getLicenseNo() {
        return licenseNo;
    }
};

// IParkingSpot Interface
class IParkingSpot {
private:
    int id;
    bool isFree;
    IVehicle *vehicle;
public:
    virtual bool getIsFree() = 0;
    virtual void parkVehicle(IVehicle *v) = 0;
    virtual int getId() = 0;
};

// Parking Spot Types
class Handicapped : public IParkingSpot {
private:
    int id;
    bool isFree;
    IVehicle *vehicle;
public:
    Handicapped(int id) : id(id), isFree(true), vehicle(nullptr) {}
    bool getIsFree() override {
        return isFree;
    }
    void parkVehicle(IVehicle *v) override {
        vehicle = v;
        isFree = false;
    }
    int getId() override {
        return id;
    }
};

class Compact : public IParkingSpot {
private:
    int id;
    bool isFree;
    IVehicle *vehicle;
public:
    Compact(int id) : id(id), isFree(true), vehicle(nullptr) {}
    bool getIsFree() override {
        return isFree;
    }
    void parkVehicle(IVehicle *v) override {
        vehicle = v;
        isFree = false;
    }
    int getId() override {
        return id;
    }
};

class Large : public IParkingSpot {
private:
    int id;
    bool isFree;
    IVehicle *vehicle;
public:
    Large(int id) : id(id), isFree(true), vehicle(nullptr) {}
    bool getIsFree() override {
        return isFree;
    }
    void parkVehicle(IVehicle *v) override {
        vehicle = v;
        isFree = false;
    }
    int getId() override {
        return id;
    }
};

class MotorCycleSpot : public IParkingSpot {
private:
    int id;
    bool isFree;
    IVehicle *vehicle;
public:
    MotorCycleSpot(int id) : id(id), isFree(true), vehicle(nullptr) {}
    bool getIsFree() override {
        return isFree;
    }
    void parkVehicle(IVehicle *v) override {
        vehicle = v;
        isFree = false;
    }
    int getId() override {
        return id;
    }
};

// Vehicle Types
class Car : public IVehicle {
public:
    void getTicket() override {
        cout << "I have got the ticket for parking my car" << endl;
    }
};

class Truck : public IVehicle {
public:
    void getTicket() override {
        cout << "I have got the ticket for parking my Truck" << endl;
    }
};

class Van : public IVehicle {
public:
    void getTicket() override {
        cout << "I have got the ticket for parking my Van" << endl;
    }
};

class MotorCycle : public IVehicle {
public:
    void getTicket() override {
        cout << "I have got the ticket for parking my MotorCycle " << endl;
    }
};

// Ticket Status
class TicketStatus {
private:
    int ticketStatus;
public:
    void setTicketStatus(int ticket) {
        ticketStatus = ticket;
    }
    int getTicketStatus() {
        return ticketStatus;
    }
};

// ParkingTicket Class
class ParkingTicket {
private:
    int ticketNum;
    time_t entryTimeStamp;
    time_t exitTimeStamp;
    double amount;
    TicketStatus status;
    IVehicle *vehicle;
    IPayment *payment;
    Entrance *entrance;
    Exit *exit;

public:
    void setTicketNum(int tnum) {
        ticketNum = tnum;
    }
    void setEntryTime() {
        entryTimeStamp = time(0);
    }
    void setExitTime(int timestayed) {
        exitTimeStamp = entryTimeStamp + timestayed;
    }
    void setAmount(double amt) {
        amount = amt;
    }
    void setTicket(int ticket) {
        status.setTicketStatus(ticket);
    }
    int getTicketNum() const {
        return ticketNum;
    }
    double getAmount() const {
        return amount;
    }
    time_t getEntryTime() const {
        return entryTimeStamp;
    }
    time_t getExitTime() const {
        return exitTimeStamp;
    }

    void printTicketInfo() const {
        cout << "Ticket Number: " << ticketNum << endl;
        cout << "Entry Time: " << ctime(&entryTimeStamp);
        cout << "Exit Time: " << ctime(&exitTimeStamp);
        cout << "Amount: $" << amount << endl;
    }
};


// Entrance Class
class Entrance {
private:
    int id;
public:
    Entrance(int id) : id(id) {}
    int getEntranceId() {
        return id;
    }
    ParkingTicket* getTicket(IVehicle* vehicle) {
        ParkingTicket *ticket = new ParkingTicket();
        ticket->setTicketNum(rand());
        ticket->setEntryTime();
        ticket->setAmount(0); // Amount will be calculated later
        vehicle->getTicket();
        return ticket;
    }
};

// Exit Class
class Exit {
private:
    int id;
public:
    Exit(int id) : id(id) {}
    int getExitId() {
        return id;
    }
    void validateTicket(ParkingTicket *ticket) {
        // Validate the ticket
        ticket->setExitTime(3600); // Assume vehicle stayed for 1 hour
        ticket->setAmount(10.0); // Set amount based on the parking rate
    }
};

// IPayment Interface
class IPayment {
private:
    double amount;
    PaymentStatus *paystatus;
    time_t payDate;
    string paymentId;

public:
    virtual void initiateTransaction() = 0;

    void setAmount(double amt) {
        amount = amt;
    }

    void setPayDate() {
        payDate = time(0);
    }

    void setPaymentId() {
        paymentId = generateRandomString(16) + to_string(rand());
    }
};

// Payment Methods
class Cash : public IPayment {
public:
    void initiateTransaction() override {
        setAmount(rand() * 123.34);
        setPayDate();
        setPaymentId();
        // Update payment status
    }
};

class Card : public IPayment {
public:
    void initiateTransaction() override {
        setAmount(rand() * 123.34 + 32);
        setPayDate();
        setPaymentId();
        // Update payment status
    }
};

// ParkingRate Class
class ParkingRate {
public:
    double calculateAmt(time_t entryTime, time_t exitTime) const {
        double hours = difftime(exitTime, entryTime) / 3600;
        double rate = 10.0; // Example rate per hour
        double totalAmt = hours * rate + (hours * rate) * (18.0 / 100.0);
        return totalAmt;
    }

    void printRate(time_t entryTime, time_t exitTime) const {
        double amount = calculateAmt(entryTime, exitTime);
        cout << "Parking Rate: $" << amount << endl;
    }
};


// IAccount Interface
class IAccount {
private:
    string userName;
    string pwd;
    AccountStatus *status;
    Person *person;

public:
    virtual bool resetPassword() = 0;
};

// Person Class
class Person {
private:
    string name;
    string address;
    string email;
    string phoneNum;

public:
    Person(string name, string address, string email, string phoneNum)
        : name(name), address(address), email(email), phoneNum(phoneNum) {}

    void printInfo() const {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Email: " << email << endl;
        cout << "Phone Number: " << phoneNum << endl;
    }
};


// AdminAccount Class
class AdminAccount : public IAccount {
public:
    bool resetPassword() override {
        // Simple reset password implementation
        cout << "Admin password reset successfully." << endl;
        return true;
    }

    bool addParkingSpot(IParkingSpot *spot);
    bool removeParkingSpot(IParkingSpot *spot);
    bool addEntrance(Entrance *entrance);
    bool addExit(Exit *exit);
    bool addDisplayboard(Displayboard *board);
};

// AgentAccount Class
class AgentAccount : public IAccount {
public:
    bool resetPassword() override {
        cout << "Agent password reset successfully." << endl;
        return true;
    }

    bool processTicket(ParkingTicket *ticket) {
        cout << "Ticket processed successfully." << endl;
        return true;
    }
};

// Displayboard Class
class Displayboard {
private:
    int id;
    map<string, vector<IParkingSpot*>> parkingSpots;

public:
    Displayboard(int id) : id(id) {}

    int getId() {
        return id;
    }

    void showFree() {
        // Show free parking spots
        for (auto &entry : parkingSpots) {
            cout << entry.first << ": ";
            for (auto spot : entry.second) {
                if (spot->getIsFree()) {
                    cout << spot->getId() << " ";
                }
            }
            cout << endl;
        }
    }

    void addParkingSpot(IParkingSpot *spot, string type) {
        parkingSpots[type].push_back(spot);
    }
};

// ParkingLotSystem Class
class ParkingLotSystem {
private:
    int id;
    string name;
    string address;
    map<string, Entrance*> entrances;
    map<string, Exit*> exits;
    ParkingRate *parkingRate;
    map<string, Displayboard*> displayboards;
    map<string, ParkingTicket*> parkingTickets;
    map<string, IParkingSpot*> parkingspots;
    static const int max_capacity = 40000;
    static ParkingLotSystem *instance;

    ParkingLotSystem() {}

public:
    static ParkingLotSystem* getInstance() {
        // Double-checked locking for thread safety
        static ParkingLotSystem instance;
        return &instance;
    }

     ParkingTicket* getParkingTicket(IVehicle *vehicle, const Person& person) {
        if (isFull()) {
            cout << "Parking is full!" << endl;
            return nullptr;
        }

        Entrance *entrance = entrances.begin()->second;
        ParkingTicket *ticket = entrance->getTicket(vehicle);
        string ticketId = to_string(ticket->getTicketNum());
        parkingTickets[ticketId] = ticket;

        // Find a free spot and assign the vehicle to it
        for (auto &entry : parkingspots) {
            if (entry.second->getIsFree()) {
                entry.second->parkVehicle(vehicle);
                break;
            }
        }

        // Print the information
        cout << "Person Information:" << endl;
        person.printInfo();
        cout << "Ticket Information:" << endl;
        ticket->printTicketInfo();

        return ticket;
    }

    bool isFull() {
        int occupiedSpots = 0;
        for (auto &entry : parkingspots) {
            if (!entry.second->getIsFree()) {
                occupiedSpots++;
            }
        }
        return occupiedSpots >= max_capacity;
    }

    bool addEntrance(Entrance* entrance) {
        string entranceId = to_string(entrance->getEntranceId());
        entrances[entranceId] = entrance;
        return true;
    }

    bool addExit(Exit* exit) {
        string exitId = to_string(exit->getExitId());
        exits[exitId] = exit;
        return true;
    }

    bool addParkingSpot(IParkingSpot *spot) {
        string spotId = to_string(spot->getId());
        parkingspots[spotId] = spot;
        return true;
    }

    bool addDisplayboard(Displayboard *board) {
        string boardId = to_string(board->getId());
        displayboards[boardId] = board;
        return true;
    }

    bool removeParkingSpot(IParkingSpot *spot) {
        string spotId = to_string(spot->getId());
        parkingspots.erase(spotId);
        return true;
    }

    void validateAndPrintTicket(ParkingTicket *ticket) {
        if (ticket) {
            cout << "Validating ticket..." << endl;
            Exit *exit = exits.begin()->second;
            exit->validateTicket(ticket);
            ticket->printTicketInfo();

            ParkingRate rate;
            rate.printRate(ticket->getEntryTime(), ticket->getExitTime());
        }
    }
};

#endif // PARKINGLOTSYSTEM_H
