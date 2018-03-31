/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA4 - Fitness Application																									   *
*Date: February 21, 2018																															   *
*Description: FitnessAppWrapper.cpp source file contains the class function descriptions for FitnessAppWrapper class.						           *
********************************************************************************************************************************************************/

#include "Fitness.h"

FitnessAppWrapper::FitnessAppWrapper() //constructor opens files
{
	mDietFile.open("dietPlans.txt");
	mExerciseFile.open("exercisePlans.txt");
}

FitnessAppWrapper::~FitnessAppWrapper() //destructor closes files
{
	mDietFile.close();
	mExerciseFile.close();
}

void FitnessAppWrapper::runApp() //main driver for the program
{
	int option = 0; //menu option

	do
	{
		displayWelcome(); 
		displayMenu();
		cin >> option;
		system("cls");

		switch (option)
		{
		case 1: //load diet plans			
			loadWeeklyPlan(mDietFile, m_DietPlan);
			mDietFile.close();			
			break;
		case 2: //load exercise plans
			loadWeeklyPlan(m_ExercisePlan, mExerciseFile);	
			mExerciseFile.close();
			break;
		case 3: //store diet plans
			mDietFile.open("dietPlans.txt");
			storeWeeklyPlan(DIET);
			mDietFile.close();
			break;
		case 4: //store exercise plans
			mExerciseFile.open("exercisePlans.txt");
			storeWeeklyPlan();
			mExerciseFile.close();			
			break;
		case 5: //print diet plans
			displayWeeklyPlan();
			system("pause");
			system("cls");
			break;
		case 6: //print exercise plans
			displayWeeklyPlan(EXERCISE);
			system("pause");
			system("cls");
			break;
		case 7: //edit daily diet plan
			editDailyDiet();
			system("pause");
			system("cls");
			break;
		case 8: //edit daily exercise plan
			editDailyExercise();
			system("pause");
			system("cls");
			break;
		}
	}
	while (option != EXIT);

	mDietFile.open("dietPlans.txt");
	mExerciseFile.open("exercisePlans.txt");
	storeWeeklyPlan(DIET); //store diets
	storeWeeklyPlan(); //store exercise
	mDietFile.close();
	mExerciseFile.close(); //files opened and closed to reset fstream to either input or output modes

	cout << "Thank you for using David's Fitness Application." << endl;
}

void FitnessAppWrapper::loadDailyPlan(fstream &fs, DietPlan &dplan) //load daily diet plan
{
	fs >> dplan;
}

void FitnessAppWrapper::loadDailyPlan(fstream &fs, ExercisePlan &eplan) //load daily exercise plan
{
	fs >> eplan;
}


void FitnessAppWrapper::loadWeeklyPlan(fstream &fs, List &llist) //load weekly diet
{
	int i = 0;	
	DietPlan d1;	

	for (i = 0; i < WEEKLY; i++)
	{
		loadDailyPlan(fs, d1);
		m_DietPlan.insertAtEnd(d1); //insert to linked list
	}
}

void FitnessAppWrapper::loadWeeklyPlan(List &llist, fstream &fs) //load weekly exercise
{
	int i = 0;
	ExercisePlan e1;

	for (i = 0; i < WEEKLY; i++)
	{
		loadDailyPlan(fs, e1);
		m_ExercisePlan.insertAtEnd(e1);	//insert to linked list
	}
}

void FitnessAppWrapper::displayDailyPlan(DietPlan dplan)
{
	cout << dplan;
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan eplan)
{
	cout << eplan;
}

void FitnessAppWrapper::displayWeeklyPlan()
{
	ListNode *pCur = m_DietPlan.getHead();

	while (pCur != NULL)
	{
		displayDailyPlan(pCur->getDPlan()); //go to node and get plan
		pCur = pCur->getNext();
	}
}

void FitnessAppWrapper::displayWeeklyPlan(Exercise plan) //overload for exercise plans
{
	ListNode *pCur = m_ExercisePlan.getHead();

	while (pCur != NULL)
	{
		displayDailyPlan(pCur->getEPlan());
		pCur = pCur->getNext();
	}
}

void FitnessAppWrapper::storeDailyPlan(DietPlan dplan)
{
	mDietFile << dplan;
} 

void FitnessAppWrapper::storeDailyPlan(ExercisePlan eplan)
{
	mExerciseFile << eplan;
}

void FitnessAppWrapper::storeWeeklyPlan(Diet plan) 
{
	ListNode *pCur = m_DietPlan.getHead();

	while (pCur != NULL)
	{
		storeDailyPlan(pCur->getDPlan()); //go to node, get plan and save to file
		pCur = pCur->getNext();
	}
}

void FitnessAppWrapper::storeWeeklyPlan()
{
	ListNode *pCur = m_ExercisePlan.getHead();

	while (pCur != NULL)
	{
		storeDailyPlan(pCur->getEPlan());
		pCur = pCur->getNext();
	}
}

void FitnessAppWrapper::editDailyDiet()
{
	displayWeeklyPlan();

	cout << "Choose a diet plan name to edit: " << endl;

	string s; 	
	getchar();
	getline(cin, s);

	ListNode *pCur = m_DietPlan.getHead();

	while (pCur != NULL && pCur->getDPlan().getName() != s) //go to node, get plan->name
	{
		pCur = pCur->getNext();
	}

	if (pCur != NULL) //found target
	{
		pCur->setData(pCur->getDPlan().editGoal());
	}
	else
	{
		cout << "Plan not found." << endl;
	}
}

void FitnessAppWrapper::editDailyExercise() //overloaded for exercise
{
	displayWeeklyPlan(EXERCISE);

	cout << "Choose an exercise plan name to edit: " << endl;

	string s;	
	getchar();
	getline(cin, s);

	ListNode *pCur = m_ExercisePlan.getHead();

	while (pCur != NULL && pCur->getEPlan().getName() != s)
	{
		pCur = pCur->getNext();
	}

	if (pCur != NULL) //found target
	{
		pCur->setData(pCur->getEPlan().editGoal());
	}
	else
	{
		cout << "Plan not found." << endl;
	}
}

void FitnessAppWrapper::displayMenu() //prints main menu
{
	cout << "1. Load weekly diet plan from file." << endl;
	cout << "2. Load weekly exercise plan from file." << endl;
	cout << "3. Store weekly diet plan to file." << endl;
	cout << "4. Store weekly exercise plan to file." << endl;
	cout << "5. Display weekly diet plan to screen." << endl;
	cout << "6. Display weekly exercise plan to screen." << endl;
	cout << "7. Edit daily diet plan." << endl;
	cout << "8. Edit daily exercise plan." << endl;
	cout << "9. Exit." << endl;
}

void FitnessAppWrapper::displayWelcome() //prints welcome message
{
	cout << "Welcome to David's Fitness Application!" << endl << "Choose a following menu option: " << endl << endl;
}
