#include<iostream>
using namespace std;

class tree{

    protected:
    class node{
        public:
        int data;
        node *left, *right, *up;   
        node(int d){
            data  = d;
            left  = nullptr;
            right = nullptr;
            up    = nullptr;
        }
    }; // end class node

    node *root;
    int nNodes;

    public:
    // constructor - no parameters
    tree(){
        root   = nullptr;
        nNodes = 0;
    }    

    void insert(int d){
        node *newNode   = new node(d);
        node *currPtr   = root;
        node *parentPtr = nullptr;

        int LR;

        // special case if tree is empty
        if (nNodes == 0)
            root=newNode;
        
        else{

            // find which node should be parent to newNode
            while (currPtr){
                parentPtr = currPtr;
                if (d < currPtr->data){
                    currPtr = currPtr->left;
                    LR = 0;
                }
                else{
                    currPtr = currPtr->right;
                    LR = 1;
                }
            }

            // connect newNode to parent
            newNode->up = parentPtr;
            if (LR==0)
                parentPtr->left = newNode;
            else
                parentPtr->right = newNode;

        }

        // increment number of nodes
        nNodes++;

    }

    void print_all(){
        print_all(root);
    }

    void print_all(node *currNode){
        if (currNode){
            print_all(currNode->left);
            cout << currNode->data << endl;
            print_all(currNode->right);
        }
    }

    // search function
    // print all

}; // end class tree

int main(){
    tree douggy_pine;
    douggy_pine.insert(10);
    douggy_pine.insert(7);
    douggy_pine.insert(15);
    douggy_pine.insert(6);
    douggy_pine.insert(8);
    douggy_pine.insert(12);
    douggy_pine.insert(18);
    douggy_pine.insert(11);
    douggy_pine.insert(15);

    douggy_pine.print_all();

    cout << "ending" << endl;    

    return 0;
}