/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA4 - Fitness Application																									   *
*Date: February 21, 2018																															   *
*Description: List.cpp source file contains the class function descriptions for List class.													           *
********************************************************************************************************************************************************/

#include "Fitness.h"

List::List()
{
	mHead = NULL;
}

List::~List() //list destructor - deletes all nodes in list
{
	if (mHead != NULL) //check for empty list
	{
		ListNode *pCur = mHead;

		while (pCur != NULL)
		{
			ListNode *pNext = pCur->getNext();
			delete pCur;
			pCur = pNext;
		}

		mHead = NULL; //set head pointer to null
	}
}

bool List::insertAtEnd(DietPlan newDPlan)
{
	ListNode *pMem = NULL;
	bool success = false;

	pMem = new ListNode(newDPlan, NULL);

	if (pMem != NULL) //memory allocated succesfully?
	{
		if (mHead == NULL) //insert into empty list
		{
			mHead = pMem;
			
			return true;
		}
		else
		{
			ListNode *pCur = mHead, *pPrev = NULL;
			while (pCur != NULL)
			{
				pPrev = pCur;
				pCur = pCur->getNext();
			}

			pPrev->setNext(pMem);			
		}
	}
}

bool List::insertAtEnd(ExercisePlan newEPlan)
{
	ListNode *pMem = NULL;
	bool success = false;

	pMem = new ListNode(newEPlan, NULL);

	if (pMem != NULL) //memory allocated succesfully?
	{
		if (mHead == NULL) //insert into empty list
		{
			mHead = pMem;
			return true;
		}
		else
		{
			ListNode *pCur = mHead, *pPrev = NULL;
			while (pCur != NULL)
			{
				pPrev = pCur;
				pCur = pCur->getNext();
			}

			pPrev->setNext(pMem);			
		}
	}
}

void List::printNode(void) //alternative to wrapper display function
{
	if (mHead != NULL)
	{
		static ListNode *pCur = mHead;
		{
			if (pCur != NULL)
			{
				cout << pCur->getDPlan() << endl;
				pCur = pCur->getNext();
			}
		}
	}
}


void List::printList(Diet plan) //alternative to wrapper display weekly - prints entire list
{
	if (mHead != NULL)
	{
		ListNode *pCur = mHead;

		while (pCur != NULL)
		{
			cout << pCur->getDPlan() << endl;
			pCur = pCur->getNext();			
		}
	}
}

void List::printList(Exercise plan) //prints entire exercise list
{
	if (mHead != NULL)
	{
		ListNode *pCur = mHead;

		while (pCur != NULL)
		{
			cout << pCur->getEPlan() << endl;
			pCur = pCur->getNext();
		}
	}
}

void List::saveList(fstream &outfile, Diet plan) //save weekly diets to file
{
	if (mHead != NULL)
	{
		ListNode *pCur = mHead;

		while (pCur != NULL)
		{
			outfile << pCur->getDPlan() << endl;
			pCur = pCur->getNext();
		}
	}
}

void List::saveList(fstream &outfile, Exercise plan) //save weekly exercise
{
	if (mHead != NULL)
	{
		ListNode *pCur = mHead;

		while (pCur != NULL)
		{
			outfile << pCur->getEPlan() << endl;
			pCur = pCur->getNext();			
		}
	}
}


ListNode *List::getHead() //get head of the list
{
	return mHead;
}

DietPlan List::getPlan() //unused
{
	return mHead->getDPlan();
}