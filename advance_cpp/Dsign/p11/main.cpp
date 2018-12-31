/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-31
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "person.h"
#include "Student.h"
#include "FrqFller.h"
#include "FrqStudent.h"
#include "Traveler.h"
#include "Agent.h"

int main()
{
    Traveler sT(new Student);
    Traveler fT(new FrqFller);
    Traveler fsT(new FrqStudent);
    Agent   ag;
    ag.AddTrav(&sT);
    ag.AddTrav(&fsT);
    ag.AddTrav(&fT);
    person Ag(&ag);

    Ag.Goal();    

    return 0;
}
