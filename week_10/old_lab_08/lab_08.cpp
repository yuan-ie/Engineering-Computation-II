#include<iostream>
#include<iomanip>
#include <chrono>
#include <vector>
#include "heap.h"
#include "bubble.h"
#include "merge.h"
#include "RNG.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv){

    RNG R(10000);

    int n_trials_per_size = 1000;
    long int swaps_heap;
    long int swaps_bubl;
    long int swaps_merg;

    int buffer_size;
    int buffer_size_array[] = {50, 100, 200, 500, 1000, 2000};

    int array_len = sizeof(buffer_size_array) / sizeof(int);

    steady_clock::time_point t1,t2,t3,t4;
    float t_heap, t_merg, t_bubl;

    binary_heap data_heap;
    bubble_sort data_bubl;
    merge       data_merg;

    cout
    << setw(6) << "size"
    << "\t" << setw(12) << "swaps:heap"
    << "\t" << setw(12) << "swaps:bubl"
    << "\t" << setw(12) << "swaps:merg"
    << "\t" << setw(12) << "time:heap"
    << "\t" << setw(12) << "time:bubl"
    << "\t" << setw(12) << "time:merg"
    << endl;

    for (int k = 0; k<array_len; k++){
    
        buffer_size = buffer_size_array[k];

        swaps_heap = 0;
        swaps_bubl = 0;
        swaps_merg = 0;

        t_heap = 0;
        t_merg = 0;
        t_bubl = 0;

        for (int j = 0 ;j<n_trials_per_size;j++){

            R.reset();
            data_heap.reset(buffer_size);
            data_bubl.reset(buffer_size);
            data_merg.reset();
            
            for (int i = 0; i<buffer_size; i++){
                int val = R.gen();
                data_heap.insert (val);
                data_bubl.insert (val);
                data_merg.insert (val);
            }
    
            t1 = steady_clock::now();
            swaps_heap += data_heap.sort();
            t2 = steady_clock::now();
            swaps_bubl += data_bubl.sort();
            t3 = steady_clock::now();
            swaps_merg += data_merg.sort();
            t4 = steady_clock::now();

            t_heap += duration_cast<microseconds>(t2-t1).count();
            t_bubl += duration_cast<microseconds>(t3-t2).count();
            t_merg += duration_cast<microseconds>(t4-t3).count();

        }

        float avg_heap = (float) swaps_heap / n_trials_per_size;
        float avg_bubl = (float) swaps_bubl / n_trials_per_size;
        float avg_merg = (float) swaps_merg / n_trials_per_size;

        float avg_t_heap = t_heap / n_trials_per_size;
        float avg_t_bubl = t_bubl / n_trials_per_size;
        float avg_t_merg = t_merg / n_trials_per_size;
        
        cout << fixed
        << setprecision(2)
        << setw(6) << buffer_size 
        << "\t" << setw(12) << avg_heap 
        << "\t" << setw(12) << avg_bubl 
        << "\t" << setw(12) << avg_merg
        << "\t" << setw(12) << avg_t_heap
        << "\t" << setw(12) << avg_t_bubl
        << "\t" << setw(12) << avg_t_merg
        << endl;
        
    } 
    

    return 0;
    
}