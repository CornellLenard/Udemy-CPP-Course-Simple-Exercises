/*********************************************************************************

  * FileName:       flight.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Flight
  * Project:        The seventh project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include "flight.h"


FlightOrder::FlightOrder(const std::string& fon, const std::string& cn, const std::string& cd, double c) :
	flight_order_num_(fon), customer_name_(cn), creating_date_(cd), cost_(c)
{
	is_paid_ = false;
}


FlightOrder::~FlightOrder()
{
}


std::string FlightOrder::GetFlightOrderNum() const
{
	return flight_order_num_;
}


std::string FlightOrder::GetCustomerName() const
{
	return customer_name_;
}


std::string FlightOrder::GetCreatingDate() const
{
	return creating_date_;
}


double FlightOrder::GetCost() const
{
	return cost_;
}


void FlightOrder::SetPaid()
{
	is_paid_ = true;
}


Flight::Flight(const std::string& fn, const std::string& c, const std::string& dd, const std::string& ad, const std::string& f, const std::string& t, double co) :
	flight_num_(fn), company_(c), departure_date_(dd), arrival_date_(ad), from_(f), to_(t), cost_(co)
{
	order_num_ = 0;
}


Flight::~Flight()
{
	std::unordered_map<std::string, FlightOrder*>::iterator p = orders_.begin();

	for (p; p != orders_.end(); p++)
	{
		if (p->second != nullptr)
		{
			delete p->second;
			p->second = nullptr;
		}
	}

	orders_.clear();
}


std::string Flight::GetFlightNum() const
{
	return flight_num_;
}


std::string Flight::GetCompany() const
{
	return company_;
}


std::string Flight::GetDepartureDate() const
{
	return departure_date_;
}


std::string Flight::GetArrivalDate() const
{
	return arrival_date_;
}


std::string Flight::GetFrom() const
{
	return from_;
}


std::string Flight::GetTo() const
{
	return to_;
}


double Flight::GetCost() const
{
	return cost_;
}


std::string Flight::AddOrder(const std::string& customer_name)
{
	std::string order_num_str = std::to_string(order_num_);
	orders_[order_num_str] = new FlightOrder(order_num_str, customer_name, "date", cost_);
	order_num_++;
	return order_num_str;
}


void Flight::SetOrderPaid(const std::string& flight_order_num)
{
	orders_[flight_order_num]->SetPaid();
}


bool Flight::SearchForOrder(const std::string& flight_order_num) const
{
	return orders_.find(flight_order_num) != orders_.end();
}


void Flight::CancelOrder(const std::string& flight_order_num)
{
	std::unordered_map<std::string, FlightOrder*>::iterator p = orders_.find(flight_order_num);
	delete p->second;
	p->second = nullptr;
	orders_.erase(p);
}


