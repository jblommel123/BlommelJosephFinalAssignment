#include "Ride.h"
#include <iostream>
#include <iomanip>

void Ride::displayRideInfo()
{
	std::cout << std::setw(20) << "Ride name: " << std::right << name << std::endl;
	std::cout << std::setw(20) << "Distance: " << std::right << distance << std::endl;
	std::cout << std::setw(20) << "Average Heart Rate: " << std::right << averageHeartRate << std::endl;
	std::cout << std::setw(20) << "Average Power: " << std::right << averagePower << std::endl;
	std::cout << std::setw(20) << "Average Speed: " << std::right << averageSpeed << std::endl;
	std::cout << std::setw(20) << "Date: " << std::right << date << std::endl;

}

// std::ostream& operator<<(std::ostream& os, const Ride& r)
//{
//	//std::string Name, int Distance, int avgHeartRate, int avgPower, std::string Date, double avgSpeed
//	os << r.name << '\n';
//	os << r.distance << '\n';
//	os << r.averageHeartRate << '\n';
//	os << r.averagePower << '\n';
//	os << r.date << '\n';
//	os << r.averageSpeed << '\n';
//	return os;
//}
//
//// Extraction operator
// std::istream& operator>>(std::istream& is, Ride& r)
//{
//	// read in individual members of s
//	is >> r.name >> r.distance >> r.averageHeartRate >> r.averagePower >> r.date >> r.averageSpeed;
//	return is;
//}

Ride::Ride(std::string Name, int Distance, int avgHeartRate, int avgPower, std::string Date, double avgSpeed)
{
	name = Name;
	distance = Distance;
	averageHeartRate = avgHeartRate;
	averagePower = avgPower;
	date = Date;
	averageSpeed = avgSpeed;
}

Ride::Ride()  {
	name = "";
	distance = 0;
	averageHeartRate = 0;
	averagePower = 0;
	date = "";
	averageSpeed = 0;
}

int Ride::getDistance()
{
	return distance;
}

int Ride::getAverageHeartRate()
{
	return averageHeartRate;
}

std::string Ride::getDate()
{
	return date;
}

int Ride::getAveragePower()
{
	return averagePower;
}

double Ride::getAverageSpeed()
{
	return averageSpeed;
}

std::string Ride::getName() {
	return name;
}

void Ride::setName(std::string Name)
{
	name = Name;
}

void Ride::setDistance(int Distance)
{
	distance = Distance;
}

void Ride::setAveragePower(int avgPower)
{
	averagePower = avgPower;
}

void Ride::setDate(std::string Date)
{
	date = Date;
}

void Ride::setAverageHeartRate(int avgHeartRate)
{
	averageHeartRate = avgHeartRate;
}

void Ride::setAverageSpeed(double avgSpeed)
{
	averageSpeed = avgSpeed;
}
