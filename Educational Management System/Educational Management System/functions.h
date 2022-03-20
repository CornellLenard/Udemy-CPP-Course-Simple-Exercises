/*********************************************************************************

  * FileName:       functions.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the functions
  * Project:        The fourth project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#pragma once


#include <iostream>


/*
* Initializes the system
*/
void Initialize();

/*
* Login interface
*/
void LoginSystem();

/*
* Logins
*/
void Login();

/*
* Signs up
*/
void SignUp();

/*
* If the login user is a student, then enter student system
*/
void StudentSystem();

/*
* Student registers courses
*/
void StudentRegisCourse();

/*
* Lists the courses that the student has elected
*/
void StudentListCourse();

/*
* Student views a course
*/
void StudentViewCourse();

/*
* Student unregisters courses
* @ Parameter:
*       course_id: The id of the course that the student wants to unregister
*/
void Unregister(const std::string& course_id);

/*
* Student submits solutions
* @ Parameter:
*       course_id: The id of the course that the student wants to submit solutions for
*/
void SubmitSolution(const std::string& course_id);

/*
* Displays the grade report of the student
*/
void StudentGradeReport();

/*
* If the login user is a lecturer, then enter the lecturer system
*/
void LecturerSystem();

/*
* Lists the courses that the lecturer has taught
*/
void LecturerListCourse();

/*
* Lecturer creates a new course
*/
void LecturerCreateCourse();

/*
* Lecturer views a course
*/
void LecturerViewCourse();

/*
* Lecturer lists the assignments
* @ Parameter:
*       course_id: The id of the course
*/
void LecturerListAssignment(const std::string& course_id);

/*
* Lecturer creates new assignments
* @ Parameter:
*       course_id: The id of the course
*/
void LecturerCreateAssignment(const std::string& course_id);

/*
* Lecturer views assignments
* @ Parameter:
*       course_id: The id of the course
*/
void LecturerViewAssignment(const std::string& course_id);

/*
* Lecturer views the solutions of the students
* @ Parameter:
*       course_id: The id of the course
*/
void LecturerListViewSolution(const std::string& course_id);


