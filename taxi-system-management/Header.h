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

using namespace std;

// Stałe dla maksymalnej liczby kierowców, samochodów i zamówień
const int MAX_DRIVERS = 100;
const int MAX_CARS = 100;
const int MAX_ORDERS = 100;

// Struktura reprezentująca imię i nazwisko
struct Name {
    string firstName;
    string lastName;
};

// Struktura reprezentująca kierowcę
struct Driver {
    Name driverName;
    string licenseNumber;
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
    double amount; // Kwota zamówienia
    bool completed;
};

// Struktura reprezentująca firmę taksówkarską
struct TaxiCompany {
    Driver* drivers[MAX_DRIVERS];
    Car* cars[MAX_CARS];
    Order* orders[MAX_ORDERS];
    int driverCount = 0;
    int carCount = 0;
    int orderCount = 0;
};

void hireDriver(TaxiCompany& company);
void addCar(TaxiCompany& company);
void placeOrder(TaxiCompany& company);
double calculateTotalEarnings(const TaxiCompany& company);
void showDrivers(const TaxiCompany& company);
void clearMemory(TaxiCompany& company);
void showMenu();

#endif /* Header_h */
