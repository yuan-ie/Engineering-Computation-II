#include<string>
#include<iostream>
using namespace std;

class student{
    private:
    string name;
    int grades[10];
    int nGrades;

    public:

    student(string n=""){
        set_name(n);
        nGrades = 0;
    }

    void set_name(string n){
        name = n;
    }

    string get_name(){
        return name;
    }

    void add_grade(int g){
        if (nGrades < 10){
            grades[nGrades++] = g;
        }
    }

    void display(){
        cout << name << " ";
        for (int i = 0 ; i<nGrades ; i++)
            cout << grades[i] << " ";
        cout << endl;
    }

    double get_average(){
        double s = 0;

        if (nGrades==0)
            return 0;

        for (int i = 0 ; i<nGrades ; i++)
            s += grades[i];
        return s / nGrades;
    }

    string get_grades_string(){
        string str = "";
        for (int i = 0 ; i < nGrades ; i++)
            str += to_string(grades[i]) + " ";

        return str;
    }

};

ostream & operator<<(ostream & os, student & st)
{
    os << st.get_name() << ": " ;
    os << st.get_grades_string();

   return os;
}
