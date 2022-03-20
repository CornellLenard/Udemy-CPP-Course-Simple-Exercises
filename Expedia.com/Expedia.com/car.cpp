/*********************************************************************************

  * FileName:       car.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Car
  * Project:        The seventh project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include "car.h"


CarOrder::CarOrder(const std::string& con, const std::string& cn, const std::string& cd, const std::string& d, double c) :
	car_order_num_(con), customer_name_(cn), creating_date_(cd), date_(d), cost_(c)
{
	is_paid_ = false;
}


CarOrder::~CarOrder()
{
}


std::string CarOrder::GetCarOrderNum() const
{
	return car_order_num_;
}


std::string CarOrder::GetCustomerName() const
{
	return customer_name_;
}


std::string CarOrder::GetCreatingDate() const
{
	return creating_date_;
}


std::string CarOrder::GetDate() const
{
	return date_;
}


double CarOrder::GetCost() const
{
	return cost_;
}


void CarOrder::SetPaid()
{
	is_paid_ = true;
}


Car::Car(const std::string& cn, const std::string& cb, const std::string& ct, double c) :
	car_num_(cn), car_brand_(cb), car_type_(ct), cost_(c)
{
	order_num_ = 0;
}


Car::~Car()
{
	std::unordered_map<std::string, CarOrder*>::iterator p = orders_.begin();

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


std::string Car::GetCarNum() const
{
	return car_num_;
}


std::string Car::GetCarBrand() const
{
	return car_brand_;
}


std::string Car::GetCarType() const
{
	return car_type_;
}


double Car::GetCost() const
{
	return cost_;
}


std::string Car::AddOrder(const std::string& customer_name, const std::string& date)
{
	std::string order_num_str = std::to_string(order_num_);
	orders_[order_num_str] = new CarOrder(order_num_str, customer_name, "date", date, cost_);
	order_num_++;
	return order_num_str;
}


void Car::SetOrderPaid(const std::string& car_order_num)
{
	orders_[car_order_num]->SetPaid();
}


bool Car::SearchForOrder(const std::string& car_order_num) const
{
	return orders_.find(car_order_num) != orders_.end();
}


void Car::CancelOrder(const std::string& car_order_num)
{
	std::unordered_map<std::string, CarOrder*>::iterator p = orders_.find(car_order_num);
	delete p->second;
	p->second = nullptr;
	orders_.erase(p);
}


