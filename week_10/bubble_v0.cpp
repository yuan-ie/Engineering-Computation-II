#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

class bubble_sorter {
   public:
    // create a vector of N random floats
    void create_list(int N) {
        buffer.clear();
        for (int i = 0; i < N; i++) buffer.push_back((float)rand() / RAND_MAX);
    }

    // swap two elements in the vector
    void swap(int i, int j) {
        float tmp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = tmp;
        swap_count++;
    }

    // bubblesort the the list
    void sort_list() {

        swap_count = 0;
        int N = buffer.size();

        // for each top-level pass "j", find the jth largest
        // item and bubble it to the bottom
        for (int j = 0; j < N; j++) {

            // during the "jth" pass, bubble down to find the
            // jth largest item
            for (int i = 0; i < (N - 1 - j) ; i++) {

                // compare item i with item i+1, and swap if out of order
                if (buffer[i] > buffer[i + 1]) 
                    swap(i, i + 1);
            }

        }
    }

    // create a list of N floats and sort them, returning the number of swaps
    int create_and_sort(int N) {
        create_list(N);
        sort_list();
        return swap_count;
        
    }

    // print buffer contents
    void print_buffer() {
        for (int i = 0; i < buffer.size(); i++) cout << buffer[i] << endl;
    }

   private:
    vector<float> buffer;
    int swap_count;
};

int main() {

    // init random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    bubble_sorter x;
    int swap_count;
    int n_iterations = 100;

    // create a list of 50 numbers and sort them
    // return the swap count
    
    int N[] = {10,20,50,100,200,500,1000,2000,5000};
    for (int j = 0 ; j <9 ; j++){
        swap_count = 0;
        for (int i = 0 ; i < n_iterations ; i++){
            swap_count += x.create_and_sort(N[j]);
        }
        cout << N[j] << "\t" << (float)swap_count / n_iterations << endl;
    }

    return 0;
}