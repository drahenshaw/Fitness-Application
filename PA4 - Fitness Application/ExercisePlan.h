/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA4 - Fitness Application																									   *
*Date: February 21, 2018																															   *
*Description: ExercisePlan.h header file for ExercisePlan class.																			           *
********************************************************************************************************************************************************/

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ifstream;
using std::ostream;
using std::ofstream;
using std::endl;

class ExercisePlan
{
public:
	//constructor
	ExercisePlan();

	//copy constructor
	ExercisePlan(ExercisePlan &copy);

	//destructor
	~ExercisePlan();

	//setters
	void setSteps(int newSteps);
	void setName(string newName);
	void setDate(string newDate);

	//getters
	int getSteps() const;
	string getName() const;
	string getDate() const;
	
	//editGoal
	ExercisePlan editGoal();
	
	//overloaded assignment
	ExercisePlan & operator= (const ExercisePlan &rhs);

private:
	int mSteps;
	std::string mName;
	std::string mDate;
};

ostream & operator << (ostream &lhs, ExercisePlan &rhs); //overloaded stream operators
ofstream & operator << (ofstream &lhs, ExercisePlan &rhs);
fstream & operator >> (fstream &lhs, ExercisePlan &rhs);