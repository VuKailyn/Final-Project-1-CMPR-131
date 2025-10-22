#include "FitnessEvent.h"

FitnessEvent::FitnessEvent(string* newNbhdList, int newSize, string fileName)// default constrctor
{
	size = newSize;
	neighboorhoods = newNbhdList;

	ifstream partData(fileName);
	partData.open();
	if (!partData)
	{
		cout << "File not opened." << endl;
		listFirst = listLast = nullptr;
	}
	else
	{
		string line;
		while (getline(partData, line))
		{
			int IDEnd = line.find(' ');
			int temp = line.find(' ', IDEnd + 1);
			int nameEnd = line.find(' ', temp + 1);

			double* miles = new double[size];
			int end = nameEnd;

			for (int i = 0; i < size; i++)
			{
				miles[i] = stod(line.substr(end + 1, line.find(' ', end)));
				end = line.find(' ', end + 1);
			}

			if (listFirst == nullptr)
			{
				listFirst = listLast = new Participant(stoi(line.substr(0, IDEnd)), line.substr(IDEnd + 1, (line.substr(IDEnd + 1, nameEnd).length() - IDEnd)), miles, size);
			}
			else
			{
				listLast->next = new Participant(stoi(line.substr(0, IDEnd)), line.substr(IDEnd + 1, (line.substr(IDEnd + 1, nameEnd).length() - IDEnd)), miles, size);
				listLast = listLast->next;
			}
		}
	}

	partData.close();
}

//Big five
FitnessEvent::FitnessEvent(const FitnessEvent& obj) // copy constructor
{

}


FitnessEvent& FitnessEvent:: operator = (const FitnessEvent& RHS)// overloaded assig. oper.
{

}

FitnessEvent::FitnessEvent(FitnessEvent&& other) noexcept //Move constructor
{

}

FitnessEvent FitnessEvent:: operator=(FitnessEvent&& other) noexcept //Move assignment operator
{

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
		return nullptr;

	Participant* current = listFirst;
	if (current->name == name)
		return current;
	else
		return nullptr;
}

Participant* FitnessEvent::findMostMiles()
{
	Participant* most = listFirst;
	Participant* current = listFirst->next;

	while (current != nullptr)
	{
		if (most->totalMiles <= current->totalMiles)
			most = current;
		current = current->next
	}

	return most;
}

//Neighboorhood accessor and mutator
void FitnessEvent::displayNeighboorhoods()
{
	for (int i = 0; i < size; i++)
	{
		cout << neighboorhoods[i] << endl;
	}
}

//Size accessor and mutator
int FitnessEvent::getSize()
{
	return size;
}