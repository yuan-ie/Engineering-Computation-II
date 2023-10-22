#include<iostream>
using namespace std;

void f1(int a){
    // pass by value
    // make a copy of variable, name it "a"
    // and give it the same value as the calling
    // parameter
    // x is 0, a is a new variable whose value is also 0
    a = 1;
}

void f2(int &a){
    // pass by reference
    // "a" is just another name for the calling parameter
    // "x"
    // x is NOT copied, just given another name.
    a = 1;
}

int main(){
    int x = 0;
    f1(x);
    cout << "x = " << x << endl;

    int y = 0;
    f2(y);
    cout << "y = " << y << endl;

    return 0;
}