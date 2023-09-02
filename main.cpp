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
#include "functions.h"
using namespace std;

int main()
{
    ifstream gradeFile;
    gradeFile.open("grades.csv");

    //if file does not open
    if(!gradeFile)
    {
        cout<< "Error opening file\n";
        exit(1);
    }
    else
    {
        cout<< "File opened successfully\n";
    }
    vector<Student> student;

    //displayMenu();
    //choice();
    readFile(student, gradeFile);
    displayVector(student);




    return 0;
}