#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Vehicle {

private:
    string model, color, vehicleId;
    int year;
    double rentalPrice;
    bool availStatus;

public:

    Vehicle(string model, string color, string vehicleId, int year, double rentalPrice, bool availStatus)
        : model(model), color(color), vehicleId(vehicleId), year(year),
          rentalPrice(rentalPrice), availStatus(availStatus) {}

    virtual ~Vehicle() {}

    string getModel() { return model; }
    void setModel(string model) { this->model = model; }

    string getColor() { return color; }
    void setColor(string color) { this->color = color; }

    string getVehicleId() { return vehicleId; }
    void setVehicleId(string vehicleId) { this->vehicleId = vehicleId; }

    int getYear() { return year; }
    void setYear(int year) { this->year = year; }

    double getRentalPrice() { return rentalPrice; }
    void setRentalPrice(double rentalPrice) { this->rentalPrice = rentalPrice; }

    bool getAvailStatus() { return availStatus; }
    void setAvailStatus(bool availStatus) { this->availStatus = availStatus; }

    virtual void displayInfo() {
        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Model: " << model << endl;
        cout << "Color: " << color << endl;
        cout << "Year: " << year << endl;
        cout << "Rental Price: $" << rentalPrice << " per day" << endl;
        cout << "Available: " << (availStatus ? "Yes" : "No") << endl;
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

    Car(string model, string color, string vehicleId, int year,
        double rentalPrice, bool availStatus, string bodyType,
        int passengerCapacity)
        : Vehicle(model, color, vehicleId, year, rentalPrice, availStatus),
          bodyType(bodyType), passengerCapacity(passengerCapacity) {}

    static void addCar(Car* c) {
        if (carCount < 5)
            carList[carCount++] = c;
        else
            cout << "Car list is full (max 5)." << endl;
    }

    string getBodyType() { return bodyType; }
    void setBodyType(string bodyType) { this->bodyType = bodyType; }

    int getPassengerCapacity() { return passengerCapacity; }
    void setPassengerCapacity(int passengerCapacity) { this->passengerCapacity = passengerCapacity; }

    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Body Type: " << bodyType << endl;
        cout << "Passenger Capacity: " << passengerCapacity << endl;
    }
};

Vehicle* Car::carList[5];
int Car::carCount = 0;

class Motorcycle : public Vehicle {

private:
    string bikeType;
    int engineCC;

public:

    static Vehicle* motoList[5];
    static int motoCount;

    Motorcycle(string model, string color, string vehicleId, int year,
               double rentalPrice, bool availStatus, string bikeType,
               int engineCC)
        : Vehicle(model, color, vehicleId, year, rentalPrice, availStatus),
          bikeType(bikeType), engineCC(engineCC) {}

    static void addMoto(Motorcycle* m) {
        if (motoCount < 5)
            motoList[motoCount++] = m;
        else
            cout << "Motorcycle list is full (max 5)." << endl;
    }

    string getBikeType() { return bikeType; }
    void setBikeType(string bikeType) { this->bikeType = bikeType; }

    int getEngineCC() { return engineCC; }
    void setEngineCC(int engineCC) { this->engineCC = engineCC; }

    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Bike Type: " << bikeType << endl;
        cout << "Engine CC: " << engineCC << endl;
    }
};

Vehicle* Motorcycle::motoList[5];
int Motorcycle::motoCount = 0;

Vehicle* findVehicleById(string id) {
    for (int i = 0; i < Car::carCount; i++)
        if (Car::carList[i]->getVehicleId() == id) return Car::carList[i];

    for (int i = 0; i < Motorcycle::motoCount; i++)
        if (Motorcycle::motoList[i]->getVehicleId() == id) return Motorcycle::motoList[i];

    return nullptr;
}

class Booking {

private:
    static int nextBookingId;
    int bookingId;
    string vehicleId;
    string customerId;
    string rentalDate;
    string returnDate;
    int numDays;
    bool bookingStatus;

