/*********************************************************************************

  * FileName:       admin.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Admin
  * Project:        The sixth project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include "obr_classes.h"


Admin::Admin(std::string i, std::string n, std::string p, std::string g, std::string b):
	id_(i), name_(n), password_(p), gender_(g), birthday_(b)
{
}


Admin::~Admin()
{
}


bool Admin::VerifyPassword(const std::string& password) const
{
	return this->password_ == password;
}


std::string Admin::GetAdminName() const
{
	return name_;
}


void Admin::ViewProfile() const
{
	std::cout << "\nThe Profile of Admin " << id_ << "\n\tName: " << name_;
	std::cout << "\n\tGender: " << gender_ << "\n\tBirthday: " << birthday_ << '\n';
}


