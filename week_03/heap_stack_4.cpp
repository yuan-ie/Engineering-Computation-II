#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

class student{
    private:
    string name;
    vector<int> grades;

    public:

    // constructor
    student(string n = ""){
        name = n;
        grades.clear();
    }
    
    void set_name(string n){
        name = n;
    }

    // Add a grade for the student
    // @param g [int] new grade
    // @return none
    void add_grade(int g){
        grades.push_back(g);
    }
    
    // Compute the student average
    // @return [float] mean
    float get_mean(){

        // default behavior if there are no grades
        if (grades.size() == 0)
            return 100;

        // compute and return mean
        float mean = 0;
        for (int i = 0 ; i<grades.size() ; i++)
            mean += grades[i];
        return mean / grades.size();

    }

    // display the student info    
    void display(){
        cout << name << ": " << get_mean() << endl;
    }

};

void test_case_1(){
    student student_1("alice");
    student_1.add_grade(100);
    student_1.add_grade(95);    
    student_1.display();
}

void test_case_2(){
    student ece_3822[5];
    ece_3822[0].set_name("obeid");
    ece_3822[1].set_name("picone");

    for (int i = 0 ; i < 5 ; i++)
        ece_3822[i].display();

}

void test_case_3(){
    student *ptr_to_student;
    ptr_to_student = new student("biswas");
    (*ptr_to_student).add_grade(100);   // works but fugly
    ptr_to_student->add_grade(94);      // nicer shortcut
    ptr_to_student->display();
    delete ptr_to_student;
}

void display_all_students(student **myPeople){
    for (int i = 0 ; i< 5 ; i++)
        myPeople[i]->display();
}

student** create_class_list(){

    // create a pointer to a list of student pointers
    student **ece_3822;

    // create the list of student pointers
    ece_3822 = new student*[5];

    // create five new students and attach each to its
    // respective student pointer
    // assign an arbitrary grade
    // for (int i = 0 ; i<5; i++){
    //     ece_3822[i] = new student;
    //     ece_3822[i]->add_grade(100-i);        
    // }

    ece_3822[0] = new student("alice");
    ece_3822[1] = new student("bob");
    ece_3822[2] = new student("charlie");
    ece_3822[3] = new student("dennis");
    ece_3822[4] = new student("elise");

    ece_3822[0]->add_grade(99);     // preferred syntax
    *ece_3822[1].add_grade(98);     // valid but not preferred

    // return the pointer to the list of pointers
    return ece_3822;
}

void test_case_4(){
    student **my_class = create_class_list();   
    display_all_students(my_class);
}

int main(int argc,char **argv){

    // make sure there's at least one commandline argument
    if (argc < 2)
        exit(1);

    // check to see which testcase to run
    if (      !strcmp( argv[1] , "1" ) )
        test_case_1();
    else if ( !strcmp( argv[1] , "2" ) )
        test_case_2();
    else if ( !strcmp( argv[1] , "3" ) )
        test_case_3();
   else if ( !strcmp( argv[1] , "4" ) )
        test_case_4();
}