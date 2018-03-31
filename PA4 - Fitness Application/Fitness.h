/*******************************************************************************************************************************************************
*Programmer: David Henshaw																															   *
*Class: CptS 122, Spring 2018, Lab Section 03																										   *
*Programming Assignment: PA4 - Fitness Application																									   *
*Date: February 21, 2018																															   *
*Description: Fitness.h header file for entire program.																						           *
********************************************************************************************************************************************************/

#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "DietPlan.h"
#include "ExercisePlan.h"
#include "ListNode.h"
#include "List.h"
#include "FitnessAppWrapper.h"

#define MENUMIN 1
#define MENUMAX 9
#define WEEKLY 7
#define EXIT 9

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::fstream;