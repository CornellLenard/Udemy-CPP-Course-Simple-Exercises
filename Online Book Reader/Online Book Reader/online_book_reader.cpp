/*********************************************************************************

  * FileName:       online_book_reader.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class OnlineBookReader
  * Project:        The sixth project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include "obr_classes.h"


void OnlineBookReader::InitInterface()
{
	std::cout << "Welcome to the Online Book Reader Application !\n";
	std::cout << "\t1: Login\n\t2: Sign Up\n\t3: Exit\n";
	int choice = 0;

	while (true)
	{
		std::cout << "\tPlease enter a choice: ";
		std::cin >> choice;
		if (choice < 1 || choice > 3)
			std::cout << "ERROR: Wrong choice ! Please enter again !\n";
		else
			break;
	}

	switch (choice)
	{
		case 1: Login(); break;
		case 2: SignUp(); break;
		case 3: break;
	}
}


void OnlineBookReader::Login()
{
	std::string id = "", password = "";
	std::cout << "\nYou wish to login as reader or administrator?\n\t1: reader\n\t2: administrator\n";
	int choice = 0;

	while (true)
	{
		std::cout << "\tPlease enter a choice: ";
		std::cin >> choice;
		if (choice != 1 && choice != 2)
			std::cout << "ERROR: Wrong choice ! Please enter again !\n";
		else
			break;
	}
	std::cout << '\n';

	// Classifies the situations based on whether the user is reader or admin
	if (choice == 1)
	{
		while (true)
		{
			std::cout << "Please enter your id and password: ";
			std::cin >> id >> password;
			// Verifies whether the user id and the password are correct
			if (um_->VerifyUserIdPassword(id, password) == false)
				std::cout << "ERROR: Wrong user id and password ! Please enter again !\n";
			else
				break;
		}
		// Sets the current user id
		um_->SetCurrent(id, false);
		// Creates UserInterface
		um_->SetUserInterface();
	}
	else
	{
		while (true)
		{
			std::cout << "Please enter your id and password: ";
			std::cin >> id >> password;
			if (um_->VerifyAdminIdPassword(id, password) == false)
				std::cout << "ERROR: Wrong admin id and password ! Please enter again !\n";
			else
				break;
		}
		um_->SetCurrent(id, true);
		um_->SetAdminInterface();
	}
}


void OnlineBookReader::SignUp()
{
	std::cout << "\nPlease enter your id, name, password, gender, birthday: ";
	std::string id = "", name = "", password = "", gender = "", birthday = "";
	std::cin >> id >> name >> password >> gender >> birthday;
	um_->AddUser(id, name, password, gender, birthday);
	um_->SetCurrent(id, false);
	um_->SetUserInterface();
}


OnlineBookReader::OnlineBookReader()
{
	bm_ = new BookManager();
	um_ = new UserManager(bm_);
}


OnlineBookReader::~OnlineBookReader()
{
	if (bm_ != nullptr)
	{
		delete bm_;
		bm_ = nullptr;
	}
	if (um_ != nullptr)
	{
		delete um_;
		um_ = nullptr;
	}
}


void OnlineBookReader::Run()
{
	InitInterface();
}


void OnlineBookReader::TestInit()
{
	std::cout << "Test Init\n";
	um_->AddUser("d001", "ZH", "d001", "Male", "1996");
	um_->AddUser("d002", "ZJY", "d002", "Male", "1996");
	um_->TestOnlyAddAdmin("a001", "CC", "a001", "Male", "1996");
	bm_->AddBook();
	bm_->AddBook();
	bm_->AddBook();
	Book* book = (bm_->books_.find("111"))->second;
	User* user = (um_->users_.find("d001"))->second;
	user->read_progress_.insert(std::map<std::string, std::tuple<Book*, int, int> >::value_type("111", std::make_tuple(book, 2, 7)));
	book = (bm_->books_.find("222"))->second;
	user->read_progress_.insert(std::map<std::string, std::tuple<Book*, int, int> >::value_type("222", std::make_tuple(book, 2, 6)));
	std::cout << '\n';
}


