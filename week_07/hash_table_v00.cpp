#include<iostream>
#include<string>
using namespace std;

struct student{
    string first;
    string last;
    float gpa;
    student(string f="" , string l="" , float g=0.0){
        first = f;
        last = l;
        gpa = g;
    }
};

class hash_table{

    protected:

    const static int BUFFLEN = 100;
    int n_elements;

    int hash_function(string f , string l){
        int idx;
        // code goes here
        return idx;
    }

    student buffer[BUFFLEN];

    public:

    hash_table(){
        n_elements = 0;
    }

    void insert(student s){
        int key = hash_function(s.first , s.last);
        buffer[key] = s;
        n_elements++;
    }

    student search(string f , string l){

        student s;
        return s;

    }

};

int main(){

    student s1("iyad","obeid",4.0);
    student s2("joe","picone",3.5);
    student s3("john","helferty",3.9);

    hash_table my_instructors;
    my_instructors.insert(s1);
    my_instructors.insert(s2);
    my_instructors.insert(s3);

    student s4 = my_instructors.search("john","helferty");


}