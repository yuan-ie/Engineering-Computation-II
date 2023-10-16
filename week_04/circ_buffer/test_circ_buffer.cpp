#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include "circ_buffer.h"
using namespace std;

class moving_avg : public circ_buffer{
    private:
    public:

    // passing an argument to the circ_buffer constructor
    // whatever is in the braces is a constructor for moving_avg
    // specifically
    moving_avg(int n) : circ_buffer(n){}

    float get_average(){
        float sum = 0;
        int bs = get_buff_size();
        int i;

        for (i = 0 ; i<bs ; i++)
            sum += get_element(i);

        return sum / bs;
    }

};

void filter_data(int buffsize){
    float in_val;
    float out_val;
    string line; 

    string out_file_name = "data_filtered_" + to_string(buffsize) + ".txt";

    ifstream file_in ("data_original.txt");     // open input file
    ofstream file_out(out_file_name);           // open output file

    file_out << fixed << setprecision(2);       // set output precision

    moving_avg myFilter(buffsize);              // declare n-pt moving average filter
                                                // for every number in <file_in>
    while (getline(file_in,line) ){             // read stringed number from file
        in_val = stof(line);                    // convert stringed number to a float
        myFilter.insert(in_val);                // insert float into filter
        out_val = myFilter.get_average();       // get the moving average from the filter
        file_out << out_val << endl;            // write the average to <file_out>
    }

    file_in.close ();
    file_out.close();

}

void super_filter(){
    float in_val;
    float outval1, outval10, outval251;
    string line; 

    // string out_file_name = "data_filtered_" + to_string(buffsize) + ".txt";

    ifstream file_in ("data_original.txt");     // open input file
    // ofstream file_out(out_file_name);           // open output file

    file_out << fixed << setprecision(2);       // set output precision

    moving_avg myFilter1(1);
    moving_avg myFilter10(10);
    moving_avg myFilter251(251);


    while (getline(file_in,line) ){             // read stringed number from file

        in_val = stof(line);                    // convert stringed number to a float

        myFilter1.insert(in_val);                // insert float into filter
        myFilter10.insert(in_val);                // insert float into filter
        myFilter251.insert(in_val);                // insert float into filter

        outval1 = myFilter1.get_average();       // get the moving average from the filter
        outval10 = myFilter10.get_average();       // get the moving average from the filter
        outval251 = myFilter251.get_average();       // get the moving average from the filter
 
        // file_out << out_val << endl;            // write the average to <file_out>
 
    }

    file_in.close ();
    // file_out.close();

}


int main(){

    filter_data(1);
    filter_data(5);
    filter_data(10);
    filter_data(25);
    filter_data(251);

    super_filter();

}