    static string calcReturnDate(string rentalDate, int numDays) {
        int day, month, year;
        char slash;
        stringstream ss(rentalDate);
        ss >> day >> slash >> month >> slash >> year;

        day += numDays;
        while (day > 30) {
            day -= 30;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }

        stringstream result;
        result << setw(2) << setfill('0') << day << "/"
               << setw(2) << setfill('0') << month << "/"
               << year;
        return result.str();
    }

public:
    Booking() {
        bookingId = nextBookingId++;
        vehicleId = "";
        customerId = "";
        rentalDate = "";
        returnDate = "";
        numDays = 0;
        bookingStatus = false;
    }

    virtual ~Booking() {}

    int getBookingId() { return bookingId; }

    string getFormattedId() {
        stringstream ss;
        ss << "B" << setw(3) << setfill('0') << bookingId;
        return ss.str();
    }

    void setCustomerId(string customerId) { this->customerId = customerId; }
    string getCustomerId() { return customerId; }

    virtual Vehicle* CreateBooking() {
        string id;
        Vehicle* v = nullptr;

        while (v == nullptr) {
            cout << "Enter vehicle ID to book (e.g. C001): ";
            cin >> id;

            v = findVehicleById(id);
            if (v == nullptr) {
                cout << "No vehicle found with ID \"" << id << "\". Try again." << endl;
            } else if (!v->getAvailStatus()) {
                cout << "Vehicle " << id << " is not available right now." << endl;
                v = nullptr;
            }
        }

        vehicleId = id;

        cout << "Enter rental date (DD/MM/YYYY): ";
        cin >> rentalDate;

        cout << "Enter number of days: ";
        cin >> numDays;

        returnDate = calcReturnDate(rentalDate, numDays);
        bookingStatus = true;
        v->setAvailStatus(false);   // no longer bookable by someone else

        cout << "Booking ID: " << getFormattedId() << endl;
        cout << "Return date: " << returnDate << endl;

        return v;
    }

    void CancelBooking() {
        bookingStatus = false;

        Vehicle* v = findVehicleById(vehicleId);
        if (v != nullptr) v->setAvailStatus(true);  // free it back up

        cout << "Booking " << getFormattedId() << " cancelled" << endl;
    }

    void EditBooking() {
        cout << "Enter new rental date (DD/MM/YYYY): ";
        cin >> rentalDate;

        cout << "Enter new number of days: ";
        cin >> numDays;

        returnDate = calcReturnDate(rentalDate, numDays);

        cout << "Booking updated" << endl;
        cout << "New return date: " << returnDate << endl;
    }

    virtual void DisplayBooking() {
        cout << "\n--- Booking Info ---" << endl;
        cout << "Booking Id: " << getFormattedId() << endl;
        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Customer ID: " << customerId << endl;
        cout << "Rental date: " << rentalDate << endl;
        cout << "Return date: " << returnDate << endl;
        cout << "Number of days: " << numDays << endl;
        cout << "Booking status: " << (bookingStatus ? "Active" : "Cancelled") << endl;
    }

    string getVehicleId() { return vehicleId; }
    string getRentalDate() { return rentalDate; }
    string getReturnDate() { return returnDate; }
    int getNumDays() { return numDays; }
    bool getBookingStatus() { return bookingStatus; }
};

int Booking::nextBookingId = 1;

class Rental : public Booking {

private:
    double rentalPrice;
    double securityDeposit;
    double totalPrice;
    string paymentStatus;
    string paymentMethod;

public:

    Rental(double securityDeposit = 50.00)
        : Booking(), rentalPrice(0), securityDeposit(securityDeposit),
          totalPrice(0), paymentStatus("Unpaid"), paymentMethod("") {}

    Vehicle* CreateBooking() override {
        Vehicle* v = Booking::CreateBooking();
        if (v != nullptr) {
            calculateRental(v->getRentalPrice());
        }
        return v;
    }

    void calculateRental(double pricePerDay) {
        rentalPrice = pricePerDay * getNumDays();
        totalPrice = rentalPrice + securityDeposit;

        cout << "\n--- Rental Calculation ---" << endl;
        cout << "Price Per Day: $" << pricePerDay << endl;
        cout << "Number of Days: " << getNumDays() << endl;
        cout << "Rental Price: $" << rentalPrice << endl;
        cout << "Security Deposit: $" << securityDeposit << endl;
        cout << "Total Price: $" << totalPrice << endl;
    }

