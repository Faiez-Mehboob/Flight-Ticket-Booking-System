# ✈️ Flight Ticket Booking System

This is a C++ console-based **Flight Ticket Booking System** developed as a project for the Object Oriented Programming (OOP) course at FAST NUCES Karachi. It allows users to view available flights, make bookings, print tickets, and even book a cab — all while applying core OOP principles.


## 🛠️ Features

- User registration and login system
- Search and book flights based on route and date
- Manage multiple passenger types: adults, children, infants
- Optional cab booking for added convenience
- Ticket printing and reservation summary
- Cancel existing bookings
- User authentication via credential file


## 🧱 Technologies Used

- **Language**: C++  
- **Paradigm**: Object-Oriented Programming  
- **File Handling**: `fstream` for ticket and credential management  
- **Data Structures**: `vector`, `string`  


## 📂 File Structure

- `Flight_Ticket_Booking_System.cpp` — Main source file containing all classes and logic.
- `credentials.txt` — File for storing registered usernames and passwords.
- `[FlightID].txt` — Dynamically generated ticket files after booking.


## 🧩 OOP Concepts Implemented

- Classes and Objects (e.g. `Flight`, `Passenger`, `Cab`)  
- Encapsulation and Data Hiding  
- Composition (`Passenger` owns a `Cab`)  
- Functional decomposition for modular logic  


## 🔄 How It Works

1. **Sign Up / Login**
   - New users can register.
   - Returning users can log in using stored credentials.

2. **Booking Flow**
   - Input departure, arrival, date, and ticket class.
   - Choose from matching available flights.
   - Enter passenger details and confirm booking.
   - Optionally add a cab.

3. **Ticket Output**
   - Print your reservation details to a `.txt` file.
   - View all your reserved flights.

4. **Cancel Booking**
   - Cancel any booked flight by providing its flight ID.


## 📌 Usage Instructions

1. Clone the repo:
   ```bash
   git clone https://github.com/Faiez-Mehboob/Flight-Ticket-Booking-System.git
   
2. **Compile:**
   - g++ Flight_Ticket_Booking_System.cpp -o bookingSystem

3. **Run:**
   - ./bookingSystem

## ✅ Future Improvements

- GUI version using Qt or SFML
- Admin dashboard to manage flights
- Real-time flight data integration
- Encrypted credential storage

## 📃 License

- This project is for educational purposes only and does not include any real-time data or payment processing.

