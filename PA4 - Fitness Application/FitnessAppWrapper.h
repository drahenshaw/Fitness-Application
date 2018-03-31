/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA4 - Fitness Application																									   *
*Date: February 21, 2018																															   *
*Description: FitnessAppWrapper.h header file for FitnessAppWrapper class.																	           *
********************************************************************************************************************************************************/

#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "DietPlan.h"
#include "ExercisePlan.h"
#include "ListNode.h"
#include "List.h"

using std::fstream;
using std::ifstream;

class FitnessAppWrapper
{
public:
	//Constructor / Destructor
	FitnessAppWrapper();
	~FitnessAppWrapper();

	//Program driver
	void runApp(); 

	void loadDailyPlan(fstream &fs, DietPlan &dplan);
	void loadDailyPlan(fstream &fs, ExercisePlan &eplan);

	void loadWeeklyPlan(fstream &fs, List &llist);
	void loadWeeklyPlan(List &llist, fstream &fs);	

	void displayDailyPlan(DietPlan dplan); 
	void displayDailyPlan(ExercisePlan eplan);

	void displayWeeklyPlan(); 
	void displayWeeklyPlan(Exercise plan);

	void storeDailyPlan(DietPlan dplan); 
	void storeDailyPlan(ExercisePlan eplan);

	void storeWeeklyPlan();
	void storeWeeklyPlan(Diet plan); 	

	void editDailyDiet();
	void editDailyExercise();

	void displayMenu();
	void displayWelcome();

private:
	fstream mDietFile;		//file stream objects
	fstream mExerciseFile;

	List m_DietPlan;		//linked list objects
	List m_ExercisePlan; 
};
