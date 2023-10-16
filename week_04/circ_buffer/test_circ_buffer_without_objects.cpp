#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

/* apply moving average filter
@param buffsize [int] buffer size
@return         none
*/
void filter_data(int buffsize){

    // declare variables
    float *buffer;
    int curr_ind = 0;
    float sum;    
    int i;
    float in_val;
    float out_val;
    string line; 

    // name the output file
    string out_file_name = "data_filtered_" + to_string(buffsize) + ".txt";

    // open the input and output files
    ifstream file_in ("data_original.txt");     // open input file
    ofstream file_out(out_file_name);           // open output file

    file_out << fixed << setprecision(2);       // set output precision


    // create the buffer;
    buffer = new float(buffsize);

    // init the buffer to zeros
    for (i = 0 ; i < buffsize ; i++)
        buffer[i] = 0;

    // visit every number in the file
    while (getline(file_in,line) ){             // read stringed number from file
        in_val = stof(line);                    // convert stringed number to a float

        // insert number into buffer
        buffer[curr_ind] = in_val;

        // advance the buffer index
        curr_ind = (curr_ind + 1) % buffsize;

        // compute the buffer sum
        sum = 0;
        for (i = 0 ; i<buffsize ; i++)
            sum += buffer[i];

        // divide sum by buffer size to get average        
        out_val = sum / buffsize;

        // write average value to file
        file_out << out_val << endl;            // write the average to <file_out>

    }

    // close files
    file_in.close ();
    file_out.close();

    // reclaim memory
    delete [] buffer;
}

int main(){

    // filter_data(1);
    filter_data(5);
    // filter_data(10);
    // filter_data(25);

}