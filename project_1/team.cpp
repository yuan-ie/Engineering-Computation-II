#ifndef _TEAM_
#define _TEAM_

#include "player.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class team
{
    private:
    string team_name;
    int captain;
    int team_score = 0;
    //vector <string> player_list;
    vector <int> player_status;
    vector <player*> player_list;
    int count = 1; // count rounds

    public:

    team(string teamname)
    {
        team_name = teamname;
    }

    // PLAYER INFO
    string get_name();
    int add_player(player* p, int stats);
    
    // START PLAYING
    int play_turn();
    int get_score();
    
    // DISPLAY
    void display();
};

// get the name of the team
string team::get_name()
{
    return team_name;
}

// add players and captain to team (0 = normal, 1 = captain)
int team::add_player(player* p, int stats)
{
        p->player::set_status(stats);
        player_list.push_back(p);
        return stats;
    
}

// each player listed plays # turns each
// regular player has 1 turn, captain has 2 turns.
int team::play_turn()
{
    for(int i=0; i<player_list.size(); i++)
    {

        player* p = player_list[i];

        if (p->get_status()==1)
        {
            // PLAY TWICE IF CAPTAIN
            int score1 = p->play_turn();
            int score2 = p->play_turn();
            int score = score1 + score2;
        }
        else
            int score = p->play_turn();
            //int score = player_list[i]->player::play_turn(); //same thing as above
    }

    // UNCOMMENT TO CHECK THE NUMBER OF TURNS OF EACH TEAM
    /*
    cout << "ROUND " << count << endl;
    count++;
    cout << endl;
    */
    

    return 0;
}

// display each player's info
void team::display()
{
    for(int i=0; i<player_list.size(); i++)
    {
    player_list[i]->player::display();
    }
}

// get each player's score and total it for the team score
int team::get_score()
{
    team_score = 0;
    for(int i=0; i<player_list.size(); i++)
    {
        player* p = player_list[i];
        //int score = player_list[i]->player::get_score();
        int score = p->get_score();
        // cout << p << " scored " << score << endl; // CHECK EACH INDIVIDUAL TOTAL SCORE
        team_score = team_score + score; 
    }
    //cout << "total: " << team_score << endl; // CHECK TOTAL TEAM SCORE
    return team_score;
}

#endif