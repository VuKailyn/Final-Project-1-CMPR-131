#include "FitnessEvent.h"

FitnessEvent::FitnessEvent()// default constrctor
{
	size = 6;
	neighboorhoods[6];
	string areas[]= { "Old Towne","El Modena","Orange Hills","Santiago Creek", "Villa Park Area","North El Camino Real" };
	for (int i = 0; i < size; i++)
	{
		neighboorhoods[i] = areas[i];
	}

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

}

//Participant Linked List Methods
void addPartcipant(string name)
{

}

void FitnessEvent::displayParticipants() const
{

}

void FitnessEvent::removeParticipant(string name)
{

}

Participant* FitnessEvent::search(string name) const
{

}

double FitnessEvent::totMilesRun(string name)
{

}

//Neighboorhood accessor and mutator
void FitnessEvent::displayNeighboorhoods()
{
	for (int i = 0; i < size; i++)
	{
		cout << neighboorhoods[i] << endl;
	}
}

void FitnessEvent::changeNeighboorhood(int index, string newNeighboorhood)
{
	neighboorhoods[index] = newNeighboorhood;
}

//Size accessor and mutator
int FitnessEvent::getSize()
{
	return size;
}

void FitnessEvent::changeSize(int newSize)
{
	size = newSize; 
}