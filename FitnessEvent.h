/*
	string team; - Ethan Rokos, Kailyn Vu, Marco Luevano, John Hanson
	CMPR 131 - Fall 2025
	October 25, 2025

	Final Project #1

	Collaborations: ChatGPT
*/
#pragma once
#ifndef FITNESSEVENT_H
#define FITNESSEVENT_H
#include <iostream>
#include <fstream>
#include <string>


//Particpant node
struct Participant
{
	//Participant name, array for miles walked, array size, total miles walked, and pointer to next node
	std::string fName;
	std::string lName;
	std::string name = fName + " " + lName;
	int partID;
	double* milesWalked;
	int neighborhoodSize;
	double totalMiles;
	Participant* next;

	//Calculates total miles walked. called on construction so all future reference to total miles can just use the variable instead
	double calculateTotalMiles()
	{
		double total = 0.0;
		for (int i = 0; i < neighborhoodSize; i++)
		{
			total += milesWalked[i];
		}
		return total;
	}
	
	//Constructor for the struct
	Participant(int newID, std::string newFName, std::string newLName, double* newMilesWalked, int size)
	{
		partID = newID;
		fName = newFName;
		lName = newLName;
		name = newFName + " " + newLName;
		milesWalked = newMilesWalked;
		neighborhoodSize = size;
		totalMiles = calculateTotalMiles();
		next = nullptr;
	}

	//destructor
	~Participant()
	{
		delete[] milesWalked;
		milesWalked = nullptr;
	}
};

class FitnessEvent
{
private:
	int size;
	Participant* listFirst;
	Participant* listLast;
	std::string* neighborhoods;



public:
	//Constrcutors
	FitnessEvent(std::string* newNbhdList, int newSize, std::string fileName);

	//Big five
	FitnessEvent(const FitnessEvent& otherEvent); // copy constructor
	FitnessEvent& operator = (const FitnessEvent& RHS);// overloaded assig. oper.
	FitnessEvent(FitnessEvent&& other) noexcept; //Move constructor
	FitnessEvent& operator=(FitnessEvent&& other) noexcept; //Move assignment operator
	~FitnessEvent(); // Destructor

	//Participant Linked List Methods
	void displayParticipants() const;
	Participant* search(std::string name) const;
	Participant* findMostMiles();

	//Neighborhood accessor and mutator
	void displayNeighborhoods();

	//Size accessor and mutator
	int getSize();

};

#endif
