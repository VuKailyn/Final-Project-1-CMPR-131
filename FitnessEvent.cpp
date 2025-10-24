#include "FitnessEvent.h"
#include <sstream>
using namespace std;
FitnessEvent::FitnessEvent(string* newNbhdList, int newSize, string fileName)// default constrctor
{
	size = newSize;
	neighborhoods = new string[size];
	for (int i = 0; i < size; i++)
	{
		neighborhoods[i] = newNbhdList[i];
	}

	ifstream partData(fileName);
	if (!partData)
	{
		cout << "File not opened." << endl;
		listFirst = listLast = nullptr;
		return;
	}

	listFirst = listLast = nullptr;

	string line;
	while (getline(partData, line))
	{
		istringstream iss(line);
		int id;
		string name;
		iss >> id >> name;

		double* miles = new double[size];
		for (int i = 0; i < size; i++)
		{
			if (!(iss >> miles[i]))
			{
				miles[i] = 0;
			}
		}

		Participant* temp = new Participant(id, name, miles, size);

		if (listFirst == nullptr)
		{
			listFirst = listLast = temp;
		}
		else {
			listLast->next = temp;
			listLast = temp;
		}
	}
	partData.close();
}

//Big five
FitnessEvent::FitnessEvent(const FitnessEvent& otherEvent) // copy constructor
{
	//copy neighborhoods array
	size = otherEvent.size;
	neighborhoods = new string[size];
	for(int i = 0; i < size; i++)
	{
		neighborhoods[i] = otherEvent.neighborhoods[i];
	}
	
	//initialize new ll pointers
	listFirst = listLast = nullptr;

	//copy participants list
	Participant* current = otherEvent.listFirst;
	while (current)
	{
		//copy milesWalked array
		double* newMiles = new double[current->neighborhoodSize];
		for (int i = 0; i < current->neighborhoodSize; i++)
		{
			Participant* temp = new Participant(current->partID, current->name, newMiles, current->neighborhoodSize);
			newMiles[i] = current->milesWalked[i];
			
			
			if (listFirst == nullptr)
			{
				listFirst = listLast = temp;
			}
			else {
				listLast->next = temp;
				listLast = temp;
			}
			delete temp;
		}
		current = current->next;
	}
}


FitnessEvent& FitnessEvent::operator=(const FitnessEvent& RHS)// overloaded assig. oper.
{
	if (this == &RHS) { return *this;}

	//delete all participants
	Participant* current = listFirst;
	while(current)
	{
		Participant* temp = current;
		current = current->next;
		delete temp;
	}
	
	listFirst = listLast = nullptr;
	delete[] neighborhoods;
	size = RHS.size;
	
	//copy neighborhood list
	neighborhoods = new string[size];
	for(int i = 0; i < size; i++)
	{
		neighborhoods[i] = RHS.neighborhoods[i];
	}
	
	//copy participant ll
	Participant* otherCurrent = RHS.listFirst;
	while (otherCurrent)
	{
		double* newMiles = new double[otherCurrent->neighborhoodSize];
		for (int i = 0; i < otherCurrent->neighborhoodSize; i++)
		{
			newMiles[i] = otherCurrent->milesWalked[i];
		}
		
		Participant* temp = new Participant(otherCurrent->partID, otherCurrent->name, newMiles, otherCurrent->neighborhoodSize);
		if (listFirst == nullptr)
		{
			listFirst = listLast = temp;
		}
		else {
			listLast->next = temp;
			listLast = temp;
		}
		otherCurrent = otherCurrent->next;
	}
	return *this;
}

FitnessEvent::FitnessEvent(FitnessEvent&& otherEvent) noexcept //Move constructor
{
	//steal data and pointers
	size = otherEvent.size;
	neighborhoods = otherEvent.neighborhoods;
	listFirst = otherEvent.listFirst;
	listLast = otherEvent.listLast;

	//set source pointers to nullptr and empty object
	otherEvent.neighborhoods = nullptr;
	otherEvent.listFirst = otherEvent.listLast = nullptr;
	otherEvent.size = 0;
}

FitnessEvent& FitnessEvent:: operator=(FitnessEvent&& otherEvent) noexcept //Move assignment operator
{
	if (this == &otherEvent) {return *this;}

	//clean up current object
	Participant* current = listFirst;
	while (current)
	{
		Participant* temp = current;
		current = current->next;
		delete temp;
	}
	delete[] neighborhoods;

	//steal data and pointers
	size = otherEvent.size;
	neighborhoods = otherEvent.neighborhoods;
	listFirst = otherEvent.listFirst;
	listLast = otherEvent.listLast;

	//set source pointers to nullptr and empty object
	otherEvent.neighborhoods = nullptr;
	otherEvent.listFirst = otherEvent.listLast = nullptr;
	otherEvent.size = 0;

	return *this;
}

FitnessEvent::~FitnessEvent() // Destructor
{

	Participant* current = listFirst;
	Participant* nextNode = nullptr;

	while (current != nullptr)
	{
		nextNode = current->next;
		delete current;
		current = nextNode;
	}

	listFirst = listLast = nullptr;
}
	
//Participant Linked List Methods
void FitnessEvent::displayParticipants() const
{
	Participant* current = listFirst;

	while (current != nullptr)
	{
		cout << current->name << endl;
		current = current->next;
	}
}

Participant* FitnessEvent::search(string name) const
{
	if (listFirst == nullptr)
	{
		return nullptr;
	}

	Participant* current = listFirst;
	
	while (current)
	{
		if(current->name == name)
		{ 
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

Participant* FitnessEvent::findMostMiles()
{
	Participant* most = listFirst;
	Participant* current = listFirst;

	while (current != nullptr)
	{
		if (most->totalMiles <= current->totalMiles)
		{
			most = current;
		}
		current = current->next;
	}
	return most;
}

//Neighboorhood accessor and mutator
void FitnessEvent::displayNeighborhoods()
{
	for (int i = 0; i < size; i++)
	{
		cout << neighborhoods[i] << endl;
	}
}

//Size accessor and mutator
int FitnessEvent::getSize()
{
	return size;
}
