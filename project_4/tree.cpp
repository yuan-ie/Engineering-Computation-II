#include <iostream>
#include <string>
#include <vector>
using namespace std;



// template<typename T>
class tree{

    protected:

    const static int num_branches = 7000;
    vector <song> branch[num_branches];

    class node
    {
        public:
        int data;
        int key;
        node *left, *right, *up;   
        node(song s){
            int data;
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
                // if new data = current data, insert into vector
                else if (d == currPtr->data)
                {
                    LR = 2;
                    branch[d].push_back(s);
                    break;
                }

            }

            // connect newNode to parent
            newNode->up = parentPtr;

            // insert the struct object in vector in node
            if (LR==0)
            {
                parentPtr->left = newNode;
                // first element of its own vector
                branch[d].push_back(s);
            }
            else if (LR==1)
            {
                parentPtr->right = newNode;
                // first element of its own vector
                branch[d].push_back(s);
            }

        }

        // increment number of nodes
        nNodes++;
    }

    // true if songs match and bands match
    bool match(song s, song tmp)
    {
        return (s.sn == tmp.sn) && (s.bn == tmp.bn);
    }

    // search for the song inputted
    void search(song s)
    {
        // make a temporary song
        song tmp(s.bn,s.sn);

        // get the hash value for the tmp
        int d = hash_function(tmp);

        // new node things
        node *newNode   = new node(tmp);
        newNode->data = d;
        node *currPtr   = root;

        // display prompt
        cout << "\nsearching for song " << tmp.sn << ":" << endl;
        
        
        while (currPtr)
        {
            // if the tmp data is less than the current data,
            // go to current node's left child
            if (d < currPtr->data)
            {
                currPtr = currPtr->left;
            }
            // if the tmp data is more than the current data,
            // go to current node's right child
            else if (d > currPtr->data)
            {
                currPtr = currPtr->right;
            }
            // if tmp data = current data, go through the vectors
            else if (d == currPtr->data)
            {
                // TEST [success]
                // cout << branch[d][k].sn << " is stored in branch " << d << " and element " << k << endl;

                // go through the vectors until the right song + band is found
                for(int i=0; i<branch[d].size(); i++)
                {
                    cout << branch[d][i].sn << " by " <<  branch[d][i].bn << " at element " << i << endl;
                    // if match, end loop
                    if (match(branch[d][i], tmp))
                    {
                        cout << "match!" << endl;
                        break;
                    }
                }
                break;
            }

        }

        
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