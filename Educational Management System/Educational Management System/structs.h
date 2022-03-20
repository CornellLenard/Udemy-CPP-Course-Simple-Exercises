/*********************************************************************************

  * FileName:       structs.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the structs
  * Project:        The fourth project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#pragma once


#include <iostream>
#include <vector>
#include <list>
#include <map>


struct StudentInfo
{
	std::string password;
	std::string name;
	std::string email;
	std::list<std::string> my_course;
};


struct LecturerInfo
{
	std::string password;
	std::string name;
	std::string email;
	std::list<std::string> my_course;
};


struct Assignment
{
	bool submitted;
	std::string solution;
	std::string grade;
	std::string comment;
};


struct CourseInfo
{
	std::string name;
	std::string taught_by;
	int assignment_num;
	std::vector<std::string> assignments;
	std::map<std::string, std::vector<Assignment>> assignment_list;
};


