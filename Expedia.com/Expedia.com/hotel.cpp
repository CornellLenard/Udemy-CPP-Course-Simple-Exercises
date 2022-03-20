/*********************************************************************************

  * FileName:       hotel.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Hotel
  * Project:        The seventh project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include "hotel.h"


HotelOrder::HotelOrder(const std::string& hon, const std::string& cna, const std::string& cd, const std::string& rn, const std::string& fd, const std::string& td,
	int d, int an, int cnu, int in, double c) : hotel_order_num_(hon), customer_name_(cna), creating_date_(cd), room_num_(rn), from_date_(fd),
	to_date_(td), days_(d), adult_num_(an), children_num_(cnu), infant_num_(in), cost_(c)
{
	is_paid_ = false;
}


HotelOrder::~HotelOrder()
{
}


std::string HotelOrder::GetHotelOrderNum() const
{
	return hotel_order_num_;
}


std::string HotelOrder::GetCustomerName() const
{
	return customer_name_;
}


std::string HotelOrder::GetCreatingDate() const
{
	return creating_date_;
}


std::string HotelOrder::GetFromDate() const
{
	return from_date_;
}


std::string HotelOrder::GetToDate() const
{
	return to_date_;
}


double HotelOrder::GetCost() const
{
	return cost_;
}


void HotelOrder::SetPaid()
{
	is_paid_ = true;
}


Hotel::Hotel(const std::string& hnu, const std::string& hna, const std::string& l, double c) :
	hotel_num_(hnu), hotel_name_(hna), location_(l), cost_(c)
{
	order_num_ = 0;
}


Hotel::~Hotel()
{
	std::unordered_map<std::string, HotelOrder*>::iterator p = orders_.begin();

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


std::string Hotel::GetHotelNum() const
{
	return hotel_num_;
}


std::string Hotel::GetHotelName() const
{
	return hotel_name_;
}


std::string Hotel::GetLocation() const
{
	return location_;
}


double Hotel::GetCost() const
{
	return cost_;
}


std::string Hotel::AddOrder(const std::string& customer_name, const std::string& room_num, const std::string& from_date,
	const std::string& to_date, int days, int adult_num, int children_num, int infant_num)
{
	std::string order_num_str = std::to_string(order_num_);
	orders_[order_num_str] = new HotelOrder(order_num_str, customer_name, "date", room_num, from_date, to_date, days, adult_num, children_num, infant_num, cost_ * days);
	order_num_++;
	return order_num_str;
}


void Hotel::SetOrderPaid(const std::string& hotel_order_num)
{
	orders_[hotel_order_num]->SetPaid();
}


bool Hotel::SearchForOrder(const std::string& hotel_order_num) const
{
	return orders_.find(hotel_order_num) != orders_.end();
}


void Hotel::CancelOrder(const std::string& hotel_order_num)
{
	std::unordered_map<std::string, HotelOrder*>::iterator p = orders_.find(hotel_order_num);
	delete p->second;
	p->second = nullptr;
	orders_.erase(p);
}


