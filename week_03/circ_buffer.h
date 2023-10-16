#ifndef CIRC_BUFFER_H
#define CIRC_BUFFER_H

class circ_buffer{

    private:

    void increment_ind(){
        ind_to_insert = (ind_to_insert+1) % buff_size;
    }

    float *buff = nullptr;
    int buff_size;
    int ind_to_insert;

    public:

    circ_buffer(int n = 10) {
        buff = new float[n];
        buff_size = n;
        ind_to_insert = 0;

        clear();
            
    }

    ~circ_buffer(){
        delete [] buff;
    }

    void clear(){
        for (int i = 0 ; i< buff_size; i++)
            buff[i] = 0;
    }

    void insert(float x){
        buff[ ind_to_insert ] = x;
        increment_ind();
    }

    // return the j'th element from the buffer
    // j=0 is the newest value
    // j=1 is the second newest value
    float get_element(int j){
        int ind = (buff_size + ind_to_insert - 1 - j) % buff_size;
        return buff[ind];
    }

    int get_buff_size(){
        return buff_size;
    }

};

#endif