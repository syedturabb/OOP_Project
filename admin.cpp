#include<iostream>
using namespace std;
class Manager {
private:
    string system_username;  
    int system_password;     

public:

    Manager();
    bool login();
    void displayOptions();
    void showRoomStatus();
    void addEmployee();

};

Manager::Manager() 
{
    system_username = "user";
    system_password = 123456;
}

bool Manager:: login() 
{
    string username;
    int password;
    bool isLoggedIn = false;
    int match = 1;  // Used to match the user names

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

        // Check if the username matches
    if (username == system_username && password == system_password) {
        cout << "\t\t\t\tWelcome Manager!\n";
        isLoggedIn = true;
        displayOptions();
    } 
    else
    {
        cout << "Wrong username or password.\n";
    }

    return isLoggedIn;
    }

void Manager:: displayOptions() 
    {
        int choice;
        do {
            cout << "\nManager Menu:\n";
            cout << "1. Show Room Status\n";
            cout << "2. Add New Employee\n";
            cout << "3. Logout\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    showRoomStatus();
                    break;
                case 2:
                    addEmployee();
                    break;
                case 3:
                    cout << "Logging out...\n";
                    return;
                default:
                    cout << "Invalid choice. Please choose again.\n";
            }
        } while (choice != 3);
    }

void Manager:: showRoomStatus() 
    {
        int rooms[101];
        ifstream inFile("rooms.txt");

        if (!inFile) {
            cout << "Error: Unable to open file!\n";
            return;
        }

        for (int i = 1; i <= 100; i++) {
            inFile >> rooms[i];
        }
        inFile.close();

        for (int i = 1; i <= 100; i++) {
            if (rooms[i] == 1) {
                cout << "Room " << i << ": Not Available\t";
            } else {
                cout << "Room " << i << ": Available\t";
            }
            if (i % 5 == 0) {
                cout << "\n";
            }
        }
    }


void Manager:: addEmployee()    
    {
        string name;
        int id;
        long long phone;

        cout << "Enter the name of the new employee: ";
        cin.ignore();  // To avoid newline issue after previous input
        getline(cin, name);

        cout << "Enter an ID for the new employee: ";
        cin >> id;

        cout << "Enter the phone number of the new employee: ";
        cin >> phone;

        // Save the new employee information in separate files
        ofstream outFileNames("Employes/names.txt", ios::app);
        ofstream outFileIds("Employes/ids.txt", ios::app);
        ofstream outFilePhones("Employes/phone_nums.txt", ios::app);

        if (outFileNames && outFileIds && outFilePhones) {
            outFileNames << "\n" << name;
            outFileIds << "\n" << id;
            outFilePhones << "\n" << phone;

            cout << "\nEmployee added successfully.\n";
        } else {
            cout << "Error: Unable to open file(s) to save employee information!\n";
        }

        outFileNames.close();
        outFileIds.close();
        outFilePhones.close();
    }