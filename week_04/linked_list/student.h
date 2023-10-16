#include<string>
#include<iostream>
using namespace std;

class student{
    private:
    string name;
    int grades[10];
    int nGrades;

    public:

    student(){
        nGrades = 0;
    }
    void set_name(string n){
        name = n;
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
};