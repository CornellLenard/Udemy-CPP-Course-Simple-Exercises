/*********************************************************************************

  * FileName:       customer.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class Customer
  * Project:        The seventh project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#pragma once


#include <map>
#include <string>
#include "Itinerary.h"


class Customer
{
private:
	// The customer name
	std::string name_;
	// The customer password
	std::string password_;
	// The customer gender
	std::string gender_;
	// The customer age
	int age_;
	// The customer birthday
	std::string birthday_;
	// The customer itineraries
	std::multimap<std::string, Itinerary*> itineraries_;
	// Generates the itinerary number
	int itinerary_num_;

public:
	Customer(const std::string& n, const std::string& p, const std::string& g, int a, const std::string& b);
	~Customer();

	/*
	* Gets the customer password
	* @ Return:
	*                  The customer password
	*/
	std::string GetPassword() const;

	/*
	* Gets the customer gender
	* @ Return:
	*                  The customer gender
	*/
	std::string GetGender() const;

	/*
	* Gets the customer age
	* @ Return:
	*                  The customer age
	*/
	int GetAge() const;

	/*
	* Gets the customer birthday
	* @ Return:
	*                  The customer birthday
	*/
	std::string GetBirthday() const;

	/*
	* Lists the itineraries
	*/
	void ListItineraries() const;

	/*
	* Searches itinerary
	* @ Parameter:
	*       itinerary_num:  The number of the itinerary
	* @ Return:
	*                       Whether there is a itinerary with the given itinerary number
	*/
	bool SearchForItinerary(const std::string& itinerary_num) const;

	/*
	* Adds a flight to the itinerary
	* @ Parameter:
	*       itinerary_num:  The number of the itinerary
	*       itf:            The flight
	*/
	void AddItineraryFlight(const std::string& itinerary_num, const ItineraryFlight& itf);

	/*
	* Adds a hotel to the itinerary
	* @ Parameter:
	*       itinerary_num:  The number of the itinerary
	*       ith:            The hotel
	*/
	void AddItineraryHotel(const std::string& itinerary_num, const ItineraryHotel& ith);

	/*
	* Adds a car to the itinerary
	* @ Parameter:
	*       itinerary_num:  The number of the itinerary
	*       itc:            The car
	*/
	void AddItineraryCar(const std::string& itinerary_num, const ItineraryCar& itc);

	/*
	* Searches the order with the given order number in the itinerary with the itinerary number, the type depends on choice
	* @ Parameter:
	*       itinerary_num:  The number of the itinerary
	*       choice:         The type of order
	*       order_num:      The number of the order
	* @ Return:
	*                       Whether the order exists
	*/
	bool SearchForItineraryItem(const std::string& itinerary_num, int choice, const std::string& order_num);

	/*
	* Deletes the order with the given order number in the itinerary with the itinerary number, the type depends on choice
	* @ Parameter:
	*       itinerary_num:  The number of the itinerary
	*       choice:         The type of order
	*       order_num:      The number of the order
	*/
	void DeleteItineraryItem(const std::string& itinerary_num, int choice, const std::string& order_num);

	/*
	* Adds a itinerary
	*/
	void AddItinerary();
};


