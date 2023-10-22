#include<iostream>
#include<string>
using namespace std;

/* Student Struct, with default constructor */
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

/* Enable cout for student */
ostream & operator<<(ostream & os , student &s){
    os << s.first << " " << s.last << ", gpa = " << s.gpa;
    return os;
}

/*  Generic hash table class
    Requires that hash_function(student) be overloaded by inheriting class
*/
class hash_table_generic{

    protected:

    const static int BUFFLEN = 100;
    int n_elements;

    virtual int hash_function(student) = 0;

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

    hash_table_generic(){
        n_elements = 0;
    }

    // generic insert function - should work regardless of hash table type
    void insert(student s){

        // if every slot is taken, then the buffer can't hold any
        // more students
        if (n_elements == BUFFLEN)
            return;

        if (already_in_buffer(s))
            return;

        int key;
        
        key = hash_function(s);
        key = de_collision(key);
        buffer[key] = s;
        n_elements++;

        cout << "inserting " << s << " at index " << key << endl;

        // collision strategy:
        // if buffer[key] is already taken, try key+1
        // if buffer[key+1] is already taken, try key+2 etc
        // include wrap -> if key+whatever == BUFFLEN then key=0
        // if they're all taken, then no insertion possible using
        // this collision strategy

    }


};

/*  Hash students by first AND last name 
    ** <hash_function(student)> has been overloaded
    ** search function allows search by first and last name
*/
class hash_table_first_and_last : public hash_table_generic{

    protected:
    int hash_function(student s){
        int idx;
        long int sum = 0;

        string f = s.first;
        string l = s.last;

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

    public:
    student search(string f, string l){

        // create a temp student with matching first and last name
        student tmp_student(f,l,0.0);

        // get a hash key
        int key = hash_function(tmp_student);

        // look for the right student
        // this uses <is_this_the_right_student> from the base class
        while ( !is_this_the_right_student(buffer[key],f,l) )
            key = (key + 1)%BUFFLEN;
        
        return buffer[key];
    }


};

/*  Hash students by last name only
    ** <hash_function(student) has been overloaded
    ** <search> function allows for search by last name only
    ** <is_this_the_right_student> has been overloaded to only check for last name
*/
class hash_table_last : public hash_table_generic{
    protected:

    // a very bad hash function
    int hash_function(student s){
        int idx = 0;
        return idx;
        }

    // check for matches using only the last name
    bool is_this_the_right_student(student s, string l){
        return (s.last==l);
    }

    public:

    // search by last name
    student search(string l){

        // create a temp student with matching last name
        student tmp_student("",l,0.0);

        // compute hash key for the student
        int key = hash_function(tmp_student);

        // look for student in the buffer
        while (!is_this_the_right_student(buffer[key],l))
            key = (key + 1)%BUFFLEN;

        // return results        
        return buffer[key];

    }

};

class database {
    private:
    hash_table_first_and_last HT_FL;
    hash_table_last           HT_L;

    public:
    void insert(student s){
        HT_FL.insert(s);
        HT_L.insert (s);
    }

    student search_by_last(string l){
        return HT_L.search(l);
    }

    student search_by_first_and_last(string f , string l){
        return HT_FL.search(f,l);
    }

};

int main(){

    student s1("iyad","obeid",4.0);
    student s2("joe","picone",3.5);
    student s3("john","helferty",3.9);
    student s4("nhoj","helferty",3.7);
    student s5("nhoj","helferty",3.1);

    database my_instructors;

    my_instructors.insert(s1);
    my_instructors.insert(s2);
    my_instructors.insert(s3);
    my_instructors.insert(s4);
    my_instructors.insert(s5);
    my_instructors.insert(s5);
    my_instructors.insert(s5);
    my_instructors.insert(s5);
    my_instructors.insert(s5);
    
    student s6 = my_instructors.search_by_last("helferty");
    cout << "search by last: found -> " << s6 << endl;

    student s7 = my_instructors.search_by_first_and_last("joe","picone");
    cout << "search by first and last last: found -> " << s7 << endl;

}