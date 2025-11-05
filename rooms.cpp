#include <iostream>
#include <fstream>
#include <string>
#include <limits>  
using namespace std;

class Room {
private:
    int roomNumber;
    bool isReserved;

public:
    Room();
    Room(int);
    int getRoomNumber() const;
    bool getStatus() const;
    void reserve();
    void cancelReservation();
    void saveToFile(ofstream &file) const;
    void loadFromFile(ifstream &file);
};

Room::Room() 
    {
        roomNumber = 0;
        isReserved = false;
    }

Room::Room(int number) 
    {
        roomNumber = number;
        isReserved = false;
    }

int Room:: getRoomNumber() const 
    {
        return roomNumber;
    }

bool Room:: getStatus() const 
    {
        return isReserved;
    }

void Room:: reserve() 
    {
        isReserved = true;
    }

void Room:: cancelReservation() 
    {
        isReserved = false;
    }

void Room:: saveToFile(ofstream &file) const 
    {
        file << roomNumber << " " << isReserved << endl;
    }

void Room:: loadFromFile(ifstream &file) 
    {
        file >> roomNumber >> isReserved;
    }

class Reservation 
{
private:
    Room *rooms;
    int totalRooms;

public:
    Reservation(int);
    ~Reservation();
    void initializeRooms();
    void reserveRoom();
    void showRoomStatus();
    void saveRoomData(); 
    Room &getRoom(int roomNumber) 
    {
        return rooms[roomNumber - 1];
    }
};

Reservation::Reservation(int roomCount = 100) 
    { 
        totalRooms = roomCount;
        rooms = new Room[totalRooms];
        for (int i = 0; i < totalRooms; ++i) {
            rooms[i] = Room(i + 1); 
        }
    }

Reservation::~Reservation() 
    {
        delete[] rooms;
    }

void Reservation:: initializeRooms() 
    {
        ifstream file("rooms.txt");
        if (!file) {
            ofstream createFile("rooms.txt");
            for (int i = 0; i < totalRooms; ++i) {
                rooms[i].saveToFile(createFile);
            }
            createFile.close();
        } else {
            for (int i = 0; i < totalRooms; ++i) {
                rooms[i].loadFromFile(file);
            }
            file.close();
        }
    }

void Reservation:: reserveRoom() 
    {
        int roomNumber;
        do {
            cout << "Enter room number to reserve (1-" << totalRooms << "): ";
            cin >> roomNumber;
            if (cin.fail()) {
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining characters
                cout << "Invalid input. Please enter a valid room number." << endl;
                continue;
            }

            if (roomNumber < 1 || roomNumber > totalRooms) {
                cout << "We have only " << totalRooms << " rooms in our hotel." << endl;
            }
        } while (roomNumber < 1 || roomNumber > totalRooms);

        Room &room = rooms[roomNumber - 1];
        if (!room.getStatus()) {
            room.reserve();
            cout << "Room " << roomNumber << " is reserved." << endl;
        } else {
            cout << "Room " << roomNumber << " is already reserved." << endl;
        }

        saveRoomData();
    }

void Reservation:: showRoomStatus() 
    {
        for (int i = 0; i < totalRooms; i++) 
        {
            cout << "Room " << (i + 1) << ": " 
                 << (rooms[i].getStatus() ? "Not available" : "Available") << "\t";
            if ((i + 1) % 5 == 0) 
            {
                cout << endl;
            }
        }
        cout << endl; 
    }

void Reservation:: saveRoomData() 
    {
        ofstream saveRooms("rooms.txt");
        for (int i = 0; i < totalRooms; i++) 
        {
            rooms[i].saveToFile(saveRooms);
        }
    }


class Cancellation 
{
public:
    void cancelRoom(Reservation &);
    
};

void Cancellation:: cancelRoom(Reservation &reservation) 
    {
        int roomNumber;
        cout << "Enter room number to cancel (1-100): ";
        cin >> roomNumber;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid room number." << endl;
            return;
        }

        if (roomNumber < 1 || roomNumber > 100) {
            cout << "We have only 100 rooms in our hotel." << endl;
            return;
        }

        Room &room = reservation.getRoom(roomNumber);

        if (room.getStatus()) {
            room.cancelReservation();
            cout << "Room " << roomNumber << " reservation is cancelled." << endl;
        } else {
            cout << "Room " << roomNumber << " is not reserved." << endl;
        }

        reservation.saveRoomData();
    }
