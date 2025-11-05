#include<iostream>
using namespace std;

class Hotel 
{
    public:
        void displayFront();
};

void Hotel::displayFront() 
{
    cout << "*************************************" << endl;
    cout << "            WELCOME TO HOTEL        " << endl;
    cout << "*************************************" << endl;
    cout << "          PROJECT MEMBERS           " << endl;
    cout << "1. TURAB HAIDER" << endl;
    cout << "2. SHAHEER KHAN GHOURI" << endl;
    cout << "3. MUJEEB UR REHMAN" << endl;
    cout << "ADDRESS: XYZ" << endl;
    cout << "CONTACT US: +9230-267826138, +035455852" << endl;
}