/**
 * @file functions.h
 * @author Mikayla Winant
 * @brief 
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//struct Definition
struct Student
{
    int id;
    string lastName;
    string firstName;
    string ssn;
    float test[4];
    float final;
    string letterGrade;
};

//Function Protytpes
void displayMenu();
void choice();
void readFile(vector<Student> &student, ifstream &gradeFile);
void displayVector(vector<Student> &student);


#endif