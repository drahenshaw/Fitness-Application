/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA4 - Fitness Application																									   *
*Date: February 21, 2018																															   *
*Description: List.h header file for List class.																							           *
********************************************************************************************************************************************************/

#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "DietPlan.h"
#include "ExercisePlan.h"
#include "ListNode.h"

using std::fstream;

typedef enum diet
{
	DIET
}Diet;

typedef enum exercise
{
	EXERCISE
}Exercise;

class List
{
public:
	//Constructor / Destructor
	List();
	~List();

	//Getters
	ListNode *getHead();
	DietPlan getPlan();

	//List Insertion
	bool insertAtEnd(DietPlan newDPlan);
	bool insertAtEnd(ExercisePlan newEPlan);

	//Print
	void printNode();
	void printList(Diet plan);
	void printList(Exercise plan);

	//Save to File
	void saveList(fstream &outfile, Diet plan);
	void saveList(fstream &outfile, Exercise plan);

private:
	ListNode *mHead;
};