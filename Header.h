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
    void setFirstName (string FirstName) {
        firstName = FirstName;
    }
    void setLastName (string LastName) {
        lastName = LastName;
    }
};

// Struktura reprezentująca kierowcę
class Driver {
private:
    Name driverName;
    int licenseNumber;
    int experience; // w latach
public:
    string getDriverFirstName(){return driverName.getFirstName();}
    string getDriverLastName(){return driverName.getLastName();}
    int getLicenseNumber(){return licenseNumber;}
    int getExperience(){return experience;}
    void setDriverFirstName (string DriverFirstName) {
        driverName.setFirstName(DriverFirstName);
    }
    void setDriverLastName (string DriverLastName) {
        driverName.setLastName(DriverLastName);
    }
    void setLicenseNumber (int LicenseNumber) {
        licenseNumber = LicenseNumber;
    }
    void setExperience (int Experience) {
        experience = Experience;
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
    void setBrand (string Brand) {
        brand = Brand;
    }
    void setModel (string Model) {
        model = Model;
    }
    void setPlateNumber (string PlateNumber) {
        plateNumber = PlateNumber;
    }
};

// Struktura reprezentująca zamówienie
class Order {
private:
    Name customerName;
    string pickupLocation;
    string dropoffLocation;
    int orderId;
    int amount; // Kwota zamówienia
    bool completed;
public:
    string getCustomerFirstName(){return customerName.getFirstName();}
    string getCustomerLastName(){return customerName.getLastName();}
    string getPickupLocation(){return pickupLocation;}
    string getDropOffLocation(){return dropoffLocation;}
    int getOrderId(){return orderId;}
    int getAmount(){return amount;}
    bool getCompleted(){return completed;}
    void setCustomerFirstName (string CustomerFirstName) {
        customerName.setFirstName(CustomerFirstName);
    }
    void setCustomerLastName (string CustomerLastName) {
        customerName.setLastName(CustomerLastName);
    }
    void setPickupLocation (string PickupLocation) {
        pickupLocation = PickupLocation;
    }
    void setDropOffLocation (string DropOffLocation) {
        dropoffLocation= DropOffLocation;
    }
    void setOrderId (int OrderId) {
        orderId = OrderId;
    }
    void setAmount (int Amount) {
        amount = Amount;
    }
    void setCompleted (bool Completed) {
        completed = Completed;
    }
    
};

// Struktura reprezentująca firmę taksówkarską
class TaxiCompany {
private:
    Driver** drivers = nullptr;
    Car** cars = nullptr;
    Order** orders = nullptr;
    int driverCount = 0;
    int carCount = 0;
    int orderCount = 0;
public:
    Driver**& getDrivers(){return drivers;}
    Car**& getCars(){return cars;}
    Order**& getOrders(){return orders;}
    int& getDriverCount(){return driverCount;}
    int& getCarCount(){return carCount;}
    int& getOrderCount(){return orderCount;}
    Order* getOneOrder(int i){return orders[i];}
    Driver* getOneDriver(int i){return drivers[i];}
    Car* getOneCar(int i){return cars[i];}
    void setDrivers (Driver**& Drivers) {
        drivers = Drivers;
    }
    void setCars (Car**& Cars) {
        cars = Cars;
    }
    void setOrders (Order**& Orders) {
        orders = Orders;
    }
    void setDriverCount (int DriverCount) {
        driverCount = DriverCount;
    }
    void setCarCount (int CarCount) {
        carCount = CarCount;
    }
    void setOrderCount (int OrderCount) {
        orderCount = OrderCount;
    }
};

void hireDriver(Driver**& driver, int &size);
void deleteDriver(Driver**& driver, int &size);
void addCar(Car**& car, int &size);
void deleteCar(Car**& car, int &size);
void placeOrder(Order**& order, int &size);
void deleteAllOrders(Order**& order, int &size);
double calculateTotalEarnings(TaxiCompany& company);
void showDrivers(TaxiCompany& company);
void showOrders(TaxiCompany& company);
void showCars(TaxiCompany& company);
void generateAllData(TaxiCompany& company);
void parsingPlaceOrder (Order**& order, int &size);
void clearMemory(TaxiCompany& company);
void showMenu();
void completeOrder(Order**& orders, int &size, TaxiCompany &company);

#endif /* Header_h */
