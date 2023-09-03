/**
 * @file main.cpp
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
#include "functions.h"
using namespace std;

int main()
{
    //open file
    ifstream gradeFile;
    gradeFile.open("grades.csv");

    //if file does not open
    if(!gradeFile)
    {
        cout<< "Error opening file\n";
        exit(1);
    }
    //Define vector of struct
    vector<Student> student;

    //define array of pointers for last name, SSN, & first name indexing
    Student *indexByLastname[SIZE], *indexBySSN[SIZE], *indexByFirstName[SIZE];

    //read csv file
    readFile(student, gradeFile);

    //point lastName ptr to vector
    point(indexByLastname, student, SIZE);

    //point SSN ptr to vector
    point(indexBySSN, student, SIZE);

    //point first name prt to vector
    point(indexByFirstName, student, SIZE);

    //sort index by last name
    sortPointersLastName(indexByLastname, SIZE);

    //sort index by SSN
    sortPointersSSN(indexBySSN, SIZE);

    //sort index by first name
    sortPointersFirstName(indexByFirstName, SIZE);

    //allow user to see menu and make choice
    choice(indexByLastname, indexBySSN, indexByFirstName, student);

    //close file
    gradeFile.close();

    return 0;
}