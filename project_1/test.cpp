#include<iostream>
#include <time.h>
#include<cstring>
#ifndef _PLAYER_
#define _PLAYER_

using namespace std;

void test_case_1();
//void test_case_2();
//void test_case_3();


class player
{
    private:
    
    //int lvl[3] = {0,1,2}; //ability level
    int lvl;
    int status[2] = {0,1}; //0:normal, 1:captain
    int score;
    string player_name;

    public:

    player(string name)
    {
        player_name = name;
    }

    int set_ability(int set);
    int reset_score();
    int play_turn();
    int get_score();
    void display();
};


int player::reset_score()
{
    score = 0;
    return score;
}

int player::set_ability(int set)
{
    //lvl = rand() % 3; // sets random number from range 0 to 2
    lvl = set;
    //cout << set << endl;
    return lvl;
}

int player::play_turn()
{
    int add_score;

    switch (lvl)
    {
    case(0):
         add_score = rand() % 4; // scores 0, 1, 2, or 3
         score = score + add_score;
    break;

    case(1):
    add_score = rand() % 4 + 2; // scores 2, 3, 4, or 5
         score = score + add_score;
    break;

    case(2):
    add_score = rand() % 4 + 4; // scores 4, 5, 6, or 7
         score = score + add_score;
    break;
    }
    return score;
}

int player::get_score()
{
    return score;
}

void player::display()
{
    cout << "PLAYER NAME: " << player_name << endl;
    cout << "ABILITY LVL: " << lvl << endl;
    cout << "TOTAL SCORE: " << score << endl;
}

//#define _PLAYER_
#endif


int main(int argc, char **argv){

    // randomize the random number generator
    srand(time(NULL));

    // pick a test case to run, or modify to create your own
    if (argc == 1){
        cout << "error - specify test case 1, 2, or 3 at the command line" << endl;
        exit(EXIT_FAILURE);
    }
   
    if ( strcmp(argv[1] , "1") == 0 )
        test_case_1();
    
    /*
    else if ( strcmp(argv[1] , "2") == 0)
        test_case_2();
    
    else if ( strcmp(argv[1] , "3") == 0)
        test_case_3();
    */
    
    else{
        cout << "error - invalid command line option" << endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}

// Test ability to create players
void test_case_1(){

    cout << "********** Test Case 1 **********" << endl;

    // create a player
    player alice("Alice Adams");

    // reset player's score to zero
    alice.reset_score();

    // set player's ability (0, 1, or 2)
    alice.set_ability(2);

    // player gets a single turn (score is incremented by a random number)
    alice.play_turn();

    // return the player's score
    int score = alice.get_score();

    // display the player's name and total score
    alice.display();

    cout << endl;
}