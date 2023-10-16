/*
YUAN NGHIEM
October 8, 2023
TUID: 915809283
tul16619@temple.edu
*/


#include<iostream>
#include<fstream>
#include "linked_list.h"

#include <vector>
#include <cstring>
using namespace std;

#define DEFAULT_DIRECTORY "/data/courses/ece_3822/current/project_2/"
#define DEFAULT_FILENAME "dataFile1.txt"
#define FILE_2 "dataFile2.txt"
#define FILE_3 "dataFile3.txt"



// do not edit
string get_filename(int argc, char** argv){
    string filename = DEFAULT_DIRECTORY;
    
    // no command line inputs: use default
    if (argc == 1)
        filename += DEFAULT_FILENAME;

    else if ( strcmp(argv[1] , "1") == 0 )
        filename += DEFAULT_FILENAME;
    
    else if ( strcmp(argv[1] , "2") == 0)
        filename += FILE_2;
    
    else if ( strcmp(argv[1] , "3") == 0)
        filename += FILE_3;
    //command line filename given
    else
        filename += (string) argv[1];
    
    return filename;

}

/*-------------------------------------------------------------*/

class linked_list_movies : public linked_list<int>{
    public:
    int views;

    // display all the movie IDs of each customer
    void display()
    {
        node *current;
        current = head;
        while (current != nullptr)
        {
            //cout << current->data << endl;
            current = current->next;
        }
    
    }

    // look through the movie IDs and find number of views for specific movie
    void read_views(int id)
    {
        node *current;
        current = head;
        views = 0;
        //cout << id << endl;
        while (current != nullptr)
        {
            //cout << current->data << endl;
            if(current->data == id)
            {
                views++;
            }
            current = current->next;
        }
        cout << "movie " << id << " was watched " << views << " time(s)" << endl;
    }
};

/*-------------------------------------------------------------*/

// THIS CLASS HAS ALMOST EVERYTHING
class organize_list : public linked_list<int>
{
    public:
    int i; // resets in loop
    int j=0; // does not reset
    vector <node*> customer_ID;
    vector <node*> keep_movie_ID;
    

    organize_list()
    {
        linked_list();
    }

    // read the data through all of the nodes
    // note: not necessary to use. only use to check if data was inserted correctly into the linked list
    void read_data() // [SUCCESS]
    {
        node *current;
        current = head;
        while (current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
    
    }

    // organize client data by ID number, numbers of movie watched, and each ID number
    // note: MUST BE CALLED FIRST AFTER DATA FILE IS OPENED AND READ
    void organize_data() // [SUCCESS]
    {
        node *current;
        current = head;
        int j = 0;
        while (current != nullptr)
        {
            // [ID number]
            customer_ID.push_back(current);
            //node *ID_num = new node;
            //ID_num = customer_ID[j];
            //cout << "ID number: "<< customer_ID[j]->data << endl; // check

            // [number of movies watched]
            current = current->next;

            node *movie_count = new node;
            movie_count = current;
            //cout << "number of movies watched: " << movie_count->data << endl; // check

            // movie IDs
            for (i=0; i<movie_count->data; i++)
            {
                current = current->next;
                node *movie_ID = new node;
                movie_ID = current;
                keep_movie_ID.push_back(movie_ID);
                j++;
                // cout << "movie ID: " << movie_ID->data <<endl; // check
            }

            //current = nullptr;
            current = current->next; //move to the next ID
            j++;
        }

        // test: check if these are linked
        // cout << "ID number: "<< customer_ID[0]->data << endl;
        // cout << "ID address: "<< customer_ID[0] << endl;
        // cout << "movies watched: "<< customer_ID[0]->next->data << endl;
        // cout << "first movie: "<< customer_ID[0]->next->next->data << endl;
        // cout << "second movie: "<< customer_ID[0]->next->next->next->data << endl;
    }

    // get a specific client ID
    node* get_client_ID(int num)
    {
        int i=0;
        
        node *current = customer_ID[i];
        node *return_ID = nullptr;
        //cout << num << endl;
        while (customer_ID[i] != nullptr)
        {
            current = customer_ID[i];
            //cout << "ID and address: " <<current->data << " and " << current <<endl;
            if (current->data == num)
            {
                return_ID = current;
            }
            i++;
        }
        //cout << "return ID and address: " <<return_ID->data << " and " << return_ID <<endl;

        return return_ID;
    }


    // get IDS of each client
    vector <node*> get_all_client_ID()
    {
        int i=0;
        node *current = customer_ID[i];
        while (customer_ID[i] != nullptr)
        {
            //current = customer_id[i];
            //cout << customer_ID[i]->data << endl;
            i++;
        }

        return customer_ID;
    }
    
    // store all movies watched into a vector
    vector <node*> keep_movies()
    {
        // for (j=0; j<keep_movie_ID.size(); j++)
        // {
        //     cout << keep_movie_ID[j]->data << endl;
        // }
        return keep_movie_ID;
        //movie_ids.insert(movieID);
    }

};

/*-------------------------------------------------------------*/

class customer : public linked_list<int>
{
    public:
    // init variables
    int client_num;
    int number_of_clients;
    node *client_num_adr;
    int i, number;
    int movies_watched;
    int movieID;
    vector <node*> ID_list;


    //int customer_id;
    linked_list_movies movie_ids;

    customer()
    {
        // do nothing
        // idk what this is for
    }

