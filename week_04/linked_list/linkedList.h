#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace linked_list_node{
    template<typename T>
    class node{

        public:
        T data;
        node* next;

        node(){}
        node(T d , node* n){
            data = d;
            next = n;
        }
    };
}

template<typename T>
class linkedList{

    private:
    linked_list_node::node<T> *head;
    unsigned int nItems;

    public:
    linkedList(){
        head = nullptr;
        nItems = 0;
    }

    int len(){
        return nItems;
    }

    void insert(T newData){
        head = new linked_list_node::node<T>(newData , head);
        nItems++;
    }

    // alternate insert function
    // node *p_newNode = new node;
    // p_newNode->data = newData;
    // p_newNode->next = head;
    // head = p_newNode;

    void print_forward(){
        linked_list_node::node<T> *currPtr = head;
        while (currPtr){
            std::cout << currPtr->data << std::endl;
            currPtr = currPtr->next;
        }
    }

    void print_reverse(){
        print_reverse(head);
    }

    void print_reverse(linked_list_node::node<T> *currPtr){
        if (currPtr){
            print_reverse(currPtr->next);
            std::cout << currPtr->data << std::endl;
        }
    }

    void print_item(unsigned int n){

        int ctr = 0;
        linked_list_node::node<T> *currPtr = head;

        if (n>=nItems){
            std::cout <<"PRINT_ITEM n not found" << std::endl;
            return;
        }

        while (ctr < n){
            currPtr = currPtr->next;
            ctr ++;
        }
        std::cout << currPtr->data << std::endl;

    }

};


#endif