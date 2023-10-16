#include<iostream>
#include"linkedList.h"
#include"student.h"
using namespace std;

void f1();
void f2();

int main(){

    student iyad;
    iyad.set_name("Iyad");
    iyad.add_grade(100);
    iyad.add_grade(99); // bad day
    iyad.display();

    student joe;
    joe.set_name("Joe");
    joe.add_grade(78);
    joe.add_grade(84); // he's trying
    joe.display();

    linkedList<student> classList;
    classList.insert(iyad);
    classList.insert(joe);

    linkedList<student*> classList2;
    classList2.insert(&iyad);
    classList2.insert(&joe);

    // this student is on the heap
    student *changhee = new student;
    classList2.insert(changhee);

    return 0;

}

void f1(){
    linkedList<double> myList_of_double;

    myList_of_double.insert(4.2);
    myList_of_double.insert(-23.45);
    myList_of_double.insert(1.2345);

    myList_of_double.print_forward();
    cout << endl;

}

void f2(){
        linkedList<int> myList_of_int;
    myList_of_int.insert(4);
    myList_of_int.insert(3);
    myList_of_int.insert(-87);
    
    myList_of_int.print_reverse();
    cout << endl;

}