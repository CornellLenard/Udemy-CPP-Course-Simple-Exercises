/*********************************************************************************

  * FileName:       itinerary.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class Itinerary
  * Project:        The seventh project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#pragma once


#include <iostream>
#include <vector>


class ItineraryFlight
{
private:
	std::string flight_order_num_;
	std::string flight_num_;
	std::string departure_date_;
	std::string arrival_date_;
	std::string from_;
	std::string to_;
	std::string details_;
	double cost_;

public:
	ItineraryFlight(const std::string& fon, const std::string& fn, const std::string& dd, const std::string& ad,
		const std::string& f, const std::string& t, const std::string& d, double c);
	~ItineraryFlight();
	std::string GetFlightOrderNum() const;
	std::string GetFlightNum() const;
	std::string GetDepartureDate() const;
	std::string GetArrivalDate() const;
	std::string GetFrom() const;
	std::string GetTo() const;
	std::string GetDetails() const;
	double GetCost() const;
};


class ItineraryHotel
{
private:
	std::string hotel_order_num_;
	std::string hotel_num_;
	std::string hotel_name_;
	std::string location_;
	std::string room_num_;
	std::string from_date_;
	std::string to_date_;
	int adult_num_;
	int children_num_;
	int infant_num_;
	double cost_;

public:
	ItineraryHotel(const std::string& hon, const std::string& hnu, const std::string& hna, const std::string& l, const std::string& rn,
		const std::string& fd, const std::string& td, int an, int cn, int in, double c);
	~ItineraryHotel();
	std::string GetHotelOrderNum() const;
	std::string GetHotelNum() const;
	std::string GetHotelName() const;
	std::string GetLocation() const;
	std::string GetRoomNum() const;
	std::string GetFromDate() const;
	std::string GetToDate() const;
	double GetCost() const;
};


class ItineraryCar
{
private:
	std::string car_order_num_;
	std::string car_num_;
	std::string car_brand_;
	std::string car_type_;
	std::string date_;
	double cost_;

public:
	ItineraryCar(const std::string& con, const std::string& cn, const std::string& cb, const std::string& ct, const std::string& d, double c);
	~ItineraryCar();
	std::string GetCarOrderNum() const;
	std::string GetCarNum() const;
	std::string GetCarBrand() const;
	std::string GetCarType() const;
	std::string GetDate() const;
	double GetCost() const;
};


class Itinerary
{
private:
	// The number of the itinerary
	std::string itinerary_num_;
	// The creating date of the itinerary
	std::string creating_date_;
	// The flight orders in the itinerary
	std::vector<ItineraryFlight> flights_;
	// The hotel orders in the itinerary
	std::vector<ItineraryHotel> hotels_;
	// The car orders in the itinerary
	std::vector<ItineraryCar> cars_;

public:
	Itinerary(const std::string& in, const std::string& cd);
	~Itinerary();

	/*
	* Gets the cost of the itinerary
	* @ Return:
	*                       The cost of the itinerary
	*/
	double GetItineraryCost() const;
	
	/*
	* List the itinerary
	*/
	void ListItinerary() const;
	
	/*
	* Adds itinerary flight
	* @ Parameter:
	*       itf:   The itinerary flight
	*/
	void AddItineraryFlight(const ItineraryFlight& itf);
	
	/*
	* Adds itinerary hotel
	* @ Parameter:
	*       ith:   The itinerary hotel
	*/
	void AddItineraryHotel(const ItineraryHotel& ith);
	
	/*
	* Adds itinerary car
	* @ Parameter:
	*       itc:   The itinerary car
	*/
	void AddItineraryCar(const ItineraryCar& itc);
	
	/*
	* Searches an order
	* @ Parameter:
	*       choice:         The type of order
	*       order_num:      The number of the order
	* @ Return:
	*                          Whether the order exists
	*/
	bool SearchForOrder(int choice, const std::string& order_num);
	
	/*
	* Cancels an order
	* @ Parameter:
	*       choice:         The type of order
	*       order_num:      The number of the order
	*/
	void DeleteItineraryItem(int choice, const std::string& order_num);
};


