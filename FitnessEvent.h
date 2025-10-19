#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Participant
{
	int size;
	string name;
	Participant* next;
	double milesRun[];
};

class FitnessEvent
{
	private:
		int size;
		Participant* list;
		string neighboorhoods[];
		


	public:
		//Constrcutors
		FitnessEvent();// default constrctor

		//Big five
		FitnessEvent(const FitnessEvent& obj); // copy constructor
		FitnessEvent& operator = (const FitnessEvent& RHS);// overloaded assig. oper.
		FitnessEvent(FitnessEvent&& other) noexcept; //Move constructor
		FitnessEvent operator=(FitnessEvent&& other) noexcept; //Move assignment operator
		~FitnessEvent(); // Destructor

		//Participant Linked List Methods
		void addPartcipant(string name);
		void displayParticipants() const;
		void removeParticipant(string name);
		Participant* search(string name) const;
		double totMilesRun(string name);

		//Neighboorhood accessor and mutator
		void displayNeighboorhoods();
		void changeNeighboorhood(int, string);
		
		//Size accessor and mutator
		int getSize();
		void changeSize(int);

};


