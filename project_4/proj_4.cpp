#include <iostream>
#include <fstream>
#include "song_struct.h"
#include "hashtable.cpp"
#include "tree.cpp"

// global variable/class
hashtable_songname song_list;
tree song_tree;

void load_data(){
    
    string filename_complete = "/data/courses/ece_3822/current/project_4/songlist.txt";

    ifstream f_id;
    f_id.open(filename_complete,ios_base::in);

    string line;
    string band_name;
    string song_title;

    int i_split;

    while(getline(f_id,line)){

        // "line" is one complete line from the text file

        // find the comma, which separates band name from song
        i_split = line.find(',');

        //extract bandname and songname
        band_name = line.substr(0,i_split);         // band name is everything up till the comma
        line.erase(0,i_split+2);                    // erase band name plus comma, plus space
        song_title = line.substr(0, line.size()-1); // erase the carriage return at the end

        // insert the song title into the song list
        song s(band_name, song_title);

        // insert each song object in the hashtable and tree
        song_list.insert(s); // hashtable
        song_tree.insert(s); // tree
        
    }
    f_id.close();

}

void search_data(){
    
    string filename_complete = "/data/courses/ece_3822/current/project_4/songlist.txt";

    ifstream f_id;
    f_id.open(filename_complete,ios_base::in);

    string line;
    string band_name;
    string song_title;

    int i_split;
    int count = 0;
    int hash_traversals = 0;
    int tree_traversals = 0;

    while(getline(f_id,line)){

        // "line" is one complete line from the text file

        // find the comma, which separates band name from song
        i_split = line.find(',');

        //extract bandname and songname
        band_name = line.substr(0,i_split);         // band name is everything up till the comma
        line.erase(0,i_split+2);                    // erase band name plus comma, plus space
        song_title = line.substr(0, line.size()-1); // erase the carriage return at the end

        song s(band_name, song_title);

        // search for each song and get number of traversals
        song_list.search(s);
        hash_traversals += song_list.get_traversals();

        song_tree.search(s);
        tree_traversals += song_tree.get_traversals();

        count++;
        
    }

    float avg_hash = (float)hash_traversals / (float)count;
    float avg_tree = (float)tree_traversals / (float)count; 

    cout << " - Hashtable" << endl;
    cout << "   - average traversals: " << avg_hash << endl;
    cout << " - Binary Search Tree " << endl;
    cout << "   - average traversals: " << avg_tree << endl;
    f_id.close();
}


int main(){

    load_data();

    // TEST FUNCTIONS
    // song s1("The Who", "Rather Be");
    // song_list.search(s1);
    // song_tree.search(s1);

    cout << "\nMEMORY USAGE: " << endl;
    cout << " - Hashtable" << endl;
    cout << "   - Stack: " << sizeof(song_list) << endl;
    cout << " - Binary Search Tree " << endl;
    cout << "   - Stack: " << sizeof(song_tree) << endl;

    cout << "\nTRAVERSALS: " << endl;
    search_data();

    song_tree.num_nodes();

    // 1,643,851 bytes allocated // hash table heap
    // 4,904,886 bytes allocated // tree heap
    
    return 0;
}
