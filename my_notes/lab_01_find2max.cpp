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
#include <math.h>

using namespace std;


int main()
{

    // step 0 - you can ignore this bit
    string filename = "/data/courses/ece_3822/current/lab_01/data.txt";
    //string filename = "/home/tul16619/ece_3822/lab_01/mynumb.txt";

    int i = 0;
    string line;
    int linecount = 0;






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
        //cout << value[i] << endl;
        i++;
    }

    //find max and second max
    double max1 = 0;
    double max2 = 0;
    double product;
    double result;

    for(i=0; i<linecount; i++)
    {
        if(max1 < value[i])
            max1 = value[i];
    }
    
    for(i=0; i<linecount; i++)
    {
        if((max2 < value[i]) && (value[i] < max1))
            max2 = value[i];
    }

    product = max1 * max2;
    result = sqrt(product);

    cout << "max value is: " << max1 << endl;
    cout << "2nd max value is: " << max2 << endl;
    cout << "product of max1 and max2 is " << fixed << setprecision(2) << product << endl;
    cout << "the square root of the product is " << fixed << setprecision(2) << result << endl;



    file_id.close();

    return 0;
}
