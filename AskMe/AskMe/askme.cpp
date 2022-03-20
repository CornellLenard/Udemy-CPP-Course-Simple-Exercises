/*********************************************************************************

  * FileName:       askme.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the AskMe
  * Project:        The third project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


// The third project: a file-based forum, use non-OOP and implement in a single file according to the course progress
// No STL


#include <iostream>
#include <fstream>
#include <string>


// Stores the current user id
std::string user_id = "";
// Whether current user allows anonymous asking
int allow = 0;


/*
* Logins
* @ Return:
*                  Whether the user and password are correct
*/
bool Login();

/*
* Verifies whether the password is correct
* @ Parameter:
*       user_name: The user name
*       password:  The password
*       line:      One line from file
* @ Return:
*                  Whether the password is correct
*/
bool Verify(const std::string& user_name, const std::string& password, const std::string& line);

/*
* Reads one line from file, gets the indices of every ',' in this line and fills them into the ar[]
* @ Parameter:
*       ar[]:      The array that stores the ','
*       line:      One line from file
*       size:      How many ',' to read
*/
void GetIndex(int ar[], const std::string& line, int size = 3);

/*
* Signs up
*/
void SignUp();

/*
* Prints the questions to me
* Needs to judge whether the asked person is the current user
* This project allows thread questions, so it is necessary to print with different formats
*/
void PrintQuestionsToMe();

/*
* Prints the questions from me
*/
void PrintQuestionsFromMe();

/*
* Answers questions
*/
void AnswerQuestion();

/*
* Deletes questions
* If the question is thread question, then deletes itself
* Else, deletes itself and all the thread questions belong to it
*/
void DeleteQuestion();

/*
* Asks questions
* Classifies the situations according to whether the question is anonymous and is thread questiond question
*/
void AskQuestion();

/*
* Lists the users
*/
void ListSystemUsers();

/*
* The fees functionality of forum
*/
void Feed();


void AskMeSystem()
{
	std::cout << "Menu:\n\t1: Login\n\t2: Sign Up\n";
	int choice = 0;

	while (true)
	{
		std::cout << "\nEnter number in range 1 - 2: ";
		std::cin >> choice;
		if (choice == 1)
		{
			if (Login() == true)
				break;
			else
				std::cout << "ERROR: Wrong user name and password!\n";
		}
		else
		{
			SignUp();
			break;
		}
	}

	std::cout << "\nMenu:\n";
	std::cout << "\t1: Print Questions To Me\n";
	std::cout << "\t2: Print Questions From Me\n";
	std::cout << "\t3: Answer Question\n";
	std::cout << "\t4: Delete Question\n";
	std::cout << "\t5: Ask Question\n";
	std::cout << "\t6: List System Users\n";
	std::cout << "\t7: Feed\n";
	std::cout << "\t8: Logout\n";

	while (true)
	{
		std::cout << "\nEnter number in range 1 - 8: ";
		std::cin >> choice;
		switch (choice)
		{
			case 1: PrintQuestionsToMe(); break;
			case 2: PrintQuestionsFromMe(); break;
			case 3: AnswerQuestion(); break;
			case 4: DeleteQuestion(); break;
			case 5: AskQuestion(); break;
			case 6: ListSystemUsers(); break;
			case 7: Feed(); break;
			case 8: return;
			default: std::cout << "ERROR: Invalid number...Try again!\n";
		}
	}
}


bool Login()
{
	std::cout << "Enter user name & password: ";
	std::string user_name = "", password = "", line = "";
	std::cin >> user_name >> password;

	// Reads the users file and judges some information
	std::ifstream in("..\\users.txt");

	if (in.is_open() == false)
	{
		std::cout << "ERROR: Can't open this file!\n";
		exit(1);
	}

	while (getline(in, line))
	{
		if (Verify(user_name, password, line) == true)
		{
			in.close();
			return true;
		}
	}

	in.close();
	return false;
}


bool Verify(const std::string& user_name, const std::string& password, const std::string& line)
{
	int ar[5] = { 0,0,0,0,0 };
	GetIndex(ar, line, 5);

	if ((line.substr(ar[0] + 1, ar[1] - ar[0] - 1) == user_name) && (line.substr(ar[1] + 1, ar[2] - ar[1] - 1) == password))
	{
		user_id = line.substr(0, ar[0]);
		allow = (line.substr(ar[4] + 1, 1) == "1") ? 1 : 0;
		return true;
	}
	else
		return false;
}


