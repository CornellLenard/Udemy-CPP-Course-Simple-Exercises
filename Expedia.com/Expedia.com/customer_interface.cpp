/*********************************************************************************

  * FileName:       customer_interface.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class CustomerInterface
  * Project:        The seventh project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include "customer_interface.h"


CustomerInterface::CustomerInterface(const std::string& cun, std::unordered_map<std::string, Customer*>& cd, Database* db):
	current_user_name_(cun), customer_database_(cd), database_(db)
{
}


CustomerInterface::~CustomerInterface()
{
	database_ = nullptr;
}


void CustomerInterface::InitInterface()
{
	bool logout = false;
	while (true)
	{
		std::cout << "\nHello " << current_user_name_ << " | User View\n";
		std::cout << "Menu:\n\t1: View Profile\n\t2: Make Itinerary\n\t";
		std::cout << "3: List my itineraries\n\t4: Logout\n";
		int choice = 0;

		while (true)
		{
			std::cout << "\nPlease enter number in range 1 - 4: ";
			std::cin >> choice;
			if (choice < 1 || choice>4)
				std::cout << "ERROR: Wrong choice ! Please enter again !\n";
			else
				break;
		}

		switch (choice)
		{
			case 1: ViewProfile(); break;
			case 2: MakeItinerary(); break;
			case 3: ListItineraries(); break;
			case 4: logout = true; break;
		}

		if (logout == true)
			break;
	}
}


void CustomerInterface::ViewProfile()
{
	Customer* current_user = customer_database_[current_user_name_];
	std::cout << "\nThe user profile:\n\tName:     " << current_user_name_ << "\n\t";
	std::cout << "Gender:   " << current_user->GetGender() << "\n\tAge:      " << current_user->GetAge();
	std::cout << "\n\tBirthday: " << current_user->GetBirthday() << '\n';
	current_user = nullptr;
}


void CustomerInterface::MakeItinerary()
{
	std::cout << "\nMenu:\n\t1: Add Itinerary\n\t2: Add Flight\n\t3: Add Hotel";
	std::cout << "\n\t4: Add Car\n\t5: Pay\n\t6: Cancel Order\n";
	int choice = 0;

	while (true)
	{
		std::cout << "\nPlease enter number in range 1 - 6: ";
		std::cin >> choice;
		if (choice < 1 || choice > 6)
			std::cout << "ERROR: Wrong choice ! Please enter again !\n";
		else
			break;
	}

	switch (choice)
	{
		case 1: AddItinerary(); break;
		case 2: AddFlight(); break;
		case 3: AddHotel(); break;
		case 4: AddCar(); break;
		case 5: PayForOrder(); break;
		case 6: CancelOrder(); break;
	}
}


void CustomerInterface::AddItinerary()
{
	customer_database_[current_user_name_]->AddItinerary();
}


void CustomerInterface::AddFlight()
{
	database_->ListFlights();
	std::string flight_num = "";

	while (true)
	{
		std::cout << "\nPlease enter the flight num that you wish to add: ";
		std::cin >> flight_num;
		if (database_->SearchForFlight(flight_num) == false)
			std::cout << "ERROR: No such flight ! Please enter again !\n";
		else
			break;
	}

	std::string order_num = database_->AddFlight(flight_num, current_user_name_);
	Customer* current_user = customer_database_[current_user_name_];
	std::string itinerary_num = "";

	while (true)
	{
		std::cout << "\nWhich itinerary do you wish to add this in ? ";
		std::cin >> itinerary_num;
		if (current_user->SearchForItinerary(itinerary_num) == false)
			std::cout << "ERROR: No such itinerary ! Please enter again !\n";
		else
			break;
	}

	const Flight& f = database_->GetFlight(flight_num);
	ItineraryFlight itf(order_num, flight_num, f.GetDepartureDate(), f.GetArrivalDate(), f.GetFrom(), f.GetTo(), "details", f.GetCost());
	current_user->AddItineraryFlight(itinerary_num, itf);
	current_user = nullptr;
}


void CustomerInterface::AddHotel()
{
	database_->ListHotels();
	std::string hotel_num = "", room_num = "", from_date = "", to_date = "";
	int days = 0, adult_num = 0, children_num = 0, infant_num = 0;

	while (true)
	{
		std::cout << "\nPlease enter the hotel num that you wish to add: ";
		std::cin >> hotel_num;
		if (database_->SearchForHotel(hotel_num) == false)
			std::cout << "ERROR: No such hotel ! Please enter again !\n";
		else
			break;
	}

	std::cout << "Please enter the room num that you wish to live in at the hotel: ";
	std::cin >> room_num;
	std::cout << "Please enter the date from which you wish to live in the hotel room: ";
	std::cin >> from_date;
	std::cout << "Please enter the date to which you wish to live in the hotel room: ";
	std::cin >> to_date;
	std::cout << "Please enter the number of the days you wish to live in the hotel room: ";
	std::cin >> days;
	std::cout << "Please enter how many adults will live in the hotel room: ";
	std::cin >> adult_num;
	std::cout << "Please enter how many children will live in the hotel room: ";
	std::cin >> children_num;
	std::cout << "Please enter how many infants will live in the hotel room: ";
	std::cin >> infant_num;
	std::string order_num = database_->AddHotel(hotel_num, current_user_name_, room_num, from_date, to_date, days, adult_num, children_num, infant_num);
	Customer* current_user = customer_database_[current_user_name_];
	std::string itinerary_num = "";

	while (true)
	{
		std::cout << "\nWhich itinerary do you wish to add this in ? ";
		std::cin >> itinerary_num;
		if (current_user->SearchForItinerary(itinerary_num) == false)
			std::cout << "ERROR: No such itinerary ! Please enter again !\n";
		else
			break;
	}

	const Hotel& h = database_->GetHotel(hotel_num);
	ItineraryHotel ith(order_num, hotel_num, h.GetHotelName(), h.GetLocation(), room_num, from_date, to_date, adult_num, children_num, infant_num, h.GetCost() * days);
	current_user->AddItineraryHotel(itinerary_num, ith);
	current_user = nullptr;
}


void CustomerInterface::AddCar()
{
	database_->ListCars();
	std::string car_num = "", date = "";

	while (true)
	{
		std::cout << "\nPlease enter the car num that you wish to add: ";
		std::cin >> car_num;
		if (database_->SearchForCar(car_num) == false)
			std::cout << "ERROR: No such car ! Please enter again !\n";
		else
			break;
	}

	std::cout << "Please enter the date that you wish to use the car: ";
	std::cin >> date;
	std::string order_num = database_->AddCar(car_num, current_user_name_, date);
	Customer* current_user = customer_database_[current_user_name_];
	std::string itinerary_num = "";

	while (true)
	{
		std::cout << "\nWhich itinerary do you wish to add this in ? ";
		std::cin >> itinerary_num;
		if (current_user->SearchForItinerary(itinerary_num) == false)
			std::cout << "ERROR: No such itinerary ! Please enter again !\n";
		else
			break;
	}

	const Car& c = database_->GetCar(car_num);
	ItineraryCar itc(order_num, car_num, c.GetCarBrand(), c.GetCarType(), date, c.GetCost());
	current_user->AddItineraryCar(itinerary_num, itc);
	current_user = nullptr;
}


void CustomerInterface::PayForOrder()
{
	int choice = 0;
	while (true)
	{
		std::cout << "\nWhich of the following would you like to pay for ?\n";
		std::cout << "\t1: Flight\n\t2: Hotel\n\t3: Car\n";
		std::cout << "Please enter your choice: ";
		std::cin >> choice;
		if (choice < 1 || choice > 3)
			std::cout << "ERROR: Wrong choice ! Please enter again !\n";
		else
			break;
	}

	std::string num = "", order_num = "";
	if (choice == 1)
	{
		while (true)
		{
			std::cout << "\nPlease enter the flight num and the flight order num: ";
			std::cin >> num >> order_num;
			if (database_->SearchForFlight(num) == false)
				std::cout << "ERROR: No such flight ! Please enter again !\n";
			else if (database_->SearchForFlightOrder(num, order_num) == false)
				std::cout << "ERROR: No such flight order ! Please enter again !\n";
			else
				break;
		}
		database_->SetFlightOrderPaid(num, order_num);
	}
	else if (choice == 2)
	{
		while (true)
		{
			std::cout << "\nPlease enter the hotel num and the hotel order num: ";
			std::cin >> num >> order_num;
			if (database_->SearchForHotel(num) == false)
				std::cout << "ERROR: No such hotel ! Please enter again !\n";
			else if (database_->SearchForHotelOrder(num, order_num) == false)
				std::cout << "ERROR: No such hotel order ! Please enter again !\n";
			else
				break;
		}
		database_->SetHotelOrderPaid(num, order_num);
	}
	else
	{
		while (true)
		{
			std::cout << "\nPlease enter the car num and the car order num: ";
			std::cin >> num >> order_num;
			if (database_->SearchForCar(num) == false)
				std::cout << "ERROR: No such car ! Please enter again !\n";
			else if (database_->SearchForCarOrder(num, order_num) == false)
				std::cout << "ERROR: No such car order ! Please enter again !\n";
			else
				break;
		}
		database_->SetCarOrderPaid(num, order_num);
	}
}


void CustomerInterface::CancelOrder()
{
	int choice = 0;
	while (true)
	{
		std::cout << "\nWhich of the following order type would you like to cancel ?\n";
		std::cout << "\t1: Flight\n\t2: Hotel\n\t3: Car\n";
		std::cout << "Please enter your choice: ";
		std::cin >> choice;
		if (choice < 1 || choice > 3)
			std::cout << "ERROR: Wrong choice ! Please enter again !\n";
		else
			break;
	}

	switch (choice)
	{
		case 1: CancelFlightOrder(); break;
		case 2: CancelHotelOrder(); break;
		case 3: CancelCarOrder(); break;
	}
}


void CustomerInterface::CancelFlightOrder()
{
	std::string num = "", order_num = "", itinerary_num = "";
	Customer* current_user = customer_database_[current_user_name_];

	while (true)
	{
		std::cout << "\nPlease enter the flight num and the flight order num: ";
		std::cin >> num >> order_num;
		if (database_->SearchForFlight(num) == false)
			std::cout << "ERROR: No such flight ! Please enter again !\n";
		else if (database_->SearchForFlightOrder(num, order_num) == false)
			std::cout << "ERROR: No such flight order ! Please enter again !\n";
		else
			break;
	}

	database_->CancelFlightOrder(num, order_num);

	while (true)
	{
		std::cout << "\nPlease enter the itinerary num that the order belongs to: ";
		std::cin >> itinerary_num;

		if (current_user->SearchForItinerary(itinerary_num) == false)
			std::cout << "ERROR: No such itinerary ! Please enter again !\n";
		else if (current_user->SearchForItineraryItem(itinerary_num, 1, order_num) == false)
			std::cout << "ERROR: No such order ! Please enter again !\n";
		else
			break;
	}

	current_user->DeleteItineraryItem(itinerary_num, 1, order_num);
	current_user = nullptr;
}


void CustomerInterface::CancelHotelOrder()
{
	std::string num = "", order_num = "", itinerary_num = "";
	Customer* current_user = customer_database_[current_user_name_];

	while (true)
	{
		std::cout << "\nPlease enter the hotel num and the hotel order num: ";
		std::cin >> num >> order_num;
		if (database_->SearchForHotel(num) == false)
			std::cout << "ERROR: No such hotel ! Please enter again !\n";
		else if (database_->SearchForHotelOrder(num, order_num) == false)
			std::cout << "ERROR: No such hotel order ! Please enter again !\n";
		else
			break;
	}

	database_->CancelHotelOrder(num, order_num);

	while (true)
	{
		std::cout << "\nPlease enter the itinerary num that the order belongs to: ";
		std::cin >> itinerary_num;
		if (current_user->SearchForItinerary(itinerary_num) == false)
			std::cout << "ERROR: No such itinerary ! Please enter again !\n";
		else if (current_user->SearchForItineraryItem(itinerary_num, 2, order_num) == false)
			std::cout << "ERROR: No such order ! Please enter again !\n";
		else
			break;
	}

	current_user->DeleteItineraryItem(itinerary_num, 2, order_num);
	current_user = nullptr;
}


void CustomerInterface::CancelCarOrder()
{
	std::string num = "", order_num = "", itinerary_num = "";
	Customer* current_user = customer_database_[current_user_name_];

	while (true)
	{
		std::cout << "\nPlease enter the car num and the car order num: ";
		std::cin >> num >> order_num;
		if (database_->SearchForCar(num) == false)
			std::cout << "ERROR: No such car ! Please enter again !\n";
		else if (database_->SearchForCarOrder(num, order_num) == false)
			std::cout << "ERROR: No such car order ! Please enter again !\n";
		else
			break;
	}

	database_->CancelCarOrder(num, order_num);

	while (true)
	{
		std::cout << "\nPlease enter the itinerary num that the order belongs to: ";
		std::cin >> itinerary_num;

		if (current_user->SearchForItinerary(itinerary_num) == false)
			std::cout << "ERROR: No such itinerary ! Please enter again !\n";
		else if (current_user->SearchForItineraryItem(itinerary_num, 3, order_num) == false)
			std::cout << "ERROR: No such order ! Please enter again !\n";
		else
			break;
	}

	current_user->DeleteItineraryItem(itinerary_num, 3, order_num);
	current_user = nullptr;
}


void CustomerInterface::ListItineraries()
{
	customer_database_[current_user_name_]->ListItineraries();
}


