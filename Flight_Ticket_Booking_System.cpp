#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;

class Cab{
public:
    string Comfortlvl;

    void SetComfort(int comfort){
        if(comfort==1){
            Comfortlvl="Mini";
        }    
        else if(comfort==2){
            Comfortlvl="Ride Ac";
        }
        else if(comfort==3){
            Comfortlvl="Premium";
        }
        else if(comfort==4){
            Comfortlvl="None";
        }
    }
};
class Flight {
public:
    string flightId;
    string airlines;
    string departureAirport;
    string arrivalAirport;
    string departuredate;
    string departureDateTime;
    string arrivalDateTime;
    double ticketPrice;
    int availableSeats;
    string baggageAllowance;
    string ticketclass;

    Flight(string flightId,string airlines, string departureAirport, string arrivalAirport,string date, string departureDateTime,
           string arrivalDateTime, double ticketPrice, int availableSeats, string bag, string ticketclass)
        : flightId(flightId),airlines(airlines), departureAirport(departureAirport), arrivalAirport(arrivalAirport), departuredate(date),
          departureDateTime(departureDateTime), arrivalDateTime(arrivalDateTime), ticketPrice(ticketPrice),
          availableSeats(availableSeats), baggageAllowance(bag), ticketclass(ticketclass) {}

    bool isSeatAvailable(int seatsRequested) {
        return availableSeats >= seatsRequested;
    }

    void bookSeat(int seatsRequested) {
        availableSeats -= seatsRequested;
    }
};

class passenger {
public:
    string name;
    string contactInfo;
    int numAdults;
    int numChildren;
    int numInfants;
    double totalPrice;
    string departure;
    string arrival;
    string date;
    string category;
    int seats;
    vector <Flight> availableFlights;
    vector <Flight> bookedFlights;
    Cab cab;
    
    void setfunction(){
        cout << "Enter the departure airport: ";
        cin >> departure;
        cout << "Enter the arrival airport: ";
        cin >> arrival;
        cout << "Enter the departure date (DD-MM-YYYY) : ";
        cin >> date;
        cout << "Enter the ticket class: ";
        cin >> category;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your contact info: ";
        cin >> contactInfo;
        cout << "Enter the number of adults: ";
        cin >> numAdults;
        cout << "Enter the number of children: ";
        cin >> numChildren;
        cout << "Enter the number of infants: ";
        cin >> numInfants;
    }
    
