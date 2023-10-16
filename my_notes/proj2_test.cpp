#include<iostream>
#include<fstream>
#include "linked_list.h"
#include <vector>
using namespace std;

#define DEFAULT_DIRECTORY "/data/courses/ece_3822/current/project_2/"
#define DEFAULT_FILENAME "dataFile1.txt"

// do not edit
string get_filename(int argc, char** argv){
    string filename = DEFAULT_DIRECTORY;
    
    // no command line inputs: use default
    if (argc == 1)
        filename += DEFAULT_FILENAME;

    // command line filename given
    else
        filename += (string) argv[1];
    
    return filename;
}

/*-------------------------------------------------------------*/

class linked_list_movies : public linked_list<int>{
    public:

    void display(){
        // WRITE CODE TO DISPLAY THE LIST OF MOVIES
    }
};

/*-------------------------------------------------------------*/
class organize_list : public linked_list<int>
{
    public:
    int i;
    vector <node*> customer_ID;
    vector <node*> movie_count;

    organize_list()
    {
        linked_list();
    }

    // read the data through all of the nodes
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
    void organize_data() // [SUCCESS]
    {
        node *current;
        current = head;
        int j = 0;
        while (current != nullptr)
        {
            // ID number
            node *ID_num = new node;
            ID_num = current;
            customer_ID.push_back(ID_num);
            cout << "ID number: "<< customer_ID[j]->data << endl;

            // number of movies watched
            current = current->next;
            movie_count.push_back(current);
            cout << "number of movies watched: " << movie_count[j]->data << endl;

            // movie IDs
            for (i=0; i<movie_count[j]->data; i++)
            {
                current = current->next;
                node *movie_ID = new node;
                movie_ID = current;
                cout << "movie ID: " << movie_ID->data <<endl;
            }

            //current = nullptr;
            current = current->next; //move to the next ID
            j++;
        }

        //cout << head->data << endl;
    }

    node* get_client_ID(int num)
    {
        return customer_ID[num];
    }

    vector <node*> get_all_client_ID()
    {
        int i=0;
        node *current = customer_ID[i];
        while (customer_ID[i] != nullptr)
        {
            //current = customer_id[i];
            cout << customer_ID[i]->data << endl;
            i++;
        }
        return customer_ID;
    }
    

};

/*-------------------------------------------------------------*/

class customer : public organize_list
{
    public:
    int client_num;
    int i;
    node *client_num_adr;
    int movies_watched;
    int movieID;
    int customer_id;
    linked_list_movies movie_ids;

    customer(int d)
    {
        
    }

    customer(node *ptr)
    {
        node *current = ptr;
        client_num_adr = ptr; // save address to be used for other subroutines
        client_num = current->data;
        cout << "client ID: " << client_num << endl;
        //get_client_ID_num(num);
    }

    

    // WRITE CODE TO DISPLAY THE CUSTOMER AND MOVIES
    void display()
    {
        node *current = client_num_adr;

        //next node is the number of movies watched
        current = current->next;
        movies_watched = current->data;
        cout << "number of movies watched: " << movies_watched << endl;

        cout << "movies: ";

        for (i=0; i<movies_watched; i++)
        {
            current = current->next;
            movieID = current->data;
            cout << movieID << ", ";
        }
        
        cout << "\b\b  " << endl;

        
        
        //current = nullptr;
        
    }

};


// note this a linked list of POINTERS to customers...
// that way you only every make one copy of each customer
// and simply place a pointer to that customer in the linked list

/*-------------------------------------------------------------*/

class linked_list_customers : public linked_list<customer*>{

    public:

    void print_customer(int customer_id)
    {
        
    }

    void print_all(){
        // WRITE THIS FUNCTION
    }

    void print_views(int movie_id){
        // WRITE THIS FUNCTION
    }

    void load_customers(string filename){

        int i = 0;
        int j = 0;
        // DATA VECTOR
        vector <int> data_list;
        vector <int> flipped_data_list;

        string      line; 
        ifstream    file_id(filename);

        // MY CLASS
        organize_list data;
        
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

};

/*-------------------------------------------------------------*/

int main(int argc, char** argv){

    // get the filename where the data is stored
    string filename;
    filename = get_filename(argc,argv);

    // init variables
    
    linked_list_customers clients;

    

    
    
    // test: output specific client's info
    //customer client(data.get_client_ID(1));
    //client.display();


    // [THINGS TO MAKE WORK]
    clients.load_customers(filename);

    clients.print_customer(1);
    // clients.print_all();
    // clients.print_customer(72,4);
    // clients.print_views(109); 

    return 0;
}