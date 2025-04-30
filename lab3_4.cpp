#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    int year;

public:
    Vehicle(string b, int y) : brand(b), year(y) {}
    
    virtual void showInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }
    
    virtual void startEngine() {
        cout << "Starting engine of Vehicle" << endl;
    }
    
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(string b, int y, int doors) : Vehicle(b, y), numDoors(doors) {}
    
    void showInfo() override {
        Vehicle::showInfo();
        cout << "Number of doors: " << numDoors << endl;
    }
    
    void startEngine() override {
        cout << "Car engine is starting!" << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryCapacity;

public:
    ElectricCar() : Car("", 0, 0), batteryCapacity(0) {}
    
    ElectricCar(string b, int y, int doors, int battery) 
        : Car(b, y, doors), batteryCapacity(battery) {}
    
    void showInfo() override {
        Car::showInfo();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
    
    void startEngine() override {
        cout << "Electric engine is starting... Silent but powerful!" << endl;
    }
};

int main() {
    Vehicle* vehicle = new Vehicle("Generic", 2015);
    vehicle->showInfo();
    vehicle->startEngine();
    cout << endl;
    
    Car* car = new Car("Toyota", 2021, 4);
    car->showInfo();
    car->startEngine();
    cout << endl;
  
    ElectricCar* electricCar1 = new ElectricCar();
    electricCar1->showInfo();
    electricCar1->startEngine();
    cout << endl;
    
    ElectricCar* electricCar2 = new ElectricCar("Tesla", 2023, 4, 75);
    electricCar2->showInfo();
    electricCar2->startEngine();
    cout << endl;
    
    ElectricCar* electricCar3 = new ElectricCar("Nissan", 2022, 4, 40);
    electricCar3->showInfo();
    electricCar3->startEngine();
    cout << endl;
    
    delete vehicle;
    delete car;
    delete electricCar1;
    delete electricCar2;
    delete electricCar3;
    return 0;
}