void GetIndex(int ar[], const std::string& line, int size)
{
	int i = 0, count = 0;
	while (count < size)
	{
		if (line[i] == ',')
		{
			ar[count] = i;
			count++;
		}
		i++;
	}
}


void SignUp()
{
	std::string user_name = "", password = "", name = "", email = "", _allow = "";
	std::cout << "Enter user name. (No spaces): ";
	std::cin >> user_name;
	std::cout << "Enter password: ";
	std::cin >> password;
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter email: ";
	std::cin >> email;
	std::cout << "Allow anonymous quesitons?: (0 or 1) ";
	std::cin >> _allow;

	user_id = std::to_string(rand() % 1000);
	allow = (_allow == "1") ? 1 : 0;
	user_name = user_id + ',' + user_name + ',' + password + ',' + name + ',' + email + ',' + _allow;

	// Uses ios::app in order not to overwrite users
	std::ofstream out("..\\users.txt", std::ios::app);

	if (out.is_open() == false)
	{
		std::cout << "ERROR: Can't open this file!\n";
		exit(1);
	}

	out << std::endl;
	out << user_name;
	out.close();
}


void PrintQuestionsToMe()
{
	std::string line = "";
	int ar[7] = { 0,0,0,0,0,0,0 };
	int is_thread = 0, anonymous_q = 0;
	std::ifstream in("..\\questions.txt");

	if (in.is_open() == false)
	{
		std::cout << "ERROR: Can't open this file!\n";
		exit(1);
	}

	while (getline(in, line))
	{
		GetIndex(ar, line, 7);
		if (line.substr(ar[2] + 1, ar[3] - ar[2] - 1) == user_id)
		{
			anonymous_q = (line.substr(ar[4] + 1, 1) == "0") ? 0 : 1;
			is_thread = (line.substr(ar[0] + 1, ar[1] - ar[0] - 1) == "-1") ? 0 : 1;

			if (allow == 0 && anonymous_q == 1)
				continue;
			std::cout << '\n';

			if (is_thread == 1)
				std::cout << "\tThread: ";
			std::cout << "Question Id (" << line.substr(0, ar[0]) << ") ";

			if (allow + anonymous_q != 2)
				std::cout << "from user id(" << line.substr(ar[1], ar[2] - ar[1] - 1) << ") ";
			std::cout << "\tQuestion: " << line.substr(ar[5] + 1, ar[6] - ar[5] - 1) << '\n';

			if (line.substr(ar[3] + 1, 1) == "1")
			{
				if (is_thread == 1)
					std::cout << "\tThread: ";
				std::cout << "\tAnswer: " << line.substr(ar[6] + 1, 100) << '\n';
			}
		}
	}

	in.close();
}


void PrintQuestionsFromMe()
{
	std::string line = "";
	int ar[7] = { 0,0,0,0,0,0,0 };
	int anonymous_q = 0;
	std::ifstream in("..\\questions.txt");

	if (in.is_open() == false)
	{
		std::cout << "ERROR: Can't open this file~\n";
		exit(1);
	}

	std::cout << '\n';
	while (getline(in, line))
	{
		GetIndex(ar, line, 7);
		if (line.substr(ar[1] + 1, ar[2] - ar[1] - 1) == user_id)
		{
			anonymous_q = (line.substr(ar[4] + 1, 1) == "0") ? 0 : 1;
			std::cout << "Question Id (" << line.substr(0, ar[0]) << ") ";

			if (anonymous_q == 0)
				std::cout << "!AQ ";
			std::cout << "to user id(" << line.substr(ar[2] + 1, ar[3] - ar[2] - 1) << ") \tQuestion: " << line.substr(ar[5] + 1, ar[6] - ar[5] - 1);

			if (line.substr(ar[3] + 1, 1) == "1")
				std::cout << "   Answer: " << line.substr(ar[6] + 1, 100) << '\n';
			else
				std::cout << "   NOT Answered YET\n";
		}
	}

	in.close();
}


