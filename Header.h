//
//  Header.h
//  taxi-system-management
//
//  Created by Andrzej Zwirko on 19/03/2024.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>
#include <locale>
#include <random>
#include <string_view>

using namespace std;

// Struktura reprezentująca imię i nazwisko
class Name {
private:
    string firstName;
    string lastName;
public:
    string getFirstName(){return firstName;}
    string getLastName(){return lastName;}
    void setFirstName (string firstname) {
        firstName = firstname;
    }
    void setLastName (string lastname) {
        lastName = lastname;
    }
};

// Struktura reprezentująca kierowcę
class Driver {
private:
    Name driverName;
    int licenseNumber;
    int experience; // w latach
public:
    int getLicenseNumber(){return licenseNumber;}           // tutaj muszę dodać w public: Name drivername;
    int getExperience(){return experience;}
    void setLicenseNumber (int licensenumber) {
        licenseNumber = licensenumber;
    }
    void setExperience (int experience) {
        experience = experience;
    }
};

// Struktura reprezentująca samochód
class Car {
private:
    string brand;
    string model;
    string plateNumber;
public:
    string getBrand(){return brand;}
    string getModel(){return model;}
    string getPlateNumber(){return plateNumber;}
    void setBrand 
};

// Struktura reprezentująca zamówienie
struct Order {
    Name customerName;
    string pickupLocation;
    string dropoffLocation;
    int amount; // Kwota zamówienia
    bool completed;
};

// Struktura reprezentująca firmę taksówkarską
struct TaxiCompany {
    Driver** drivers;
    Car** cars;
    Order** orders;
    int driverCount = 0;
    int carCount = 0;
    int orderCount = 0;
};

void hireDriver(Driver**& driver, int &size);
void deleteDriver(Driver**& driver, int &size);
void addCar(Car**& car, int &size);
void deleteCar(Car**& car, int &size);
void placeOrder(Order**& order, int &size);
void deleteAllOrders(Order**& order, int &size);
double calculateTotalEarnings(const TaxiCompany& company);
void showDrivers(const TaxiCompany& company);
void showOrders(const TaxiCompany& company);
void showCars(const TaxiCompany& company);
void generateAllData(TaxiCompany& company);
void parsingPlaceOrder (Order**& order, int &size);
void clearMemory(TaxiCompany& company);
void showMenu();

#endif /* Header_h */
