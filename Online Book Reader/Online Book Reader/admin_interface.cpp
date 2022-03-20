/*********************************************************************************

  * FileName:       admin_interface.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class AdminInterface
  * Project:        The sixth project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include "obr_classes.h"


AdminInterface::AdminInterface(UserManager* um, Admin* a, BookManager* bm): um_(um), current_admin_(a), bm_(bm)
{
	AdminFunctionList();
}


AdminInterface::~AdminInterface()
{
	this->um_ = nullptr;
	this->bm_ = nullptr;
	this->current_admin_ = nullptr;
}


void AdminInterface::AdminFunctionList()
{
	int choice = 0;
	while (true)
	{
		std::cout << "\nCurrent Admin: " << current_admin_->GetAdminName() << '\n';
		std::cout << "\t1: View Profile\n\t2: List System Books\n\t3: Add Book\n\t4: Activate New User Account\n";
		std::cout << "\t5: Search Book\n\t6: Edit Book\n\t7: Delete Book\n\t8: Logout\n";

		while (true)
		{
			std::cout << "\tPlease enter a choice: ";
			std::cin >> choice;
			if (choice < 1 || choice > 8)
				std::cout << "ERROR: Wrong choice ! Please enter again !\n";
			else
				break;
		}

		switch (choice)
		{
			case 1: ViewProfile(); break;
			case 2: ListBooks(); break;
			case 3: AddBook(); break;
			case 4: ActivateNewUser(); break;
			case 5: SearchBook(); break;
			case 6: EditBook(); break;
			case 7: DeleteBook(); break;
			case 8: return;
		}
	}
}


void AdminInterface::ViewProfile() const
{
	current_admin_->ViewProfile();
}


void AdminInterface::ListBooks() const
{
	bm_->ListBooks();
}


void AdminInterface::AddBook()
{
	bm_->AddBook();
}


void AdminInterface::ActivateNewUser()
{
	std::map<std::string, User*>::iterator p = (um_->users_).begin();
	for (p; p != (um_->users_).end(); p++)
		if (p->second->GetVerification() == false)
			SetVerification(p->second);
}


void AdminInterface::SetVerification(User* u)
{
	u->verified_ = true;
}

void AdminInterface::SearchBook() const
{
	bm_->SearchBook();
}

void AdminInterface::EditBook()
{
	bm_->EditBook();
}

void AdminInterface::DeleteBook()
{
	bm_->DeleteBook();
}


