/*********************************************************************************

  * FileName:       customer_interface.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class CustomerInterface
  * Project:        The seventh project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#pragma once


#include "customer.h"
#include "database.h"


class CustomerInterface
{
private:
	// The current user name
	std::string current_user_name_;
	// Customer database
	std::unordered_map<std::string, Customer*>& customer_database_;
	// Points to the database
	Database* database_;

	/*
	* Cancels flight order
	*/
	void CancelFlightOrder();
	
	/*
	* Cancels hotel order
	*/
	void CancelHotelOrder();
	
	/*
	* Cancels car order
	*/
	void CancelCarOrder();

public:
	CustomerInterface(const std::string& cun, std::unordered_map<std::string, Customer*>& cd, Database* db);
	~CustomerInterface();

	/*
	* Creates initial interface
	*/
	void InitInterface();

	/*
	* Views the users' profiles
	*/
	void ViewProfile();

	/*
	* Processes the itineraries
	*/
	void MakeItinerary();

	/*
	* Adds an itinerary
	*/
	void AddItinerary();

	/*
	* Adds a flight order
	*/
	void AddFlight();

	/*
	* Adds a hotel order
	*/
	void AddHotel();

	/*
	* Adds a car order
	*/
	void AddCar();

	/*
	* Pays for the order
	*/
	void PayForOrder();

	/*
	* Cancels the order
	*/
	void CancelOrder();

	/*
	* Lists the itineraries
	*/
	void ListItineraries();
};


