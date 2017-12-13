//Lab 2 by: Alex Irizarry

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

const int NUM_TEAMS = 4;
const int NUM_MEMBERS = 3;
const int ID[NUM_TEAMS] = { 123, 321, 456, 789 };
const string MEMBERS[NUM_TEAMS][NUM_MEMBERS] = 
{
	{ "Sarah", "Joe", "John" },
	{ "Chris", "Kevin", "James" },
	{ "Tom", "Kim", "Emily" },
	{ "Jill", "Jason", "Jim" } 
};

struct TeamS
{
	int ident;
	string names[3];
};

void menu();
void initialize(vector <TeamS> &TeamV, const int id[], const string m[][NUM_MEMBERS], int arraySize);
void printList(const vector <TeamS> & TeamV);
void add(vector <TeamS> & TeamV);
int search(const vector <TeamS> & TeamV, int id);

vector<TeamS> TeamV(NUM_TEAMS);

int main()
{
	
	initialize(TeamV, ID, MEMBERS, NUM_TEAMS);
	menu();
	

	system("pause");
	return 0;
}

void menu()
{
	
	string looperA;
	bool looperB = false;
	while (looperB == false)
	{
		cout << "\n" << "Enter choice 1 to see a list of teams" << endl;
		cout << "Enter choice 2 to add a team to the list" << endl;
		cout << "Enter choice 3 to search for a team using an ID" << endl;
		cout << "Enter choice 4 to end the program" << endl;
		cout << "\n" << "Enter choice:" << endl;
		getline(cin, looperA);

		if (looperA == "1")
		{
			printList(TeamV);
		}
		else if (looperA == "2")
		{
			add(TeamV);
		}
		else if (looperA == "3")
		{
			int searchFor;
			int searchVal;
			cout << "Enter Team ID: " << endl;
			cin >> searchFor;
			cin.ignore(1000, '\n');
			searchVal = search(TeamV, searchFor);
			if (searchVal == -1)
			{
				cout << "ERROR: ID NUMBER NOT FOUND" << endl;
			}
			else
			{
				cout << "ID: " << setw(10) << TeamV[searchVal].ident << setw(10) << TeamV[searchVal].names[0]
					<< setw(10) << TeamV[searchVal].names[1] << setw(10) << TeamV[searchVal].names[2] << endl;
			}
		}
		else if (looperA == "4")
		{
			cout << "\n" << "Lab 2 By: Alex Irizarry has ended" << endl;
			looperB = true;
		}
		else
		{
			cout << "ERROR: INVALID SELECTION PLEASE CHOOSE A VALID CHOICE" << endl;
		}
	}
}

void initialize(vector <TeamS> &TeamV, const int id[], const string m[][NUM_MEMBERS], int arraySize)
{
	int i = 0;
	int j = 0;
	
	for (i = 0; i < arraySize; i++)
	{
		TeamV[i].ident = ID[i];

		for (j = 0; j < NUM_MEMBERS; j++)
		{
			TeamV[i].names[j] = m[i][j];
		}
	}
}

void printList(const vector <TeamS> & TeamV)
{
	int i = 0;
	int size = TeamV.size();

	for (i = 0; i < size; i++)
	{
		cout << "Information for Team " << (i + 1) << endl;
		cout << "ID: " << setw(10) << TeamV[i].ident << setw(10) << TeamV[i].names[0] 
			<< setw(10) << TeamV[i].names[1] << setw(10) << TeamV[i].names[2] << endl;
	}
}

void add(vector <TeamS> & TeamV)
{
	int valID;
	string name1;
	string name2;
	string name3;

	cout << "Enter Team ID: " << endl;
	cin >> valID;
	cin.ignore(1000, '\n');
	cout << "Enter member 1: " << endl;
	getline(cin, name1);
	cout << "Enter member 2: " << endl;
	getline(cin, name2);
	cout << "Enter member 3: " << endl;
	getline(cin, name3);


	TeamS newTeam;
	newTeam.ident = valID;
	newTeam.names[0] = name1;
	newTeam.names[1] = name2;
	newTeam.names[2] = name3;

	TeamV.push_back(newTeam);
}

int search(const vector <TeamS> & TeamV, int id)
{
	int i = 0;
	int pos = -1;
	bool found = false;
	int numElems = TeamV.size();


	while (i < numElems && !found)
	{
		if (TeamV[i].ident == id)
		{
			found = true;
			pos = i;
		}
		i++;
	}
	return pos;
}
