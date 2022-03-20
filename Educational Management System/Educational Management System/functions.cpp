/*********************************************************************************

  * FileName:       functions.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the functions
  * Project:        The fourth project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include <string>
#include "structs.h"
#include "functions.h"


// The id of the current user
std::string id = "";
std::map<std::string, StudentInfo> stu_account;
std::map<std::string, LecturerInfo> lec_account;
std::map<std::string, CourseInfo> course;


void Initialize()
{
	StudentInfo si1, si2;
	si1.email = "lenard@gmail.com";
	si1.name = "lenard";
	si1.password = "s001";
	si1.my_course.push_back("CS111");
	si1.my_course.push_back("CS112");
	si1.my_course.push_back("CS123");
	si1.my_course.push_back("CS333");
	si1.my_course.push_back("CS136");
	si1.my_course.push_back("CS240");
	si1.my_course.push_back("CS350");
	stu_account["s001"] = si1;
	si2.email = "zh@gamil.com";
	si2.name = "zh";
	si2.password = "s002";
	si2.my_course.push_back("CS111");
	si2.my_course.push_back("CS112");
	si2.my_course.push_back("CS123");
	si2.my_course.push_back("CS333");
	si2.my_course.push_back("CS136");
	si2.my_course.push_back("CS240");
	si2.my_course.push_back("CS350");
	stu_account["s002"] = si2;
	LecturerInfo li;
	li.email = "mostafa@gmail.com";
	li.name = "mostafa";
	li.password = "l001";
	li.my_course.push_back("CS111");
	lec_account["l001"] = li;
	CourseInfo ci;
	ci.assignments.push_back("aaa");
	ci.assignments.push_back("bbb");
	ci.assignments.push_back("ccc");
	ci.assignment_num = 3;
	ci.name = "Prog 1";
	ci.taught_by = "l001";
	Assignment ass1, ass2, ass3;
	ass1.comment = "good"; ass2.comment = "good"; ass3.comment = "good";
	ass1.grade = "15"; ass2.grade = "20"; ass3.grade = "35";
	ass1.solution = "a"; ass2.solution = "b"; ass3.solution = "c";
	ass1.submitted = true; ass2.submitted = true; ass3.submitted = true;
	std::vector<Assignment> vec;
	vec.push_back(ass1); vec.push_back(ass2); vec.push_back(ass3);
	ci.assignment_list["s001"] = vec;
	Assignment ass4, ass5, ass6;
	ass4.comment = "good"; ass5.comment = "fair"; ass6.comment = "bad";
	ass4.grade = "15"; ass5.grade = "5"; ass6.grade = "0";
	ass4.solution = "a"; ass5.solution = "e"; ass6.solution = "";
	ass4.submitted = true; ass5.submitted = true; ass6.submitted = false;
	std::vector<Assignment> vec2;
	vec2.push_back(ass4); vec2.push_back(ass5); vec2.push_back(ass6);
	ci.assignment_list["s002"] = vec2;
	course["CS111"] = ci;
	ci.taught_by = "?";
	ci.name = "Prog 2";
	course["CS112"] = ci;
	ci.name = "Math 1";
	course["CS123"] = ci;
	ci.name = "Math 2";
	course["CS333"] = ci;
	ci.name = "Prog 3";
	course["CS136"] = ci;
	ci.name = "Stat 1";
	course["CS240"] = ci;
	ci.name = "Stat 2";
	course["CS350"] = ci;
	CourseInfo ci2;
	ci2.assignments.push_back("aaa");
	ci2.assignments.push_back("bbb");
	ci2.assignments.push_back("ccc");
	ci2.assignment_num = 3;
	ci2.name = "Stat 3";
	ci2.taught_by = "?";
	course["CS351"] = ci2;
}


void LoginSystem()
{
	int choice = 0;
	while (true)
	{
		std::cout << "Please make a choice:\n";
		std::cout << "\t1 - Login\n\t2 - Sign up\n\t3 - Shutdown system\n";

		while (true)
		{
			std::cout << "\tEnter Choice: ";
			std::cin >> choice;
			if (choice < 1 || choice > 3)
				std::cout << "ERROR: Wrong choice! Please enter again!\n";
			else
				break;
		}

		switch (choice)
		{
			case 1: Login(); break;
			case 2: SignUp(); break;
			case 3: return;
		}

		std::cout << '\n';
	}
}


void Login()
{
	std::string user_name = "", password = "";
	while (true)
	{
		std::cout << "\nPlease enter user name and password:\nUser Name: ";
		std::cin >> user_name;
		std::cout << "Password: ";
		std::cin >> password;

		// If the first digit of the id is 's', then this is a student
		if (user_name[0] == 's')
		{
			std::map<std::string, StudentInfo>::iterator p = stu_account.find(user_name);
			if (p == stu_account.end())
				std::cout << "ERROR: No such student! Please enter again!\n";
			else if ((*p).second.password != password)
				std::cout << "ERROR: Wrong password! Please enter again!\n";
			else
				break;
		}
		else if (user_name[0] == 'l')
		{
			std::map<std::string, LecturerInfo>::iterator p = lec_account.find(user_name);
			if (p == lec_account.end())
				std::cout << "ERROR: No such lecturer! Please enter again!\n";
			else if ((*p).second.password != password)
				std::cout << "ERROR: Wrong password! Please enter again!\n";
			else
				break;
		}
		else
			std::cout << "ERROR: Wrong user id format! Please enter again!\n";
	}
	// Sets the current user id
	id = user_name;
	(user_name[0] == 's') ? (StudentSystem()) : (LecturerSystem());
}


void SignUp()
{
	std::string _id = "", password = "", name = "", email = "";

	while (true)
	{
		std::cout << "Please enter your id: ";
		std::cin >> _id;
		if (_id[0] != 's' && _id[0] != 'd')
			std::cout << "ERROR: Wrong format! Please enter again!\n";
		else
			break;
	}

	std::cout << "Please enter your password: ";
	std::cin >> password;
	std::cout << "Please enter your name: ";
	std::cin >> name;
	std::cout << "Please enter your email: ";
	std::cin >> email;
	id = _id;

	if (_id[0] == 's')
	{
		StudentInfo si;
		si.email = email;
		si.name = name;
		si.password = password;
		stu_account[id] = si;
		StudentSystem();
	}
	else
	{
		LecturerInfo li;
		li.email = email;
		li.name = name;
		li.password = password;
		lec_account[id] = li;
		LecturerSystem();
	}
}


void StudentSystem()
{
	std::cout << "\nWelcome " << stu_account[id].name << ". You are logged in\n";
	int choice = 0;
	while (true)
	{
		std::cout << "\n\nPlease make a choice:\n";
		std::cout << "\t1 - Register in Course\n";
		std::cout << "\t2 - List My Courses\n";
		std::cout << "\t3 - View Course\n";
		std::cout << "\t4 - Grades Report\n";
		std::cout << "\t5 - Log out\n";

		while (true)
		{
			std::cout << "\tEnter Choice: ";
			std::cin >> choice;
			if (choice < 1 || choice > 5)
				std::cout << "ERROR: Wrong choice! Please enter again!\n";
			else
				break;
		}

		switch (choice)
		{
			case 1: StudentRegisCourse(); break;
			case 2: StudentListCourse(); break;
			case 3: StudentViewCourse(); break;
			case 4: StudentGradeReport(); break;
			case 5: return;
		}
	}
}


void StudentRegisCourse()
{
	std::string input_course = "";

	while (true)
	{
		std::cout << "Please enter the course id: ";
		std::cin >> input_course;
		if (course.find(input_course) == course.end())
			std::cout << "ERROR: can't find the course! Please enter again!\n";
		else
			break;
	}

	stu_account[id].my_course.push_back(input_course);
	course[input_course].assignment_list[id] = std::vector<Assignment>();
	Assignment ass;
	ass.comment = "N/A";
	ass.grade = "N/A";
	ass.solution = "";
	ass.submitted = false;

	for (int i = 0; i < course[input_course].assignment_num; i++)
		course[input_course].assignment_list[id].push_back(ass);
}


void StudentListCourse()
{
	std::list<std::string>& lst = stu_account[id].my_course;
	std::list<std::string>::const_iterator p = lst.begin();
	int count = 1;
	std::cout << "\n\nMy Courses list:\n";
	for (p; p != lst.end(); p++)
		std::cout << count++ << ") Course " << course[*p].name << " - Code " << *p << '\n';
}


void StudentViewCourse()
{
	std::cout << "\n\nMy Courses list:\n";
	int count = 1;
	std::list<std::string>& lst = stu_account[id].my_course;
	std::list<std::string>::const_iterator p = lst.begin();

	for (p; p != lst.end(); p++)
		std::cout << count++ << ") Course " << course[*p].name << " - Code " << *p << '\n';

	int choice = 0;

	while (true)
	{
		std::cout << "\nWhich ith [1 - " << count - 1 << "] course to view? ";
		std::cin >> choice;
		if (choice < 1 || choice >= count)
			std::cout << "ERROR: Wrong choice! Please enter again!\n";
		else
			break;
	}

	p = lst.begin();
	while (choice > 1)
	{
		p++;
		choice--;
	}

	std::vector<Assignment>& vec = course[*p].assignment_list[id];
	std::cout << "\nCourse " << course[*p].name << " with Code " << *p << " - taught by Doctor " << lec_account[course[*p].taught_by].name << '\n';
	std::cout << "Course has " << vec.size() << " assignment\n";

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << "Assignment " << i + 1 << " ";
		if (vec[i].submitted == false)
			std::cout << "NOT ";
		std::cout << "submitted - " << vec[i].grade << '\n';
	}

	while (true)
	{
		std::cout << "\n\nPlease make a choice:\n";
		std::cout << "\t1 - UnRegister from Course\n\t2 - Submit solution\n\t3 - Back\n";
		choice = 0;

		while (true)
		{
			std::cout << "\tEnter Choice: ";
			std::cin >> choice;
			if (choice < 1 || choice > 3)
				std::cout << "ERROR: Wrong choice! Please enter again!\n";
			else
				break;
		}

		switch (choice)
		{
			case 1: Unregister(*p); return;
			case 2: SubmitSolution(*p); break;
			case 3: return;
		}
	}
}


void Unregister(const std::string& course_id)
{
	// Erases the row corresponding to the student in the assignment_list
	course[course_id].assignment_list.erase(course[course_id].assignment_list.find(id));
	std::list<std::string>& lst = stu_account[id].my_course;
	std::list<std::string>::iterator p = lst.begin();

	// Erases the course from the student's course list
	for (p; p != lst.end(); p++)
	{
		if (*p == course_id)
		{
			lst.erase(p);
			break;
		}
	}
}


void SubmitSolution(const std::string& course_id)
{
	std::vector<Assignment>& vec = course[course_id].assignment_list[id];
	int choice = 0;
	std::string solution = "";
	std::cout << '\n';

	while (true)
	{
		std::cout << "Which ith [1 - " << vec.size() << "] assignment to submit? ";
		std::cin >> choice;
		if (choice < 1 || choice > vec.size())
			std::cout << "ERROR: Wrong choice! Please enter again!\n";
		else
			break;
	}

	std::cout << "Enter the solution (no space)\n";
	std::cin >> solution;
	vec[choice - 1].submitted = true;
	vec[choice - 1].solution = solution;
}


void StudentGradeReport()
{
	std::list<std::string>& lst = stu_account[id].my_course;
	std::list<std::string>::const_iterator p = lst.begin();
	int count = 0, count_grade = 0;
	std::cout << '\n';

	while (p != lst.end())
	{
		count = 0, count_grade = 0;
		std::vector<Assignment>& vec = course[*p].assignment_list[id];
		std::cout << "Course code " << *p << " - Total submitted ";

		for (int j = 0; j < vec.size(); j++)
		{
			if (vec[j].submitted == true)
			{
				count++;
				count_grade += stoi(vec[j].grade);
			}
		}

		std::cout << count << " assignments - Grade " << count_grade << '\n';
		p++;
	}
}


void LecturerSystem()
{
	std::cout << "\nWelcome Doctor " << lec_account[id].name << ". You are logged in\n";
	while (true)
	{
		std::cout << "\n\nPlease make a choice:\n";
		std::cout << "\t1 - List My Courses\n";
		std::cout << "\t2 - Create Course\n";
		std::cout << "\t3 - View Course\n";
		std::cout << "\t4 - Log out\n";
		int choice = 0;

		while (true)
		{
			std::cout << "\tEnter Choice: ";
			std::cin >> choice;
			if (choice < 1 || choice > 4)
				std::cout << "ERROR: Wrong choice! Please enter again!\n";
			else
				break;
		}

		switch (choice)
		{
			case 1: LecturerListCourse(); break;
			case 2: LecturerCreateCourse(); break;
			case 3: LecturerViewCourse(); break;
			case 4: return;
		}
	}
}


void LecturerListCourse()
{
	std::list<std::string>& lst = lec_account[id].my_course;
	std::list<std::string>::const_iterator p = lst.begin();
	int count = 1;
	std::cout << "\nMy Courses list:\n";
	for (p; p != lst.end(); p++)
		std::cout << count++ << ") Course " << course[*p].name << " - Code " << *p << '\n';
}


void LecturerCreateCourse()
{
	std::string new_id = "", new_name = "";
	int number = 0;
	std::cout << "Please enter the new course code: ";
	std::cin >> new_id;
	std::cout << "Please enter the new course name: ";
	std::cin >> new_name;
	std::cout << "Please enter the number of assignments: ";
	std::cin >> number;
	CourseInfo ci;
	ci.assignment_num = number;
	ci.name = new_name;
	ci.taught_by = id;
	course[new_id] = ci;
}


void LecturerViewCourse()
{
	std::cout << "\nMy Courses list:\n";
	int count = 1;
	std::list<std::string>& lst = lec_account[id].my_course;
	std::list<std::string>::const_iterator p = lst.begin();

	for (p; p != lst.end(); p++)
		std::cout << count++ << ") Course " << course[*p].name << " - Code " << *p << '\n';

	int choice = 0;
	while (true)
	{
		std::cout << "\nWhich ith [1- " << count - 1 << "] course to view? ";
		std::cin >> choice;
		if (choice < 1 || choice >= count)
			std::cout << "ERROR: Wrong choice! Please enter again!\n";
		else
			break;
	}

	p = lst.begin();
	while (choice > 1)
	{
		p++;
		choice--;
	}
	std::cout << "\nCourse " << course[*p].name << " with Code " << *p << " - taught by Doctor " << course[*p].taught_by << '\n';
	std::cout << "Course has " << course[*p].assignment_num << " assignment\n";

	while (true)
	{
		std::cout << "\n\nPlease make a choice:\n";
		std::cout << "\t1 - List Assignment\n\t2 - Create Assignment\n\t3 - View Assignment\n\t4 - Back\n";
		choice = 0;

		while (true)
		{
			std::cout << "\tEnter Choice: ";
			std::cin >> choice;
			if (choice < 1 || choice > 4)
				std::cout << "ERROR: Wrong choice! Please enter again!\n";
			else
				break;
		}

		switch (choice)
		{
			case 1: LecturerListAssignment(*p); break;
			case 2: LecturerCreateAssignment(*p); break;
			case 3: LecturerViewAssignment(*p); break;
			case 4: return;
		}
	}
}


void LecturerListAssignment(const std::string& course_id)
{
	std::vector<std::string>& vec = course[course_id].assignments;
	std::cout << "\nThe assignments of " << course[course_id].name << " with Code " << course_id << " are as follows:\n";
	for (int i = 0; i < vec.size(); i++)
		std::cout << "Assignment " << i + 1 << ": " << vec[i] << '\n';
}


void LecturerCreateAssignment(const std::string& course_id)                           //创建新作业要记得在作业列表里的每一行都新增一个Assignment
{
	std::string new_assignment = "", temp = "";
	course[course_id].assignment_num++;
	std::cout << "Please enter the new assignment:\n";
	std::getline(std::cin, temp);
	std::getline(std::cin, new_assignment);
	course[course_id].assignments.push_back(new_assignment);

	Assignment ass;
	ass.comment = "N/A";
	ass.grade = "N/A";
	ass.solution = "";
	ass.submitted = false;
	std::map<std::string, std::vector<Assignment> >& mp = course[course_id].assignment_list;
	std::map<std::string, std::vector<Assignment> >::iterator p = mp.begin();
	for (p; p != mp.end(); p++)
		(*p).second.push_back(ass);
}


void LecturerViewAssignment(const std::string& course_id)
{
	std::cout << "\nPlease make a choice:\n";
	std::cout << "\t1 - Print Content\n\t2 - Grades Report\n\t3 - List/View Solutions\n\t4 - Back\n";
	int choice = 0, second_choice = 0;

	while (true)
	{
		std::cout << "\tEnter Choice: ";
		std::cin >> choice;
		if (choice < 1 || choice > 4)
			std::cout << "ERROR: Wrong choice! Please enter again!\n";
		else
			break;
	}

	if (choice == 1)
	{
		while (true)
		{
			std::cout << "\nWhich assignment would you like to check? ";
			std::cin >> second_choice;
			if (second_choice < 1 || second_choice > course[course_id].assignment_num)
				std::cout << "ERROR: Wrong choice! Please enter again!\n";
			else
				break;
		}
		std::cout << "\nThe assignment " << second_choice << " of this course is: " << course[course_id].assignments[second_choice - 1] << '\n';
	}
	else if (choice == 2)
	{
		std::map<std::string, std::vector<Assignment> >& mp = course[course_id].assignment_list;
		std::map<std::string, std::vector<Assignment> >::const_iterator p = mp.begin();
		std::vector<Assignment>::const_iterator pv;
		std::cout << "\nStudent ID";

		for (int i = 0; i < course[course_id].assignment_num; i++)
			std::cout << "\tAssignment " << i + 1;
		std::cout << '\n';

		while (p != mp.end())
		{
			std::cout << (*p).first;
			pv = (*p).second.begin();
			for (pv; pv != (*p).second.end(); pv++)
				std::cout << '\t' << (*pv).grade;
			std::cout << '\n';
			p++;
		}
	}
	else if (choice == 3)
		LecturerListViewSolution(course_id);
	else
		return;
}


void LecturerListViewSolution(const std::string& course_id)
{
	int choice = 0, second_choice = 0;
	std::string student_id = "";

	while (true)
	{
		std::cout << "\tEnter Student ID: ";
		std::cin >> student_id;
		if (course[course_id].assignment_list.find(student_id) == course[course_id].assignment_list.end())
			std::cout << "ERROR: No such student! Please enter again!\n";
		else
			break;
	}

	while (true)
	{
		std::cout << "\tOn which assignment would you like to operate: ";
		std::cin >> choice;
		if (choice < 1 || choice > course[course_id].assignment_num)
			std::cout << "ERROR: Wrong choice! Please enter again!\n";
		else
			break;
	}

	std::cout << "\nPlease make a choice:\n";
	std::cout << "\t1 - Print Content\n\t2 - Set Grade\n\t3 - Set Comment\n\t4 - Back\n";

	while (true)
	{
		std::cout << "\tEnter Choice: ";
		std::cin >> second_choice;
		if (second_choice < 1 || second_choice > 4)
			std::cout << "ERROR: Wrong choice! Please enter again!\n";
		else
			break;
	}

	if (second_choice == 1)
		std::cout << "The solution is: " << course[course_id].assignment_list[student_id][choice - 1].solution << '\n';
	else if (second_choice == 2)
	{
		std::string grade = "";
		std::cout << "Please enter the grade: ";
		std::cin >> grade;
		course[course_id].assignment_list[student_id][choice - 1].grade = grade;
	}
	else if (second_choice == 3)
	{
		std::string comment = "";
		std::cout << "Please enter the comment: ";
		std::cin >> comment;
		course[course_id].assignment_list[student_id][choice - 1].comment = comment;
	}
	else
		return;
}


