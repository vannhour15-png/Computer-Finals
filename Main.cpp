#include <iostream>
using namespace std;

class Vehicle {

private:
    string Model, Color, vehicleId;
    int year;
    double rentalPrice;
    bool AvailStatus;

public:

    Vehicle(string Model, string Color, string vehicleId, int year, double rentalPrice, bool AvailStatus) {
        this->Model = Model;
        this->Color = Color;
        this->vehicleId = vehicleId;
        this->year = year;
        this->rentalPrice = rentalPrice;
        this->AvailStatus = AvailStatus;
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

    string getVehicleId() {
        return vehicleId;
    }

    void setVehicleId(string vehicleId) {
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

    virtual void displayInfo() {
        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Model: " << Model << endl;
        cout << "Color: " << Color << endl;
        cout << "Year: " << year << endl;
        cout << "Rental Price: $" << rentalPrice << endl;

        if (AvailStatus)
            cout << "Available: Yes" << endl;
        else
            cout << "Available: No" << endl;
    }
    static void SearchByType(Vehicle* list[], int count, string typeName) {
        cout << "\n--- All " << typeName << " ---" << endl;

        if (count == 0) {
            cout << "None found." << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            list[i]->displayInfo();
            cout << "-----------------------" << endl;
        }
    }
};

class Car : public Vehicle {
private:
    string bodyType;
    int passengerCapacity;

public:
    static Vehicle* carList[5];
    static int carCount;

    Car(string Model, string Color, string vehicleId, int year, double rentalPrice, bool AvailStatus, string bodyType, int passengerCapacity)
        : Vehicle(Model, Color, vehicleId, year, rentalPrice, AvailStatus) {

        this->bodyType = bodyType;
        this->passengerCapacity = passengerCapacity;
    }

    static void addCar(Car* c) {
        if (carCount < 5)
            carList[carCount++] = c;
        else
            cout << "Car list is full (max 5)." << endl;
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

    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Body Type: " << bodyType << endl;
        cout << "Passenger Capacity: " << passengerCapacity << endl;
    }
};

class Motorcycle : public Vehicle {
private:
    string bikeType;
    int engineCC;

public:
    static Vehicle* motoList[5];
    static int motoCount;

    Motorcycle(string Model, string Color, string vehicleId, int year, double rentalPrice, bool AvailStatus, string bikeType, int engineCC)
        : Vehicle(Model, Color, vehicleId, year, rentalPrice, AvailStatus) {

        this->bikeType = bikeType;
        this->engineCC = engineCC;
    }

    static void addMoto(Motorcycle* m) {
        if (motoCount < 5)
            motoList[motoCount++] = m;
        else
            cout << "Motorcycle list is full (max 5)." << endl;
    }

    string getBikeType() {
        return bikeType;
    }

    void setBikeType(string bikeType) {
        this->bikeType = bikeType;
    }

    int getEngineCC() {
        return engineCC;
    }

    void setEngineCC(int engineCC) {
        this->engineCC = engineCC;
    }

    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Bike Type: " << bikeType << endl;
        cout << "Engine CC: " << engineCC << endl;
    }
};


class Rental {
    private:
    double totalPrice;
    double securityDeposit;
    string paymentStatus;
    
    public:
    Rental(double totalPrice, double securityDeposit, string paymentStatus) {
        this->totalPrice = totalPrice;
        this->securityDeposit = securityDeposit;
        this->paymentStatus = paymentStatus;
    }
    
    double gettotalprice() {
        return totalPrice;
    }
    
    void settotalprice(double totalPrice) {
        this->totalPrice = totalPrice;
    }
    
    double getsecuritydeposit() {
        return securityDeposit;
    }
    
    void setsecurityDeposit(double securityDeposit) {
        this->securityDeposit = securityDeposit;
    }
    
    string getpaymentstatus() {
        return paymentStatus;
    }
    
    void setpaymentstatus(string paymentStatus) {
        this->paymentStatus = paymentStatus;
    }
    
    void displayInfo() {
        cout << "Total Price: $" << totalPrice << endl;
        cout << "Security Deposit: $" << securityDeposit << endl;
        cout << "Payment Status: " << paymentStatus << endl;
    }
};

class Customer {
    
    private:
    string name;
    int customerId;
    string dateOFBirth;
    string gender;
    string phoneNumber;
    string email;
    
    public:
    Customer(string name, int customerId, string dateOFBirth, string gender, string phoneNumber, string email) {
        this->name = name;
        this->customerId = customerId;
        this->dateOFBirth = dateOFBirth;
        this->gender = gender;
        this->phoneNumber = phoneNumber;
        this->email = email;
    }
    
    string getname() {
        return name;
    }
    
    void setname(string name) {
        this->name = name;
    }
    
    int getcustomerId() {
        return customerId;
    }
    
    void setcustomerId(int customerId) {
        this->customerId = customerId;
    }
    
