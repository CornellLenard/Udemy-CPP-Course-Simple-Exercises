/*********************************************************************************

  * FileName:       askme.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class AskMe
  * Project:        The fifth project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#pragma once


#include <iostream>


class AskMe
{
private:
	std::string user_id_;
	int allow_;
	bool Login();
	bool Verify(const std::string& user_name, const std::string& password, const std::string& line);
	void SignUp();
	void PrintQuestionsToMe() const;
	void GetIndex(int ar[], const std::string& line, int size = 3) const;
	void PrintQuestionsFromMe() const;
	void AnswerQuestion() const;
	void DeleteQuestion() const;
	void AskQuestion() const;
	void ListSystemUsers() const;
	void Feed() const;
public:
	AskMe();
	~AskMe();
	void AskMeSystem();
};


