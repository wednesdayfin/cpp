#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    int year;
    double price;
public:
    Car(string m = "", int y = 0, double p = 0.0) : model(m), year(y), price(p) {}
    
    void display() {
        cout << "Model: " << model << "\nYear: " << year 
             << "\nPrice: $" << price << "\n" << endl;
    }
    
    void input() {
        cout << "Enter model: ";
        getline(cin >> ws, model);
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter price: $";
        cin >> price;
    }
    
    ~Car() {
        cout << "Car " << model << " destroyed" << endl;
    }
};

class CarCollection {
private:
    Car* cars;
    int count;
public:
    CarCollection() {
        cout << "How many cars? ";
        cin >> count;
        cars = new Car[count];
        
        for(int i = 0; i < count; i++) {
            cout << "\nCar #" << i+1 << ":\n";
            cars[i].input();
        }
    }
    
    ~CarCollection() {
        delete[] cars;
        cout << "CarCollection destroyed" << endl;
    }
    
    void displayCars() {
        cout << "\n--- Car Collection ---\n";
        for(int i = 0; i < count; i++) {
            cars[i].display();
        }
    }
};
int main() {
    CarCollection collection;
    collection.displayCars();
    return 0;
}
