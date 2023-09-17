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
#include <iomanip>
#include <ctype.h>

using namespace std;

const int SIZE = 20;

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
void choice(Student * lastName[], Student * ssn[], Student * firstName[], vector<Student> &student);
void readFile(vector<Student> &student, ifstream &gradeFile);
void displayVector(vector<Student> &student);
void point(Student * ptrs[], vector<Student> &student, int size);
void displayArrayThroughPointers(Student *ptrs[], int size);
void sortPointersLastName(Student * ptrs[], int size);
void sortPointersSSN(Student * ptrs[], int size);
void sortPointersFirstName(Student * ptrs[], int size);
int binarySearch(Student * ptrs[], int size, int choice, string value);
void displaySearch(Student * ptrs[], int place);
bool isGreater(string s1, string s2);

#endif