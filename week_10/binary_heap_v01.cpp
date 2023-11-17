#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>
using namespace std;

template<typename T>
class heap{

    //////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////
    private:

    T *buff;
    int bufflen;
    int n_items;
    int n_swaps;

    //////////////////////////////////////////////////////////////////////
    // Helper functions <private>
    //////////////////////////////////////////////////////////////////////
    int parent(int i){
        return floor((i-1)/2);
    }
    int left(int i){
        return (2*i + 1);
    }
    int right(int i){
        return (2*i + 2);
    }
    bool is_valid_idx(int idx){
        return (idx < n_items);
    }
    void swap(int i , int j){
        T tmp = buff[i];
        buff[i] = buff[j];
        buff[j] = tmp;
        n_swaps++;
    }

    //////////////////////////////////////////////////////////////////////
    // Bubble functions <private>
    //////////////////////////////////////////////////////////////////////
    void bubble_up(){
        // while current item > parent, swap and repeat
        int curr_idx = n_items;
        int parent_idx;

        while (true){
            
            // if at root of tree, then break, we're done
            if (curr_idx == 0)
                break;

            // if smaller than parent, then break, we're done
            parent_idx = parent(curr_idx);
            if (buff[curr_idx]< buff[parent_idx])
                break;

            // otherwise, swap and repeat
            swap(curr_idx , parent_idx);
            curr_idx = parent_idx;
            
        }
    }
    void bubble_down(){
        int curr_idx = 0;
        int largest_child_idx;

        while(true){
            largest_child_idx = find_largest_child(curr_idx);
            
            // if there are no valid children, break
            if (largest_child_idx==-1)
                break;

            // if current item is larger than valid children, break
            if (buff[curr_idx] > buff[largest_child_idx])
                break;
            
            // else, swap with largest child and set up for another pass
            swap(curr_idx,largest_child_idx);
            curr_idx = largest_child_idx;

        }

    }

    //////////////////////////////////////////////////////////////////////
    // Find index of largest valid child <private>
    //////////////////////////////////////////////////////////////////////
    int find_largest_child(int i){
        int l_idx = left(i);
        int r_idx = right(i);

        // if there are no valid children
        if (!is_valid_idx(l_idx))
            return -1;

        // if right isn't valid, then left is the only valid child
        if (!is_valid_idx(r_idx))
            return l_idx;
        
        // else, there are two valid children, so we must find the larger one
        if (buff[l_idx] > buff[r_idx])
            return l_idx;
        
        return r_idx;
    }

    //////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////
    public:


    //////////////////////////////////////////////////////////////////////
    // Constructor <public>
    //////////////////////////////////////////////////////////////////////
    heap(int BL=7){
        bufflen = BL;
        buff = new T[bufflen];
        n_items = 0;
        n_swaps = 0;
    }

    //////////////////////////////////////////////////////////////////////
    // Insert new item into heap <public>
    //////////////////////////////////////////////////////////////////////
    void insert(T x){
        buff[n_items] = x;
        bubble_up();
        n_items++;
    }

    //////////////////////////////////////////////////////////////////////
    // Display all items in heap array <public>
    //////////////////////////////////////////////////////////////////////
    void display_all(){
        for (int i = 0 ; i<n_items ; i++)
            cout << buff[i] << " ";
        cout << endl;
    }

    //////////////////////////////////////////////////////////////////////
    // Return whether heap array is empty <public>
    //////////////////////////////////////////////////////////////////////
    bool is_empty(){
        return n_items==0;
    }

    //////////////////////////////////////////////////////////////////////
    // Pop highest priority customer from the heap <public>
    //////////////////////////////////////////////////////////////////////
    T pop(){
        T return_value = buff[0];

        buff[0] = buff[n_items-1];
        n_items--;
        bubble_down();

        return return_value;
    }
    int get_n_swaps(){
        return n_swaps;
    }
};

//////////////////////////////////////////////////////////////////////
// Main function
//  Test basic heap functionality
//////////////////////////////////////////////////////////////////////
int main(){
    heap<float> my_heap(100000);;
    long int n_swaps;
    int n_trials = 50;
    int buff_size[] = {10,100,1000,10000,100000};

    /* initialize random seed: */
    srand (time(NULL));

    for (int k = 0 ; k<5 ; k++){

        n_swaps = 0;

        for (int j = 0 ; j<n_trials; j++){

            // insert buff_size random numbers
            for (int i = 0 ; i < buff_size[k] ; i++)
                my_heap.insert( (float)rand() / RAND_MAX );

            while (!my_heap.is_empty())
                my_heap.pop();

            n_swaps += my_heap.get_n_swaps();

        }


        cout << buff_size[k] << "\t" << float(n_swaps) / n_trials  << endl;
    }
    return 0;
}