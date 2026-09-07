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
            this->bookingStatus = true;
        }
        void CreateBooking(){
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
        void CancelBooking(){
            bookingStatus = false;
            cout << "Booking cancelled" << endl;
        }
        void EditBooking(){
            cout << "Enter new rent date: ";
            cin >> rentalDate;

            cout << "Enter new return date: ";
            cin >> returnDate;

            cout << "Enter new number of days: ";
            cin >> numDays;

            cout << "Booking updated" << endl;
        }
        void DisplayBooking(){
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

int main() {
    Car car1("Toyota", "Black", 101, 2022, 50.00, true, true, "Sedan", 4);
    cout << "--- Car Info ---" << endl;
    car1.displayInfo();

    Booking booking1(1, "05/09/2026", "10/09/2026", 5, true);
    booking1.DisplayBooking();

    cout << "\nCreating a new booking: " << endl;
    booking1.CreateBooking();
    booking1.DisplayBooking();

    cout << "\nEdit booking: " << endl;
    booking1.EditBooking();
    booking1.DisplayBooking();

    cout << "\nCancelling booking: " << endl;
    booking1.CancelBooking();
    booking1.DisplayBooking();

    return 0;

}