void AnswerQuestion()
{
	std::string input_id = "", line = "", answer = "";
	std::cout << "Enter Question id or -1 to cancel: ";
	std::cin >> input_id;

	if (input_id == "-1")
		return;

	bool found = false;
	int ar[7] = { 0,0,0,0,0,0,0 };
	std::ifstream in("..\\questions.txt");

	if (in.is_open() == false)
	{
		std::cout << "ERROR: Can't open this file!\n";
		exit(1);
	}

	while (getline(in, line))
	{
		GetIndex(ar, line, 7);
		if (line.substr(0, ar[0]) == input_id)
		{
			found = true;
			break;
		}
	}

	if (found == false)
	{
		std::cout << "ERROR: Can't find the question!\n";
		return;
	}

	std::cout << "Question Id (" << input_id << ") from user id(" << line.substr(ar[1] + 1, ar[2] - ar[1] - 1);
	std::cout << ")\tQuestion: " << line.substr(ar[5] + 1, ar[6] - ar[5] - 1) << '\n';

	if (line.substr(ar[3] + 1, 1) == "1")
	{
		std::cout << "\tAnswer: " << line.substr(ar[6] + 1, 100) << '\n';
		std::cout << "\nWarning: Already answered. Answer will be updated\n";
	}

	std::cout << "Enter answer: ";
	std::string temp = "";
	std::getline(std::cin, temp);
	std::getline(std::cin, answer);

	if (line.substr(ar[3] + 1, 1) == "1")
		answer = line.substr(0, ar[6] + 1) + answer;
	else
		answer = line.substr(0, ar[3] + 1) + '1' + line.substr(ar[4], line.length() - ar[4]) + answer;

	in.close();
	std::ofstream out("..\\temp.txt", std::ios::out | std::ios::trunc);
	in.open("..\\questions.txt");
	int control_row = 0;

	while (getline(in, line))
	{
		control_row++;
		if (control_row > 1)
			out << std::endl;
		GetIndex(ar, line, 6);
		if (line.substr(0, ar[0]) == input_id)
			out << answer;
		else
			out << line;
	}

	in.close();
	out.close();
	in.open("..\\temp.txt");
	out.open("..\\questions.txt", std::ios::out | std::ios::trunc);
	control_row = 0;

	while (getline(in, line))
	{
		control_row++;
		if (control_row > 1)
			out << std::endl;
		out << line;
	}

	in.close();
	out.close();
}


void DeleteQuestion()
{
	std::string input_id = "", line = "";
	int ar[7] = { 0,0,0,0,0,0,0 };
	int flag = 0;
	std::cout << "Enter Question id or -1 to cancel: ";
	std::cin >> input_id;
	if (input_id == "-1")
		return;
	std::ifstream in("..\\questions.txt");

	if (in.is_open() == false)
	{
		std::cout << "ERROR: Can't open this file!\n";
		exit(1);
	}

	while (getline(in, line))
	{
		GetIndex(ar, line, 7);
		// If this question is raised by the current user or raised to the current user, then it could be deleted, else returns
		if (line.substr(0, ar[0]) == input_id)
		{
			if (line.substr(ar[1] + 1, ar[2] - ar[1] - 1) != user_id && line.substr(ar[2] + 1, ar[3] - ar[2] - 1) != user_id)
			{
				std::cout << "ERROR: This question is neither from you nor to you, you can't delete it!\n";
				return;
			}
			flag = (line.substr(ar[0] + 1, ar[1] - ar[0] - 1) == "-1") ? 1 : 2;
			break;
		}
	}

	in.close();
	in.open("..\\questions.txt");
	std::ofstream out("..\\temp.txt", std::ios::out | std::ios::trunc);
	int control_row = 0;

	// Classifies the situations according to whether the question is thread question
	if (flag == 1)
	{
		while (getline(in, line))
		{
			GetIndex(ar, line, 7);
			if ((line.substr(0, ar[0]) == input_id) || (line.substr(ar[0] + 1, ar[1] - ar[0] - 1) == input_id))
				continue;
			else
			{
				control_row++;
				if (control_row > 1)
					out << std::endl;
				out << line;
			}
		}
	}
	else
	{
		while (getline(in, line))
		{
			GetIndex(ar, line, 7);
			if (line.substr(0, ar[0]) == input_id)
				continue;
			else
			{
				control_row++;
				if (control_row > 1)
					out << std::endl;
				out << line;
			}
		}
	}

	in.close();
	out.close();
	in.open("..\\temp.txt");
	out.open("..\\questions.txt", std::ios::out | std::ios::trunc);
	control_row = 0;

	while (getline(in, line))
	{
		control_row++;
		if (control_row > 1)
			out << std::endl;
		out << line;
	}

	in.close();
	out.close();
}