    void makePayment() {
        cout << "\n--- Payment Method ---" << endl;
        cout << "1. Cash" << endl;
        cout << "2. Credit Card" << endl;
        cout << "3. Debit Card" << endl;
        cout << "4. ABA Pay" << endl;
        cout <<"Please enter your payment option: " << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: paymentMethod = "Cash"; break;
            case 2: paymentMethod = "Credit Card"; break;
            case 3: paymentMethod = "Debit Card"; break;
            case 4: paymentMethod = "ABA Pay"; break;
            default: paymentMethod = "Unknown";
        }

        paymentStatus = "Paid";

        cout << "Payment Method: " << paymentMethod << endl;
        cout << "Payment Status: " << paymentStatus << endl;
    }

    double getRentalPrice() { return rentalPrice; }
    double getSecurityDeposit() { return securityDeposit; }
    double getTotalPrice() { return totalPrice; }
    string getPaymentStatus() { return paymentStatus; }
    string getPaymentMethod() { return paymentMethod; }

    void DisplayBooking() override {
        Booking::DisplayBooking();
        cout << "Total Price: $" << totalPrice << endl;
        cout << "Payment Status: " << paymentStatus << endl;
        cout << "Payment Method: " << paymentMethod << endl;
    }
};

class Customer {

private:
    static int nextCustomerId;
    string name;
    int customerId;
    string dateOfBirth;
    string gender;
    string phoneNumber;
    string email;

public:

    static Customer* customerList[5];
    static int customerCount;

    Customer() : name(""), customerId(nextCustomerId++), dateOfBirth(""),
                 gender(""), phoneNumber(""), email("") {}

    string getname() { return name; }
    void setname(string name) { this->name = name; }

    int getcustomerId() { return customerId; }

    string getdateOFBirth() { return dateOfBirth; }
    void setdateOFbirth(string dateOfBirth) { this->dateOfBirth = dateOfBirth; }

    string getgender() { return gender; }
    void setgender(string gender) { this->gender = gender; }

    string getphoneNumber() { return phoneNumber; }
    void setphoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }

    string getemail() { return email; }
    void setemail(string email) { this->email = email; }

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Customer ID: " << CreateCustId() << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Gender: " << gender << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    string CreateCustId() {
        stringstream ss;
        ss << "P" << setw(3) << setfill('0') << customerId;
        return ss.str();
    }

    void addCustomer() {
        if (customerCount >= 5) {
            cout << "\nCustomer list is full (maximum 5 customers)." << endl;
            return;
        }

        cout << "\n--- Add Customer ---" << endl;

        cout << "Enter name: ";
        cin >> name;

        cout << "Enter date of birth (DD/MM/YYYY): ";
        cin >> dateOfBirth;

        cout << "Enter gender (Male/Female): ";
        cin >> gender;

        cout << "Enter phone number: ";
        cin >> phoneNumber;

        cout << "Enter email: ";
        cin >> email;

        customerList[customerCount++] = this;

        cout << "\nCustomer added successfully! Your customer ID is " << CreateCustId() << endl;
    }

    static void displayAllCustomers() {
        cout << "\n--- All Customers ---" << endl;

        if (customerCount == 0) {
            cout << "No customers found." << endl;
            return;
        }

        for (int i = 0; i < customerCount; i++) {
            cout << "\nCustomer " << i + 1 << endl;
            customerList[i]->displayInfo();
            cout << "-----------------------" << endl;
        }
    }
};

void DisplayMainMenu() {
    cout << "       (VVIP RENTALS - MAIN MENU)" << endl;
    cout << "  [1] Search all Cars" << endl;
    cout << "  [2] Search all Motorcycles" << endl;
    cout << "  [3] Booking Menu" << endl;
    cout << "  [4] Show all Customers" << endl;
    cout << "  [5] Exit" << endl;
    cout << "----------------------------------" << endl;
    cout << "Select an option: ";
}

