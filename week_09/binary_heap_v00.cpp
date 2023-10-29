#include<iostream>
using namespace std;

class heap{
    private:
    int *buff;
    int bufflen;
    int n_items;

    public:
    heap(int BL=7){
        bufflen = BL;
        buff = new int[bufflen];
        n_items = 0;
    }
    void insert(int x){
        buff[n_items] = x;
        bubble_up();
        n_items++;
    }
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

        // while ( buff[curr_idx] > buff[parent(curr_idx)]){
        //     swap(curr_idx , parent(curr_idx));
        //     curr_idx = parent(curr_idx);
        // }       
    }
    void display_all(){

    }
};

int main(){
    heap my_heap;

    my_heap.insert(3);
    my_heap.insert(6);
    my_heap.insert(8);
    my_heap.insert(7);
    my_heap.insert(5);
    my_heap.insert(0);
    my_heap.insert(9);

    my_heap.display_all();

    return 0;
}