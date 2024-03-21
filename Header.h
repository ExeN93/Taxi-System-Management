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
struct Name {
    string firstName;
    string lastName;
};

// Struktura reprezentująca kierowcę
struct Driver {
    Name driverName;
    int licenseNumber;
    int experience; // w latach
};

// Struktura reprezentująca samochód
struct Car {
    string brand;
    string model;
    string plateNumber;
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
