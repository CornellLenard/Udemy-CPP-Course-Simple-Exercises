/*********************************************************************************

  * FileName:       car.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class Car
  * Project:        The seventh project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#pragma once


#include <iostream>
#include <string>
#include <unordered_map>


class CarOrder
{
private:
	// The number of car order
	std::string car_order_num_;
	// The customer name
	std::string customer_name_;
	// The creating date of the order
	std::string creating_date_;
	// The use date of the car
	std::string date_;
	// The cost
	double cost_;
	// Whether the order is paid
	bool is_paid_;

public:
	CarOrder(const std::string& con, const std::string& cn, const std::string& cd, const std::string& d, double c);
	~CarOrder();

	/*
	* Gets the number of the car order
	* @ Return:
	*                  The car order number
	*/
	std::string GetCarOrderNum() const;

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
	* Gets the date when using the car
	* @ Return:
	*                  The date when using the car
	*/
	std::string GetDate() const;

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


class Car
{
private:
	// The car number
	std::string car_num_;
	// The car brand
	std::string car_brand_;
	// The car type
	std::string car_type_;
	// The car cost
	double cost_;
	// The orders
	std::unordered_map<std::string, CarOrder*> orders_;
	// Generates the car order number
	int order_num_;

public:
	Car(const std::string& cn, const std::string& cb, const std::string& ct, double c);
	~Car();

	/*
	* Gets the car number
	* @ Return:
	*                  The car number
	*/
	std::string GetCarNum() const;

	/*
	* Gets the car brand
	* @ Return:
	*                  The car brand
	*/
	std::string GetCarBrand() const;

	/*
	* Gets the car type
	* @ Return:
	*                  The car type
	*/
	std::string GetCarType() const;

	/*
	* Gets the car cost
	* @ Return:
	*                  The car cost
	*/
	double GetCost() const;

	/*
	* Adds an order
	* @ Parameter:
	*       customer_name:  The customer name
	*       date:           The date when the order exists
	* @ Return:
	*                       The order number
	*/
	std::string AddOrder(const std::string& customer_name, const std::string& date);

	/*
	* Sets the order as paid
	* @ Parameter:
	*       car_order_num:  The number of the car order
	*/
	void SetOrderPaid(const std::string& car_order_num);

	/*
	* Searches an order
	* @ Parameter:
	*       car_order_num:  The number of the car order
	* @ Return:
	*                       Whether the order exists
	*/
	bool SearchForOrder(const std::string& car_order_num) const;

	/*
	* Cancels an order
	* @ Parameter:
	*       car_order_num:  The number of the car order
	*/
	void CancelOrder(const std::string& car_order_num);
};


