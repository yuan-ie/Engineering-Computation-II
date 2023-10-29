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
struct student
{
    string first;
    string last;
    float gpa;
    int id;
    string major;

    student(string f = "", string l = "", float g = 0.0, int num = 0, string m = "")
    {
        first = f;
        last = l;
        gpa = g;
        id = num;
        major = m;
    }

    bool is_empty(){
        return ((first=="") & (last=="") & (gpa==0) & (id==0) & (major==""));
    }
};

/*----------------------------------------------------*/
// YOUR CODE HERE
// generic hash table (parent hash table)
class hashTable_generic
{
    protected:
    int n_elements;
    int max_elements;

    string first_name;
    string last_name;
    float gpa_;
    int id_num;
    string major_;

    // besides push back, not sure how to implement an array without a specific size
    // especially when the number of students gets incremeneted at an inconsistent time
    const static int buff_len = 100000;
    student buffer[buff_len];

    virtual int hash_function(student) = 0;

    public:
    int i;

    hashTable_generic()
    {
        n_elements = 0;
    }

    int collision(int key)
    {
        // if the index is not empty, move to the next
        while(buffer[key].id != 0)
            key = (key + 1) % buff_len;

        return key;
    }

    bool match(student s, string f, string l)
    {
        return ((s.first == f) && (s.last == l));
    }

    void insert(student s)
    {
        int key;
        // cout << "buffer length: " << buff_len << endl;
        // cout << "number of elements: " << n_elements << endl;
        if (n_elements == buff_len)
            return;

        // if (already_in_buffer(s))
        //     return;
        else
        {
            key = hash_function(s);
            //cout << buffer[key].first << endl;

            key = collision(key);
            buffer[key] = s;
            //cout << buffer[key].first << endl;
            n_elements++;
        }    
    }

    void display(student s, int flag)
    {
        if(flag==1)
            cout << s.first << " " << s.last << " " << s.gpa << " " << s.id << " " << s.major << endl;
        if(flag==0)
            cout << "student not found" << endl;
    }

    void read_all()
    {
        for(int i=0; i<50000; i++)
        {
            student s = buffer[i];
            cout << s.first << " " << s.last << " " << s.gpa << " " << s.id << " " << s.major << endl;
        }
    } 

};

/*----------------------------------------------------*/
// hash table for first and last name
class hashTable_first_and_last : public hashTable_generic
{
    protected:
    int hash_function(student s)
    {
        int sum = 0;
        int idx;
        last_name = s.last;
        first_name = s.first;

        // temporary student last name
        student tmp_student (first_name,last_name,0.0,0,"");

        for (int i=0; i<first_name.length(); i++)
        {
            sum += (i+1) * int(first_name[i]);
        }
        for (int i=0; i<last_name.length(); i++)
        {
            sum += (i+1) * int(last_name[i]);
        }

        // guarantee that idx is between 0 and buff_len-1
        idx = sum % buff_len;

        // return index derived from id number
        return idx;  
    }

    public:
    void search(string f, string l)
    {
        // parameters: (first name, last name, gpa, id, major)
        // only put id number in empty student data
        student tmp(f,l,0.0,0,"");
        int i = 0;
        int flag;
        
        int key = hash_function(tmp);

        while(!match(buffer[key], f, l))
        {
            key = (key+1) % buff_len;
            i++;
            if (i==buff_len)
                break;
        }
        if (match(buffer[key],f,l))
            flag = 1;
        else
            flag = 0;

        display(buffer[key],flag);
        
    }

};

// hash table for ID number
class hashTable_ID : public hashTable_generic
{
    protected:
    int hash_function(student s)
    {
        int sum = 0;
        int idx;
        int tmp_id;
        int digit;
        int i = 0;
        int prod;

        id_num = s.id;

        // temporary id number
        tmp_id = id_num;

        for (int i=0; i<9; i++)
        {
            // get last digit of id number
            digit = tmp_id % 10;
            sum += digit;

            // remove last digit
            tmp_id /= 10;
        }
        sum = sum + id_num;
        // guarantee that idx is between 0 and buff_len-1
        idx = sum % buff_len;

        // return index derived from id number
        return idx;  
    }

