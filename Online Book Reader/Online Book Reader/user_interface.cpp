/*********************************************************************************

  * FileName:       user_interface.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class UserInterface
  * Project:        The sixth project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include "obr_classes.h"


UserInterface::UserInterface(UserManager* um, User* u, BookManager* bm): um_(um), current_user_(u), bm_(bm)
{
	UserFunctionList();
}


UserInterface::~UserInterface()
{
	this->um_ = nullptr;
	this->bm_ = nullptr;
	this->current_user_ = nullptr;
}


void UserInterface::UserFunctionList() const
{
	int choice = 0;
	while (true)
	{
		std::cout << "\nCurrent User: " << current_user_->GetUserName() << '\n';
		std::cout << "\t1: View Profile\n\t2: List System Books\n";
		std::cout << "\t3: View Current Reading Sessions\n\t4: Search Book\n\t5: Logout\n";

		while (true)
		{
			std::cout << "\tPlease enter a choice: ";
			std::cin >> choice;
			if (choice < 1 || choice > 5)
				std::cout << "ERROR: Wrong choice ! Please enter again !\n";
			else
				break;
		}

		switch (choice)
		{
			case 1: ViewProfile(); break;
			case 2: ListBooks(); break;
			case 3: SelectBook(); break;
			case 4: SearchBook(); break;
			case 5: return;
		}
	}
}


void UserInterface::ViewProfile() const
{
	current_user_->ViewProfile();
}


void UserInterface::ListBooks() const
{
	bm_->ListBooks();
}


void UserInterface::SelectBook() const
{
	current_user_->ListReadingProgress();
	std::string id = "";
	const std::map<std::string, std::tuple<Book*, int, int> >& read_progress = current_user_->GetReadingProgress();

	while (true)
	{
		std::cout << "\nWhich book would you like to select? Please enter the book id: ";
		std::cin >> id;
		if (read_progress.find(id) == read_progress.end())
			std::cout << "ERROR: Wrong id ! Please enter again !\n";
		else
			break;
	}

	const std::tuple<Book*, int, int>& tp = (read_progress.find(id))->second;
	std::cout << "\nCurrent Book: " << id << '\t' << std::get<0>(tp)->GetName() << "\tCurrent Session: " << std::get<1>(tp) << "\tCurrent Page: " << std::get<2>(tp);
	std::cout << "\n\n\t1: Next Page\n\t2: Previous Page\n\t3: Jump to Page\n\t4: Remove This Book\n\t5: Exit\n";
	int choice = 0;

	while (true)
	{
		while (true)
		{
			std::cout << "\tPlease enter a choice: ";
			std::cin >> choice;
			if (choice < 1 || choice > 5)
				std::cout << "ERROR: Wrong choice ! Please enter again !\n";
			else
				break;
		}

		if (choice == 1)
		{
			current_user_->SetReadingProgress(id, true);
			std::cout << "\nCurrent Book: " << id << '\t' << std::get<0>(tp)->GetName();
			std::cout << "\tCurrent Session: " << std::get<1>(tp) << "\tCurrent Page: " << std::get<2>(tp) << '\n';
		}
		else if (choice == 2)
		{
			current_user_->SetReadingProgress(id, false);
			std::cout << "\nCurrent Book: " << id << '\t' << std::get<0>(tp)->GetName();
			std::cout << "\tCurrent Session: " << std::get<1>(tp) << "\tCurrent Page: " << std::get<2>(tp) << '\n';
		}
		else if (choice == 3)
		{
			int page = 0;
			std::cout << "Which page would you like to jump to? ";
			std::cin >> page;
			current_user_->JumpToPage(id, page);
			std::cout << "\nCurrent Book: " << id << '\t' << std::get<0>(tp)->GetName();
			std::cout << "\tCurrent Session: " << std::get<1>(tp) << "\tCurrent Page: " << std::get<2>(tp) << '\n';
		}
		else if (choice == 4)
			current_user_->RemoveBook(id);
		else
			return;
	}
}

void UserInterface::SearchBook() const
{
	bm_->SearchBook();
}


