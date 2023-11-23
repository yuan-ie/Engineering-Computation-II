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

        // check to make sure it worked
        // cout << band_name << " <<- " << song_title << endl;
    	// cout << song_title << " <<- " << band_name << endl;

        // insert the song title into the song list
        song s(band_name, song_title);
        song_list.insert(s);
        song_tree.insert(s);
        
    }
    f_id.close();

}



int main(){

    load_data();

    song s1("The Who", "Rather Be");
    song_list.search(s1);
    song_tree.search(s1);

    //song_list.search("Uptown Funk");
    
    // song_list.search("Timber");
    // song_list.search("New Rules");

    //song_tree.search("Uptown Funk");
    
    // song_tree.search("Timber");
    // song_tree.search("New Rules");
    
    return 0;
}
