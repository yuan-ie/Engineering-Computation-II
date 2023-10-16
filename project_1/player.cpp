#ifndef _PLAYER_
#define _PLAYER_

/* this include gives you access to 
    int generate_score(int)
which takes ability (0,1,2) as input and returns a valid 
score according to the project instructions */

#include "ece_3822.h" // i didnt use this at all sorry
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class player
{
    private:
    
    //int lvl[3] = {0,1,2}; //ability level
    int lvl;
    int status; //0:normal, 1:captain
    int score;
    string player_name;

    public:

    // set player's name ONLY
    player(string name)
    {
        player_name = name;
    }

    // set player's name AND ability level
    player(string name, int set)
    {
        player_name = name;
        lvl = set;
    }

    string set_playername(string name);
    int set_ability(int set);
    int reset_score();
    int play_turn();
    int get_score();
    void display();
    int set_status(int stats);
    int get_status();
};


// initialize score to zero
int player::reset_score()
{
    score = 0;
    return score;
}

// set the players status to 0 = normal or 1 = captain given by main program
int player::set_status(int stats)
{
    status = stats;
    return status;
}

// get the (regular or captain) status of the player
int player::get_status()
{
    return status;
}


// set the ability of player given by the main program
int player::set_ability(int set)
{
    lvl = set;
    return lvl;
}

// each turn is based on the ability skill of the player
int player::play_turn()
{
    int add_score;

    switch (lvl)
    {
    case(0):
         add_score = rand() % 4; // scores 0, 1, 2, or 3
         score = score + add_score; 
         //cout << player_name << " scored " << add_score << endl; // CHECK EACH INDIVIDUAL SCORE
    break;

    case(1):
    add_score = rand() % 4 + 2; // scores 2, 3, 4, or 5
         score = score + add_score;
         //cout << player_name << " scored " << add_score << endl; // CHECK EACH INDIVIDUAL SCORE
    break;

    case(2):
    add_score = rand() % 4 + 4; // scores 4, 5, 6, or 7
         score = score + add_score;
         //cout << player_name << " scored " << add_score << endl; // CHECK EACH INDIVIDUAL SCORE
    break;
    }
    return score;
}

// get score from each turn
int player::get_score()
{
    return score;
}


// DISPLAY EVERYTHING ABOUT THE PLAYER
void player::display()
{
    cout << "PLAYER NAME: " << player_name << endl;

    // UNCOMMENT TO CHECK ABILITY LEVEL AND STATUS
    /*
    cout << "ABILITY LVL: " << lvl << endl;
    cout << "STATUS: " << status << endl; // CHECK STATUS
    if (status==1)
        cout << "STATUS: captain" << endl;
    if (status==0) 
        cout << "STATUS: regular" << endl;
    */

    cout << "TOTAL SCORE: " << score << endl;
    cout << endl;

}



//#define _PLAYER_
#endif