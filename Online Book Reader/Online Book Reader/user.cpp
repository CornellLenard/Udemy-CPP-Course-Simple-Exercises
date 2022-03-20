/*********************************************************************************

  * FileName:       user.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class User
  * Project:        The sixth project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include "obr_classes.h"


User::User(std::string i, std::string n, std::string p, std::string g, std::string b): id_(i), name_(n), password_(p), gender_(g), birthday_(b)
{
	verified_ = false;
}


User::~User()
{
}


bool User::VerifyPassword(const std::string& password) const
{
	return this->password_ == password;
}


std::string User::GetUserName() const
{
	return name_;
}


bool User::GetVerification() const
{
	return verified_;
}


void User::ViewProfile() const
{
	std::cout << "\nThe Profile of User " << id_ << "\n\tName: " << name_;
	std::cout << "\n\tGender: " << gender_ << "\n\tBirthday: " << birthday_ << '\n';
}


void User::ListReadingProgress() const
{
	std::cout << "\nYour Current Reading Progress is as follows:\n";
	std::map<std::string, std::tuple<Book*, int, int> >::const_iterator p = read_progress_.begin();

	for (p; p != read_progress_.end(); p++)
	{
		std::cout << "Book Id: " << p->first << "\tBook Name: " << std::get<0>(p->second)->GetName();
		std::cout << "\tCurrent Session: " << std::get<1>(p->second) << "\tCurrent Page: " << std::get<2>(p->second) << '\n';
	}
}


const std::map<std::string, std::tuple<Book*, int, int> >& User::GetReadingProgress() const
{
	return read_progress_;
}


void User::SetReadingProgress(const std::string& id, bool plus)
{
	std::tuple<Book*, int, int>& tp = (read_progress_.find(id))->second;

	// If plus is true, it means next page
	if (plus == true)
	{
		// If it reaches the last page, then returns
		if (std::get<2>(tp) == std::get<0>(tp)->GetPage())
			return;

		// Else the page+1
		std::get<2>(tp)++;
		// If it surpasses the last page of the session, then goes to next session
		int upper = std::get<0>(tp)->GetUpperBound(std::get<1>(tp));
		if (std::get<2>(tp) > upper)
			std::get<1>(tp)++;
	}
	else
	{
		if (std::get<2>(tp) == 1)
			return;
		std::get<2>(tp)--;
		int lower = std::get<0>(tp)->GetLowerBound(std::get<1>(tp));
		if (std::get<2>(tp) < lower)
			std::get<1>(tp)--;
	}
}


void User::JumpToPage(const std::string& id, int page)
{
	if (page < 1)
		return;

	std::tuple<Book*, int, int>& tp = (read_progress_.find(id))->second;

	// If it surpasses the last page, then returns
	if (page > std::get<0>(tp)->GetPage())
		return;

	std::get<2>(tp) = page;
	std::get<1>(tp) = std::get<0>(tp)->GetWhichSession(page);
}


void User::RemoveBook(const std::string& id)
{
	std::get<0>((read_progress_.find(id))->second) = nullptr;
	read_progress_.erase(read_progress_.find(id));
}


