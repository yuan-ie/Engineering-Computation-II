#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class hashtable_generic
{
    protected:
    int n_elements;
    float memory;
    int traversals;

    string song_name;
    string band_name;

    const static int buff_len = 1000;

    // the buffer is a vector
    vector <song> buffer[buff_len];
    // song buffer[buff_len];

    // must be here to use the hash function of the child class
    virtual int hash_function(song) = 0;

    public:
    int i;

    hashtable_generic()
    {
        n_elements = 0;
        memory = 0;
    }

    // true if songs match and bands match
    bool match(song s, song tmp)
    {
        return (s.sn == tmp.sn) && (s.bn == tmp.bn);
    }

    float get_memory()
    {
        memory = sizeof(buffer);
        return memory;
    }

    int get_traversals()
    {
        return traversals;
    }

    void insert(song s)
    {
        int key;

        // cannot continue if buffer is full
        if (n_elements == buff_len)
            return;
        
        else
        {
            // hash the song name
            key = hash_function(s);

            // store the song into this buffer vector
            buffer[key].push_back(s);

            // increment elements
            n_elements++;
        }
    }
};

// hash table for song name
class hashtable_songname : public hashtable_generic
{
    protected:
    int hash_function(song s)
    {
        int sum = 0;
        int idx;
        song_name = s.sn;

        // temporary song name
        string tmp_song = song_name;

        // get the sum of song name
        for (int i=0; i<tmp_song.length(); i++)
        {
            sum += (i+1) * int(tmp_song[i]);
        }

        // guarantee that idx is between 0 and buff_len-1
        idx = sum % buff_len;

        // return index derived from song name
        return idx;  
    }

    // special fucntion to first/lastname hashtable
    // inserts names so it can find different students with the same name
    

    public:
    void search(song s)
    {
        song tmp(s.bn, s.sn);
        int i = 0;

        traversals = 0;
        
        // get the key from hash function
        int key = hash_function(tmp);
        traversals ++;

        // cout << "\nsearching for song " << tmp.sn << ":" << endl;
        
        // check through the vector of buffer[key] to see if it has matching song name
        for(i=0; i<buffer[key].size(); i++)
        {
            // cout << buffer[key][i].sn << " by " <<  buffer[key][i].bn << " at element " << i << endl;
            // if match, break the loop
            if (match(buffer[key][i], tmp))
            {
                // cout << "match!" << endl;
                break;
            }
            traversals ++;
        }
        
        // cout << "number of traversals: " << traversals <<  endl;
    }

};