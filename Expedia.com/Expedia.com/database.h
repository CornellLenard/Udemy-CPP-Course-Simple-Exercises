/*********************************************************************************

  * FileName:       database.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class Database
  * Project:        The seventh project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#pragma once


#include "flight.h"
#include "hotel.h"
#include "car.h"


class Database
{
private:
	// The flight database
	std::unordered_map<std::string, Flight*> flights_;
	// The hotel data base
	std::unordered_map<std::string, Hotel*> hotels_;
	// The car database
	std::unordered_map<std::string, Car*> cars_;

public:
	Database();
	~Database();

	/*
	* Lists the flights
	*/
	void ListFlights() const;
	
	/*
	* Searches a flight
	* @ Parameter:
	*       flight_num:        The number of the flight
	* @ Return:
	*                          Whether the flight exists
	*/
	bool SearchForFlight(const std::string& flight_num) const;
	
	/*
	* Gets a flight
	* @ Parameter:
	*       flight_num:        The number of the flight
	* @ Return:
	*                          The flight
	*/
	const Flight& GetFlight(const std::string& flight_num) const;
	
	/*
	* Adds a flight order to the flight with flight_num as number
	* @ Parameter:
	*       flight_num:        The number of the flight
	*       customer_name:     The customer name
	* @ Return:
	*                          The order number
	*/
	std::string AddFlight(const std::string& flight_num, const std::string& customer_name);
	
	/*
	* Searches a flight order
	* @ Parameter:
	*       flight_num:        The number of the flight
	*       flight_order_num:  The number of the flight order
	* @ Return:
	*                          Whether the order exists
	*/
	bool SearchForFlightOrder(const std::string& flight_num, const std::string& flight_order_num);
	
	/*
	* Sets the flight order as paid
	* @ Parameter:
	*       flight_num:        The number of the flight
	*       flight_order_num:  The number of the flight order
	*/
	void SetFlightOrderPaid(const std::string& flight_num, const std::string& flight_order_num);
	
	/*
	* Cancels flight order
	* @ Parameter:
	*       flight_num:        The number of the flight
	*       flight_order_num:  The number of the flight order
	*/
	void CancelFlightOrder(const std::string& flight_num, const std::string& flight_order_num);
	
	/*
	* Lists hotels
	*/
	void ListHotels() const;
	
	/*
	* Searches a hotel
	* @ Parameter:
	*       hotel_num:         The number of the hotel
	* @ Return:
	*                          Whether the hotel exists
	*/
	bool SearchForHotel(const std::string& hotel_num) const;
	
	/*
	* Gets a hotel
	* @ Parameter:
	*       hotel_num:         The number of the hotel
	* @ Return:
	*                          The hotel
	*/
	const Hotel& GetHotel(const std::string& hotel_num) const;
	
	/*
	* Adds a hotel order to the flight with hotel_num as number
	* @ Parameter:
	*       hotel_num:         The number of the hotel
	*       customer_name:     The customer name
	*       room_num:          The room number
	*       from_date:         The check in date
	*       to_date:           The check out date
	*       days:              How many days the customer lives in
	*       adult_num:         How many adults live in
	*       children_num:      How many children live in
	*       infant_num:        How many infants live in
	* @ Return:
	*                          The order number
	*/
	std::string AddHotel(const std::string& hotel_num, const std::string& customer_name, const std::string& room_num, const std::string& from_date,
		const std::string& to_date, int days, int adult_num, int children_num, int infant_num);
	
	/*
	* Searches a hotel order
	* @ Parameter:
	*       hotel_num:         The number of the hotel
	*       hotel_order_num:   The number of the hotel order
	* @ Return:
	*                          Whether the order exists
	*/
	bool SearchForHotelOrder(const std::string& hotel_num, const std::string& hotel_order_num);
	
	/*
	* Sets the hotel order as paid
	* @ Parameter:
	*       hotel_num:         The number of the hotel
	*       hotel_order_num:   The number of the hotel order
	*/
	void SetHotelOrderPaid(const std::string& hotel_num, const std::string& hotel_order_num);
	
	/*
	* Cancels hotel order
	* @ Parameter:
	*       hotel_num:         The number of the hotel
	*       hotel_order_num:   The number of the hotel order
	*/
	void CancelHotelOrder(const std::string& hotel_num, const std::string& hotel_order_num);
	
	/*
	* Lists cars
	*/
	void ListCars() const;
	
	/*
	* Searches a car
	* @ Parameter:
	*       car_num:           The number of the car
	* @ Return:
	*                          Whether the car exists
	*/
	bool SearchForCar(const std::string& car_num) const;
	
	/*
	* Gets a car
	* @ Parameter:
	*       car_num:           The number of the car
	* @ Return:
	*                          The car
	*/
	const Car& GetCar(const std::string& car_num) const;
	
	/*
	* Adds a car order to the car with car_num as number
	* @ Parameter:
	*       car_num:           The number of the car
	*       customer_name:     The customer name
	*       date:              The order date
	* @ Return:
	*                          The order number
	*/
	std::string AddCar(const std::string& car_num, const std::string& customer_name, const std::string& date);
	
	/*
	* Searches a car order
	* @ Parameter:
	*       car_num:           The number of the car
	*       car_order_num:     The number of the car order
	* @ Return:
	*                          Whether the order exists
	*/
	bool SearchForCarOrder(const std::string& car_num, const std::string& car_order_num);
	
	/*
	* Sets the car order as paid
	* @ Parameter:
	*       car_num:           The number of the car
	*       car_order_num:     The number of the car order
	*/
	void SetCarOrderPaid(const std::string& car_num, const std::string& car_order_num);
	
	/*
	* Cancels car order
	* @ Parameter:
	*       car_num:           The number of the car
	*       car_order_num:     The number of the car order
	*/
	void CancelCarOrder(const std::string& car_num, const std::string& car_order_num);
	
	/*
	* Initializes the database for testing
	*/
	void TestInit();
};


