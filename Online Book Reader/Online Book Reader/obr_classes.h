/*********************************************************************************

  * FileName:       obr_classes.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the classes of the Online Book Reader
  * Project:        The sixth project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <map>


class User;
class UserManager;
class Book;
class BookManager;


class OnlineBookReader
{
private:
	// Creates a UserManager
	UserManager* um_;
	// Creates a BookManager
	BookManager* bm_;

	/*
	* Creates the initial interface
	*/
	void InitInterface();
	
	/*
	* Logins
	*/
	void Login();
	
	/*
	* Signs up
	*/
	void SignUp();

public:
	OnlineBookReader();
	~OnlineBookReader();
	
	/*
	* Runs the Online Book Reader
	*/
	void Run();
	
	/*
	* Initializes the system for testing
	*/
	void TestInit();
};


class Admin
{
private:
	// The id of the admin
	std::string id_;
	// The name of the admin
	std::string name_;
	// The password of the admin
	std::string password_;
	// The gender of the admin
	std::string gender_;
	// The birthday of the admin
	std::string birthday_;

public:
	Admin(std::string i = "N/A", std::string n = "N/A", std::string p = "N/A", std::string g = "N/A", std::string b = "N/A");
	~Admin();
	
	/*
	* Verifies whether the password is correct
	* @ Parameter:
	*       password:  The password
	* @ Return:
	*                  Whether the password is correct
	*/
	bool VerifyPassword(const std::string& password) const;
	
	/*
	* Gets the name of the admin
	* @ Return:
	*                  The name of the admin
	*/
	std::string GetAdminName() const;
	
	/*
	* Views the profile of the admin
	*/
	void ViewProfile() const;
};


class AdminInterface
{
private:
	// Points to UserManager
	UserManager* um_;
	// Points to Admin
	Admin* current_admin_;
	// Points to BookManager
	BookManager* bm_;

public:
	AdminInterface(UserManager* um, Admin* a, BookManager* bm);
	~AdminInterface();
	
	/*
	* Lists the functionalities for admin
	*/
	void AdminFunctionList();
	
	/*
	* Views the profile
	*/
	void ViewProfile() const;
	
	/*
	* Lists the books
	*/
	void ListBooks() const;
	
	/*
	* Adds a book
	*/
	void AddBook();
	
	/*
	* Activates a new user
	*/
	void ActivateNewUser();
	
	/*
	* Sets the verification flag
	* @ Parameter:
	*       u:         To whom the verification is set
	*/
	void SetVerification(User* u);
	
	/*
	* Searches a book
	*/
	void SearchBook() const;
	
	/*
	* Edits a book
	*/
	void EditBook();
	
	/*
	* Deletes a book
	*/
	void DeleteBook();
};


class UserInterface
{
private:
	// Points to UserManager
	UserManager* um_;
	// Points to User
	User* current_user_;
	// Points to BookManager
	BookManager* bm_;

public:
	UserInterface(UserManager* um, User* u, BookManager* bm);
	~UserInterface();
	
	/*
	* Lists the functionalities for user
	*/
	void UserFunctionList() const;
	
	/*
	* Views the profile
	*/
	void ViewProfile() const;
	
	/*
	* Lists the books
	*/
	void ListBooks() const;
	
	/*
	* Selects a book
	*/
	void SelectBook() const;
	
	/*
	* Searches a book
	*/
	void SearchBook() const;
};


class UserManager
{
private:
	// Points to User
	User* current_user_;
	// Points to Admin
	Admin* current_admin_;
	// The user database
	std::map<std::string, User*> users_;
	// The admin database
	std::map<std::string, Admin*> admins_;
	// Creates UserInterface
	UserInterface* ui_;
	// Creates AdminInterface
	AdminInterface* ai_;
	// Points to BookManager
	BookManager* bm_;
	
	/*
	* Clears the space
	*/
	void Clear();
	
	/*
	* Friend method
	*/
	friend void AdminInterface::ActivateNewUser();
	
	/*
	* Friend method
	*/
	friend void OnlineBookReader::TestInit();

public:
	UserManager(BookManager* bm);
	~UserManager();
	
	/*
	* Verifies whether the user password is correct
	* @ Parameter:
	*       id:        The user id
	*       password:  The password
	* @ Return:
	*                  Whether the password is correct
	*/
	bool VerifyUserIdPassword(const std::string& id, const std::string& password) const;
	
	/*
	* Verifies whether the admin password is correct
	* @ Parameter:
	*       id:        The admin id
	*       password:  The password
	* @ Return:
	*                  Whether the password is correct
	*/
	bool VerifyAdminIdPassword(const std::string& id, const std::string& password) const;
	
	/*
	* Adds a new user
	* @ Parameter:
	*       id:        The user id
	*       name:      The user name
	*       password:  The user password
	*       gender:    The user gender
	*       birthday:  The user birthday
	*/
	void AddUser(const std::string& id, const std::string& name, const std::string& password, const std::string& gender, const std::string& birthday);
	
	/*
	* Sets the current user
	* @ Parameter:
	*       id:        The user id
	*       is_admin:  Whether the user is admin
	*/
	void SetCurrent(const std::string& id, bool is_admin);
	
