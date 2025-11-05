#include <iostream>
#include <string>
using namespace std;
class Menu {
    
protected:
    float total;
    float price;
public:
    int h;
    virtual void showMenu() = 0;  // Pure virtual function to enforce implementation in derived classes
    virtual float calculateBill(float quantity) = 0;  // Calculate the total bill  
    
};
class Appetizer : public Menu {
public:
    Appetizer();
    void showMenu();
    float calculateBill(float);
    
};
Appetizer::Appetizer() 
    {
        price = 5;
    }

void Appetizer::showMenu()
    {
        cout << "\nIn Appetizer, we have:\n";
        cout << "1. Buffalo wings\n";
        cout << "2. Sweet and Sour Wings\n";
        cout << "3. Chicken Spring Rolls\n";
    }

float Appetizer:: calculateBill(float quantity)
    {
        total = quantity * price;
        cout << "Your Bill is: $" << total << endl;
        return total;
    }

class Sandwiches : public Menu {
public:
    Sandwiches(); 
    void showMenu();
    float calculateBill(float);
};

Sandwiches::Sandwiches()
    {
        price = 6;
    }
void Sandwiches:: showMenu()
    {
        cout << "\nIn Sandwiches, we have:\n";
        cout << "1. Egg Sandwich\n";
        cout << "2. Chicken Sandwich\n";
        cout << "3. Cheese Sandwich\n";
    }

float Sandwiches::calculateBill(float quantity)
    {
        total = quantity * price;
        cout << "Your Bill is: $" << total << endl;
        return total;
    }

class Continental : public Menu {
public:
    Continental();
    void showMenu(); 
    float calculateBill(float);
};

Continental::Continental() 
    {
        price = 7;
    }

void Continental::showMenu() 
    {
        cout << "\nIn Continental, we have:\n";
        cout << "1. Creamy White Chicken Lasagna\n";
        cout << "2. Spaghetti Pasta with Marinara Sauce\n";
        cout << "3. Peri Peri Chicken\n";
    }

float Continental::calculateBill(float quantity)
    {
        total = quantity * price;
        cout << "Your Bill is: $" << total << endl;
        return total;
    }

class Chinese : public Menu 
{
public:
    Chinese();
    void showMenu();
    float calculateBill(float);
};
Chinese::Chinese() 
    {
        price = 9;
    }

void Chinese:: showMenu() 
    {
        cout << "\nIn Chinese, we have:\n";
        cout << "1. Egg Fried Rice\n";
        cout << "2. Beef Chili Dry\n";
        cout << "3. Vegetable Fried Rice\n";
    }

float Chinese::calculateBill(float quantity)
    {
        total = quantity * price;
        cout << "Your Bill is: $" << total << endl;
        return total;
    }

class Desserts : public Menu 
{
public:
    Desserts();
    void showMenu();
    float calculateBill(float);
};

Desserts::Desserts() 
    {
        price = 8;
    }

void Desserts:: showMenu() 
    {
        cout << "\nIn Desserts, we have:\n";
        cout << "1. Cream Caramel\n";
        cout << "2. Chocolate Lava\n";
        cout << "3. Fruit Trifle\n";
    }

float Desserts:: calculateBill(float quantity)  
    {
        total = quantity * price;
        cout << "Your Bill is: $" << total << endl;
        return total;
    }


void processMenu(Menu& menu) 
{
    int choice;
    float quantity;

    menu.showMenu();
    
    do {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice < 1 || choice > 3) {
            cout << "Invalid choice. Please choose a number between 1 and 3." << endl;
        }
    } while (choice < 1 || choice > 3);

    cout << "How many would you like to order? ";
    cin >> quantity;
    
    menu.calculateBill(quantity);
}