void AskQuestion()
{
	std::string to_id = "", thread = "", question = "", anonymous = "0", line = "";
	int ar[7] = { 0,0,0,0,0,0,0 };
	bool user_allow_anonymous = true;
	std::cout << "Enter User id or -1 to cancel: ";
	std::cin >> to_id;

	if (to_id == "-1")
		return;

	std::cout << "Note: Anonymous questions are ";
	std::ifstream in("..\\users.txt");

	if (in.is_open() == false)
	{
		std::cout << "ERROR: Can't open this file!\n";
		exit(1);
	}

	while (getline(in, line))
	{
		GetIndex(ar, line, 5);
		if (line.substr(0, ar[0]) == to_id)
		{
			if (line.substr(ar[4] + 1, 1) == "0")
			{
				std::cout << "not ";
				user_allow_anonymous = false;
			}
			break;
		}
	}
	in.close();

	if (user_allow_anonymous == true)
	{
		std::cout << "Enter whether this is an anonymous question (Yes: 1   No: 0): ";
		std::cin >> anonymous;
	}

	std::cout << "allowed for this user\nFor thread question: Enter Question id or -1 for new question: ";
	std::cin >> thread;
	std::cout << "Enter question text: ";
	// Uses temp and getline() to clear the buffer
	std::string temp = "";
	std::getline(std::cin, temp);
	std::getline(std::cin, question);

	// If it is not a thread question
	if (thread == "-1")
	{
		std::ofstream out("..\\questions.txt", std::ios::app);
		question = std::to_string(rand() % 1000) + ",-1," + user_id + ',' + to_id + ",0," + anonymous + ',' + question + ',';
		out << std::endl << question;
		out.close();
	}
	else
	{
		question = std::to_string(rand() % 1000) + ',' + thread + ',' + user_id + ',' + to_id + ",0," + anonymous + ',' + question + ',';
		int count = 0;
		in.open("..\\questions.txt");
		std::ofstream out("..\\temp.txt", std::ios::out | std::ios::trunc);

		while (getline(in, line))
		{
			count++;
			if (count > 1)
				out << std::endl;
			GetIndex(ar, line, 7);

			if (line.substr(0, ar[0]) == thread)
			{
				out << line;
				while (true)
				{
					getline(in, line);
					GetIndex(ar, line, 7);
					if (line.substr(ar[0] + 1, ar[1] - ar[0] - 1) == thread)
						out << std::endl << line;
					else
					{
						out << std::endl << line << std::endl << question;
						break;
					}
				}
			}
			else
				out << line;
		}

		in.close();
		out.close();
		in.open("..\\temp.txt");
		out.open("..\\questions.txt", std::ios::out | std::ios::trunc);
		count = 0;

		while (getline(in, line))
		{
			count++;
			if (count > 1)
				out << std::endl;
			out << line;
		}

		in.close();
		out.close();
	}
}


void ListSystemUsers()
{
	std::ifstream in("..\\users.txt");
	if (in.is_open() == false)
	{
		std::cout << "ERROR: Can't open this file!\n";
		exit(1);
	}
	std::string line = "";
	int ar[4] = { 0,0,0,0 };

	while (getline(in, line))
	{
		GetIndex(ar, line, 4);
		std::cout << "ID: " << line.substr(0, ar[0]) << "\t\tName: ";
		std::cout << line.substr(ar[2] + 1, ar[3] - ar[2] - 1) << '\n';
	}

	in.close();
}


void Feed()
{
	std::string line = "";
	int ar[7] = { 0,0,0,0,0,0,0 };
	std::ifstream in("..\\questions.txt");

	if (in.is_open() == false)
	{
		std::cout << "ERROR: Can't open this file!\n";
		exit(1);
	}

	while (getline(in, line))
	{
		GetIndex(ar, line, 7);

		if (line.substr(ar[3] + 1, 1) != "1")
			continue;

		if (line.substr(ar[0] + 1, ar[1] - ar[0] - 1) != "-1")
			std::cout << "Thread Parent Question ID (" << line.substr(ar[0] + 1, ar[1] - ar[0] - 1) << ") ";
		std::cout << "Question Id (" << line.substr(0, ar[0]) << ") ";

		if (line.substr(ar[4] + 1, 1) == "0")
			std::cout << "from user id(" << line.substr(ar[1] + 1, ar[2] - ar[1] - 1) << ") ";
		std::cout << "To user id(" << line.substr(ar[2] + 1, ar[3] - ar[2] - 1) << ") \tQuestion: " << line.substr(ar[5] + 1, ar[6] - ar[5] - 1);
		std::cout << "\n\tAnswer: " << line.substr(ar[6] + 1, 100) << '\n';
	}

	in.close();
}


int main()
{
	while (true)
	{
		AskMeSystem();
		std::cout << '\n';
	}
	return 0;
}


