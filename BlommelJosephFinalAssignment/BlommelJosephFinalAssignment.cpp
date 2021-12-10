// BlommelJosephFinalAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Ride.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
void displayMenu();
int getMenuChoice();
Ride enterARide();
void enterRideLog(std::vector<Ride>& rides);
void viewAllRides(std::vector<Ride>& rides);
void searchForARideByName(std::vector<Ride>& rides);
void saveAndExit(std::vector<Ride>& rides);
void open(std::vector<Ride>& rides);
void viewStatistics(std::vector<Ride>& rides);

int main()
{
    
    std::vector<Ride> rideLog;
    open(rideLog);
    std::cout << "Welcome to your ride log." << std::endl;
    int menuChoice = getMenuChoice();
    do {
        switch (menuChoice)
        {
        case 1: enterRideLog(rideLog);
            break;
        case 2: viewAllRides(rideLog);
            break;
        case 3:
            searchForARideByName(rideLog);
            break;
        case 4: viewStatistics(rideLog);
            break;
        case 5:saveAndExit(rideLog);
            break;
        default:
            break;
        }
        menuChoice = getMenuChoice();
    } while (menuChoice != 6);
    

}
//displays all choices
void displayMenu()
{
    std::cout << "1. Enter a ride" << std::endl;
    std::cout << "2. View All Rides" << std::endl;
    std::cout << "3. Search for a ride by name" << std::endl;
    std::cout << "4. View Statistics" << std::endl;
    std::cout << "5. Save and Exit" << std::endl;
}
//get menu choice
int getMenuChoice()
{
    std::cout << "Please enter one of the following menu choices." << std::endl;
    displayMenu();
    std::string menuChoiceString;
    std::getline(std::cin, menuChoiceString);
    int menuChoice = stoi(menuChoiceString);
    while (menuChoice < 1 || menuChoice > 6) {
        std::cout << "That is not a menu choice. Please enter one of the choices from the menu." << std::endl;
        displayMenu();
        std::getline(std::cin, menuChoiceString);
        menuChoice = stoi(menuChoiceString);
    }

    return menuChoice;


}
//enter a number of rides
void enterRideLog(std::vector<Ride>& rideLog) {
    std::cout << "How many rides would you like to enter?" << std::endl;
    std::string ridesToEnter;
    std::getline(std::cin, ridesToEnter);
    int numberOfRidesToEnter = stoi(ridesToEnter);

    while (numberOfRidesToEnter < 1)
    {
        std::cout << "If that number is correct you didn't ride. Enter a number greater than 1.";
        std::getline(std::cin, ridesToEnter);
        numberOfRidesToEnter = stoi(ridesToEnter);
    }

    for (int i = 0; i < numberOfRidesToEnter; i++)
    {
        rideLog.push_back(enterARide());
    }
}

//view all rides
void viewAllRides(std::vector<Ride>& rides)
{
    for (int i = 0; i < rides.size(); i++)
    {
        rides[i].displayRideInfo();
    }
}

//search for a particular ride
void searchForARideByName(std::vector<Ride>& rides)
{
    std::string rideNameSearch;
    bool rideFound = false;
    std::cin.clear();
    std::cout << "Enter the name of the ride you would like to search for. Note that this is case sensitive." << std::endl;
    std::getline(std::cin, rideNameSearch);
    for (int i = 0; i < rides.size(); i++)
    {
        std::string nameToCompare = rides[i].getName();
        int result = nameToCompare.compare(rideNameSearch);
        if (result == 0) {
            std::cout << "Ride found." << std::endl;
            rides[i].displayRideInfo();
            rideFound = true;
            break;
        }
        
    }

    if (!rideFound)
    {
        std::cout << "Ride not found." << std::endl;
    }
}

//save data and exit
void saveAndExit(std::vector<Ride>& rides)
{
    std::ofstream stream("Rides.csv", std::ios::out);
    
    for (int i = 0; i < rides.size(); i++)
    {
        //std::string Name, int Distance, int avgHeartRate, int avgPower, std::string Date, double avgSpeed
        stream << rides[i].getName() << "," << rides[i].getDistance() << "," << rides[i].getAverageHeartRate() << "," << rides[i].getAveragePower() << "," << rides[i].getDate() << "," << rides[i].getAverageSpeed() << '\n';
    }

    exit(0);

}

