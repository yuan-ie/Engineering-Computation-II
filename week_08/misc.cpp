#include<iostream>
using namespace std;

class base{
    public:

    virtual int f1() = 0;

    int f2(){
        int i = 3;
        return i;
    }

};

class derived : public base{
    public:
    int f1(){
        int i = 0;
        return i;
    }
    int f2(){
        int i = 4;
        return i;
    }

};

class derived_2 : public derived{};

int main(){

    derived d;
    derived_2 dd;

    cout << d.f2() << endl;

    return 0;
}