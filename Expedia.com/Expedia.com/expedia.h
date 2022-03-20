/*********************************************************************************

  * FileName:       expedia.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class Expedia
  * Project:        The seventh project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#pragma once


#include "customer.h"
#include "customer_interface.h"


class Expedia
{
private:
	// The current user name
	std::string current_user_name_;
	// The customer database
	std::unordered_map<std::string, Customer*> customer_database_;
	// Points to customer interface
	CustomerInterface* ci_;
	// Points to database
	Database* database_;

	/*
	* Creates initial interface
	*/
	void InitInterface();
	
	/*
	* Logins
	*/
	void Login();
	
	/*
	* Signs up
	*/
	void SignUp();
	
	/*
	* Enters the customer interface
	*/
	void EnterCustomerInterface();
	
	/*
	* Initializes the system for testing
	*/
	void TestInit();

public:
	Expedia(Database* db);
	~Expedia();
	
	/*
	* Runs expedia
	*/
	void Run();
};


