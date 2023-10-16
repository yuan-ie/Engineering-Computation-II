#include<iostream>
#include"linkedList.h"
#include"student.h"
using namespace std;

void example_1();

int main(){

    // example_1();

    student iyad;
    iyad.set_name("Iyad");
    iyad.add_grade(100);
    iyad.add_grade(99); // bad day

    student joe;
    joe.set_name("Joe");
    joe.add_grade(78);
    joe.add_grade(84); // he's trying

    linkedList<student> classList;
    classList.insert(iyad);
    classList.insert(joe);

    classList.print_forward();

    cout << endl;
    student st = classList.pop();
    cout << "Popping: " << st << endl;

    cout << endl;
    cout << "remaining list:" << endl;
    classList.print_forward();

    // linkedList<student*> classList2;
    // classList2.insert(&iyad);
    // classList2.insert(&joe);

    // // this student is on the heap
    // student *changhee = new student;
    // classList2.insert(changhee);

    return 0;

}

void example_1(){
        linkedList<double> myList;
        myList.insert(8);
        myList.insert(6);
        myList.insert(7);
        myList.insert(5);
        myList.insert(3);
        
        myList.print_forward();

        cout << endl;
        cout << "Popping: " << myList.pop() << endl;    // should pop 3
        cout << "Popping: " << myList.pop() << endl;    // should pop 5
        cout << "Popping: " << myList.pop() << endl;    // should pop 7

        cout << endl;
        cout << "remaining list:" << endl;
        myList.print_forward();

}