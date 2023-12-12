#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void load_data(string filename)
{
    ifstream f_id;
    f_id.open(filename,ios_base::in);

    string line;
    int i_split;

    string header;

    string movie_ID, primary_title, original_title;
    string is_adult,  genres;

    // read the first line, store into header, and forget about it
    getline(f_id, header);
    
    while(getline(f_id,line))
    {
        int i = 0;
        // "line" is one complete line from the text file

        // find the comma, which separates band name from song
        i_split = line.find('\t');
        while (i_split != std::string::npos)
        {
            switch (i)
            {
            case 0:
                movie_ID = line.substr(0,i_split);
                cout << movie_ID << endl;
                break;
            case 1:
                title_type = line.substr(0,i_split);
                cout << title_type << endl;
                break;
            case 2:
                primary_title = line.substr(0,i_split);
                cout << primary_title << endl;
                break;
            case 3:
                original_title = line.substr(0,i_split);
                cout << original_title << endl;
                break;
            case 4:
                is_adult = line.substr(0,i_split);
                cout << is_adult << endl;
                break;
            case 5:
                start_year = line.substr(0,i_split);
                cout << start_year << endl;
                break;
            case 6:
                end_year = line.substr(0,i_split);
                cout << end_year << endl;
                break;
            case 7:
                runtime_minutes = line.substr(0,i_split);
                cout << runtime_minutes << endl;
                break;
            case 8:
                i_split = line.find("\n");   
                genres = line.substr(0,i_split);
                cout << genres << endl;
                break;
            default:
                break;
            }
            
            i++;
            line = line.substr(i_split + 1);
            i_split = line.find("\t");            
        }
        //line.erase(0, line.size()-1); // erase the carriage return at the end
        
    }
    f_id.close();
}

int main(int argc, char** argv){
    string filename;

    if (argc !=2 ){
        cout << "ERROR: include a command line arguement of 0, 1, or 2" << endl;
        return -1;
    }

    switch (stoi(argv[1])){
        case 0: filename = "/data/courses/ece_3822/current/project_5_data/movies.tsv"; break;
        case 1: filename = "/data/courses/ece_3822/current/project_5_data/names.tsv"; break;
        case 2: filename = "/data/courses/ece_3822/current/project_5_data/starring_roles.tsv"; break;
    }

    load_data(filename);

    return 0;
}