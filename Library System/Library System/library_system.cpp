/*********************************************************************************

  * FileName:       library_system.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the Library System
  * Project:        The second project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


// The second project, use non-OOP and implement in a single cpp file according to the progress of the course
// No STL except algorithm


#include <iostream>
#include <algorithm>


// The struct of book
struct Book
{
	int id;
	std::string name;
	int quantity;
	// How many people are borrowing
	int borrowed;
	// Stores the ids of the people who are borrowing the book
	int borrowed_by_id[10];
};


// The struct of user
struct User
{
	int id;
	std::string name;
	// How many books the user has borrowed
	int borrowed;
	// Stores the ids of the books that the user has borrowed
	int borrowed_id[10];
};


// Stores the books
Book books[10000];
// Stores the users
User users[5000];
// Stores the sizes of the books and users
int book_size = 0, user_size = 0;


/*
* Gets the user's index in the users with the user's name
* @ Parameter:
*       user_name: The user name
* @ Return:
*                  The index
*/
int GetUserIndex(const std::string& user_name);

/*
* Gets the book's index in the books with the book's name
* @ Parameter:
*       book_name: The book name
* @ Return:
*                  The index
*/
int GetBookIndex(const std::string& book_name);

/*
* Gets the user's index in the users with the user's id
* @ Parameter:
*       id:        The user id
* @ Return:
*                  The index
*/
int GetUserIndexById(int id);

/*
* Adds a new book
*/
void AddBook();

/*
* Searches a book with prefix
*/
void SearchBooksByPrefix();

/*
* Judges whether s2 is a prefix of s1
* @ Parameter:
*       s1:        The string s1
*       s2:        The string s2
* @ Return:
*                  Whether s2 is a prefix of s1
*/
bool JudgePrefix(const std::string& s1, const std::string& s2);

/*
* Prints the users who borrow a certain book
*/
void PrintWhoBorrowedBookByName();

/*
* Prints the books by the order of id
*/
void PrintLibraryById();

/*
* Compares the books by id
* @ Parameter:
*       b1:        The book 1
*       b2:        The book 2
* @ Return:
*                  True if b1 < b2, else false
*/
bool CompareById(const Book& b1, const Book& b2);

/*
* Prints the books by the order of name
*/
void PrintLibraryByName();

/*
* Compares the books by name
* @ Parameter:
*       b1:        The book 1
*       b2:        The book 2
* @ Return:
*                  True if b1 < b2, else false
*/
bool CompareByName(const Book& b1, const Book& b2);

/*
* Adds a new user
*/
void AddUser();

/*
* User borrows a book
*/
void UserBorrowBook();

/*
* User returns a book
*/
void UserReturnBook();

/*
* Prints users
*/
void PrintUsers();


void LibrarySystem()
{
	std::cout << "Library Menu:\n";
	std::cout << "1) add_book\n";
	std::cout << "2) search_books_by_prefix\n";
	std::cout << "3) print_who_borrowed_book_by_name\n";
	std::cout << "4) print_library_by_id\n";
	std::cout << "5) print_library_by_name\n";
	std::cout << "6) add_user\n";
	std::cout << "7) user_borrow_book\n";
	std::cout << "8) user_return_book\n";
	std::cout << "9) print_users\n";
	std::cout << "10) Exit\n";
	int choice = 0;

	while (true)
	{
		std::cout << "\nEnter your menu choice [1 - 10]: ";
		std::cin >> choice;
		switch (choice)
		{
			case 1: AddBook(); break;
			case 2: SearchBooksByPrefix(); break;
			case 3: PrintWhoBorrowedBookByName(); break;
			case 4: PrintLibraryById(); break;
			case 5: PrintLibraryByName(); break;
			case 6: AddUser(); break;
			case 7: UserBorrowBook(); break;
			case 8: UserReturnBook(); break;
			case 9: PrintUsers(); break;
			case 10: return;
			default: std::cout << "ERROR: Wrong choice!\n";
		}
	}
}


int GetUserIndex(const std::string& user_name)
{
	for (int i = 0; i < user_size; i++)
	{
		if (users[i].name == user_name)
			return i;
	}
	return -1;
}


int GetBookIndex(const std::string& book_name)
{
	for (int i = 0; i < book_size; i++)
	{
		if (books[i].name == book_name)
			return i;
	}
	return -1;
}


int GetUserIndexById(int id)
{
	for (int i = 0; i < user_size; i++)
	{
		if (users[i].id == id)
			return i;
	}
	return -1;
}