    void BookFlight(vector <Flight>& flights) {
        setfunction();
        bool found;
        for (auto& f : flights) {
            if ((f.departureAirport == departure &&
                f.arrivalAirport == arrival &&
                f.departuredate == date) || 
                (f.departureAirport==departure && f.arrivalAirport==arrival)) {
                availableFlights.push_back(f);
            }
        }
            cout <<endl<< "Available flights:" << endl<<endl;
            for (auto& f : availableFlights) {
                if (availableFlights.empty()) 
                {
                    cout << "No flights found!" << endl;
                    return;
                }
                else if((f.departureAirport == departure &&
                f.arrivalAirport == arrival &&
                f.departuredate == date) || 
                (f.departureAirport==departure && f.arrivalAirport==arrival)){
                    found=true;
                    cout << "Airlines: " << f.airlines << endl;
                    cout << "Flight ID: " << f.flightId << endl;
                    cout << "Departure Airport: " << f.departureAirport << endl;
                    cout << "Arrival Airport: " << f.arrivalAirport << endl;
                    cout << "Departure date: " << f.departuredate << endl;
                    cout << "Departure Time: " << f.departureDateTime << endl;
                    cout << "Arrival Time: " << f.arrivalDateTime << endl;
                    cout << "Ticket Price: " << f.ticketPrice <<" PKR " <<endl;
                    cout << "Available Seats: " << f.availableSeats << endl;
                    cout << "Baggage Allowance: " << f.baggageAllowance << endl;
                    cout << "Ticket Class: " << f.ticketclass << endl;
                    cout << "-----------------------------------" << "\n\n";
                }
            }
            if(found){
                cout << "Which flight do you want to book ?\nEnter Flight id : ";
                string choice;
                cin >> choice;
                bool found=false;
                for(auto& f : availableFlights) { 
                    if(f.flightId == choice) {
                        string c;
                        found=true;
                        cout << "Enter the number of seats you want to book: ";
                        cin >> seats;
                        if (seats > f.availableSeats) {
                            cout << "Seats not available!" << endl;
                            return;
                        }
                        int sum = numAdults + numChildren + numInfants;
                        if(sum != seats) {
                            cout << "Invalid number of passengers!" << endl;
                            return;
                        }
                        f.bookSeat(seats);
                        bookedFlights.push_back(f);
                        cout << "Flight booked successfully!" << endl;
                        cout << "-----------------------------------\n\n";
                        cout << "Booking details: " << endl;
                        cout << "Name: " << name << endl;
                        cout << "Contact : " << contactInfo << endl;
                        cout << "Number of seats booked: " << sum << endl;
                        cout << "Flight ID: " << f.flightId << endl;
                        cout << "Airlines: " << f.airlines << endl;
                        cout << "Departure Airport: " << f.departureAirport << endl;
                        cout << "Arrival Airport: " << f.arrivalAirport << endl;
                        cout << "Departure date: " << f.departuredate << endl;
                        cout << "Departure Time: " << f.departureDateTime << endl;
                        cout << "Baggage Allowance: " << f.baggageAllowance << endl;
                        cout << "Ticket Class: " << f.ticketclass << endl;
                        calculateTotalPrice(f.ticketPrice);
                        cout << "Total price: " << totalPrice <<" PKR"<< endl;
                        cout << "-----------------------------------" << "\n\n";
                        cout <<"Do you also want to book a cab ? (Y/N): ";
                        cin>>c;
                        if (c == "Y" || c == "y") {
                            int cabc;
                            cout << "\n1. Mini\t\t2. Ride A/C\t3. Premium" << endl;
                            cout << "Select the Cab Class: ";
                            cin >> cabc;
                            cab.SetComfort(cabc);
                            cout << "Cab booked successfully!" << endl;
                        } else if (c == "N" || c == "n") {
                            cab.SetComfort(4);
                        }
                        break;
                    } 
                }
                if(!found){
                    cout << "Invalid flight id!" << endl;
                    return; 
                }
            }
            else{
                cout<<"No FLights Found"<<endl;
            }
    }
    void cancelBooking() {
        cout << "Enter Flight id: ";
        string id;
        cin >> id;
        bool found = false;
        for (auto it = bookedFlights.begin(); it != bookedFlights.end(); ++it) {
            if (it->flightId == id) {
                calculateTotalPrice(it->ticketPrice);
                cout << "Booking cancelled successfully!" << endl;
                cout << "Ticket Amount refunded: " << totalPrice << " PKR" << endl;
                bookedFlights.erase(it);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No booking found!" << endl;
        }
    }
    
    void printTicket(){
        cout << "Enter Flight id: ";
        string id;
        cin>>id;
        bool found=false;
        for(auto& f : bookedFlights){
            if(f.flightId == id){
                string filename=id+".txt";
                ofstream fout(filename,ios::out);
                if(!fout.is_open()){
                    cout<<"Could not Open file"<<endl;
                }
                else{
                    cout<<"File opened"<<endl;
                }
                stringstream ss;
                ss << "Flight details: " << endl;
                ss << "Name: " << name << endl;
                ss << "Contact : " << contactInfo << endl;
                ss << "Number of seats booked: " << numAdults + numChildren + numInfants << endl;
                ss << "Flight ID: " << f.flightId << endl;
                ss << "Airlines: " << f.airlines << endl;
                ss << "Departure Airport: " << f.departureAirport << endl;
                ss << "Arrival Airport: " << f.arrivalAirport << endl;
                ss << "Departure Time: " << f.departureDateTime << endl;
                ss << "Baggage Allowance: " << f.baggageAllowance << endl;
                ss << "Ticket Class: " << f.ticketclass << endl;
                calculateTotalPrice(f.ticketPrice);
                ss << "Total price: " << totalPrice <<" PKR"<< endl;
                ss << "Cab: "<< cab.Comfortlvl << endl;
                ss << "-----------------------------------" << "\n\n";
                string str=ss.str();
                fout<<str;
                fout.close();
                cout<<"Ticket Printed Successfully"<<endl;
                found=true;
                break;
            }
        }
        if(!found){
            cout<<"No Such Booking Reserved"<<endl;
        }
    }

    void viewReservedFlights() {
        if (bookedFlights.empty()) {
            cout << "No flights reserved!" << endl;
            return;
        }

        cout << "Reserved Flights:" << endl;
        for (auto& f : bookedFlights) {
            cout << "Flight ID: " << f.flightId << endl;
            cout << "Airlines: " << f.airlines << endl;
            cout << "Departure Airport: " << f.departureAirport << endl;
            cout << "Arrival Airport: " << f.arrivalAirport << endl;
            cout << "Departure date: " << f.departuredate << endl;
            cout << "Departure Time: " << f.departureDateTime << endl;
            cout << "Baggage Allowance: " << f.baggageAllowance << endl;
            cout << "Cab: "<< cab.Comfortlvl << endl;
            cout << "Ticket Class: " << f.ticketclass << endl;
            cout << "-----------------------------------" << "\n\n";
        }
    }

    void calculateTotalPrice(double basePrice) {
        totalPrice = (numAdults * basePrice) + (numChildren * (basePrice * 0.75)) + (numInfants * (basePrice * 0.5));
    }
};

void clearscreen(){
    cout<<"\033[H\033[2J";
}


void registerUser(const string& username, const string& password) {
    ofstream outfile("credentials.txt", ios::app); 
    if (outfile.is_open()) {
        outfile << username << ' ' << password << '\n'; 
        cout << "Registration successful!\n";
        outfile.close();
    } else {
        cout << "Error: Unable to open file for writing.\n";
    }
}

bool authenticateUser(const string& username, const string& password) {
    ifstream infile("credentials.txt");
    if (infile.is_open()) {
        string storedUsername, storedPassword;
        while (infile >> storedUsername >> storedPassword) {
            if (storedUsername == username && storedPassword == password) {
                infile.close();
                return true; 
            }
        }
        infile.close();
    }
    return false;
}

int main() {
    vector <Flight> flights = {
        Flight("FL122","PIA", "karachi", "islamabad","29-04-2024" ,"12:00PM", "02:00PM", 15000, 53, "20kg", "Economy"),
        Flight("FL123","PIA", "karachi", "islamabad","27-04-2024" ,"11:00PM", "01:00PM", 17000, 53, "20kg", "Business"),
        Flight("FL124","AirBlue", "lahore", "karachi","29-04-2024", "3:00PM", "05:00PM", 35000, 35, "30kg", "Business"),
        Flight("FL125","AirSial", "jeddah", "doha","30-04-2024" , "06:00PM", "08:00PM", 100000, 90, "40kg", "First Class"),
        Flight("FL126","Emirates", "dallas", "newyork","29-04-2024" , "11:00PM", "01:00AM", 30000, 55, "50kg", "Economy"),
        Flight("FL127","FlyJinnah", "lahore", "multan","29-04-2024" , "12:00AM", "02:00AM", 28000, 98, "60kg", "Business")
    };
    ofstream outfile("credentials.txt", ios::app);
    outfile.close();
    string username,password;
    int signchoice;
    bool Authenticated=false;
    do{
        cout<<"<---------------SIGN IN--------------->"<<endl;
        cout << "1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin>>signchoice;
        switch(signchoice){
        case 1:
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            registerUser(username, password);
            cin.ignore();
            cout<<"Press Enter to Continue:";
            cin.ignore();
            clearscreen();
            break;
        case 2:
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (authenticateUser(username, password)) {
                cout << "Login successful!\n";
                Authenticated=true;
            } else {
                cout << "Invalid username or password.\n";
                Authenticated=false;
            }
            cin.ignore();
            cout<<"Press Enter to Continue:";
            cin.ignore();
            clearscreen();
            break;
        default:
            cout<<"Invalid Choice"<<endl;
            cin.ignore();
            cout<<"Press Enter to Continue:";
            cin.ignore();
            clearscreen();
            break;
        }
    }while(!Authenticated);
    passenger p;
    int choice;
    do{
        cout<<"<---------------------------_Welcome To AMF Flight Reservation_---------------------------->"<<endl;
        cout<<"1. Book Flight\n2. Cancel Flight\n3. Check Reserved Flights\n4. Print Reservation\n5. Exit"<<endl;
        cout<<"Enter Choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            clearscreen();
            cout<<"<---------------------------_Welcome To AMF Flight Reservation_---------------------------->"<<endl;
            p.BookFlight(flights);
            cin.ignore();
            cout<<"Press Enter to Continue:";
            cin.ignore();
            clearscreen();
            break;
        case 2:
            clearscreen();
            cout<<"<---------------------------_Welcome To AMF Flight Reservation_---------------------------->"<<endl;
            p.cancelBooking();
            cin.ignore();
            cout<<"Press Enter to Continue:";
            cin.ignore();
            clearscreen();
            break;
        case 3:
            clearscreen();
            cout<<"<---------------------------_Welcome To AMF Flight Reservation_---------------------------->"<<endl;
            p.viewReservedFlights();
            cin.ignore();
            cout<<"Press Enter to Continue:";
            cin.ignore();
            clearscreen();
            break;
        case 4:
            clearscreen();
            cout<<"<---------------------------_Welcome To AMF Flight Reservation_---------------------------->"<<endl;
            p.printTicket();
            cin.ignore();
            cout<<"Press Enter to Continue:";
            cin.ignore();
            clearscreen();
            break;
        case 5:
            continue;
            break;
        default:
            cin.ignore();
            cout<<"INVALID CHOICE! Try again."<<endl;
            cout<<"Press Enter to Continue:";
            cin.ignore();
            clearscreen();
            break;
        }
    }
    while(choice!=5);
    clearscreen();
    cout<<"<-----------------------------------------GOODBYE AND THANK YOU FOR USING AMF FLIGHT RESERVATION----------------------------------------------------->";
    return 0;
}
