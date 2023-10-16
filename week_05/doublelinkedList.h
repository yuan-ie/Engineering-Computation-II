#ifndef LINKED_LIST_H
#define LINKED_LIST_H


template<typename T>
class doublelinkedList{

    // access specifier, allows variable accessibility from sub classes
    protected:

    // class node within class double linked list
    class node{

        public:
        T data; // data is type T (template)
        node* next; // declare next as a pointer to node
        node* prev; // declare prev as a pointer to node

        node(){}
        node(T d)
        {
            data = d;
            next = nullptr; // next is initialized to null = 0
            prev = nullptr; // prev is initialized to null = 0
        }
        node(T d , node* n , node* p){
            data = d;
            next = n;
            prev = p;
        }
    };

    // note: when using *, it creates previous word as a type -> pointer type
    node *head; // declare head as a pointer to "node" object
    node *tail; // declare tail as a pointer to "node" object
    unsigned int nItems;

    /*-----------------------------------------------------------------------------*/

    // access specifier, allows variable accessibility from anywhere, even outside of code
    public:

    // constructor
    doublelinkedList()
    {
        head = nullptr; //nullptr is a pointer that doesnt point to any valid memory location
        tail = nullptr;
        nItems = 0; // initialize number of items to zero
    }

    // squiggle denotes deconstructor   
    // removes all elements from linked list
    ~doublelinkedList()
    {
        pop_all();
    }

    int len(){
        return nItems;
    }

    // add next data onto linked list
    void insert_tail(T newData){

        // declares newNode as a pointer to node
        // allocates memory for new instance of "node" class, and creates a new "node" object to the pointer
        // initializes this new node object with "newData"
        node *newNode = new node(newData);

        if (nItems > 0){
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {
            head = newNode;
            tail = newNode;
        }
        nItems++;
    }

    void insert_head(T newData){
        
        node *newNode; // newNode created as a pointer to node
        newNode = new node(newData); // memory allocated for newNode and is initialized with the value "newData"

        // checks if list is empty
        if (nItems > 0)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else{
            head = newNode;
            tail = newNode;
        }

        nItems++;

    }

    void print_forward(){
        node *currPtr = head;
        while (currPtr){
            std::cout << currPtr->data << std::endl;
            currPtr = currPtr->next;
        }
    }

    void insert(T newData){
        insert_head(newData);
    }

    T pop(){
        T return_val = head->data;
        node *currPtr = head;
        head = head->next;
        delete currPtr;
        nItems--;
        return return_val;
    }

    void pop_all(){
        while (nItems>0)
            pop();
    }

};


#endif