#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include<string>
using namespace std;


class student{

    private:

    string name;
    string student_name;
    // ADD VARIABLES HERE AS NEEDED
    int grade;
    int n = 100;
    int *grades_stored = new int[n]; //store grades in array of arbitrary size
    int numGrades = 0; //number of grades stored initialized to 0
    int i; //loop initializer
    int k; //loop initializer
    int grade_max = 0; //max grade set to 0
    double avg;
    double sum = 0;


    public:

    // DON'T CHANGE THESE FUNCTION PROTOTYPES
    
    student()
    {
        i = 0; //initialize array location here
        for (i=0; n<100; i++)
            grades_stored[i] = 0; //clear array
    }
    void set_name(string name)
    {
        student_name = name;
    }

    void add_grade(int grade)
    {
        grades_stored[numGrades] = grade;
        //cout << "grade " << numGrades + 1 << " : " << grades_stored[numGrades] << endl;
        numGrades++;
    }

    int get_max()
    {
        for (k=0; k<numGrades; k++)
        {
            if (grades_stored[k] > grade_max)
            grade_max = grades_stored[k];
        }
        return grade_max;
    }

    double get_average()
    {
        for (k=0; k<numGrades; k++)
        {
            sum = sum + grades_stored[k];
        }
        avg = sum / numGrades;
        return avg;
    }

    void display()
    {
        cout << student_name << " : ";
        for (k=0; k<numGrades; k++)
        {
            //cout << "grade " << k+1 << " : " << grades_stored[k] << endl; //for me to read better
            cout << grades_stored[k] << ", ";
        }
        cout << "\b\b" << "  " << endl;
        cout << endl;
    }  

};

#endif 