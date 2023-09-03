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
void choice(Student * ptrs[], vector<Student> &student)
{
    string name=""; //last name
    string num; //ssn
    int choice=0;
    int place=0;
    
    do
    {
        displayMenu();
        cin>>choice;
        switch(choice){
            case 1:
            cout << "\n\nSorted by Last Name\n";
            sortPointers(ptrs, SIZE, 3);
            displayArrayThroughPointers(ptrs, SIZE);
            break;

            case 2:
            cout << "\n\nSorted by SSN\n";
            sortPointers(ptrs, SIZE, 4);
            displayArrayThroughPointers(ptrs, SIZE);
            break;

            case 3: 
            cout << "Please enter last name\n";          
            cin.ignore();
            getline(cin, name, '\n');
            sortPointers(ptrs, SIZE, 3);
            place=binarySearch(ptrs, SIZE, 3, name);
            displaySearch(ptrs, place);
            cout<< endl;
            break;

            case 4:
            cout<< "Please enter SSN\n";
            cin.ignore();
            getline(cin, num, '\n');
            sortPointers(ptrs, SIZE, 4);
            place=binarySearch(ptrs, SIZE, 4, num);
            cout<< "\n\nSearch Result by SSN\n";
            displaySearch(ptrs, place);
            cout<< endl;
            break;
        }

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
void point(Student * ptrs[], vector<Student> &student, int size)
{
   //ASSIGN EACH POINTER IN ptrs THE ADRESS OF CORRESPONDING ELEMENT IN array
  for(int i=0; i<size; i++)
  {
    ptrs[i]=&student[i];
  }
  
   
}
void displayArrayThroughPointers(Student *ptrs[], int size)
{
    cout <<left<<setw(4)<<"ID"<<setw(11)<< "Last Name"<<setw(11)<<"First Name";
    cout <<setw(12)<<"SSN"<<setw(5)<<"Grade\n";
    //DISPLAY array USING POINTERS IN ptrs
    for(int i=0; i<size; i++)
    {
        cout<< setw(4)<<ptrs[i]->id<<setw(11)<<ptrs[i]->lastName<<setw(11)<<ptrs[i]->firstName;
        cout<< setw(12)<<ptrs[i]->ssn<<setw(5)<<ptrs[i]->letterGrade;
        cout<< endl;
    }
    cout<< endl;
}
/**
 * @brief Indirectly sort the array of pointers
 * 
 * @param ptrs array of pointers to int
 * @param size size of the array
 */

void sortPointers(Student * ptrs[], int size, int choice)
{
    bool madeAswap = true;
    int lastIndex = size - 1;
    if(choice==3)
    {
        while (madeAswap)
        {
            madeAswap = false;
            for (int count = 0; count < lastIndex; ++count)
            {
                if ((ptrs[count]->lastName) > (ptrs[count + 1]->lastName))
                {
                Student *temp= ptrs[count];
                ptrs[count] = ptrs[count + 1];
                ptrs[count + 1] = temp;
                madeAswap = true;
                }
            }
    --lastIndex;
        }
    }
    else if(choice==4)
    {
        while (madeAswap)
        {
            madeAswap = false;
            for (int count = 0; count < lastIndex; ++count)
            {
                if ((ptrs[count]->ssn) > (ptrs[count + 1]->ssn))
                {
                Student *temp= ptrs[count];
                ptrs[count] = ptrs[count + 1];
                ptrs[count + 1] = temp;
                madeAswap = true;
                }
            }
    --lastIndex;
        }

    }

}
int binarySearch(Student * ptrs[], int size, int choice, string value)
{
    int first = 0, // First array element
    last = size - 1, // Last array element
    middle, // Midpoint of search
    position = -1; // Position of search value
    bool found = false; // Flag
    if(choice==3)
    {
        while (!found && first <= last)
        {
            middle = (first + last) / 2; // Calculate midpoint
            if (ptrs[middle]->lastName == value) // If value is found at mid
            {
                found = true;
                position = middle;
            }
            else if (ptrs[middle]->lastName > value) // If value is in lower half
            {
                last = middle - 1;
            }
            else
            {
                first = middle + 1; // If value is in upper half
            }
        }
        return position;
    }
    else if(choice==4)
    {
        while (!found && first <= last)
        {
            middle = (first + last) / 2; // Calculate midpoint
            if (ptrs[middle]->ssn == value) // If value is found at mid
            {
                found = true;
                position = middle;
            }
            else if (ptrs[middle]->ssn > value) // If value is in lower half
            {
                last = middle - 1;
            }
            else
            {
                first = middle + 1; // If value is in upper half
            }
        }
    return position;
    }
    else
    return position;
}

void displaySearch(Student * ptrs[], int place)
{
            cout <<left<<setw(4)<<"ID"<<setw(11)<< "Last Name"<<setw(11)<<"First Name";
            cout <<setw(12)<<"SSN"<<setw(5)<<"Grade\n";
            cout<< setw(4)<<ptrs[place]->id<<setw(11)<<ptrs[place]->lastName<<setw(11)<<ptrs[place]->firstName;
            cout<< setw(12)<<ptrs[place]->ssn<<setw(5)<<ptrs[place]->letterGrade;
            cout<< endl;
}