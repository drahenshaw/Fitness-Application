/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA4 - Fitness Application																									   *
*Date: February 21, 2018																															   *
*Description: DietPlan.cpp source file contains the class function descriptions for DietPlan class.											           *
********************************************************************************************************************************************************/

#include "Fitness.h"

DietPlan::DietPlan() //constructor
{
	mCal = 0;
	mName = { NULL };
	mDate = { NULL };
}

DietPlan::DietPlan(DietPlan &copy) //copy constructor
{
	mCal = copy.getCalories();
	mName = copy.getName();
	mDate = copy.getDate();
}
DietPlan::~DietPlan() //destructor
{
	//Definition
}

void DietPlan::setCalories(int newCalories) //setters
{
	mCal = newCalories;
}

void DietPlan::setName(string newName)
{
	mName = newName;
}

void DietPlan::setDate(string newDate)
{
	mDate = newDate;
}

int DietPlan::getCalories() const //getters
{
	return mCal;
}

string DietPlan::getName() const
{
	return mName;
}

string DietPlan::getDate() const
{
	return mDate;
}

DietPlan & DietPlan::operator= (const DietPlan &rhs) //assignment overload
{
	mCal = rhs.getCalories();
	mName = rhs.getName();
	mDate = rhs.getDate();	

	return (*this);
}

DietPlan DietPlan::editGoal()
{
	int newCals;

	cout << "Enter a new calorie goal: ";
	cin >> newCals;
	setCalories(newCals);
	
	cout << *this; //print plan to screen
	return *this;	//return plan as well
}

fstream & operator >> (fstream &lhs, DietPlan &rhs)
{
	string name, date, minus;
	int calories; 
	char newl;

	getline(lhs, name); //get name
	lhs >> calories;	//get calories
	getline(lhs, minus);	//throw away new line
	getline(lhs, date);		//get date
	getline(lhs, minus);

	rhs.setCalories(calories); //set values
	rhs.setName(name);
	rhs.setDate(date);
	return lhs;
}

ostream & operator << (ostream &lhs, DietPlan &rhs) //stream insertion overload to format how to save a plan.
{
	lhs << rhs.getName() << endl << rhs.getCalories() << endl << rhs.getDate() << endl << endl;
	return lhs;
}

ofstream & operator << (ofstream &lhs, DietPlan &rhs)
{
	lhs << rhs.getName() << endl << rhs.getCalories() << endl << rhs.getDate() << endl;
	return lhs;
}