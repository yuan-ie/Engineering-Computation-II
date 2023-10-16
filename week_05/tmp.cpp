#include<iostream>
#include<string>
#include"student.h"
using namespace std;

int main(){

    student i;
    i.set_name("Iyad");
    i.add_grade(100);
    i.add_grade(83);
    i.add_grade(40);
    cout << i << endl;
}