	/*
	* Creates UserInterface
	*/
	void SetUserInterface();
	
	/*
	* Creates AdminInterface
	*/
	void SetAdminInterface();
	
	/*
	* Adds new admin for testing
	* @ Parameter:
	*       id:        The admin id
	*       name:      The admin name
	*       password:  The admin password
	*       gender:    The admin gender
	*       birthday:  The admin birthday
	*/
	void TestOnlyAddAdmin(const std::string& id, const std::string& name, const std::string& password, const std::string& gender, const std::string& birthday);
};


class User
{
private:
	// The user id
	std::string id_;
	// The user name
	std::string name_;
	// The user password
	std::string password_;
	// The user gender
	std::string gender_;
	// The user birthday
	std::string birthday_;
	// Whether the user is verified
	bool verified_;
	// The reading progress of the user
	std::map<std::string, std::tuple<Book*, int, int> > read_progress_;
	
	/*
	* Friend method
	*/
	friend void AdminInterface::SetVerification(User* u);
	
	/*
	* Friend method
	*/
	friend void OnlineBookReader::TestInit();

public:
	User(std::string i = "N/A", std::string n = "N/A", std::string p = "N/A", std::string g = "N/A", std::string b = "N/A");
	~User();
	
	/*
	* Verifies whether the password is correct
	* @ Parameter:
	*       password:  The password
	* @ Return:
	*                  Whether the password is correct
	*/
	bool VerifyPassword(const std::string& password) const;
	
	/*
	* Gets the user name
	* @ Return:
	*                  The user name
	*/
	std::string GetUserName() const;
	
	/*
	* Gets the verification flag
	* @ Return:
	*                  The verification flag
	*/
	bool GetVerification() const;
	
	/*
	* Views profile
	*/
	void ViewProfile() const;
	
	/*
	* Lists the reading progress
	*/
	void ListReadingProgress() const;
	
	/*
	* Gets the reading progress
	* @ Return:
	*                  The reading progress
	*/
	const std::map<std::string, std::tuple<Book*, int, int> >& GetReadingProgress() const;
	
	/*
	* Sets the reading progress
	* @ Parameter:
	*       id:        The book id
	*       plus:      Means next page
	*/
	void SetReadingProgress(const std::string& id, bool plus);
	
	/*
	* Verifies whether the password is correct
	* @ Parameter:
	*       id:        The book id
	*       page:      Which page to jump to
	*/
	void JumpToPage(const std::string& id, int page);
	
	/*
	* Removes one book's reading progress
	* @ Parameter:
	*       id:        The book id
	*/
	void RemoveBook(const std::string& id);
};


class BookManager
{
private:
	// The book database
	std::map<std::string, Book*> books_;
	
	/*
	* Clears the space
	*/
	void Clear();
	
	/*
	* Friend method
	*/
	friend void OnlineBookReader::TestInit();

public:
	BookManager();
	~BookManager();
	
	/*
	* Lists the books
	*/
	void ListBooks() const;

	/*
	* Searches a book
	*/
	void SearchBook() const;
	
	/*
	* Adds a book
	*/
	void AddBook();
	
	/*
	* Edits a book
	*/
	void EditBook();
	
	/*
	* Deletes a book
	*/
	void DeleteBook();
};


class Book
{
private:
	// The book id
	std::string id_;
	// The book name
	std::string name_;
	// The book author
	std::string author_;
	// The page number
	int page_;
	// The session number
	int session_;
	// Stores the start page and end page of each session
	std::vector<std::pair<int, int> > session_page_;
	// Stores the readers who read this book
	std::map<std::string, User*> read_by_;
	
	/*
	* Friend method
	*/
	friend void BookManager::EditBook();
	
	/*
	* Friend method
	*/
	friend void BookManager::DeleteBook();

public:
	Book(std::string i = "N/A", std::string n = "N/A", std::string a = "N/A", int p = 0, int s = 0);
	~Book();
	
	/*
	* Gets the book id
	* @ Return:
	*                  The book id
	*/
	std::string GetID() const;
	
	/*
	* Gets the book name
	* @ Return:
	*                  The book name
	*/
	std::string GetName() const;
	
	/*
	* Gets the book author
	* @ Return:
	*                  The book author
	*/
	std::string GetAuthor() const;
	
	/*
	* Gets the book page number
	* @ Return:
	*                  The book page number
	*/
	int GetPage() const;
	
	/*
	* Gets the book session number
	* @ Return:
	*                  The book session number
	*/
	int GetSession() const;
	
	/*
	* Gets the session corresponding to the page
	* @ Parameter:
	*       page:      The page
	* @ Return:
	*                  The session
	*/
	int GetWhichSession(int page) const;
	
	/*
	* Gets the upper bound page corresponding to the session
	* @ Parameter:
	*       session:   The session
	* @ Return:
	*                  The upper bound page
	*/
	int GetUpperBound(int session) const;
	
	/*
	* Gets the lower bound page corresponding to the session
	* @ Parameter:
	*       session:   The session
	* @ Return:
	*                  The lower bound page
	*/
	int GetLowerBound(int session) const;
};


