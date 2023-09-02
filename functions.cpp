/**
 * @file functions.cpp
 * @author Mikayla Winant
 * @brief 
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "functions.h"

//Function Definitions
/**
 * @brief Displays Menu to user
 * 
 */
void displayMenu()
{
    cout<< "1. Print data in ascending order by last name\n";
    cout<< "2. Print data in ascending order by SSN\n";
    cout<< "3. Search by last name\n";
    cout<< "4. Search by SSN\n";
    cout<< "5. Exit\n\n";
    cout<< "Select a Menu: _";
}
/**
 * @brief displays information based on choice from user
 * 
 */
void choice()
{
    int choice=0;
    do
    {

    }while(choice!=5);
    
}
void readFile(vector<Student> &student, ifstream &gradeFile)
{
    string firstLine;
    getline(gradeFile,firstLine); //reading first line

    while(gradeFile.peek()!=EOF)
    { 
        Student line;
        char delim; 

        gradeFile>>line.id>>delim;
        getline(gradeFile, line.lastName, ',');
        getline(gradeFile, line.firstName, ',');
        getline(gradeFile, line.ssn, ',');
        gradeFile>>line.test[0]>>delim;
        gradeFile>>line.test[1]>>delim;
        gradeFile>>line.test[2]>>delim;
        gradeFile>>line.test[3]>>delim;
        gradeFile>>line.final>>delim;
        //gradeFile>>line.letterGrade;
        getline(gradeFile, line.letterGrade);

        student.push_back(line);

    }

}
/**
 * @brief Display Vector for testing purposes
 * 
 * @param student 
 */
void displayVector(vector<Student> &student)
{
    for(int i=0; i<student.size(); i++)
    {
        cout<< student[i].id<< " "<<student[i].lastName<< " "<<student[i].firstName<<" ";
        cout<< student[i].ssn<<" "<<student[i].test[0]<<" "<<student[i].test[1]<<" ";
        cout<< student[i].test[2]<<" "<<student[i].test[3]<<" "<<student[i].final<< " ";
        cout<< student[i].letterGrade<<" "<<"\n";
    }

}