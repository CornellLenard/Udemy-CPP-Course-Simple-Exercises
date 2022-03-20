/*********************************************************************************

  * FileName:       expedia.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Expedia
  * Project:        The seventh project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include "expedia.h"


Expedia::Expedia(Database* db)
{
	current_user_name_ = "";
	ci_ = nullptr;
	database_ = db;
	TestInit();
}


Expedia::~Expedia()
{
	std::unordered_map<std::string, Customer*>::iterator pc = customer_database_.begin();
	for (pc; pc != customer_database_.end(); pc++)
	{
		if (pc->second != nullptr)
		{
			delete pc->second;
			pc->second = nullptr;
		}
	}
	customer_database_.clear();

	delete ci_;
	ci_ = nullptr;
	database_ = nullptr;
}


void Expedia::InitInterface()
{
	std::cout << "Menu:\n\t1: Login\n\t2: Sign Up\n";
	int choice = 0;

	while (true)
	{
		std::cout << "\nPlease enter number in range 1 - 2: ";
		std::cin >> choice;
		if (choice < 1 || choice>2)
			std::cout << "ERROR: Wrong choice ! Please enter again !\n";
		else
			break;
	}

	if (choice == 1)
		Login();
	else
		SignUp();

	EnterCustomerInterface();
}


void Expedia::Login()
{
	std::string name = "", password = "";

	while (true)
	{
		std::cout << "\nPlease enter your user name and password: ";
		std::cin >> name >> password;
		if (customer_database_.find(name) == customer_database_.end())
			std::cout << "ERROR: No such customer ! Please enter again !\n";
		else if (customer_database_[name]->GetPassword() != password)
			std::cout << "ERROR: Wrong password ! Please enter again !\n";
		else
			break;
	}

	current_user_name_ = name;
}


void Expedia::SignUp()
{
	std::string name = "", password = "", gender = "", birthday = "";
	int age = 0;
	while (true)
	{
		std::cout << "\nPlease enter a user name that you like: ";
		std::cin >> name;
		if (customer_database_.find(name) != customer_database_.end())
			std::cout << "ERROR: This name is already existed ! Please enter another name that you like !\n";
		else
		{
			std::cout << "Please enter a password that you like: ";
			std::cin >> password;
			std::cout << "Please enter your gender: ";
			std::cin >> gender;
			std::cout << "Please enter your age: ";
			std::cin >> age;
			std::cout << "Please enter your birthday: ";
			std::cin >> birthday;
			customer_database_.insert(std::make_pair(name, new Customer(name, password, gender, age, birthday)));
			break;
		}
	}
	current_user_name_ = name;
}


void Expedia::EnterCustomerInterface()
{
	ci_ = new CustomerInterface(current_user_name_, customer_database_, database_);
	ci_->InitInterface();
}


void Expedia::TestInit()
{
	customer_database_.insert(std::make_pair("lenard", new Customer("lenard", "lenard", "Male", 22, "XXXX-XX-XX")));
	customer_database_.insert(std::make_pair("ZH", new Customer("ZH", "ZH", "Male", 22, "YYYY-YY-YY")));
}


void Expedia::Run()
{
	InitInterface();
}


