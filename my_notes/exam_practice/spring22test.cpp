#include <iostream>
using namespace std;
class node_type_A {
public:
int payload;
node_type_A* next;
node_type_A(int val, node_type_A* ptr = NULL) {
payload = val;
next = ptr;
}
};
class node_type_B {
public:
node_type_A* payload;
node_type_B* next;
node_type_B(node_type_A* val , node_type_B* ptr = NULL) {
payload = val;
next = ptr;
}
};
void print_A(node_type_A* ptr){
node_type_A* curr_ptr = ptr;
while (curr_ptr != NULL){
cout << curr_ptr->payload << endl;
curr_ptr = curr_ptr->next;
}
}
void print_B(node_type_B* ptr){
node_type_B* curr_ptr = ptr;
while (curr_ptr != NULL){
print_A(curr_ptr->payload);
curr_ptr = curr_ptr->next;
}
}
int main() {
node_type_A* n00 = new node_type_A(8 );
node_type_A* n01 = new node_type_A(6, n00);
node_type_A* n02 = new node_type_A(7, n01);
node_type_A* n03 = new node_type_A(5, n02);
node_type_A* n04 = new node_type_A(-1 );
node_type_A* n05 = new node_type_A(3 );
node_type_A* n06 = new node_type_A(0, n05);
node_type_A* n07 = new node_type_A(9, n06);
node_type_B* n08 = new node_type_B(n03 );
node_type_B* n09 = new node_type_B(n04, n08);
node_type_B* n10 = new node_type_B(n07, n09);
print_B(n10);
return 0;
}