void printBookingMenu() {
    cout << "       (BOOKING - MAIN MENU)" << endl;
    cout << "  [1] Create Booking"    << endl;
    cout << "  [2] Edit Booking"      << endl;
    cout << "  [3] Cancel Booking"    << endl;
    cout << "  [4] Display Bookings"  << endl;
    cout << "  [5] Back to Main Menu" << endl;
    cout << "----------------------------------" << endl;
    cout << "Select an option: ";
}

Customer* Customer::customerList[5];
int Customer::customerCount = 0;
int Customer::nextCustomerId = 1;

void EditBookingById(vector<Rental>& bookings, string id) {
    for (size_t i = 0; i < bookings.size(); i++) {
        if (bookings[i].getFormattedId() == id) {
            bookings[i].EditBooking();
            return;
        }
    }
    cout << "Booking not found." << endl;
}

void CancelBookingById(vector<Rental>& bookings, string id) {
    for (size_t i = 0; i < bookings.size(); i++) {
        if (bookings[i].getFormattedId() == id) {
            bookings[i].CancelBooking();
            return;
        }
    }
    cout << "Booking not found." << endl;
}

int main() {

    int choice = 0, bChoice = 0;
    vector<Rental> bookings;

    Car c1("Toyota", "Black", "C001", 2022, 50.00, true, "Sedan", 5);
    Car c2("Honda", "White", "C002", 2021, 45.00, true, "SUV", 5);
    Car c3("Mazda", "Red", "C003", 2023, 55.00, false, "Coupe", 4);

    Motorcycle m1("Yamaha", "Black", "M001", 2022, 25.00, true, "Sport", 600);
    Motorcycle m2("Honda", "Red", "M002", 2021, 20.00, true, "Cruiser", 400);

    Car::addCar(&c1);
    Car::addCar(&c2);
    Car::addCar(&c3);

    Motorcycle::addMoto(&m1);
    Motorcycle::addMoto(&m2);

    cout << "**********************************" << endl;
    cout << "   Welcome to VVIP Rentals" << endl;
    cout << "   State-of-the-art Car and Motorcycle rentals" << endl;
    cout << "   Available in Phnom Penh" << endl;
    cout << "**********************************" << endl;

    do {
        cout << endl;
        DisplayMainMenu();
        cin >> choice;

        switch (choice) {

            case 1:
                Vehicle::SearchByType(Car::carList, Car::carCount, "Cars");
                break;

            case 2:
                Vehicle::SearchByType(Motorcycle::motoList, Motorcycle::motoCount, "Motorcycles");
                break;

            case 3:
                do {
                    cout << endl;
                    printBookingMenu();
                    cin >> bChoice;

                    switch (bChoice) {

                        case 1: {
                            Rental newBooking;
                            Vehicle* v = newBooking.CreateBooking();

                            if (v != nullptr) {
                                Customer* newCust = new Customer;
                                newCust->addCustomer();
                                newBooking.setCustomerId(newCust->CreateCustId());
                                newBooking.makePayment();
                                bookings.push_back(newBooking);
                            }
                            break;
                        }

                        case 2: {
                            string editId;
                            cout << "Enter Booking ID number to edit (e.g. B001): ";
                            cin >> editId;
                            EditBookingById(bookings, editId);
                            break;
                        }

                        case 3: {
                            string cancelId;
                            cout << "Enter Booking ID number to cancel (e.g. B001): ";
                            cin >> cancelId;
                            CancelBookingById(bookings, cancelId);
                            break;
                        }

                        case 4:
                            if (bookings.empty()) {
                                cout << "No bookings yet." << endl;
                            } else {
                                for (size_t i = 0; i < bookings.size(); i++) {
                                    bookings[i].DisplayBooking();
                                }
                            }
                            break;

                        case 5:
                            cout << "Returning to main menu..." << endl;
                            break;
                            

                        default:
                            cout << "Invalid option." << endl;
                    }

                } while (bChoice != 5);
                break;

            case 4: 
                Customer::displayAllCustomers();
                break;
            
            case 5:
                cout << "Exiting Program..." << endl;
                break;

            default:
                cout << "Invalid option." << endl;
        }

    } while (choice != 5);

    return 0;
}