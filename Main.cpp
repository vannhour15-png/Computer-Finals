
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

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

    Car(string Model, string Color, string vehicleId, int year,
        double rentalPrice, bool AvailStatus, string bodyType,
        int passengerCapacity)
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

    Motorcycle(string Model, string Color, string vehicleId, int year,
               double rentalPrice, bool AvailStatus, string bikeType,
               int engineCC)
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

class Booking {
    private:
        static int nextBookingId;
        int BookingId;
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
            BookingId = nextBookingId;
            nextBookingId++;
            rentalDate = "";
            returnDate = "";
            numDays = 0;
            bookingStatus = true;
        }
 
        string getFormattedId() {
            stringstream ss;
            ss << setw(3) << setfill('0') << BookingId;
            return ss.str();
        }
 
        void CreateBooking(){
            cout << "Enter rental date (DD/MM/YYYY): ";
            cin >> rentalDate;
 
            cout << "Enter number of days: ";
            cin >> numDays;
            returnDate = calcReturnDate(rentalDate, numDays);
            bookingStatus = true;
 
            cout << "Booking ID: " << getFormattedId() << endl;
            cout << "Return date: " << returnDate << endl;
        }
 
        void CancelBooking(){
            bookingStatus = false;
            cout << "Booking " << getFormattedId() << " cancelled" << endl;
        }
 
        void EditBooking(){
            cout << "Enter new rental date (DD/MM/YYYY): ";
            cin >> rentalDate;
            cout << "Enter new number of days: ";
            cin >> numDays;
            returnDate = calcReturnDate(rentalDate, numDays);
            cout << "Booking updated" << endl;
            cout << "New return date: " << returnDate << endl;
        }
 
        void DisplayBooking(){
            cout << "\n--- Booking info ---" << endl;
            cout << "Booking Id: " << getFormattedId() << endl;
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
        string getRentalDate() {
            return rentalDate;
        }
        string getReturnDate() {
            return returnDate;
        }
        int getNumDays() {
            return numDays;
        }
        bool getBookingStatus() {
            return bookingStatus;
        }
 
        void setRentalDate(string rentalDate) {
            this->rentalDate = rentalDate;
        }
        void setNumDays(int numDays) {
            this->numDays = numDays;
        }
        void setBookingStatus(bool bookingStatus) {
            this->bookingStatus = bookingStatus;
        }
};
 
int Booking::nextBookingId = 1;
 
void EditBookingById(vector<Booking>& bookings, int id) {
    for (int i = 0; i < bookings.size(); i++) {
        if (bookings[i].getBookingId() == id) {
            bookings[i].EditBooking();
            return;
        }
    }
    cout << "Booking not found." << endl;
}
 
void CancelBookingById(vector<Booking>& bookings, int id) {
    for (int i = 0; i < bookings.size(); i++) {
        if (bookings[i].getBookingId() == id) {
            bookings[i].CancelBooking();
            return;
        }
    }
    cout << "Booking not found." << endl;
}
 

class Rental : public Booking {

private:
    double rentalPrice;
    double securityDeposit;
    double totalPrice;
    string paymentStatus;
    string paymentMethod;

public:

    Rental(int bookingId, string rentalDate, string returnDate,
           int numDays, bool bookingStatus, double rentalPrice,
           double securityDeposit, string paymentStatus,
           string paymentMethod)

        : Booking(bookingId, rentalDate, returnDate, numDays, bookingStatus) {

        this->rentalPrice = rentalPrice;
        this->securityDeposit = securityDeposit;
        this->totalPrice = 0;
        this->paymentStatus = paymentStatus;
        this->paymentMethod = paymentMethod;
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

        int choice;
        cin >> choice;

        if (choice == 1)
            paymentMethod = "Cash";
        else if (choice == 2)
            paymentMethod = "Credit Card";
        else if (choice == 3)
            paymentMethod = "Debit Card";
        else if (choice == 4)
            paymentMethod = "ABA Pay";
        else
            paymentMethod = "Unknown";

        paymentStatus = "Paid";

        cout << "Payment Method: " << paymentMethod << endl;
        cout << "Payment Status: " << paymentStatus << endl;
    }

    double getRentalPrice() {
        return rentalPrice;
    }

    double getSecurityDeposit() {
        return securityDeposit;
    }

    double getTotalPrice() {
        return totalPrice;
    }

    string getPaymentStatus() {
        return paymentStatus;
    }

    string getPaymentMethod() {
        return paymentMethod;
    }

