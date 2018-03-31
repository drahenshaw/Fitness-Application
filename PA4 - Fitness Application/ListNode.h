/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA4 - Fitness Application																									   *
*Date: February 21, 2018																															   *
*Description: ListNode.h header file for ListNode class.																					           *
********************************************************************************************************************************************************/

#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "DietPlan.h"
#include "ExercisePlan.h"

class ListNode
{
public:
	//Constructor
	ListNode(); 

	//Overload constructor
	ListNode(DietPlan newDPlan, ListNode *pNext);
	ListNode(ExercisePlan newEPlan, ListNode *pNext);

	//Destructor
	~ListNode();

	//Setters
	void setData(DietPlan newPlan);
	void setData(ExercisePlan newPlan);
	void setNext(ListNode *pNext);

	//Getters
	DietPlan getDPlan();
	ExercisePlan getEPlan();
	ListNode *getNext();

private:
	DietPlan mDPlan; 
	ExercisePlan mEPlan;
	ListNode *mNext;
};