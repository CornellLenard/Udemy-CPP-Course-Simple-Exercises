/*********************************************************************************

  * FileName:       book.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Book
  * Project:        The sixth project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include "obr_classes.h"


Book::Book(std::string i, std::string n, std::string a, int p, int s): id_(i), name_(n), author_(a), page_(p), session_(s)
{
	int start = 0, end = 0;
	for (int i = 0; i < s; i++)
	{
		std::cout << "Please enter the start & end page for session " << i + 1 << ": ";
		std::cin >> start >> end;
		session_page_.push_back(std::make_pair(start, end));
	}
}


Book::~Book()
{
}


std::string Book::GetID() const
{
	return id_;
}


std::string Book::GetName() const
{
	return name_;
}


std::string Book::GetAuthor() const
{
	return author_;
}


int Book::GetPage() const
{
	return page_;
}


int Book::GetSession() const
{
	return session_;
}


int Book::GetWhichSession(int page) const
{
	int i = 0;
	for (i; i < session_; i++)
		if (page >= session_page_[i].first && page <= session_page_[i].second)
			return i + 1;
}


int Book::GetUpperBound(int session) const
{
	return session_page_[session - 1].second;
}


int Book::GetLowerBound(int session) const
{
	return session_page_[session - 1].first;
}