    // use the node containing the ID number
    customer(node *ptr)
    {
        client_num_adr = ptr; // save address to be used for other subroutines
        client_num = client_num_adr->data;
    }

    // get the size of the list of all client ID
    customer(vector <node*> list)
    {
        number_of_clients = list.size();
        ID_list = list;
    }

    void display()
    {
        cout << "Customer " << client_num << " has watched ";
        node *current = client_num_adr;

        //next node is the number of movies watched
        current = current->next;
        movies_watched = current->data;

        // displaying all movies watched in a specific layout
        for (i=0; i<movies_watched; i++)
        {
            current = current->next;
            movieID = current->data;
            cout << movieID << ", ";
        }
        
        cout << "\b\b  " << endl;     
    }

    // return number of clients
    int return_number_of_clients()
    {
        return number_of_clients;
    }

    // display for all client info
    void display_each(int x)
    {
        client_num_adr = ID_list[x];
        client_num = ID_list[x]->data;
        display();
    }

    // inserting all movie_ids from the movie id vector i created
    void set_movie_id_list(vector <node*> list)
    {
        for (i=0; i<list.size(); i++)
        {
            movie_ids.insert(list[i]->data);
        }
        movie_ids.display();
    }

    // get number of views of specific movie
    void get_views(int m)
    {
        movie_ids.read_views(m);
    }

};


// note this a linked list of POINTERS to customers...
// that way you only every make one copy of each customer
// and simply place a pointer to that customer in the linked list

/*-------------------------------------------------------------*/
//template <typename T>
class linked_list_customers : public linked_list<int>{

    public:

    
    organize_list data;
    
    // print specific client and their info
    void print_customer(int customer_id)
    {
        //data.get_client_ID(customer_id);

        cout << "\nDisplaying customer info ..." << endl;
        
        node *data_pointer = data.get_client_ID(customer_id);
        if (data_pointer == nullptr) 
        {
            cout << "Client " << customer_id << " does not exist" << endl;
        }
        else
        {
            customer client(data_pointer);
            client.display();
        }
        
    }

    // print every client and their info
    void print_all(){
        int i;
        cout << "\nDisplaying all customer info ..." << endl;
        customer client(data.get_all_client_ID());
        int number_clients = client.return_number_of_clients();
        for (i=0; i<number_clients; i++)
        {
            client.display_each(i);
        }
        
    }

    // print the number of views for specific movie
    void print_views(int movie_id){

        cout << "\nDisplaying movie views ..." << endl;
        customer client;

        // make vector of movies watched and set it into linked list
        client.set_movie_id_list(data.keep_movies());
        // get number of views for this movie id
        client.get_views(movie_id);
    }

    // load the specified data file and read the file
    void load_customers(string filename){

        int i = 0;
        int j = 0;
        // DATA VECTOR
        vector <int> data_list;
        vector <int> flipped_data_list;

        string      line; 
        ifstream    file_id(filename);

        
        
        // read integers from file and store into a vector
        while (getline(file_id,line))
        {
            //data.insert(stoi(line));
            data_list.push_back(stoi(line));
        }

        // flip the vector since the linked_list.h inserts node at head
        for (i=data_list.size()-1; i+1>0; i--)
        {
            flipped_data_list.push_back(data_list[i]);
            //cout << flipped_data_list[j] << endl;
            data.insert(flipped_data_list[j]);
            j++;
        }

    }

    // function to organize data (MUST be called)
    void organize_data()
    {
        data.organize_data();

        //customer client(data.keep_movies());
    }

};

/*-------------------------------------------------------------*/

int main(int argc, char** argv){

    // get the filename where the data is stored
    string filename;
    filename = get_filename(argc,argv);

    // init variables
    linked_list_customers clients;
    int input;
    int phase = 1;
    int phase2;

    /*------------------------------------------------*/
    // [THINGS TO MAKE WORK]
    clients.load_customers(filename); // MUST
        // loads file
        // organize data into vectors
        // use vectors and pushes data into data stack
    
    clients.organize_data(); // MUST
        // sorts data stack by the client's info
    /*------------------------------------------------*/

    // PROJECT 2 TEST
    //  clients.print_all();
    //  clients.print_customer(724);
    //  clients.print_views(109); 


    // PROGRAM LOOP
    while (phase == 1)
    {
        cout << "\nInput number \n  (0) end program\n  (1) view specific client info\n  (2) view number of views for specific movie \n  (3) display everything\n";
        cin >> input;

        // END PROGRAM AT WILL
        if (input == 0)
        {
            cout << "\nProgram terminated" << endl;
            phase = 0;
        }
        // CLIENT INFO
        else if (input == 1)
        {
            phase2 = 1;
            while (phase2 == 1)
            {
                cout << "\nInput customer ID number to view info [(0) to go back]: ";
                cin >> input;
                if (input == 0)
                {
                    phase2 = input;
                }
                else
                {
                    clients.print_customer(input);
                }
            }
            
        }
        // MOVIE ID VIEWS
        else if (input == 2)
        {
            phase2 = 1;
            while (phase2 == 1)
            {
                cout << "\nInput movie ID number to view number of views [(0) to go back]: ";
                cin >> input;
                if (input == 0)
                {
                    phase2 = input;
                }
                else
                {
                    cout << endl;
                    clients.print_views(input);
                }
            }
        }
        // EVERYTHING
        else if (input == 3)
        {
            clients.print_all();
        }
        // INPUT AGAIN
        else
        {
            cout << "\nPlease input again" << endl;
        }
        
    }


    return 0;
}