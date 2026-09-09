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

    class Rental{
        private:
        double totalPrice;
        double securityDeposit;
        string paymentStatus;

        public:
        Rental(double totalPrice, double securityDeposit, string paymentStatus) {
            this-> totalPrice = totalPrice;
            this -> securityDeposit = securityDeposit;
            this-> paymentStatus = paymentStatus;
        }

        double gettotalprice() {
            return totalPrice;
        }

        void settotalprice(double totalPrice) {
            this-> totalPrice = totalPrice;
        }

        double getsecuritydeposit() {
            return securityDeposit;
        }
        void setsecurityDeposit(double securityDeposit) {
            this-> securityDeposit = securityDeposit;
        }
        string getpaymentstatus() {
            return paymentStatus;
        }
        void setpaymentstatus(string paymentStatus) {
            this-> paymentStatus = paymentStatus;
    }
    void displayInfo() {
        cout << "Total Price: $" << totalPrice << endl;
        cout << "Security Deposit: $" << securityDeposit << endl;
        cout << "Payment Status: " << paymentStatus << endl;
        
    }

};

    class Customer{

        private:
        string name;
        int customerId;
        string dateOFBirth;
        string gender;
        string phoneNumber;
        string email;

        public:
        Customer(string name, int customerId, string dateOFBirth, string gender, string phoneNumber, string email) {
            this -> name = name;
            this -> customerId = customerId;
            this -> dateOFBirth = dateOFBirth;
            this -> gender = gender;
            this -> phoneNumber = phoneNumber;
            this -> email = email;
        }

        string getname() {
            return name;
        }

        void setname(string name) {
            this -> name = name;
        }
        int getcustomerId() {
            return customerId;
        }

        void setcustomerId (int customerId) {
            this -> customerId = customerId;
        }
        string getdateOFBirth() {
            return dateOFBirth;
        }
        void setdateOFbirth(string dateIFBirth) {
            this -> dateOFBirth = dateOFBirth;
        }
        string getgender() {
            return gender;
        }
        void setgender(string gender) {
            this -> gender = gender;
        }
        string getphoneNumber() {
            return phoneNumber;
        }
        void setphoneNumber(string phoneNumber) {
            this -> phoneNumber = phoneNumber;
        }
        string email() {
            return email;
        }
        void setemail(string email) {
            this -> email = email;
        }

        void displayInfo() {
            cout << "Name:" << name << endl;
            cout << "Customer ID:" << customerId << endl;
            cout << "Date of Birth:" << dateOFBirth << endl;
            cout << "Gender:" << gender << endl;
            cout << "Phone Number:" << phoneNumber << endl;
            cout << "Email:" << email << endl;
        }

    };
int main(){
    Car car1("Toyota", "Black", 101, 2022, 50, true, 4, "Petrol", true);

    car1.displayInfo();
    return 0;
}