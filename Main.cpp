#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

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
 
int main() {
    Car car1("Toyota", "Black", 101, 2022, 50.00, true, true, "Sedan", 4);
    cout << "--- Car Info ---" << endl;
    car1.displayInfo();
 
    vector<Booking> bookings;  
 
    cout << "\n=== Creating Bookings ===" << endl;
    for (int i = 0; i < 2; i++) {
        Booking newBooking;
        newBooking.CreateBooking();
        bookings.push_back(newBooking);
    }
 
    cout << "\n=== All Bookings ===" << endl;
    for (int i = 0; i < bookings.size(); i++) {
        bookings[i].DisplayBooking();
    }
 
    cout << "\n=== Editing Booking ===" << endl;
    int editId;
    cout << "Enter Booking ID to edit: ";
    cin >> editId;
    EditBookingById(bookings, editId);
 
    cout << "\n=== Cancelling Booking ===" << endl;
    int cancelId;
    cout << "Enter Booking ID to cancel: ";
    cin >> cancelId;
    CancelBookingById(bookings, cancelId);
 
    cout << "\n=== Final Booking List ===" << endl;
    for (int i = 0; i < bookings.size(); i++) {
        bookings[i].DisplayBooking();
    }
 
    return 0;
}