#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace linked_list_node{
    class node{

        public:
        node(){}
        node(double d , node* n){
            data = d;
            next = n;
        }
        double data;
        node* next;
    };
}

class linkedList{

    private:
    linked_list_node::node *head;
    unsigned int nItems;

    public:
    linkedList(){
        head = nullptr;
        nItems = 0;
    }

    int len(){
        return nItems;
    }

    void insert(double newData){
        head = new linked_list_node::node(newData , head);
        nItems++;
    }

    // alternate insert function
    // node *p_newNode = new node;
    // p_newNode->data = newData;
    // p_newNode->next = head;
    // head = p_newNode;

    void print_forward(){
        linked_list_node::node *currPtr = head;
        while (currPtr){
            std::cout << currPtr->data << std::endl;
            currPtr = currPtr->next;
        }
    }

    void print_reverse(){
        print_reverse(head);
    }

    void print_reverse(linked_list_node::node *currPtr){
        if (currPtr){
            print_reverse(currPtr->next);
            std::cout << currPtr->data << std::endl;
        }
    }

    void print_item(unsigned int n){

        int ctr = 0;
        linked_list_node::node *currPtr = head;

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