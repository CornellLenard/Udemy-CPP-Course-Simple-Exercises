/*********************************************************************************

  * FileName:       flight.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class Flight
  * Project:        The seventh project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#pragma once


#include <iostream>
#include <string>
#include <unordered_map>


class FlightOrder
{
private:
	// The number of the flight order
	std::string flight_order_num_;
	// The customer name
	std::string customer_name_;
	// The creating date of the order
	std::string creating_date_;
	// The cost of the order
	double cost_;
	// Whether the order is paid
	bool is_paid_;

public:
	FlightOrder(const std::string& fon, const std::string& cn, const std::string& cd, double c);
	~FlightOrder();

	/*
	* Gets the number of the flight order
	* @ Return:
	*                  The flight order number
	*/
	std::string GetFlightOrderNum() const;

	/*
	* Gets the customer name
	* @ Return:
	*                  The customer name
	*/
	std::string GetCustomerName() const;

	/*
	* Gets the creating date of the order
	* @ Return:
	*                  The creating date of the order
	*/
	std::string GetCreatingDate() const;

	/*
	* Gets the cost of the order
	* @ Return:
	*                  The cost of the order
	*/
	double GetCost() const;

	/*
	* Sets the order to be paid
	*/
	void SetPaid();
};


class Flight
{
private:
	// The number of flight
	std::string flight_num_;
	// The company of flight
	std::string company_;
	// The departure date of flight
	std::string departure_date_;
	// The arrival date of flight
	std::string arrival_date_;
	// The departure of flight
	std::string from_;
	// The destination of flight
	std::string to_;
	// The cost of flight
	double cost_;
	// The flight orders
	std::unordered_map<std::string, FlightOrder*> orders_;
	// Generates the number of flight order
	int order_num_;
public:
	Flight(const std::string& fn, const std::string& c, const std::string& dd, const std::string& ad, const std::string& f, const std::string& t, double co);
	~Flight();

	/*
	* Gets the number of the order
	* @ Return:
	*                  The order number
	*/
	std::string GetFlightNum() const;

	/*
	* Gets the company of the order
	* @ Return:
	*                  The company of the order
	*/
	std::string GetCompany() const;

	/*
	* Gets the departure date of the order
	* @ Return:
	*                  The departure date of the order
	*/
	std::string GetDepartureDate() const;

	/*
	* Gets the arrival date of the order
	* @ Return:
	*                  The arrival date of the order
	*/
	std::string GetArrivalDate() const;

	/*
	* Gets the departure of the order
	* @ Return:
	*                  The departure of the order
	*/
	std::string GetFrom() const;

	/*
	* Gets the destination of the order
	* @ Return:
	*                  The destination of the order
	*/
	std::string GetTo() const;

	/*
	* Gets the cost of the order
	* @ Return:
	*                  The cost of the order
	*/
	double GetCost() const;

	/*
	* Adds an order
	* @ Parameter:
	*       customer_name:  The customer name
	* @ Return:
	*                       The order number
	*/
	std::string AddOrder(const std::string& customer_name);

	/*
	* Sets the order as paid
	* @ Parameter:
	*       flight_order_num:  The number of the order
	*/
	void SetOrderPaid(const std::string& flight_order_num);

	/*
	* Searches an order
	* @ Parameter:
	*       flight_order_num:  The number of the order
	* @ Return:
	*                          Whether the order exists
	*/
	bool SearchForOrder(const std::string& flight_order_num) const;

	/*
	* Cancels an order
	* @ Parameter:
	*       flight_order_num:  The number of the order
	*/
	void CancelOrder(const std::string& flight_order_num);
};


