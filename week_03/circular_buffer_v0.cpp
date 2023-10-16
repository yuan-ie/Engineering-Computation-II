#include<iostream>
#include<string>
using namespace std;

class circ_buffer{
    private:


    void increment_ind(){
        ind_to_insert = (ind_to_insert+1) % buff_size;
    }
    // note: about % operator?

    int *buff = nullptr;
    int buff_size;
    int ind_to_insert;
    string buffName;

    public:

    // function called circ_buffer, with parameters
    circ_buffer(int n = 10 , string name = "default name"){
        buff = new int[n]; // creates vector of size 10 called buff
        buff_size = n; // buffer size is 10
        ind_to_insert = 0;
        buffName = name;

        clear();
            
    }

    // squiggle indicates deconstructor (instance is destroyed and memory is free'd)
    // this subroutine prints and deletes the buff vector object
    ~circ_buffer(){
        cout << "calling deconstructor for " << buffName <<endl;
        delete [] buff;
    }

    // subroutine that initializes every element in buff to zero
    void clear(){
        for (int i = 0 ; i< buff_size; i++)
            buff[i] = 0;
    }

    // values is inputted through int x from the main function
    // starts off at buff[0], then the index is incremented through the increment_ind subroutine
    void insert(int x){
        buff[ ind_to_insert ] = x;
        increment_ind();
    }

};

circ_buffer** f1(){
    circ_buffer my_third_buffer(10,"my third buffer");

    circ_buffer my_array_of_buffers[10];

    circ_buffer **my_other_array = new circ_buffer*[5];
    my_other_array[0] = new circ_buffer(5,"buff A");
    my_other_array[1] = new circ_buffer(5,"buff B");
    
    return my_other_array;

}

int main(){

    // my_buffer is on the STACK
    circ_buffer my_buffer(10 , "buffer 0");
    my_buffer.insert(12);
    my_buffer.clear();

    // declare on heap
    circ_buffer *my_second_buffer = new circ_buffer(5,"my second buffer");
    delete my_second_buffer;

    circ_buffer **last_var = f1();
    delete [] last_var;
    
    cout << "about to execute return 0" << endl;
    return 0;
    cout << "done doing return 0" << endl;
}