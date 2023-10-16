#include<iostream>
#include"student.h"
#include"doublelinkedList.h"
using namespace std;

void f1();
void f2();

int main(){

    f2();
    return 0;
}

void f1(){
    doublelinkedList<int> x;
    x.insert_head(8);
    x.insert_tail(6);
    x.insert_head(7);
    x.insert_tail(5);
    x.insert(3);
    x.print_forward();
}

class student_linked_list : public doublelinkedList<student*>{

    public:
    student* find(string target_name){
        node *currPtr = head;
        student *target_student = nullptr;

        while(currPtr){
            if (currPtr->data->get_name() == target_name){
                target_student = currPtr->data;
                break;
            }
            else
                currPtr = currPtr->next;
        }

        return target_student;
    }

};

void f2(){

    // create four new students on the heap
    student* new_students[4];
    
    new_students[0] = new student("Iyad Obeid");
    new_students[0]->add_grade(100);    
    new_students[0]->add_grade(84);    
    new_students[0]->add_grade(94);    

    new_students[1] = new student("Joe Picone");
    new_students[1]->add_grade(49);    
    new_students[1]->add_grade(76);    

    new_students[2] = new student("Li Bai");
    new_students[2]->add_grade(79);    
    new_students[2]->add_grade(92);    
    new_students[2]->add_grade(67);    
    new_students[2]->add_grade(88);    

    new_students[3] = new student("John Helferty");

    // put the four new students on a student linked list
    student_linked_list ece3822;
    for (int i = 0 ; i <4 ; i++)
        ece3822.insert( new_students[i] );
    
    // note that search is slow because it has to go down the list one by one
    // until it either finds Li Bai or runs out of list.
    student *target_student = ece3822.find("Li Bai");
    if (!target_student){
        cout << "student not found" << endl;
    }
    else{
        cout << *target_student << endl;
    }

    // add a grade to target_student
    target_student->add_grade(98);

    // check to see if new_students[2] sees the new grade
    cout << *new_students[2] << endl;


}