#include <iostream>
#include <string>
#include <vector>
using namespace std;

class tree{

    protected:   

    class node
    {
        public:
        int key;
        int data;
        vector <song> branch;
        node *left, *right, *up;   
        node()
        {
            left  = nullptr;
            right = nullptr;
            up    = nullptr;
        }
    }; // end class node

    node *root;
    int nNodes;
    float memory = 0;
    int traversals;

    public:
    // constructor - no parameters
    tree(){
        root   = nullptr;
        nNodes = 0;
    }    

    int get_traversals()
    {
        return traversals;
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
        idx = sum;

        // return index derived from song name
        return idx;  
    }

    void insert(song s)
    {
        // get the index from hash function
        int idx = hash_function(s);

        // create new node and do node things
        node *newNode   = new node();
        newNode->data = idx;
        node *currPtr   = root;
        node *parentPtr = nullptr;

        int LR;

        // special case if tree is empty
        if (nNodes == 0)
        {
            root=newNode;    
            // increment number of nodes
            nNodes++;
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
                if (idx < currPtr->data)
                {
                    currPtr = currPtr->left;
                    LR = 0;
                }

                // if the new data is more than the current data,
                // go to current node's right child
                else if (idx > currPtr->data)
                {
                    currPtr = currPtr->right;
                    LR = 1;
                }

                // if new data = current data, insert into vector
                else if (idx == currPtr->data)
                {
                    LR = 2;
                    currPtr->branch.push_back(s);
                    break;
                }

            }

            // connect newNode to parent
            newNode->up = parentPtr;

            if (LR==0) // go to left child node
            {
                parentPtr->left = newNode;
                // first element of its own vector
                newNode->branch.push_back(s);
                // increment number of nodes
                nNodes++;
            }
            else if (LR==1) // go to right child node
            {
                parentPtr->right = newNode;
                // first element of its own vector
                newNode->branch.push_back(s);
                // increment number of nodes
                nNodes++;
            }

        }

    }

    // true if songs match and bands match
    bool match(song s, song tmp)
    {
        return (s.sn == tmp.sn) && (s.bn == tmp.bn);
    }

    // search for the song inputted
    void search(song s)
    {
        traversals = 0;

        // make a temporary song
        song tmp(s.bn,s.sn);

        // get the hash value for the tmp
        int d = hash_function(tmp);
        traversals ++;

        node *currPtr   = root;

        // display prompt
        // cout << "\nsearching for song " << tmp.sn << " by " << tmp.bn << ":" << endl;
        
        
        while (currPtr)
        {
            // if the tmp data is less than the current data,
            // go to current node's left child
            if (d < currPtr->data)
            {
                currPtr = currPtr->left;
                traversals ++;
            }
            // if the tmp data is more than the current data,
            // go to current node's right child
            else if (d > currPtr->data)
            {
                currPtr = currPtr->right;
                traversals ++;
            }
            // if tmp data = current data, go through the vectors
            else if (d == currPtr->data)
            {
                // go through the vectors until the right song + band is found
                for(int i=0; i<currPtr->branch.size(); i++)
                {
                    // cout << currPtr->branch[i].sn << " by " <<  currPtr->branch[i].bn << " at element " << i << endl;
                    // if match, end loop
                    if (match(currPtr->branch[i], tmp))
                    {
                        // cout << "match!" << endl;
                        break;
                    }
                    traversals ++;
                }
                break;
            }
        } 

        //cout << "number of traversals: " << traversals <<  endl;
    }

    void num_nodes()
    {
        cout << "\nNumber of Nodes in Tree: " << nNodes << endl;
    }

}; // end class tree