    string getdateOFBirth() {
        return dateOFBirth;
    }
    
    void setdateOFbirth(string dateOFBirth) {
        this->dateOFBirth = dateOFBirth;
    }
    
    string getgender() {
        return gender;
    }
    
    void setgender(string gender) {
        this->gender = gender;
    }
    
    string getphoneNumber() {
        return phoneNumber;
    }
    
    void setphoneNumber(string phoneNumber) {
        this->phoneNumber = phoneNumber;
    }
    
    string getemail() {
        return email;
    }
    
    void setemail(string email) {
        this->email = email;
    }
    
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Customer ID: " << customerId << endl;
        cout << "Date of Birth: " << dateOFBirth << endl;
        cout << "Gender: " << gender << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }
};

class Booking {
    private:
    int BookingId;
    string rentalDate;
    string returnDate;
    int numDays;
    bool bookingStatus;
    
    public:
    Booking(int BookingId, string rentalDate, string returnDate, int numDays, bool bookingStatus) {
        this->BookingId = BookingId;
        this->rentalDate = rentalDate;
        this->returnDate = returnDate;
        this->numDays = numDays;
        this->bookingStatus = bookingStatus;
    }
    
    void CreateBooking() {
        cout << "Enter booking Id:";
        cin >> BookingId;
        
        cout << "Enter rental date:";
        cin >> rentalDate;
        
        cout << "Enter return date:";
        cin >> returnDate;
        
        cout << "Enter number of days:";
        cin >> numDays;
        
        bookingStatus = true;
        
        cout << "Booking created" << endl;
    }
    
    void CancelBooking() {
        bookingStatus = false;
        cout << "Booking cancelled" << endl;
    }
    
    void EditBooking() {
        cout << "Enter new rent date: ";
        cin >> rentalDate;
        
        cout << "Enter new return date: ";
        cin >> returnDate;
        
        cout << "Enter new number of days: ";
        cin >> numDays;
        
        cout << "Booking updated" << endl;
    }
    
    void DisplayBooking() {
        cout << "\n--- Booking info ---" << endl;
        cout << "Booking Id: " << BookingId << endl;
        cout << "Rental date: " << rentalDate << endl;
        cout << "Return date: " << returnDate << endl;
        cout << "Number of days: " << numDays << endl;
        if (bookingStatus)
        cout << "Booking status: Active" << endl;
        else
        cout << "Booking status: Cancelled" << endl;
    }
    
    int getBookingId() {
        return BookingId;
    }
    
    void setBookingId(int BookingId) {
        this->BookingId = BookingId;
    }
    
    string getRentalDate() {
        return rentalDate;
    }
    
    void setRentalDate(string rentalDate) {
        this->rentalDate = rentalDate;
    }
    
    string getReturnDate() {
        return returnDate;
    }
    
    void setReturnDate(string returnDate) {
        this->returnDate = returnDate;
    }
    
    int getNumDays() {
        return numDays;
    }
    
    void setNumDays(int numDays) {
        this->numDays = numDays;
    }
    
    bool getBookingStatus() {
        return bookingStatus;
    }
    
    void setBookingStatus(bool bookingStatus) {
        this->bookingStatus = bookingStatus;
    }
};
Vehicle* Car::carList[5];
int Car::carCount = 0;

Vehicle* Motorcycle::motoList[5];
int Motorcycle::motoCount = 0;

int main() {
    int choice;
    
    Car c1("Toyota", "Black", "C001", 2022, 50.00, true, "Sedan");
    Car c2("Honda", "White", "C002", 2021, 45.00, true, "SUV");
    Car c3("Mazda", "Red", "C003", 2023, 55.00, false, "Coupe");
    
    Motorcycle m1("Yamaha", "Black", "M001", 2022, 25.00, true, "Sport", 600);
    Motorcycle m2("Honda", "Red", "M002", 2021, 20.00, true, "Cruiser", 400);
    
    Car::addCar(&c1);
    Car::addCar(&c2);
    Car::addCar(&c3);

    Motorcycle::addMoto(&m1);
    Motorcycle::addMoto(&m2);

    cout << "Welcome to VVIP Rentals" << endl;
    cout << "We have State of the art, Car and Motorcycle Rentals available to book In Phnom Penh" << endl;

    do {
    cout << "Please select from the options below: "; cin >> choice;
        switch (choice){
            case 1:
                Car::SearchByType(Car::carList, Car::carCount, "Cars");
                break;
            case 2:
                Motorcycle::SearchByType(Motorcycle::motoList, Motorcycle::motoCount, "Motorcycles");
                break;
            case 3:

            case 4:
                cout << "Exiting Program..";
                break;
        }
} while (choice != 4);

    ///Booking booking1(1, "05/09/2026", "10/09/2026", 5, true);
    ///booking1.DisplayBooking();

    return 0;
}