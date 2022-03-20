/*********************************************************************************

  * FileName:       customer.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Customer
  * Project:        The seventh project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include "customer.h"


Customer::Customer(const std::string& n, const std::string& p, const std::string& g, int a, const std::string& b) :
	name_(n), password_(p), gender_(g), age_(a), birthday_(b)
{
	itinerary_num_ = 0;
}


Customer::~Customer()
{
	std::multimap<std::string, Itinerary*>::iterator p = itineraries_.begin();

	for (p; p != itineraries_.end(); p++)
	{
		if (p->second != nullptr)
		{
			delete p->second;
			p->second = nullptr;
		}
	}

	itineraries_.clear();
}


std::string Customer::GetPassword() const
{
	return password_;
}


std::string Customer::GetGender() const
{
	return gender_;
}


int Customer::GetAge() const
{
	return age_;
}


std::string Customer::GetBirthday() const
{
	return birthday_;
}


void Customer::ListItineraries() const
{
	std::multimap<std::string, Itinerary*>::const_iterator p = itineraries_.begin();
	for (p; p != itineraries_.end(); p++)
		p->second->ListItinerary();
}


bool Customer::SearchForItinerary(const std::string& itinerary_num) const
{
	return itineraries_.find(itinerary_num) != itineraries_.end();
}


void Customer::AddItineraryFlight(const std::string& itinerary_num, const ItineraryFlight& itf)
{
	itineraries_.find(itinerary_num)->second->AddItineraryFlight(itf);
}


void Customer::AddItineraryHotel(const std::string& itinerary_num, const ItineraryHotel& ith)
{
	itineraries_.find(itinerary_num)->second->AddItineraryHotel(ith);
}


void Customer::AddItineraryCar(const std::string& itinerary_num, const ItineraryCar& itc)
{
	itineraries_.find(itinerary_num)->second->AddItineraryCar(itc);
}


bool Customer::SearchForItineraryItem(const std::string& itinerary_num, int choice, const std::string& order_num)
{
	return itineraries_.find(itinerary_num)->second->SearchForOrder(choice, order_num);
}


void Customer::DeleteItineraryItem(const std::string& itinerary_num, int choice, const std::string& order_num)
{
	itineraries_.find(itinerary_num)->second->DeleteItineraryItem(choice, order_num);
}


void Customer::AddItinerary()
{
	std::string itinerary_num_str = std::to_string(itinerary_num_);
	itineraries_.insert(std::make_pair(itinerary_num_str, new Itinerary(itinerary_num_str, "date")));
	itinerary_num_++;
}


