#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "admin.cpp"
#include "design.cpp"
#include "menu.cpp"
#include "rooms.cpp"
using namespace std;

class MainHotel 
{
public:
    void showBuffetOptions();
    void start();
    
};

void MainHotel::start() 
    {
        Hotel hotel;
        hotel.displayFront(); 

        Reservation roomManagement; // Composition
        Cancellation cancelManager;
        Manager manager;
        int choice;

        do 
        {
            roomManagement.initializeRooms();

            cout << "\n1. Reserve a room\n";
            cout << "2. Cancel a room\n";
            cout << "3. Buffet option\n";
            cout << "4. Show room status\n";
            cout << "5. Login as manager\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            
            cin >> choice;
            while (cin.fail() || choice < 1 || choice > 6) 
            {
                cin.clear(); // Clear the error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "\nPlease enter a valid choice (1-6): ";
                cin >> choice;
            }

            switch (choice) {
                case 1:
                    roomManagement.reserveRoom();
                    break;
                case 2:
                    cancelManager.cancelRoom(roomManagement);
                    break;
                case 3: 
                    showBuffetOptions(); 
                    break;
                case 4:
                    roomManagement.showRoomStatus();
                    break;
                case 5:
                    manager.login();
                    break;
                case 6:
                    cout << "Exiting the program." << endl;
                    break;
            }
        } while (choice != 6);
    }

void MainHotel::showBuffetOptions() {
    int menuChoice;
    Appetizer appetizer;
    Sandwiches sandwiches;
    Continental continental;
    Chinese chinese;
    Desserts desserts; 
    cout << "Here is our buffet list:\n";
    cout << "1. Appetizer for 5$\n";  
    cout << "2. Sandwiches for 6$\n";  
    cout << "3. Continental food for 7$\n";  
    cout << "4. Chinese for 9$\n"; 
    cout << "5. Desserts for 8$\n"; 
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    
    cin >> menuChoice;
    while (cin.fail() || menuChoice < 1 || menuChoice > 6) 
    {
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid choice. Please enter a valid choice (1-6): ";
        cin >> menuChoice;
    }

    switch (menuChoice) {
        case 1:
            processMenu(appetizer);  // Call Appetizer
            break;
        case 2:
            processMenu(sandwiches);  // Call Sandwiches
            break;
        case 3:
            processMenu(continental);  // Call Continental
            break;
        case 4:
            processMenu(chinese);  // Call Chinese
            break;
        case 5:
            processMenu(desserts);  // Call Desserts
            break;
        case 6:
            return;  // Exit the function
        default:
            cout << "Invalid choice." << endl;
            break;
    }
}

int main() {
    MainHotel mainHotel;
    mainHotel.start();
    return 0;
}
