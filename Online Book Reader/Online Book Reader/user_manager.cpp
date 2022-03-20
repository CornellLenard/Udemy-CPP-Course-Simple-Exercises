/*********************************************************************************

  * FileName:       user_manager.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class UserManager
  * Project:        The sixth project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


#include "obr_classes.h"


void UserManager::Clear()
{
	std::map<std::string, User*>::iterator pu = users_.begin();

	for (pu; pu != users_.end(); pu++)
	{
		delete pu->second;
		pu->second = nullptr;
	}

	std::map<std::string, Admin*>::iterator pa = admins_.begin();

	for (pa; pa != admins_.end(); pa++)
	{
		delete pa->second;
		pa->second = nullptr;
	}

	users_.clear();
	admins_.clear();
}


UserManager::UserManager(BookManager* bm): bm_(bm)
{
	current_user_ = nullptr;
	current_admin_ = nullptr;
	ui_ = nullptr;
	ai_ = nullptr;
}


UserManager::~UserManager()
{
	Clear();
	current_user_ = nullptr;
	current_admin_ = nullptr;
	if (ui_ != nullptr)
	{
		delete ui_;
		ui_ = nullptr;
	}
	if (ai_ != nullptr)
	{
		delete ai_;
		ai_ = nullptr;
	}
	bm_ = nullptr;
}


bool UserManager::VerifyUserIdPassword(const std::string& id, const std::string& password) const
{
	if (users_.find(id) == users_.end())
		return false;
	if (users_.find(id)->second->VerifyPassword(password) == true)
		return true;
	else
		return false;
}


bool UserManager::VerifyAdminIdPassword(const std::string& id, const std::string& password) const
{
	if (admins_.find(id) == admins_.end())
		return false;
	if (admins_.find(id)->second->VerifyPassword(password) == true)
		return true;
	else
		return false;
}


void UserManager::AddUser(const std::string& id, const std::string& name, const std::string& password, const std::string& gender, const std::string& birthday)
{
	users_.insert(std::map<std::string, User*>::value_type(id, new User(id, name, password, gender, birthday)));
}


void UserManager::SetCurrent(const std::string& id, bool is_admin)
{
	if (is_admin == true)
		current_admin_ = admins_.find(id)->second;
	else
		current_user_ = users_.find(id)->second;
}


void UserManager::SetUserInterface()
{
	ui_ = new UserInterface(this, current_user_, bm_);
}


void UserManager::SetAdminInterface()
{
	ai_ = new AdminInterface(this, current_admin_, bm_);
}


void UserManager::TestOnlyAddAdmin(const std::string& id, const std::string& name, const std::string& password, const std::string& gender, const std::string& birthday)
{
	admins_.insert(std::map<std::string, Admin*>::value_type(id, new Admin(id, name, password, gender, birthday)));
}


