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
    bool is_empty(){
        return ((first=="") & (last=="") & (gpa==0));
    }
};

class hash_table{

    protected:

    const static int BUFFLEN = 100;
    int n_elements;

    int hash_function(string f , string l){
        int idx;
        long int sum = 0;

        //  hash first name, taking position into account
        for (int i = 0 ; i<f.length() ; i++)
            sum += (i+1) * int(f[i]);

        //  hash last name, taking position into account
        for (int i = 0 ; i<l.length() ; i++)
            sum += (i+1) * int(l[i]);

        // guarantee that idx is between 0 and BUFFLEN-1
        idx = sum % BUFFLEN;        
        
        return idx;
    }

    // create an ARRAAY of students
    student buffer[BUFFLEN];

    int de_collision(int key){
        
        // if there is a student at buffer[key], increment key and
        // try again
        while (!buffer[key].is_empty())
            key = (key + 1) % BUFFLEN;

        return key;

    }

    bool already_in_buffer(student s){
        // for now, i'm assuming that the student s is NOT in the
        // buffer (so return false)
        //
        // but in the future we might want to check
        return false;
    }

    bool is_this_the_right_student(student s , string f, string l){
        return ((s.first==f) && (s.last==l));
    }

    public:

    hash_table(){
        n_elements = 0;
    }

    void insert(student s){

        // if every slot is taken, then the buffer can't hold any
        // more students
        if (n_elements == BUFFLEN)
            return;

        if (already_in_buffer(s))
            return;

        int key;
        
        key = hash_function(s.first , s.last);
        key = de_collision(key);
        buffer[key] = s;
        n_elements++;
        cout << s.first << "(" << s.gpa << ") " << key << endl << endl;

        // collision strategy:
        // if buffer[key] is already taken, try key+1
        // if buffer[key+1] is already taken, try key+2 etc
        // include wrap -> if key+whatever == BUFFLEN then key=0
        // if they're all taken, then no insertion possible using
        // this collision strategy

    }

    student search(string f , string l){
        student s;
        int key = hash_function(f,l);

        while ( !is_this_the_right_student(buffer[key],f,l) )
            key = (key + 1)%BUFFLEN;
        
        return buffer[key];
    }

};

int main(){

    student s1("iyad","obeid",4.0);
    student s2("joe","picone",3.5);
    student s3("john","helferty",3.9);
    student s4("nhoj","helferty",3.7);
    student s5("nhoj","helferty",3.1);

    hash_table my_instructors;

    my_instructors.insert(s1);
    my_instructors.insert(s2);
    my_instructors.insert(s3);
    my_instructors.insert(s4);
    my_instructors.insert(s5);
    my_instructors.insert(s5);
    my_instructors.insert(s5);
    my_instructors.insert(s5);
    my_instructors.insert(s5);
    
    student s6 = my_instructors.search("nhoj","helferty");
    cout << s6.gpa << endl;

}