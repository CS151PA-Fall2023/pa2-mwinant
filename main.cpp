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
    //define array of pointers called ptr
    Student *ptr[SIZE];
    //read csv file
    readFile(student, gradeFile);
    //point ptr to vector
    point(ptr, student, SIZE);
    //display menu to user, display sorted vector based on choice
    choice(ptr, student);
    //displayVector(student); //for testing
    //displayArrayThroughPointers(ptr, SIZE);
    
    //close file
    gradeFile.close();




    return 0;
}