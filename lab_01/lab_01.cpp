/*
Lab 01

Yuan Nghiem
tul16619@temple.edu
September 02, 2023

Example:
    This file can be compiled by typing

    This file can be run by typing
*/

/* 
--------------------------TASKS-------------------------------------------------------------------
1. Read a list of integers from a text file
2. Print the average value, accurate to two decimal places
3. Print the square root of the product of the largest two values, accurate to two decimal places
--------------------------------------------------------------------------------------------------
*/

#include<iostream>
#include<fstream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;


int main(int argc, char** argv){

    // step 0 - you can ignore this bit
    string filename = "/data/courses/ece_3822/current/lab_01/data.txt";
    if (argc>1)
        filename = argv[1];

    // step 1 init variables
    int i = 0;
    int linecount = 0;
    double avg = 0;
    double sum = 0;
    string line;

    double max1 = 0;
    double max2 = 0;
    double product;
    double result;


    // step 2 open file
    ifstream file_id(filename);

    /*-------------PART 1: read file and store values*------------------------------*/

    //read number of lines
    while(getline(file_id,line))
    {
        //cout << line << endl;
        linecount++;
    }
    //cout << "number of lines is: " << linecount << endl; //CHECK


    //set array size
    double value[linecount];


    //start from beginning of file
    file_id.clear();
    file_id.seekg(0);


    //convert string to int and store into value[i]
    while(getline(file_id,line))
    {
        value[i] = stof(line);
        //cout << value[i] << endl; //CHECK
        i++;
    }

    file_id.close();

/*-------------PART 2: find average and print showing 2 decimal places*--------------*/

    for (i = 0; i < linecount; i++)
    {
        sum = sum + value[i];

    } 
    avg = sum / linecount;

    //cout  <<  "the sum is " << fixed << setprecision(2)  << sum << endl; //CHECK
    cout  <<  "the average is " << fixed << setprecision(2)  << avg << endl;

/*-------------PART 3: square root of product of 1st and 2nd MAX--------------------*/

    //get first maximum
    for(i=0; i<linecount; i++)
    {
        if(max1 < value[i])
            max1 = value[i];
    }
    
    //get second maximum
    for(i=0; i<linecount; i++)
    {
        if((max2 < value[i]) && (value[i] < max1))
            max2 = value[i];
    }

    //product and squareroot
    product = max1 * max2;
    result = sqrt(product);

    //cout << "max value is: " << max1 << endl; // CHECK
    //cout << "2nd max value is: " << max2 << endl; // CHECK
    //cout << "product of max1 and max2 is " << fixed << setprecision(2) << product << endl; //CHECK
    cout << "the square root of the product of the two largest values is " << fixed << setprecision(2) << result << endl;

    return 0;
}