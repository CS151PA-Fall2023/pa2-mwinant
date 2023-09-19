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
    cout<< "3. Print data in ascending order by first name\n";
    cout<< "4. Search by last name\n";
    cout<< "5. Search by SSN\n";
    cout<< "6. Search by first name\n";
    cout<< "7. Exit\n\n";
    cout<< "Select a Menu: _";
}
/**
 * @brief displays information based on choice from user
 * 
 */
void choice(Student * lastName[], Student * ssn[], Student* firstName[], vector<Student> &student)
{
    string last=""; //last name
    string first=""; //first name
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
            displayArrayThroughPointers(lastName, SIZE);
            cin.ignore();
            break;

            case 2:
            cout << "\n\nSorted by SSN\n";
            displayArrayThroughPointers(ssn, SIZE);
            cin.ignore();
            break;

            case 3:
            cout << "\n\nSorted by first name\n";
            displayArrayThroughPointers(firstName, SIZE);
            cin.ignore();
            break;

            case 4: 
            cout << "Please enter last name\n";  
            cin.ignore();        
            getline(cin, last, '\n');
            place=binarySearch(lastName, SIZE, 4, last);
            while(place==-1)
            {
                cout<<"Invalid user input, Please Try again\n\n";
                getline(cin, last, '\n');
                place=binarySearch(lastName, SIZE, 4, last);
            }
            displaySearch(lastName, place);
            cout<< endl;
            break;

            case 5:
            cout<< "Please enter SSN\n";
            cin.ignore();
            getline(cin, num, '\n');
            place=binarySearch(ssn, SIZE, 5, num);
            while(place==-1)
            {
                cout<<"Invlaid user input, Please Try again\n\n";
                getline(cin, num, '\n');
                place=binarySearch(ssn, SIZE, 5, num);
                
            }
            //cout<< "\n\nSearch resultult by SSN\n";
            displaySearch(ssn, place);
            cout<< endl;
            break;

            case 6:
            cout<< "Please enter First Name\n";
            cin.ignore();
            getline(cin, first, '\n');
            place=binarySearch(firstName, SIZE, 6, first);
            while(place==-1)
            {
                cout<<"Invlaid user input, Please Try again\n\n";
                getline(cin, first, '\n');
                place=binarySearch(firstName, SIZE, 6, first);
            }
            //cout<< "\n\nSearch resultult by First Name\n";
            displaySearch(firstName, place);
            cout<< endl;
            break;
        }
        if(choice!=7)
        {
            cout << "\nPress Enter to Continue...\n";
        }
        getchar(); //alows break before displaying menu again

    }while(choice!=7);
    
}
/**
 * @brief read csv file to vector of struct student
 * 
 * @param student 
 * @param gradeFile 
 */
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
        //line.lastName[0]=toupper(line.lastName[0]);
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
/**
 * @brief point ptr to vector Student
 * 
 * @param ptrs 
 * @param student 
 * @param size 
 */
void point(Student * ptrs[], vector<Student> &student, int size)
{
   //ASSIGN EACH POINTER IN ptrs THE ADresultS OF CORresultPONDING ELEMENT IN array
  for(int i=0; i<size; i++)
  {
    ptrs[i]=&student[i];
  }
  
   
}
/**
 * @brief display vector student through chosen pointer
 * 
 * @param ptrs 
 * @param size 
 */
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
 * @brief sort the array of pointers by last name
 * 
 * @param ptrs array of pointers to int
 * @param size size of the array
 */

void sortPointersLastName(Student * ptrs[], int size)
{
    bool madeAswap = true;
    int lastIndex = size - 1;
    {
        while (madeAswap)
        {
            madeAswap = false;
            for (int count = 0; count < lastIndex; ++count)
            {
                if(isGreater(ptrs[count]->lastName,ptrs[count+1]->lastName))
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
/**
 * @brief sort the array of pointers by SSN
 * 
 * @param ptrs 
 * @param size 
 */
void sortPointersSSN(Student * ptrs[], int size)
{
    bool madeAswap = true;
    int lastIndex = size - 1;
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
/**
 * @brief sort the array of pointers by first name
 * 
 * @param ptrs 
 * @param size 
 */
void sortPointersFirstName(Student * ptrs[], int size)
{
    bool madeAswap = true;
    int lastIndex = size - 1;
    {
        while (madeAswap)
        {
            madeAswap = false;
            for (int count = 0; count < lastIndex; ++count)
            {
                if(isGreater(ptrs[count]->firstName,ptrs[count+1]->firstName))
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
/**
 * @brief search array based on choice from user (available choices are last name
 * ssn, and first name)
 * 
 * @param ptrs 
 * @param size 
 * @param choice 
 * @param value 
 * @return int 
 */
int binarySearch(Student * ptrs[], int size, int choice, string value)
{
    int first = 0, // First array element
    last = size - 1, // Last array element
    middle, // Midpoint of search
    position = -1; // Position of search value
    bool found = false; // Flag

    if(choice==4) //search by last name
    {
        while (!found && first <= last)
        {
            middle = (first + last) / 2; // Calculate midpoint
            if (ptrs[middle]->lastName == value) // If value is found at mid
            {
                found = true;
                position = middle;
            }
            else if (isGreater(ptrs[middle]->lastName, value)) // If value is in lower half
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
    else if(choice==5)//search by ssn
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
    else if(choice==6) //search by first name
    {
        while (!found && first <= last)
        {
            middle = (first + last) / 2; // Calculate midpoint
            if (ptrs[middle]->firstName == value) // If value is found at mid
            {
                found = true;
                position = middle;
            }
            else if (ptrs[middle]->firstName > value) // If value is in lower half
            {
                last = middle - 1;
            }
            else
            {
                first = middle + 1; // If value is in upper half
            }
        }
    if(ptrs[position+1]->firstName==value)
    {
        displaySearch(ptrs, position+1);
    }
    return position;
    
    }
    else
    return position;
}
/**
 * @brief display search in a formatted way
 * 
 * @param ptrs 
 * @param place 
 */
void displaySearch(Student * ptrs[], int place)
{
            cout <<left<<setw(4)<<"ID"<<setw(11)<< "Last Name"<<setw(11)<<"First Name";
            cout <<setw(12)<<"SSN"<<setw(5)<<"Grade\n";
            cout<< setw(4)<<ptrs[place]->id<<setw(11)<<ptrs[place]->lastName<<setw(11)<<ptrs[place]->firstName;
            cout<< setw(12)<<ptrs[place]->ssn<<setw(5)<<ptrs[place]->letterGrade;
            cout<< endl;

}
bool isGreater(string s1, string s2)
{
    if(allToUpper(s1)>allToUpper(s2))
    {
        return true;
    }
    return false;
}
string allToUpper(string s1)
{
    string s2=s1;
    for(int i=0; i<s1.size(); i++)
    {
        s2[i]=toupper(s1[i]);

    }
    return s2;
}