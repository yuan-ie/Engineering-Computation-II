#include <iostream>
#include <string>
#include <vector>
using namespace std;



// template<typename T>
class tree{

    protected:
    class node
    {
        public:
        int data;
        node *left, *right, *up;   
        node(song s){
            int data;
            left  = nullptr;
            right = nullptr;
            up    = nullptr;
        }
    }; // end class node

    const static int num_branches = 7000;
    vector <song> branch[num_branches];

    node *root;
    int nNodes;

    public:
    // constructor - no parameters
    tree(){
        root   = nullptr;
        nNodes = 0;
    }    

    int hash_function(song s)
    {
        int sum = 0;
        int idx;
        string song_name = s.sn;

        // temporary song name
        string tmp_song = song_name;

        // get the sum of song name
        for (int i=0; i<tmp_song.length(); i++)
        {
            sum += (i+1) * int(tmp_song[i]);
        }

        // guarantee that idx is between 0 and buff_len-1
        idx = sum % num_branches;

        // return index derived from song name
        return idx;  
    }

    void insert(song s)
    {
        int r;
        int d = hash_function(s);
        node *newNode   = new node(s);
        newNode->data = d;
        node *currPtr   = root;
        node *parentPtr = nullptr;

        int k;
        int LR;

        // special case if tree is empty
        if (nNodes == 0)
        {
            root=newNode;    
        }
        else
        {
            // get the hash value of the root
            // r = hash_function(root)
            // currPtr->data = r;
            // find which node should be parent to newNode
            while (currPtr)
            {
                parentPtr = currPtr;
                // if the new data is less than the current data,
                // go to current node's left child
                if (d < currPtr->data)
                {
                    currPtr = currPtr->left;
                    LR = 0;
                }
                // if the new data is more than the current data,
                // go to current node's right child
                else if (d > currPtr->data)
                {
                    currPtr = currPtr->right;
                    LR = 1;
                }
                // if new data = current data
                else if (d == currPtr->data)
                {
                    LR = 2;
                    // check for collisions
                    k = collision(d); // value only used to check where info is stored
                    branch[d].push_back(s);
                    //cout << branch[d][k].sn << " is stored in branch " << d << " and element " << k << endl;
                    break;
                }

            }

            // connect newNode to parent
            newNode->up = parentPtr;
            if (LR==0)
            {
                parentPtr->left = newNode;
                branch[d].push_back(s);
            }
            else if (LR==1)
            {
                parentPtr->right = newNode;
                branch[d].push_back(s);
            }

        }

        // increment number of nodes
        nNodes++;

    }

    // check if there is a collion, push back the vector
    int collision(int d)
    {
        // go to next
        int i;
        i = branch[d].size();
        return i;
    }

    void search (song s)
    {
        song tmp(s.bn,s.sn);
        int i = 0;
        int n = 0;
        int flag = 0;
        
        int key = hash_function(tmp);

        cout << "\nsearching for song " << tmp.sn << ":" << endl;
        // cout << key << endl;
        // cout << buffer[key].size() << endl;
        
        // check through the vector of buffer[key] to see if it has matching song name
        for(i=0; i<branch[key].size(); i++)
        {
            cout << branch[key][i].sn << " by " <<  branch[key][i].bn << " at element " << i << endl;
            // if match, raise the flag
            // if (match(buffer[key][i], song_name))
            // {
            //     flag = 1;
            //     i = i;
            //     break;
            // }
            n++;
        }
        // otherwise, flag is 0
        // cout << "i = " << i << " and flag is " << flag << endl;
        // cout << buffer[key][n].sn << " is stored in key " << key << " and element " << n << endl;
        // display(buffer[key][n],flag);
        
    }

    void count_nodes(){
        count_nodes(root);
    }

    void count_nodes(node *currNode){
        if (currNode){
            count_nodes(currNode->left);
            
            cout << currNode->data << endl;
            count_nodes(currNode->right);
        }
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