    bool match (student s, int id)
    {
        return (s.id == id);
    }

    public:
    void search(int id)
    {
        // parameters: (first name, last name, gpa, id, major)
        // only put id number in empty student data
        student tmp("","",0.0,id,"");
        int flag;
        int i = 0;
        
        int key = hash_function(tmp);

        while(!match(buffer[key], id))
        {
            key = (key+1) % buff_len;
            i++;
            if (i==buff_len)
                break;
        }
        if (match(buffer[key], id))
            flag = 1;
        else
            flag = 0;

        display(buffer[key],flag);
    }
};

/*----------------------------------------------------*/

class hashTable
{
    private:
    hashTable_ID                HT_ID;
    hashTable_first_and_last    HT_FL;
    //hashTable_lastName          HT_L;
    
    student std;

    public:
    void insert(student s)
    {
        // insert the student into the ID hashtable and the first/last name hashtable
        HT_ID.insert(s);
        HT_FL.insert(s);
    }

    void search_by_ID(int num)
    {
        // search by ID. if not found, print student not found.
        cout << "search by ID: " << num << endl;
        HT_ID.search(num);
        cout << endl;
    }
    void search_by_first_and_last(string f, string l)
    {
        // search by first and last name. if not found, print student not found.
        cout << "search by first and last name: " << f << " " << l << endl;
        HT_FL.search(f,l);
        cout << endl;
    }

    void read_all()
    {
        HT_ID.read_all();
    }
};


// YOUR CODE HERE
class queue
{
    protected:
    vector <student> list;
    int n_ele;
    int i;
    hashTable student_db;

    public:
    queue()
    {
        n_ele = 0;
    }

    // check if there is anything in the queue
    bool is_empty()
    {
        return (n_ele == 0);
    }
    
    // insert student to queue
    void insert(student s)
    {
        list.push_back(s);
        n_ele++;
    }

    // type student: return type student
    student pop()
    {
        student temp = list[0];
        
        // cout << temp.first << endl;
        
        // reorganize vector (push all values back one space)
        for(i = 1; i<n_ele; i++)
        {
            // example, if there are 5 elements: list[0]-list[4]
            // list[0] = list[1] to list[3] = list[4]
            // then pop_back (delete) list[4]
            list[i-1] = list[i];
        }
        // pop the last element
        list.pop_back();
        // decrement number of elements
        n_ele--;

        // check
        // cout << list[4].first << endl;
        
        return (temp);
    }
};

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
    student temp;

    while (!stop_thread){
        queue_mutex.lock();


        // YOUR CODE HERE
        // Checking the queue
        // If there's data, remove it from the queue and
        // add it to the hash table

       // if waiting list is not empty
        while (!waiting_list.is_empty())
        {
            // pop the students off the waiting list
            temp = waiting_list.pop();
            // check
            // cout << temp.first << endl;

            // insert the student's data into the database
            student_db.insert(temp);
        }

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
    // int i = 0;
    // vector <student> s;

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
        student s(first, last, gpa, id, major);
        
        queue_mutex.lock();

        // YOUR CODE HERE
        // [2] add the new student to the wait queue
        
        waiting_list.insert(s);
        

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

    // student_db.read_all();
    student_db.search_by_first_and_last("Jason", "Allen");
    student_db.search_by_first_and_last("Jason", "Li");

    student_db.search_by_ID(427980112);
    student_db.search_by_ID(258399712);
    student_db.search_by_ID(948140115);
    student_db.search_by_ID(793669913);
    student_db.search_by_ID(694699717);
    student_db.search_by_ID(640860013);
    student_db.search_by_ID(863830115);

    return 0;
}