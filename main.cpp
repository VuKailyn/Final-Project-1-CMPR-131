/*
    string team; - Ethan Rokos, Kailyn Vu, Marco Luevano, John Hanson
    CMPR 131 - Fall 2025
    October 25, 2025

    Final Project #1

    Collaborations: ChatGPT
*/
#include <iostream>
#include <string>
#include "FitnessEvent.h"
using namespace std;

int main()
{
    //create neighborhood list
    string neighborhoods[] = { "Downtown", "Lakeside", "Hills" };
    int size = 3;

    //create fitness event
    cout << "creating FitnessEvent from file" << endl;
    FitnessEvent event1(neighborhoods, size, "participants.txt");

    cout << "\nneighborhoods:\n";
    event1.displayNeighborhoods();
    cout << "\nparticipants:\n";
    event1.displayParticipants();

    //search for some participants
    string searchName = "Olivia Allen";
    cout << "\nsearching for participant '" << searchName << "': ";
    Participant* found = event1.search(searchName);
    if (found)
    {
        cout << "found, ID: " << found->partID << ", total miles: " << found->totalMiles << endl;
    }
    else{
        cout << "not found\n";
    }

    searchName = "Liam Sanchez";
    cout << "\nsearching for participant '" << searchName << "': ";
    found = event1.search(searchName);
    if (found)
    {
        cout << "found, ID: " << found->partID << ", total miles: " << found->totalMiles << endl;
    }
    else {
        cout << "not found\n";
    }

    searchName = "Fogell McLovin";
    cout << "\nsearching for participant '" << searchName << "': ";
    found = event1.search(searchName);
    if (found)
    {
        cout << "found, ID: " << found->partID << ", total miles: " << found->totalMiles << endl;
    }
    else {
        cout << "not found\n";
    }

    //find participant with most miles
    Participant* top = event1.findMostMiles();
    if (top)
    {
        cout << "\ntop participant: " << top->name << " (" << top->totalMiles << " miles)\n";
    }

    //test copy constructor
    cout << "\ncopy constructing event2 from event1" << endl;
    FitnessEvent event2 = event1;
    cout << "event2 participants:\n";
    event2.displayParticipants();

    //test copy assignment
    cout << "\ncopy assigning event3 to event1" << endl;
    FitnessEvent event3(neighborhoods, size, "participants.txt");
    event3 = event1;
    cout << "event3 participants:\n";
    event3.displayParticipants();

    //test move constructor
    cout << "\nmove constructing event4 from event1" << endl;
    FitnessEvent event4 = std::move(event1);
    cout << "Moved event4 participants:\n";
    event4.displayParticipants();

    //test move assignment
    cout << "\nmove assigning event5 using std::move(event2)" << endl;
    FitnessEvent event5(neighborhoods, size, "participants.txt");
    event5 = std::move(event2);
    cout << "moved event5 participants:\n";
    event5.displayParticipants();

    cout << "\ndestructors run at program exit" << endl;
    return 0;
}
