/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA4 - Fitness Application																									   *
*Date: February 21, 2018																															   *
*Description: ListNode.cpp source file contains the class function descriptions for ListNode class.											           *
********************************************************************************************************************************************************/

#include "Fitness.h"

ListNode::ListNode() //constructor
{
	mDPlan = DietPlan();
	mEPlan = ExercisePlan();

	this->mNext = NULL;
}

ListNode::ListNode(DietPlan newDPlan, ListNode *pNext) //overload constructor
{
	this->mDPlan = newDPlan;	
	this->mNext = pNext;
}

ListNode::ListNode(ExercisePlan newEPlan, ListNode *pNext) //overload constructor
{
	this->mEPlan = newEPlan;
	this->mNext = pNext;
}

ListNode::~ListNode() //destructor
{

}

void ListNode::setData(DietPlan newPlan) //setters
{
	mDPlan = newPlan;
}

void ListNode::setData(ExercisePlan newPlan)
{
	mEPlan = newPlan;
}
void ListNode::setNext(ListNode *pNext)
{
	mNext = pNext;
}

DietPlan ListNode::getDPlan() //getters
{
	return mDPlan;
}

ExercisePlan ListNode::getEPlan()
{
	return mEPlan;
}

ListNode* ListNode::getNext()
{
	return this->mNext;
}

