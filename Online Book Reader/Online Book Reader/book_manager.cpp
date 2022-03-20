/*********************************************************************************

  * FileName:       book_manager.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class BookManager
  * Project:        The sixth project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include "obr_classes.h"


void BookManager::Clear()
{
	std::map<std::string, Book*>::iterator p = books_.begin();

	for (p; p != books_.end(); p++)
	{
		delete p->second;
		p->second = nullptr;
	}

	books_.clear();
}


BookManager::BookManager()
{
}


BookManager::~BookManager()
{
	Clear();
}


void BookManager::ListBooks() const
{
	std::cout << "\nThe books in the application are as follows:\n";
	std::map<std::string, Book*>::const_iterator p = books_.begin();
	for (p; p != books_.end(); p++)
		std::cout << "Book Id: " << p->first << "\tBook Name: " << p->second->GetName() << "\tBook Author: " << p->second->GetAuthor() << '\n';
}


void BookManager::SearchBook() const
{
	std::string input = "";
	int choice = 0;
	bool flag = false;
	while (true)
	{
		std::cout << "\nWhich way would you like to use to search for a book?\n";
		std::cout << "\t1: Book Id\n\t2: Book Name\n\t3: Book Author\n\t4: Exit\n";

		while (true)
		{
			std::cout << "\tPlease enter a choice: ";
			std::cin >> choice;
			if (choice < 1 || choice > 4)
				std::cout << "ERROR: Wrong choice ! Please enter again !\n";
			else
				break;
		}

		if (choice == 4)
			break;
		std::cout << "Please enter the Book ";

		switch (choice)
		{
			case 1: std::cout << "Id: "; break;
			case 2: std::cout << "Name: "; break;
			case 3: std::cout << "Author: "; break;
		}

		std::cin >> input;
		std::map<std::string, Book*>::const_iterator p = books_.begin();

		if (choice == 1)
		{
			for (p; p != books_.end(); p++)
			{
				if (p->first == input)
				{
					flag = true;
					break;
				}
			}
			if (flag == true)
				std::cout << "\nBook Id: " << input << "\tBook Name: " << p->second->GetName() << "\tBook Author: " << p->second->GetAuthor() << '\n';
			else
				std::cout << "Not Found\n";
		}
		else if (choice == 2)
		{
			for (p; p != books_.end(); p++)
			{
				if (p->second->GetName() == input)
				{
					flag = true;
					std::cout << "\nBook Id: " << p->first << "\tBook Name: " << input << "\tBook Author: " << p->second->GetAuthor() << '\n';
				}
			}
			if (flag == false)
				std::cout << "Not Found\n";
		}
		else
		{
			for (p; p != books_.end(); p++)
			{
				if (p->second->GetAuthor() == input)
				{
					flag = true;
					std::cout << "\nBook Id: " << p->first << "\tBook Name: " << p->second->GetName() << "\tBook Author: " << input << '\n';
				}
			}
			if (flag == false)
				std::cout << "Not Found\n";
		}
	}
}


void BookManager::AddBook()
{
	std::cout << "\nPlease enter the following information for the new book:\n";
	std::string id = "", name = "", author = "";
	int page = 0, session = 0;
	std::cout << "Please enter the book id: ";
	std::cin >> id;
	std::cout << "Please enter the book name: ";
	std::cin >> name;
	std::cout << "Please enter the book author: ";
	std::cin >> author;
	std::cout << "Please enter the number of page and the number of session: ";
	std::cin >> page >> session;
	books_.insert(std::map<std::string, Book*>::value_type(id, new Book(id, name, author, page, session)));
}


void BookManager::EditBook()
{
	std::string id = "";

	while (true)
	{
		std::cout << "\nWhich book would you like to edit? Please enter the book id: ";
		std::cin >> id;
		if (books_.find(id) == books_.end())
			std::cout << "ERROR: Wrong id ! Please enter again !\n";
		else
			break;
	}

	int choice = 0;
	std::cout << "\nWhich information of the book would you like to edit?\n";
	std::cout << "\t1: Name\n\t2: Author\n";

	while (true)
	{
		std::cout << "\tPlease enter a choice: ";
		std::cin >> choice;
		if (choice != 1 && choice != 2)
			std::cout << "ERROR: Wrong choice ! Please enter again !\n";
		else
			break;
	}

	std::string input = "";
	if (choice == 1)
	{
		std::cout << "Please enter the new name: ";
		std::cin >> input;
		(books_.find(id))->second->name_ = input;
	}
	else
	{
		std::cout << "Please enter the new author: ";
		std::cin >> input;
		(books_.find(id))->second->author_ = input;
	}
}


void BookManager::DeleteBook()
{
	std::string id = "";
	while (true)
	{
		std::cout << "\nWhich book would you like to delete? Please enter the book id: ";
		std::cin >> id;
		if (books_.find(id) == books_.end())
			std::cout << "ERROR: Wrong id ! Please enter again !\n";
		else
			break;
	}

	std::map<std::string, User*>& users = (books_.find(id))->second->read_by_;
	std::map<std::string, User*>::iterator p = users.begin();

	for (p; p != users.end(); p++)
		p->second->RemoveBook(id);

	delete (books_.find(id))->second;
	(books_.find(id))->second = nullptr;
	books_.erase(books_.find(id));
}


