#include<iostream>
#include<vector>
using namespace std;

class merge_sort{
    public:

    vector<float> buffer;
    void insert(float x){
        buffer.push_back(x);
    }
    void push_front(float x){;}

    void print_all(){
        for (int i = 0 ; i<buffer.size() ; i++)
            cout << buffer[i] << endl;
    }

    vector<float> sort(vector<float> x={}){
        // mergesort: split the list into two sublists, sort the sublists, 
        // and then merge them back together

        // the first time sort gets called, x is assigned
        // "buffer"
        if ( x.empty() )
            x = buffer;

        vector<float> return_val = x;

        // if x is a singleton, don't split - its already sorted
        if (x.size()>1){

            // make left and right sublists
            int midpoint = x.size()/2;
            vector<float> left,right;
            int i;
            for (i = 0 ; i<midpoint ; i++)
                left.push_back(x[i]);
            for (i = midpoint ; i < x.size() ; i++)
                right.push_back(x[i]);

            // sort the sublists
            left  = sort(left);
            right = sort(right);

            // merge the sorted left and right sublists
            return_val.clear();
            while(true){

                // if first-in-left is smaller than first-in-right
                if (left[0] < right[0]){                    
                    return_val.push_back(left[0]);
                    left.erase(left.begin());
                }                

                // else if first-in-right is smaller than first-in-left
                else{
                    return_val.push_back(right[0]);
                    right.erase(right.begin());
                }

                // keep looping until one of the two sublists is empty
                if (left.empty() || right.empty())
                    break;
            }

            // push back whatever's left from the non-empty list
            for (i = 0 ; i< left.size() ; i++)
                return_val.push_back(left[i]);

            for (i = 0 ; i< right.size() ; i++)
                return_val.push_back(right[i]);

        }

        return return_val;
    }

};

int main(){
    merge_sort m;
    m.insert(9);
    m.insert(2);
    m.insert(1);
    m.insert(3);
    m.insert(5);
    m.insert(6);
    m.insert(8);
    m.insert(4);
    m.insert(7);
    m.insert(0);
    m.print_all();

    vector<float> sorted = m.sort();
    for (int i = 0 ; i<sorted.size() ; i++)
        cout <<sorted[i] << endl;

    return 0;
}