    void displayInfo() {

        cout << "\n--- Rental Information ---" << endl;
        cout << "Rental Price: $" << rentalPrice << endl;
        cout << "Security Deposit: $" << securityDeposit << endl;
        cout << "Total Price: $" << totalPrice << endl;
        cout << "Payment Status: " << paymentStatus << endl;
        cout << "Payment Method: " << paymentMethod << endl;
        cout << "Number of Days: " << getNumDays() << endl;
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

    static Customer* customerList[5];
    static int customerCount;

    Customer(string name, int customerId, string dateOFBirth,
             string gender, string phoneNumber, string email) {

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

    void addCustomer() {

        if (customerCount >= 5) {
            cout << "\nCustomer list is full (maximum 5 customers)." << endl;
            return;
        }

        cout << "\n--- Add Customer ---" << endl;

        cout << "Enter name: ";
        cin >> name;

        cout << "Enter customer ID: ";
        cin >> customerId;

        cout << "Enter date of birth: ";
        cin >> dateOFBirth;

        cout << "Enter gender: ";
        cin >> gender;

        cout << "Enter phone number: ";
        cin >> phoneNumber;

        cout << "Enter email: ";
        cin >> email;

        // Add customer to array
        customerList[customerCount] = this;
        customerCount++;

        cout << "\nCustomer added successfully!" << endl;
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

Vehicle* Car::carList[5];
int Car::carCount = 0;

Vehicle* Motorcycle::motoList[5];
int Motorcycle::motoCount = 0;

Customer* Customer::customerList[5];
int Customer::customerCount = 0;


int main() {

    int choice, Bchoice;
    vector<Booking> bookings;  
    Customer cust;


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

    cout << "Welcome to VVIP Rentals" << endl;
    cout << "We have State of the art, Car and Motorcycle Rentals available to book In Phnom Penh" << endl;

    do {

        cout << "1.Search all Cars\n2.Search all Motorcycles\n3.Booking Menu";
        cout << "Please select from the options above: " << endl;
        cin >> choice;

        switch (choice) {

            case 1:
                Car::SearchByType(Car::carList, Car::carCount, "Cars");
                break;

            case 2:
                Motorcycle::SearchByType(Motorcycle::motoList, Motorcycle::motoCount, "Motorcycles");
                break;

            case 3:
                do {
                    cout << "------ Booking Menu ------" << endl;
                    cout << "1.Create Booking\n2.Edit booking\n3.Cancel Booking\n4.Display Bookings" << endl;
                    cout << "Please select from the options above: " << endl;
                    cin >> Bchoice;
                    switch (Bchoice){
                        case 1:
                        for (int i = 0; i < 2; i++) {
                            Booking newBooking;
                            newBooking.CreateBooking();
                            cust.addCustomer();
                            bookings.push_back(newBooking);
                        }
                            break;
                        case 2:
                            int editId;
                            cout << "Enter Booking ID to edit: ";
                            cin >> editId;
                            EditBookingById(bookings, editId);
                            break;
                        case 3:
                            int cancelId;
                            cout << "Enter Booking ID to cancel: ";
                            cin >> cancelId;
                            CancelBookingById(bookings, cancelId);
                            break;
                        case 4:
                            for (int i = 0; i < bookings.size(); i++) {
                            bookings[i].DisplayBooking();
                            break;
                            }
                        case 5:
                            cout << "Exiting Program..";
                            break;
        }
            }
                } while (choice != 5);
                break;

            case 4:
                cout << "Exiting Program..";
                break;
        }

    } while (choice != 4);

    return 0;
};

// int main() {
//     Car car1("Toyota", "Black", 101, 2022, 50.00, true, true, "Sedan", 4);
//     cout << "--- Car Info ---" << endl;
//     car1.displayInfo();
 
//     vector<Booking> bookings;  
 
//     cout << "\n=== Creating Bookings ===" << endl;
//     for (int i = 0; i < 2; i++) {
//         Booking newBooking;
//         newBooking.CreateBooking();
//         bookings.push_back(newBooking);
//     }
 
//     cout << "\n=== All Bookings ===" << endl;
//     for (int i = 0; i < bookings.size(); i++) {
//         bookings[i].DisplayBooking();
//     }
 
//     cout << "\n=== Editing Booking ===" << endl;
//     int editId;
//     cout << "Enter Booking ID to edit: ";
//     cin >> editId;
//     EditBookingById(bookings, editId);
 
//     cout << "\n=== Cancelling Booking ===" << endl;
//     int cancelId;
//     cout << "Enter Booking ID to cancel: ";
//     cin >> cancelId;
//     CancelBookingById(bookings, cancelId);
 
//     cout << "\n=== Final Booking List ===" << endl;
//     for (int i = 0; i < bookings.size(); i++) {
//         bookings[i].DisplayBooking();
//     }
 
//     return 0;
// }
// >>>>>>> 6b79d3ce9c5affbc943ea1ca86c05dda831074a0