void AddBook()
{
	std::cout << "Enter book info: id & name & total quantity: ";
	std::cin >> books[book_size].id >> books[book_size].name >> books[book_size].quantity;
	book_size++;
}


void SearchBooksByPrefix()
{
	std::cout << "Enter book name prefix: ";
	std::string name = "";
	bool judge = false;
	std::cin >> name;

	for (int i = 0; i < book_size; i++)
	{
		if (JudgePrefix(books[i].name, name) == true)
		{
			judge = true;
			std::cout << books[i].name << '\n';
		}
	}

	if (judge == false)
		std::cout << "No books with such prefix\n";
}


bool JudgePrefix(const std::string& s1, const std::string& s2)
{
	for (int i = 0; i < s2.length(); i++)
	{
		if (s1[i] != s2[i])
			return false;
	}
	return true;
}


void PrintWhoBorrowedBookByName()
{
	std::cout << "Enter book name: ";
	std::string book_name = "";
	std::cin >> book_name;
	int book_index = GetBookIndex(book_name);

	if (book_index == -1)
	{
		std::cout << "ERROR: Invalid book name!\n";
		return;
	}

	int user_index = 0;
	for (int i = 0; i < books[book_index].borrowed; i++)
	{
		user_index = GetUserIndexById(books[book_index].borrowed_by_id[i]);
		std::cout << users[user_index].name << '\n';
	}
}


void PrintLibraryById()
{
	std::sort(books, books + book_size, CompareById);
	for (int i = 0; i < book_size; i++)
	{
		std::cout << "id = " << books[i].id << " name = " << books[i].name;
		std::cout << " total_quantity " << books[i].quantity << " total_borrowed " << books[i].borrowed << '\n';
	}
}


bool CompareById(const Book& b1, const Book& b2)
{
	return b1.id < b2.id;
}


void PrintLibraryByName()
{
	std::sort(books, books + book_size, CompareByName);
	for (int i = 0; i < book_size; i++)
	{
		std::cout << "id = " << books[i].id << " name = " << books[i].name;
		std::cout << " total_quantity " << books[i].quantity << " total_borrowed " << books[i].borrowed << '\n';
	}
}


bool CompareByName(const Book& b1, const Book& b2)
{
	return b1.name <= b2.name;
}


void AddUser()
{
	std::cout << "Enter user name & national id: ";
	std::cin >> users[user_size].name >> users[user_size].id;
	user_size++;
}


void UserBorrowBook()
{
	std::cout << "Enter user name and book name: ";
	std::string user_name = "", book_name = "";
	std::cin >> user_name >> book_name;

	int user_index = GetUserIndex(user_name);
	int book_index = GetBookIndex(book_name);

	books[book_index].quantity--;
	books[book_index].borrowed_by_id[books[book_index].borrowed] = users[user_index].id;
	books[book_index].borrowed++;
	users[user_index].borrowed_id[users[user_index].borrowed] = books[book_index].id;
	users[user_index].borrowed++;
}


void UserReturnBook()
{
	std::cout << "Enter user name and book name: ";
	std::string user_name = "", book_name = "";
	std::cin >> user_name >> book_name;

	int user_index = GetUserIndex(user_name);
	int book_index = GetBookIndex(book_name);

	int user_id = users[user_index].id;
	int book_id = books[book_index].id;
	books[book_index].quantity++;
	int loc = 0;

	for (loc; loc < books[book_index].borrowed; loc++)
		if (books[book_index].borrowed_by_id[loc] == user_id)
			break;

	for (int i = loc; i < books[book_index].borrowed - 1; i++)
		books[book_index].borrowed_by_id[i] = books[book_index].borrowed_by_id[i + 1];

	books[book_index].borrowed--;

	for (loc = 0; loc < users[user_index].borrowed; loc++)
		if (users[user_index].borrowed_id[loc] == book_id)
			break;

	for (int i = loc; i < users[user_index].borrowed; i++)
		users[user_index].borrowed_id[i] = users[user_index].borrowed_id[i + 1];

	users[user_index].borrowed--;
}


void PrintUsers()
{
	for (int i = 0; i < user_size; i++)
	{
		std::cout << "user " << users[i].name << " id " << users[i].id;
		std::cout << " borrowed books ids: ";
		for (int j = 0; j < users[i].borrowed; j++)
			std::cout << users[i].borrowed_id[j] << ' ';
		std::cout << '\n';
	}
}


int main()
{
	LibrarySystem();
	return 0;
}


