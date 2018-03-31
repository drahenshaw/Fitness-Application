/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA4 - Fitness Application																									   *
*Date: February 21, 2018																															   *
*Description: DietPlan.h header file for DietPlan class.																					           *
********************************************************************************************************************************************************/

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::fstream;
using std::ostream;
using std::ofstream;
using std::endl;

class DietPlan
{
public:
	//constructor
	DietPlan();

	//copy constructor
	DietPlan(DietPlan &copy);

	//destructor
	~DietPlan();

	//setters
	void setCalories(int newCalories);
	void setName(string newName);
	void setDate(string newDate);

	//getters
	int getCalories() const;
	string getName() const;
	string getDate() const;

	//editGoal
	DietPlan editGoal();

	//overloaded assignment
	DietPlan & operator= (const DietPlan &rhs);

private:
	int mCal;
	string mName;
	string mDate;
};

fstream & operator >> (fstream &lhs, DietPlan &rhs); //overloaded stream extraction
ostream & operator << (ostream &lhs, DietPlan &rhs); //overloaded stream insertion
ofstream & operator << (ofstream &lhs, DietPlan &rhs);