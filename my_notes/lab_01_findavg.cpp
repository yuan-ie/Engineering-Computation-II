/*
Lab 01

/* 
--------------------------TASKS-------------------------------------------------------------------
1. Read a list of integers from a text file
2. Print the average value, accurate to two decimal places
3. Print the square root of the product of the largest two values, accurate to two decimal places
--------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


int main()
{

    // step 0 - you can ignore this bit
    string filename = "/data/courses/ece_3822/current/lab_01/data.txt";
    //string filename = "/home/tul16619/ece_3822/lab_01/mynumb.txt";

    int i = 0;
    string line;
    int linecount = 0;

   
    int first;
    int last;
    
    float avg;





    // step 2 open file
    ifstream file_id(filename);




    //read number of lines
    while(getline(file_id,line))
    {
        //cout << line << endl;
        linecount++;
    }

    cout << "number of lines is: " << linecount << endl;


    //start from beginning of file
    file_id.clear();
    file_id.seekg(0);

    //set array size
    double value[linecount];


    //convert string to int and store into value[i]
    while(getline(file_id,line))
    {
        value[i] = stof(line);
        //cout << value[i] << endl;
        i++;
    }

    //print first and last number to check my array points
    cout << "first value is: " << fixed << setprecision(2) << value[0] << endl;
    cout << "last value is: " << fixed << setprecision(2) << value[linecount-1] << endl;

    double sum = 0;
    
    //find average and print showing 2 decimal places
    for (i = 0; i < linecount; i++)
    {
        sum = sum + value[i];

    } 
    avg = sum / linecount;
     
    //cout  <<  "the sum is "  << sum << endl;
    cout  <<  "the sum is " << fixed << setprecision(2)  << sum << endl;
    cout  <<  "the average is " << fixed << setprecision(2)  << avg << endl;


    file_id.close();

    return 0;
}
