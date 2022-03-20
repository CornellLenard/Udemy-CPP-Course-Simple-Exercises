/*********************************************************************************

  * FileName:       hotel.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class Hotel
  * Project:        The seventh project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#pragma once


#include <iostream>
#include <string>
#include <unordered_map>


class HotelOrder
{
private:
	// The number of hotel order
	std::string hotel_order_num_;
	// The customer
	std::string customer_name_;
	// The creating date of the order
	std::string creating_date_;
	// The room number
	std::string room_num_;
	// The check in date
	std::string from_date_;
	// The check out date
	std::string to_date_;
	// How many days the customer lives in
	int days_;
	// How many adults live in
	int adult_num_;
	// How many children live in
	int children_num_;
	// How many infants live in
	int infant_num_;
	// The cost
	double cost_;
	// Whether the order is paid
	bool is_paid_;

public:
	HotelOrder(const std::string& hon, const std::string& cna, const std::string& cd, const std::string& rn,
		const std::string& fd, const std::string& td, int d, int an, int cnu, int in, double c);
	~HotelOrder();

	/*
	* Gets the number of the order
	* @ Return:
	*                  The order number
	*/
	std::string GetHotelOrderNum() const;

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
	* Gets the check in date of the order
	* @ Return:
	*                  The check in date of the order
	*/
	std::string GetFromDate() const;

	/*
	* Gets the check out date of the order
	* @ Return:
	*                  The check out date of the order
	*/
	std::string GetToDate() const;

	/*
	* Gets the cost of the order
	* @ Return:
	*                  The cost of the order
	*/
	double GetCost() const;

	/*
	* Sets the order as paid
	*/
	void SetPaid();
};


class Hotel
{
private:
	// The number of the hotel
	std::string hotel_num_;
	// The name of the hotel
	std::string hotel_name_;
	// The location of the hotel
	std::string location_;
	// The cost
	double cost_;
	// The orders
	std::unordered_map<std::string, HotelOrder*> orders_;
	// Generates the order number
	int order_num_;

public:
	Hotel(const std::string& hnu, const std::string& hna, const std::string& l, double c);
	~Hotel();

	/*
	* Gets the hotel number
	* @ Return:
	*                  The hotel number
	*/
	std::string GetHotelNum() const;

	/*
	* Gets the hotel name
	* @ Return:
	*                  The hotel name
	*/
	std::string GetHotelName() const;

	/*
	* Gets the hotel location
	* @ Return:
	*                  The hotel location
	*/
	std::string GetLocation() const;

	/*
	* Gets the hotel cost
	* @ Return:
	*                  The hotel cost
	*/
	double GetCost() const;

	/*
	* Adds an order
	* @ Parameter:
	*       customer_name:  The customer name
	*       room_num:       The room number
	*       from_date:      The check in date
	*       to_date:        The check out date
	*       days:           How many days the customer lives in
	*       adult_num:      How many adults live in
	*       children_num:   How many children live in
	*       infant_num:     How many infants live in
	* @ Return:
	*                       The order number
	*/
	std::string AddOrder(const std::string& customer_name, const std::string& room_num, const std::string& from_date,
		const std::string& to_date, int days, int adult_num, int children_num, int infant_num);

	/*
	* Sets the order as paid
	* @ Parameter:
	*       hotel_order_num:  The number of the hotel order
	*/
	void SetOrderPaid(const std::string& hotel_order_num);

	/*
	* Searches an order
	* @ Parameter:
	*       hotel_order_num:  The number of the hotel order
	* @ Return:
	*                       Whether the order exists
	*/
	bool SearchForOrder(const std::string& hotel_order_num) const;

	/*
	* Cancels an order
	* @ Parameter:
	*       hotel_order_num:  The number of the hotel order
	*/
	void CancelOrder(const std::string& hotel_order_num);
};


