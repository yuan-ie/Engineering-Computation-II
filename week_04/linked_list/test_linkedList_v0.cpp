#include<iostream>
#include"linkedList_v0.h"
using namespace std;

int main(){
    linkedList myList;
    myList.insert(3.4);
    myList.insert(8.1);
    myList.insert(-2.15);

    myList.print_forward();
    cout << endl;

    myList.print_reverse();
    cout << endl;

    myList.print_item(0);
    myList.print_item(1);
    myList.print_item(2);
    myList.print_item(3);
    myList.print_item(-3);
    cout << endl;

    return 0;

}