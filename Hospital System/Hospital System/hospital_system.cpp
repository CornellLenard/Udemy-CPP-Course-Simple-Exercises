/*********************************************************************************

  * FileName:       hospital_system.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the Hospital System
  * Project:        The first project of the Udemy course by Dr.Mostafa S. Ibrahim

**********************************************************************************/


// The first project, use non-OOP and implement in a single cpp file according to the progress of the course
// No STL


#include <iostream>


// The 20 queues corresponding to the 20 departments of the hospital
std::string patient_queue[20][5];
// Stores the number of patients in the waiting queue
int queue_size[20];


/*
* Adds a patient
*/
void AddPatient();

/*
* Adds a new patient to the end of the queue
* @ Parameter:
*       specialization: The department number
*       name:           The name of the patient
*/
void AddAtEnd(int specialization, const std::string& name);

/*
* Adds a new patient to the front of the queue
* @ Parameter:
*       specialization: The department number
*       name:           The name of the patient
*/
void AddAtFront(int specialization, const std::string& name);

/*
* Prints the queues of the departments
*/
void PrintPatient();

/*
* Calls the next patient
*/
void GetNextPatient();


void HospitalSystem()
{
	int choice = 0;
	while (true)
	{
		std::cout << "Enter your choice:\n";
		std::cout << "1) Add new patient\n";
		std::cout << "2) Print all patients\n";
		std::cout << "3) Get next patient\n";
		std::cout << "4) Exit\n";
		std::cin >> choice;
		switch (choice)
		{
			case 1: AddPatient(); break;
			case 2: PrintPatient(); break;
			case 3: GetNextPatient(); break;
			case 4: return;
			default: std::cout << "ERROR: Wrong choice!\n";
		}
	}
}


void AddPatient()
{
	std::cout << "Enter specialization, name, status: ";
	int specialization = 0, status = 0;
	std::string name = "";
	std::cin >> specialization >> name >> status;

	if (queue_size[specialization - 1] == 5)
		std::cout << "Sorry we can't add more patients for this specialization\n\n";
	else
	{
		if (status == 0)
		{
			name += " regular";
			AddAtEnd(specialization, name);
		}
		else
		{
			name += " urgent";
			AddAtFront(specialization, name);
		}
		std::cout << '\n';
	}
}


void AddAtEnd(int specialization, const std::string& name)
{
	patient_queue[specialization - 1][queue_size[specialization - 1]] = name;
	queue_size[specialization - 1]++;
}


void AddAtFront(int specialization, const std::string& name)
{
	for (int i = queue_size[specialization - 1] - 1; i >= 0; i--)
		patient_queue[specialization - 1][i + 1] = patient_queue[specialization - 1][i];
	patient_queue[specialization - 1][0] = name;
	queue_size[specialization - 1]++;
}


void PrintPatient()
{
	std::cout << "****************************\n";

	for (int i = 0; i < 20; i++)
	{
		if (queue_size[i] > 0)
		{
			std::cout << "There are " << queue_size[i] << " patients in specialization " << i + 1 << '\n';
			for (int j = 0; j < queue_size[i]; j++)
				std::cout << patient_queue[i][j] << '\n';
			std::cout << '\n';
		}
	}

	std::cout << '\n';
}


void GetNextPatient()
{
	int specialization = 0;
	std::cout << "Enter specialization: ";
	std::cin >> specialization;

	if (queue_size[specialization - 1] == 0)
		std::cout << "No patients at the moment. Have rest. Dr\n\n";
	else
	{
		for (int i = 0; patient_queue[specialization - 1][0][i] != ' '; i++)
			std::cout << patient_queue[specialization - 1][0][i];
		std::cout << " please go with the Dr\n";

		for (int i = 0; i < queue_size[specialization - 1] - 1; i++)
			patient_queue[specialization - 1][i] = patient_queue[specialization - 1][i + 1];

		queue_size[specialization - 1]--;
		std::cout << '\n';
	}
}


int main()
{
	HospitalSystem();
	return 0;
}


