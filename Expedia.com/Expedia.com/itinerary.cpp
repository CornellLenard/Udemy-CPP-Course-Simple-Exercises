/*********************************************************************************

  * FileName:       itinerary.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Itinerary
  * Project:        The seventh project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include "itinerary.h"


ItineraryFlight::ItineraryFlight(const std::string& fon, const std::string& fn, const std::string& dd, const std::string& ad, const std::string& f, const std::string& t,
	const std::string& d, double c): flight_order_num_(fon), flight_num_(fn), departure_date_(dd), arrival_date_(ad), from_(f), to_(t), details_(d), cost_(c)
{
}


ItineraryFlight::~ItineraryFlight()
{
}


std::string ItineraryFlight::GetFlightOrderNum() const
{
	return flight_order_num_;
}


std::string ItineraryFlight::GetFlightNum() const
{
	return flight_num_;
}


std::string ItineraryFlight::GetDepartureDate() const
{
	return departure_date_;
}


std::string ItineraryFlight::GetArrivalDate() const
{
	return arrival_date_;
}


std::string ItineraryFlight::GetFrom() const
{
	return from_;
}


std::string ItineraryFlight::GetTo() const
{
	return to_;
}


std::string ItineraryFlight::GetDetails() const
{
	return details_;
}


double ItineraryFlight::GetCost() const
{
	return cost_;
}


ItineraryHotel::ItineraryHotel(const std::string& hon, const std::string& hnu, const std::string& hna, const std::string& l, const std::string& rn,
	const std::string& fd, const std::string& td, int an, int cn, int in, double c): hotel_order_num_(hon), hotel_num_(hnu), hotel_name_(hna), location_(l),
	room_num_(rn), from_date_(fd), to_date_(td), adult_num_(an), children_num_(cn), infant_num_(in), cost_(c)
{
}


ItineraryHotel::~ItineraryHotel()
{
}


std::string ItineraryHotel::GetHotelOrderNum() const
{
	return hotel_order_num_;
}


std::string ItineraryHotel::GetHotelNum() const
{
	return hotel_num_;
}


std::string ItineraryHotel::GetHotelName() const
{
	return hotel_name_;
}


std::string ItineraryHotel::GetLocation() const
{
	return location_;
}


std::string ItineraryHotel::GetRoomNum() const
{
	return room_num_;
}


std::string ItineraryHotel::GetFromDate() const
{
	return from_date_;
}


std::string ItineraryHotel::GetToDate() const
{
	return to_date_;
}


double ItineraryHotel::GetCost() const
{
	return cost_;
}


ItineraryCar::ItineraryCar(const std::string& con, const std::string& cn, const std::string& cb, const std::string& ct, const std::string& d, double c):
	car_order_num_(con), car_num_(cn), car_brand_(cb), car_type_(ct), date_(d), cost_(c)
{
}


ItineraryCar::~ItineraryCar()
{
}


std::string ItineraryCar::GetCarOrderNum() const
{
	return car_order_num_;
}


std::string ItineraryCar::GetCarNum() const
{
	return car_num_;
}


std::string ItineraryCar::GetCarBrand() const
{
	return car_brand_;
}


std::string ItineraryCar::GetCarType() const
{
	return car_type_;
}


std::string ItineraryCar::GetDate() const
{
	return date_;
}


double ItineraryCar::GetCost() const
{
	return cost_;
}


Itinerary::Itinerary(const std::string& in, const std::string& cd): itinerary_num_(in), creating_date_(cd)
{
}


Itinerary::~Itinerary()
{
}


double Itinerary::GetItineraryCost() const
{
	double cost = 0;
	std::vector<ItineraryFlight>::const_iterator pif = flights_.begin();

	for (pif; pif != flights_.end(); pif++)
		cost += pif->GetCost();

	std::vector<ItineraryHotel>::const_iterator pih = hotels_.begin();
	for (pih; pih != hotels_.end(); pih++)
		cost += pih->GetCost();

	std::vector<ItineraryCar>::const_iterator pic = cars_.begin();
	for (pic; pic != cars_.end(); pic++)
		cost += pic->GetCost();

	return cost;
}


void Itinerary::ListItinerary() const
{
	std::cout << "\nThe itinerary num: " << itinerary_num_ << '\n';
	std::cout << "The creating date of the itinerary: " << creating_date_ << '\n';
	std::cout << "\nThe itinerary consists of " << flights_.size() << " flights:\n";

	std::vector<ItineraryFlight>::const_iterator pif = flights_.begin();
	for (pif; pif != flights_.end(); pif++)
	{
		std::cout << "\n\tFlight Order Num: " << pif->GetFlightOrderNum() << "\n\tFlight Num: " << pif->GetFlightNum();
		std::cout << "\n\tFrom: " << pif->GetFrom() << "\tDeparture Date: " << pif->GetDepartureDate() << "\n\tTo: " << pif->GetTo();
		std::cout << "\tArrival Date: " << pif->GetArrivalDate() << "\n\tCost: " << pif->GetCost() << "\n";
	}
	std::cout << "\nThe itinerary consists of " << hotels_.size() << " hotels:\n";

	std::vector<ItineraryHotel>::const_iterator pih = hotels_.begin();
	for (pih; pih != hotels_.end(); pih++)
	{
		std::cout << "\n\tHotel Order Num: " << pih->GetHotelOrderNum() << "\n\tHotel Num: " << pih->GetHotelNum();
		std::cout << "\tHotel Name: " << pih->GetHotelName() << "\tLocation: " << pih->GetLocation() << "\n\tFrom Date: ";
		std::cout << pih->GetFromDate() << "\tTo Date: " << pih->GetToDate() << "\n\tCost: " << pih->GetCost() << '\n';
	}
	std::cout << "\nThe itinerary consists of " << cars_.size() << " cars:\n";

	std::vector<ItineraryCar>::const_iterator pic = cars_.begin();
	for (pic; pic != cars_.end(); pic++)
	{
		std::cout << "\n\tCar Order Num: " << pic->GetCarOrderNum() << "\tCar Num: " << pic->GetCarNum() << "\tCar Brand: " << pic->GetCarBrand();
		std::cout << "\tCar Type: " << pic->GetCarType() << "\n\tDate: " << pic->GetDate() << "\tCost: " << pic->GetCost() << '\n';
	}
}


void Itinerary::AddItineraryFlight(const ItineraryFlight& itf)
{
	flights_.push_back(itf);
}


void Itinerary::AddItineraryHotel(const ItineraryHotel& ith)
{
	hotels_.push_back(ith);
}


void Itinerary::AddItineraryCar(const ItineraryCar& itc)
{
	cars_.push_back(itc);
}


bool Itinerary::SearchForOrder(int choice, const std::string& order_num)
{
	if (choice == 1)
	{
		std::vector<ItineraryFlight>::const_iterator p = flights_.begin();

		for (p; p != flights_.end(); p++)
			if (p->GetFlightOrderNum() == order_num)
				return true;

		return false;
	}
	else if (choice == 2)
	{
		std::vector<ItineraryHotel>::const_iterator p = hotels_.begin();

		for (p; p != hotels_.end(); p++)
			if (p->GetHotelOrderNum() == order_num)
				return true;

		return false;
	}
	else
	{
		std::vector<ItineraryCar>::const_iterator p = cars_.begin();

		for (p; p != cars_.end(); p++)
			if (p->GetCarOrderNum() == order_num)
				return true;

		return false;
	}
}


void Itinerary::DeleteItineraryItem(int choice, const std::string& order_num)
{
	if (choice == 1)
	{
		std::vector<ItineraryFlight>::const_iterator p = flights_.begin();
		for (p; p != flights_.end(); p++)
		{
			if (p->GetFlightOrderNum() == order_num)
			{
				flights_.erase(p);
				break;
			}
		}
	}
	else if (choice == 2)
	{
		std::vector<ItineraryHotel>::const_iterator p = hotels_.begin();
		for (p; p != hotels_.end(); p++)
		{
			if (p->GetHotelOrderNum() == order_num)
			{
				hotels_.erase(p);
				break;
			}
		}
	}
	else
	{
		std::vector<ItineraryCar>::const_iterator p = cars_.begin();
		for (p; p != cars_.end(); p++)
		{
			if (p->GetCarOrderNum() == order_num)
			{
				cars_.erase(p);
				break;
			}
		}
	}
}