//load data 
void open(std::vector<Ride>& rides)
{
    std::ifstream istream("Rides.csv", std::ios::in);


    std::vector<std::string> data;
    std::string line, temp, dataPiece;
    while (getline(istream,line,'\n'))
    {
        data.clear();
        std::stringstream s(line);
        while (std::getline(s,dataPiece, ',')) {
            data.push_back(dataPiece);
        }
        //std::string Name, int Distance, int avgHeartRate, int avgPower, std::string Date, double avgSpeed
        std::string name = data[0];
        int distance = stoi(data[1]);
        int averageHeartRate = stoi(data[2]);
        int averagePower = stoi(data[3]);
        std::string date = data[4];
        double avgSpeed = atof(data[5].c_str());

        Ride rideToPush(name, distance, averageHeartRate, averagePower, date, avgSpeed);
        rides.push_back(rideToPush);
    }
    istream.close();
}
//calculate summary statistics
void viewStatistics(std::vector<Ride>& rides)
{
    //std::string Name, int Distance, int avgHeartRate, int avgPower, std::string Date, double avgSpeed
    int totalDistance = 0, totalHeartRate = 0, totalPower = 0;
    double totalAverageSpeed = 0;
    for (int i = 0; i < rides.size(); i++)
    {
        totalDistance += rides[i].getDistance();
        totalHeartRate += rides[i].getAverageHeartRate();
        totalPower += rides[i].getAveragePower();
        totalAverageSpeed += rides[i].getAverageSpeed();

    }

    std::cout << "Average ride distance: " << (totalDistance / rides.size()) << std::endl;
    std::cout << "Average heart rate: " << (totalHeartRate / rides.size()) << std::endl;
    std::cout << "Average Power: " << (totalPower / rides.size()) << std::endl;
    std::cout << "Average Speed: " << (totalAverageSpeed / rides.size()) << std::endl;
}
//enter 1 ride
Ride enterARide()
{
    std::string input;
    std::string name;
    int distance;
    int averageHeartRate;
    int averagePower;
    std::string date;
    double averageSpeed;

    std::cout << "Name the ride: " ;
    std::getline(std::cin, input);
    name = input;
    std::cout << "What date did this occur?: ";
    std::getline(std::cin, input);
    date = input;
    std::cout << "How many miles did you ride? Round to the nearest whole number: ";
    std::getline(std::cin, input);
    distance = stoi(input);
    while (distance <= 0) {
        std::cout << "I dont think you rode a negative distance. Enter a positive one between 50 and 200: ";
        std::getline(std::cin, input);
        distance = stoi(input);
    }

    std::cout << "What was your average heart rate?:  ";
    std::getline(std::cin, input);
    averageHeartRate = stoi(input);

    while (averageHeartRate <= 50 || averageHeartRate >= 200) {
        std::cout << "That number would not be true, enter a number between 50 and 200";
        std::getline(std::cin, input);
        averageHeartRate = stoi(input);
    }

    std::cout << "Enter your average power in watts: ";

    std::getline(std::cin, input);
    averagePower = stoi(input);

    while (averagePower < 50 || averagePower > 1500) {
        std::cout << "That is a statistically not likely number, please enter a number between 50 and 1500";
        std::getline(std::cin, input);
        averagePower = stoi(input);

    }

    std::cout << "Enter your average speed: ";
    std::getline(std::cin, input);
    averageSpeed = atof(input.c_str());
    while (averageSpeed < 4 || averageSpeed > 30)
    {
        std::cout << "That speed is not realistic, please enter one between 4 and 30: ";
        std::getline(std::cin, input);
        averageSpeed = atof(input.c_str());
    }


    //std::string Name, int Distance, int avgHeartRate, int avgPower, std::string Date, double avgSpeed

    Ride rideToReturn = Ride(name, distance, averageHeartRate, averageHeartRate, date, averageSpeed);
    return rideToReturn;
}
