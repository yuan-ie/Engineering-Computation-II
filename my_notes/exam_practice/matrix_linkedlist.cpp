#include<iostream>
using namespace std;

class matrix{
    private:
    struct node
    {
        node* right;
        node* up;
        int data;
        node() 
        {
            data = 0;
            right = NULL;
            up = NULL;
        }   
    };
    node* head;

    // MUST BE DECLARED AS A MEMBER FUNCTION TO BE USED IN CLASS SUBROUTINE
    int row;
    int col;
    int max = 0;
    int i, j = 0;

    public:

    // SYNTAX FOR CONSTRUCTOR *    
    // note: TYPE DEFINITION UNNECESSARY
    // note: constructors do NOT return value
    matrix()
    {
        row = 3; // 3 rows
        col = 4; // 4 rows
        head = nullptr; // initialize to 0
        head = new node; // allocate memory to head pointer
    
    }

    // let's say they must choose a number for r and c, but r and c CAN be zero
    void write(int x , int r , int c)
    {
        int i, j; // i for row, j for col
        node *newElement = new node;
        newElement->data = x;

        node *current = head; // make a pointer "current" with the same memory location as head
        // that way, the location of head is not overwritten


        // find where to insert the new Element in the array
        // create new spaces in the array. don't create more if not needed.
        for (i=0; i<r; i++)
        {
            if (current->up == nullptr)
            {
                node *newRow = new node;
                current->up = newRow;
            }
            current = current->up;
        }
        for (j=0; i<c; i++)
        {
            if (current->right == nullptr)
            {
                node *newCol = new node;
                current->right = newCol;
            }
            current = current->right;
        }
        
        current->data = x;
    }

    int max()
    {
        node *current = head;

         // count initialized to 0
        for (i=0; i<row; i++)
        {
            int up_count=0;
            // go through all columns in this row
            for (j=0; j<col; j++)
            {
                if (max < current->data)
                {
                    max = current->data;
                }
                current = current->right;
            }
            current = head;
            while (up_count<i+1)
            {
                current = current->up;
                up_count++;
            }
            
        }
        return max;
    }
};
int main(){
return 0;
}

