#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


class hashtable_generic
{
    protected:
    int n_elements;
    int max_elements;

    string song_name;
    string band_name;

    // each buffer will contain 1000 songs
    const static int buff_len = 7000;

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
    }

    // check if there is a collion, push back the vector
    int collision(int key)
    {
        // go to next
        i = 0;
        if (buffer[key].size() == 0)
            i = 0;
        else
        {
            // let i = buffer size if this buffer exists
            i = buffer[key].size();
        }
        
            // key = (key + 1) % buff_len;
        return i;
    }

    bool match(song s, song tmp)
    {
        return (s.sn == tmp.sn) && (s.bn == tmp.bn);
    }

    void insert(song s)
    {
        int key, k;
        if (n_elements == buff_len)
            return;
        
        else
        {
            // hash the song name
            key = hash_function(s);
            // cout << key << endl;

            // check for any collisions
            k = collision(key);
            // cout << k << endl;

            // store the song into this buffer element
            buffer[key].push_back(s);
            // buffer[key] = s;
            // int size_b = buffer[key].size();

            n_elements++;

            cout << buffer[key][k].sn << " is stored in key " << key << " and element " << k << endl;
        }
    }

    // display student info if the student exists.
    // if student DNE, display student not found
    void display(song s, int flag)
    {
        if(flag==1)
            cout << song_name << " found" << endl;
        if(flag==0)
            cout << "song not found" << endl;
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
        int n = 0;
        int flag = 0;
        
        int key = hash_function(tmp);

        cout << "\nsearching for song " << tmp.sn << ":" << endl;
        // cout << key << endl;
        // cout << buffer[key].size() << endl;
        
        // check through the vector of buffer[key] to see if it has matching song name
        for(i=0; i<buffer[key].size(); i++)
        {
            cout << buffer[key][i].sn << " by " <<  buffer[key][i].bn << " at element " << i << endl;
            // if match, raise the flag
            if (match(buffer[key][i], tmp))
            {
                flag = 1;
                cout << "match!" << endl;
                break;
            }
        }
        
    }

};