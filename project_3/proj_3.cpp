/* PROJECT 3 - proj_3.cpp

    @author
    @contact
    @date

    Implements a system that models reading data asynchronously from the cloud,
    storing it temporarily in a buffer, and then placing it into a hash table.

    Compile:
        make all
    Compile for debug:
        make debug
    Run:
        ./proj_3 [OPT]
        where [OPT] is 1, 2, or 3 depending on which test case you are running.

*/
#include<iostream>
#include<thread>
#include<fstream>
#include<vector>
#include<chrono>
#include<mutex>

using namespace std;
using namespace std::chrono;

// YOUR CODE HERE
struct student{};

// YOUR CODE HERE
class hashTable{};

// YOUR CODE HERE
class queue{};

// You will need these global variables
queue waiting_list;
hashTable student_db;
mutex queue_mutex;

// this controls the input timing. do not edit
bool stop_thread = false;
steady_clock::time_point t1 = steady_clock::now();
float t_elapsed(){
    return duration_cast<seconds>(steady_clock::now() - t1).count();
}


void process_input_data(){
    student* p_student;

    while (!stop_thread){
        queue_mutex.lock();

        // YOUR CODE HERE
        // Checking the queue
        // If there's data, remove it from the queue and
        // add it to the hash table

        queue_mutex.unlock();
    }
}

void load_data(string filename){
    string shared_path = "/data/courses/ece_3822/current/project_3/";
    string filename_complete = shared_path + filename;

    // create local variables to stash the data for each person as it's
    // read from the file
    float arrival_time,gpa;
    string first,last,major;
    int id;

    ifstream f_id;
    f_id.open(filename_complete,ios_base::in);

    // start the thread that will wait for input data to arrive
    thread thr(process_input_data);

    clock_t t_start = clock();
    while (f_id >> arrival_time){
        // read data for the next person in the file
        f_id >> first;
        f_id >> last;
        f_id >> gpa;
        f_id >> id;
        f_id >> major;

        // wait until their data packet has 'arrived'
        while ( t_elapsed() < arrival_time){
            ;
        }

        // YOUR CODE HERE
        // [1] create a new student

        queue_mutex.lock();

        // YOUR CODE HERE
        // [2] add the new student to the wait queue

        queue_mutex.unlock();

    }

    f_id.close();                       // close the data file
    
    while (!waiting_list.is_empty()){   // wait for the waiting_list queue
        ;                               // to empty out before stopping the 
    }                                   // process_input_data thread

    stop_thread = true;                 // send a signal to the thread to stop running
    thr.join();                         // wait for the thread to finish up
}

int main(int argc, char** argv){
    string filename;

    if (argc !=2 ){
        cout << "ERROR: include a command line arguement of 0, 1, or 2" << endl;
        return -1;
    }

    switch (stoi(argv[1])){
        case 0: filename = "student_data_short.txt"; break;
        case 1: filename = "student_data_medium.txt"; break;
        case 2: filename = "student_data.txt"; break;
    }

    load_data(filename);

    // now that the data has been stored in the hash table, lets test hashtable lookup
    // if the student is found, print all their info
    // if not, print <student name> "not found"

    // YOUR CODE HERE FOR TESTING THE SEARCH/LOOKUP capability

    // search for the following student IDs
    // 427980112
    // 258399712
    // 948140115

    return 0;
}