/*********************************************************************************

  * FileName:       database.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Database
  * Project:        The seventh project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include "database.h"


Database::Database()
{
}


Database::~Database()
{
	std::unordered_map<std::string, Flight*>::iterator pf = flights_.begin();
	for (pf; pf != flights_.end(); pf++)
	{
		if (pf->second != nullptr)
		{
			delete pf->second;
			pf->second = nullptr;
		}
	}
	flights_.clear();

	std::unordered_map<std::string, Hotel*>::iterator ph = hotels_.begin();
	for (ph; ph != hotels_.end(); ph++)
	{
		if (ph->second != nullptr)
		{
			delete ph->second;
			ph->second = nullptr;
		}
	}
	hotels_.clear();

	std::unordered_map<std::string, Car*>::iterator pc = cars_.begin();
	for (pc; pc != cars_.end(); pc++)
	{
		if (pc->second != nullptr)
		{
			delete pc->second;
			pc->second = nullptr;
		}
	}
	cars_.clear();
}


void Database::ListFlights() const
{
	std::unordered_map<std::string, Flight*>::const_iterator p = flights_.begin();
	std::cout << "\nThe flights are as follows:\n";

	for (p; p != flights_.end(); p++)
	{
		std::cout << "Company:   " << p->second->GetCompany() << "   Flight Num:   " << p->second->GetFlightNum() << "   From:   ";
		std::cout << p->second->GetFrom() << "   Departure Date:   " << p->second->GetDepartureDate() << "   To:   ";
		std::cout << p->second->GetTo() << "   Arrival Date:   " << p->second->GetArrivalDate() << "   Cost:   " << p->second->GetCost() << '\n';
	}
}


bool Database::SearchForFlight(const std::string& flight_num) const
{
	return flights_.find(flight_num) != flights_.end();
}


const Flight& Database::GetFlight(const std::string& flight_num) const
{
	return *(flights_.find(flight_num)->second);
}


std::string Database::AddFlight(const std::string& flight_num, const std::string& customer_name)
{
	return flights_[flight_num]->AddOrder(customer_name);
}


bool Database::SearchForFlightOrder(const std::string& flight_num, const std::string& flight_order_num)
{
	return flights_[flight_num]->SearchForOrder(flight_order_num);
}


void Database::SetFlightOrderPaid(const std::string& flight_num, const std::string& flight_order_num)
{
	flights_[flight_num]->SetOrderPaid(flight_order_num);
}


void Database::CancelFlightOrder(const std::string& flight_num, const std::string& flight_order_num)
{
	flights_[flight_num]->CancelOrder(flight_order_num);
}


void Database::ListHotels() const
{
	std::unordered_map<std::string, Hotel*>::const_iterator p = hotels_.begin();
	std::cout << "\nThe hotels are as follows:\n";

	for (p; p != hotels_.end(); p++)
	{
		std::cout << "Hotel Num:   " << p->second->GetHotelNum() << "   Hotel Name:   " << p->second->GetHotelName();
		std::cout << "   Location:   " << p->second->GetLocation() << "   Cost:   " << p->second->GetCost() << '\n';
	}
}


bool Database::SearchForHotel(const std::string& hotel_num) const
{
	return hotels_.find(hotel_num) != hotels_.end();
}


const Hotel& Database::GetHotel(const std::string& hotel_num) const
{
	return *(hotels_.find(hotel_num)->second);
}


std::string Database::AddHotel(const std::string& hotel_num, const std::string& customer_name, const std::string& room_num, const std::string& from_date,
	const std::string& to_date, int days, int adult_num, int children_num, int infant_num)
{
	return hotels_[hotel_num]->AddOrder(customer_name, room_num, from_date, to_date, days, adult_num, children_num, infant_num);
}


bool Database::SearchForHotelOrder(const std::string& hotel_num, const std::string& hotel_order_num)
{
	return hotels_[hotel_num]->SearchForOrder(hotel_order_num);
}


void Database::SetHotelOrderPaid(const std::string& hotel_num, const std::string& hotel_order_num)
{
	hotels_[hotel_num]->SetOrderPaid(hotel_order_num);
}


void Database::CancelHotelOrder(const std::string& hotel_num, const std::string& hotel_order_num)
{
	hotels_[hotel_num]->CancelOrder(hotel_order_num);
}


void Database::ListCars() const
{
	std::unordered_map<std::string, Car*>::const_iterator p = cars_.begin();
	std::cout << "\nThe cars are as follows:\n";

	for (p; p != cars_.end(); p++)
	{
		std::cout << "Car Num:   " << p->second->GetCarNum() << "   Car Brand:   " << p->second->GetCarBrand();
		std::cout << "   Car Type:   " << p->second->GetCarType() << "   Cost:   " << p->second->GetCost() << '\n';
	}
}


bool Database::SearchForCar(const std::string& car_num) const
{
	return cars_.find(car_num) != cars_.end();
}


const Car& Database::GetCar(const std::string& car_num) const
{
	return *(cars_.find(car_num)->second);
}


std::string Database::AddCar(const std::string& car_num, const std::string& customer_name, const std::string& date)
{
	return cars_[car_num]->AddOrder(customer_name, date);
}


bool Database::SearchForCarOrder(const std::string& car_num, const std::string& car_order_num)
{
	return cars_[car_num]->SearchForOrder(car_order_num);
}


void Database::SetCarOrderPaid(const std::string& car_num, const std::string& car_order_num)
{
	cars_[car_num]->SetOrderPaid(car_order_num);
}


void Database::CancelCarOrder(const std::string& car_num, const std::string& car_order_num)
{
	cars_[car_num]->CancelOrder(car_order_num);
}


void Database::TestInit()
{
	flights_.insert(std::make_pair("CZ3614", new Flight("CZ3614", "南方航空", "2022-04-15", "2022-04-16", "Chongqing", "Chongqing", 5000)));
	hotels_.insert(std::make_pair("Quin3614", new Hotel("Quin3614", "QuinHotel", "Chongqing", 333)));
	cars_.insert(std::make_pair("NTC3614", new Car("NTC3614", "猛男寨", "泥头车", 333)));
}


