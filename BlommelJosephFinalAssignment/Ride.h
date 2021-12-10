#pragma once
#include <string>
class Ride
{
private:
	std::string name ="";
	int distance = 0;
	int averageHeartRate = 0;
	int averagePower = 0;
	std::string date = "";
	double averageSpeed = 0; 
public:
	Ride();
	Ride(std::string, int, int, int, std::string, double);
	void displayRideInfo();
	int getDistance();
	int getAverageHeartRate();
	std::string getDate();
	int getAveragePower();
	std::string getName();
	double getAverageSpeed();
	void setName(std::string);
	void setDistance(int);
	void setAveragePower(int);
	void setDate(std::string);
	void setAverageHeartRate(int);
	void setAverageSpeed(double);
	//https://www.cplusplus.com/forum/beginner/49924/
	friend std::ostream& operator<<(std::ostream& , const Ride&);
	
	// Extraction operator
	friend std::istream& operator>>(std::istream&, Ride&);
};

