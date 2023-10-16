#ifndef _linked_list_h_
#define _linked_list_h_

/*
YUAN NGHIEM
tul16619@temple.edu
TUID: 915809283
October 3rd, 2023
*/

namespace ll_node{
    // node for the linked list data
    // do not edit
    class node{
        
        private:
        int data;
        node* next;

        public:
        
        // constructor
        node(int d){
            data = d;
            next = nullptr;
        };

        // getter, data
        int get_data(){
            return data;
        }

        // setter, 'next' pointer
        void set_next(node *n){
            next = n;
        }

        // getter, 'next' pointer
        node* get_next(){
            return next;
        }
    };
}

class linked_list{

    // private class variables
    private:

    ll_node::node* head;
    int n_elements;

    // public class methods
    public:

    linked_list(){
        head = nullptr;
        n_elements = 0;
    }

    void insert(int d){
        ll_node::node *newNode = new ll_node::node(d);
        newNode->set_next(head);
        head = newNode;
        n_elements++;
    }

    int pop()
    {
        int ret_val = 0;
        if (n_elements > 0){
            ret_val = head->get_data();

            // now tmpNode and head have the same address
            ll_node::node *tmpNode = head;

            // the next node is now head
            head = head->get_next();

            // deletes the address stored in tmpNode
            delete tmpNode;
            
            // number of elements is decremented
            n_elements --;
        }
        return ret_val;
    }

    // clear everything by popping everything
    void clear_list()
    {

        // using while loop since n_elements gets decremented everytime pop is used
        while (n_elements > 0)
        {
            //ll_node::node *current = head;
            // pop current data on stack and count gets decremented automatically
            pop();
        }
        //std::cout << "the number of elements is " << n_elements <<std::endl;
    }

    // if the linked list is empty, return true.
    // if not empty, return false.
    bool is_empty()
    {
        if (n_elements == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // find the size of all the data elements and return
    int size()
    {
        
        ll_node::node *current1 = head;
        int size_val = 0;
        while (current1 != nullptr)
        {
            // std::cout << current1->get_data() <<std::endl;
            current1 = current1->get_next();
            size_val++;
        }

        // note: i can do my while statement method OR just return n_elements
        // note: either works the same

        return size_val;
    }

    // find the sum of all the data and return
    int sum()
    {
        ll_node::node *current2 = head;
        int sum_val = 0;
        while (current2 != nullptr)
        {
            //std::cout << current2->get_data() <<std::endl;
            sum_val += current2->get_data();
            current2 = current2->get_next();
        }
        
        return sum_val;
    }
};

#endif