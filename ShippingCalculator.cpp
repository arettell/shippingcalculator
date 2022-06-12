// ShippingCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>


using namespace std;
// defining values
string itemname;
char yesno;
string destination;
float ordertotal = 0.00;
const float fragilecost = 2.00;
const float usa50 = 6.00;
const float usa100 = 9.00;
const float usa150 = 12.00;
const float can50 = 8.00;
const float can100 = 12.00;
const float can150 = 15.00;
const float aus50 = 10.00;
const float aus100 = 14.00;
const float aus150 = 17.00;
const float mars50 = 25.00;
const float mars100 = 50.00;
const float mars150 = 75.00;
float shippingcost = 0.00;


int main()
{
    // opening/creating a file to write to
    fstream orderfile;
    orderfile.open("order.txt", ios::out);

    //making the border with the title for both the console and file
    cout << setfill('.') << setw(50) << '.' << endl;
    cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
    cout << setfill('.') << setw(50) << '.' << endl;
    orderfile << setfill('.') << setw(50) << '.' << endl;
    orderfile << "ITCS 2530 - Programming Assignment for week #3" << endl;
    orderfile << setfill('.') << setw(50) << '.' << endl;

    //gathering information from our user, writing it to both console and file
    cout << "Please enter the item name (no spaces) " << setw(11) << '.' << right << ':';
    orderfile << "Please enter the item name (no spaces) " << setw(11) << '.' << right << ':';
    cin >> itemname;
    orderfile << itemname << endl;

    cout << "Is the item fragile? (y=yes/n=no)" << setw(17) << '.' << right << ':';
    orderfile << "Is the item fragile? (y=yes/n=no)" << setw(17) << '.' << right << ':';
    cin >> yesno;
    orderfile << yesno << endl;

    //first if statement to make sure user answered correctly, if not returns an error
    if (yesno == 'y' || yesno == 'Y' || yesno == 'n' || yesno == 'N')
    {
        
    }
    else {
        cout << "Invalid entry, exiting";
        orderfile << "Invalid entry, exiting";
        exit(EXIT_FAILURE);
    };

    // more information gathering, writing to both console and file
    cout << "Please enter your order total" << setw(21) << '.' << right << ':';
    orderfile << "Please enter your order total" << setw(21) << '.' << right << ':';
    cin >> ordertotal;
    orderfile << ordertotal << endl;

    cout << "Please enter destination. (usa/can/aus/mars)" << setw(11) << '.' << right << ':';
    orderfile << "Please enter destination. (usa/can/aus/mars)" << setw(11) << '.' << right << ':';
    cin >> destination;
    orderfile << destination << endl;

    // second if statement to make sure they answered the location correctly, if not returns an error
    if (destination == "aus" || destination == "AUS" || destination == "usa" || destination == "USA" || destination == "can" || destination == "CAN" || "mars" || "MARS")
    {

    }
    else {
        cout << "Invalid entry, exiting";
        orderfile << "Invalid entry, exiting";
        exit(EXIT_FAILURE);
    };

    // changing the item name and shipping destination to all capital letters
    transform(itemname.begin(), itemname.end(), itemname.begin(), ::toupper);
    transform(destination.begin(), destination.end(), destination.begin(), ::toupper);


    //big if statement to determine the cost of shipping based on item cost and where its going.
    if (ordertotal <= 50 && destination == "USA")
        shippingcost = usa50;
    else if (ordertotal > 50 && ordertotal <= 100 && destination == "USA")
        shippingcost = usa100;
    else if (ordertotal > 100 && ordertotal <= 150 && destination == "USA")
        shippingcost = usa150;
    else if (ordertotal <= 50 && destination == "CAN")
        shippingcost = can50;
    else if (ordertotal > 50 && ordertotal <= 100 && destination == "CAN")
        shippingcost = can100;
    else if (ordertotal > 100 && ordertotal <= 150 && destination == "CAN")
        shippingcost = can150;
    else if (ordertotal <= 50 && destination == "AUS")
        shippingcost = aus50;
    else if (ordertotal > 50 && ordertotal <= 100 && destination == "AUS")
        shippingcost = aus100;
    else if (ordertotal > 100 && ordertotal <= 150 && destination == "AUS")
        shippingcost = aus150;
    else if (ordertotal <= 50 && destination == "MARS")
        shippingcost = mars50;
    else if (ordertotal > 50 && ordertotal <= 100 && destination == "MARS")
        shippingcost = mars100;
    else if (ordertotal > 100 && ordertotal <= 150 && destination == "MARS")
        shippingcost = mars150;
    else
        shippingcost = shippingcost;

    //determining if we need to add a fragile cost based on users input
    if (yesno == 'y')
        shippingcost = shippingcost + fragilecost;
    else
    {

    }

    //adding empty lines
    cout << endl;
    cout << endl;
    orderfile << endl;
    orderfile << endl;

    //outputting the the final item, costs, and location to the console and file, setting precision for decimals.
    cout << "Your item is" << setw(37) << '.' << right << itemname << endl;
    orderfile << "Your item is" << setw(37) << '.' << right << itemname << endl;
    cout << "your shipping cost is" << fixed << setprecision(2) << setw(28) << '.' << right << '$' << shippingcost << endl;
    cout << "You are shipping to" << setw(30) << '.' << right << destination << endl;
    cout << "Your total shipping costs are" << fixed << setprecision(2) << setw(20) << '.' << right << '$' << ordertotal + shippingcost;
    orderfile << "your shipping cost is" << fixed << setprecision(2) << setw(28) << '.' << right << '$' << shippingcost << endl;
    orderfile << "You are shipping to" << setw(30) << '.' << right << destination << endl;
    orderfile << "Your total shipping costs are" << fixed << setprecision(2) << setw(20) << '.' << right << '$' << ordertotal + shippingcost;

    //more blank lines and saying thank you!
    cout << endl;
    cout << endl;
    cout << setfill('-') << setw(65) << right << "Thank You!";
    orderfile << endl;
    orderfile << endl;
    orderfile << setfill('-') << setw(65) << right << "Thank You!";

    //closing the file.
    orderfile.close();
    






}



