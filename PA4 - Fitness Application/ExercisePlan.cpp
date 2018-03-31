/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA4 - Fitness Application																									   *
*Date: February 21, 2018																															   *
*Description: ExercisePlan.cpp source file contains the class function descriptions for ExercisePlan class.									           *
********************************************************************************************************************************************************/

#include "Fitness.h"

ExercisePlan::ExercisePlan()
{
	mSteps = 0;
	mName = { NULL };
	mDate = { NULL };
}

//copy constructor
ExercisePlan::ExercisePlan(ExercisePlan &copy)
{
	mSteps = copy.getSteps();
	mName = copy.getName();
	mDate = copy.getDate();
}

//destructor
ExercisePlan::~ExercisePlan()
{
	//Definition?
}

//setters
void ExercisePlan::setSteps(int newSteps)
{
	mSteps = newSteps;
}

void ExercisePlan::setName(string newName)
{
	mName = newName;
}

void ExercisePlan::setDate(string newDate)
{
	mDate = newDate;
}

//getters
int ExercisePlan::getSteps() const
{
	return mSteps;
}
string ExercisePlan::getName() const
{
	return mName;
}

string ExercisePlan::getDate() const
{
	return mDate;
}

ExercisePlan ExercisePlan::editGoal()
{
	int newSteps;

	cout << "Enter a new step goal: ";
	cin >> newSteps;
	setSteps(newSteps);

	cout << *this; //print and return object
	return *this;
}

ExercisePlan & ExercisePlan::operator= (const ExercisePlan &rhs) //assignment overload
{
	mSteps = rhs.getSteps();
	mName = rhs.getName();
	mDate = rhs.getDate();

	return (*this);
}

fstream & operator >> (fstream &lhs, ExercisePlan &rhs) //stream overloads
{
	string name, date, minus;
	int steps;

	getline(lhs, name);
	lhs >> steps;	
	getline(lhs, minus); //throw away new line
	getline(lhs, date);
	getline(lhs, minus);
		
	rhs.setSteps(steps); //set values to plan
	rhs.setName(name);
	rhs.setDate(date);
	return lhs;
}

ostream & operator << (ostream &lhs, ExercisePlan &rhs) //how to save plan to file
{
	lhs << rhs.getName() << endl << rhs.getSteps() << endl << rhs.getDate() << endl << endl;
	return lhs;
}

ofstream & operator << (ofstream &lhs, ExercisePlan &rhs)
{
	lhs << rhs.getName() << endl << rhs.getSteps() << endl << rhs.getDate() << endl;
	return lhs;
}