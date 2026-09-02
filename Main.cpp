#include <iostream>
using namespace std;
class Vehicle {

private:
    string Model, Color;
    int vehicleId, year;
    double rentalPrice;
    bool AvailStatus;
    bool automatic;

Vehicle(string Model, string Color, int vehicleId, int year, double rentalPrice, bool AvailStatus) {

    this->Model = Model;
    this->Color = Color;
    this->vehicleId = vehicleId;
    this->year = year;
    this->rentalPrice = rentalPrice;
    this->AvailStatus = AvailStatus;
}
public:

Vehicle(string Model, string Color, int vehicleId, int year, double rentalPrice, bool AvailStatus, bool automatic) {

    this->Model = Model;
    this->Color = Color;
    this->vehicleId = vehicleId;
    this->year = year;
    this->rentalPrice = rentalPrice;
    this->AvailStatus = AvailStatus;
    this->automatic = automatic;
    }

    string getModel() {
        return Model;
    }

    void setModel(string Model) {
        this->Model = Model;
    }

    string getColor() {
        return Color;
    }

    void setColor(string Color) {
        this->Color = Color;
    }

    int getVehicleId() {
        return vehicleId;
    }

    void setVehicleId(int vehicleId) {
        this->vehicleId = vehicleId;
    }

    int getYear() {
        return year;
    }

    void setYear(int year) {
        this->year = year;
    }

    double getRentalPrice() {
        return rentalPrice;
    }

    void setRentalPrice(double rentalPrice) {
        this->rentalPrice = rentalPrice;
    }

    bool getAvailStatus() {
        return AvailStatus;
    }

    void setAvailStatus(bool AvailStatus) {
        this->AvailStatus = AvailStatus;
    }

    bool getAutomatic() {
        return automatic;
    }

    void setAutomatic(bool automatic) {
        this->automatic = automatic;
    }

    void displayInfo() {
        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Model: " << Model << endl;
        cout << "Color: " << Color << endl;
        cout << "Year: " << year << endl;
        cout << "Rental Price: $" << rentalPrice << endl;

        if (AvailStatus)
            cout << "Available: Yes" << endl;
        else
            cout << "Available: No" << endl;

        if (automatic)
            cout << "Automatic: Yes" << endl;
        else
            cout << "Automatic: No" << endl;
    }
};

class Car : public Vehicle {
private:
    string bodyType;
    int passengerCapacity;

public:

    Car(string Model, string Color, int vehicleId, int year, double rentalPrice, bool AvailStatus, bool automatic, string bodyType, int passengerCapacity)
        : Vehicle(Model, Color, vehicleId, year, rentalPrice, AvailStatus, automatic) {

        this->bodyType = bodyType;
        this->passengerCapacity = passengerCapacity;
    }

    string getBodyType() {
        return bodyType;
    }

    void setBodyType(string bodyType) {
        this->bodyType = bodyType;
    }

    int getPassengerCapacity() {
        return passengerCapacity;
    }

    void setPassengerCapacity(int passengerCapacity) {
        this->passengerCapacity = passengerCapacity;
    }
};
int main(){
    Car car1("Toyota", "Black", 101, 2022, 50, true, 4, "Petrol", true);

    car1.displayInfo();
    return 0;
}