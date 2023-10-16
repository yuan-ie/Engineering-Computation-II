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
    moving_avg(int n = 10) : circ_buffer(n){}

    float get_average(){
        float sum = 0;
        int bs = get_buff_size();
        int i;

        for (i = 0 ; i<bs ; i++)
            sum += get_element(i);

        return sum / bs;
    }

};

void f3(){

    float in_val;
    float out_val;
    string line; 

    ifstream file_in ("noisy_data.txt");        // open input file
    ofstream file_out("clean_data.txt");        // open output file

    file_out << fixed << setprecision(2);       // set output precision

    moving_avg myFilter(5);                     // declare 5pt moving average filter
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

void f2(){
    float avg;
    moving_avg my_buffer(5);

    my_buffer.insert(1.1);
    my_buffer.insert(2.3);
    my_buffer.insert(4.2);

    avg = my_buffer.get_average();
    cout << my_buffer.get_average() << endl;

}

void f1(){
    circ_buffer my_first_buffer(5);
    my_first_buffer.insert(8);
    my_first_buffer.insert(6);
    my_first_buffer.insert(7);
    my_first_buffer.insert(5);
    my_first_buffer.insert(3);
    my_first_buffer.insert(0);
    my_first_buffer.insert(9);

    cout << "most recent: " << my_first_buffer.get_element(0) << endl;
    cout << "second most recent: " << my_first_buffer.get_element(1) << endl;
    cout << "third most recent: " << my_first_buffer.get_element(2) << endl;

}

int main(){

    // f1();
    // f2();
    f3();
}