

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    time_t t;
    time(&t);
    cout << "Today's date and time is: " << ctime(&t) << endl;
    
    struct NODE {
        int info;
        NODE *next;
    };
    
/////////////////////////////////////////////////////////////////////////////////////
    cout << "Part 1" << endl;
    int Age[5] = {19, 21, 17, 22, 33};
    
    NODE *list, *P;
    list = new (NODE);
    list -> info = Age[0];
    P=list;
    //to set a value to all the nodes in the linked list of length 4
    for (int i = 1;i<5;i++){
        P -> next = new NODE;
        P = P -> next;
        P->info = Age[i];
    }
    P -> next = nullptr;
    P = list;
    //display the linked list
    while(P != nullptr){
        cout << P->info;
        if (P->next == nullptr) break;
        else cout << "->";
        P = P->next; //same as i++ in a for loop. to go from 1 location to another
    }
    cout << endl;
    
    //Insert node to front of linked list
    //first must create a new NODE with info 10
    P = list;
    NODE *R = new NODE;
    R->info = 10;
    //now two steps to put it into the list
    //STEP 1:
    R->next = P;
    //but now list is pointing to q because that's the starting node so now set list equal to the new start, which is q
    P = R;
    //Display the linked list again
    while(P != nullptr){
        cout << P->info;
        if (P->next == nullptr) break;
        else cout << "->";
        P = P->next; //same as i++ in a for loop. to go from 1 location to another
    }
    cout << endl;
    
    //insert 26 at the rear of the linked list
    //first create a new NODE with info at 20 and set the next to the nullptr
    NODE *S = new NODE;
    S->info = 26;
    S->next = nullptr;
    //now we need to find the last node in the linked list that already exists so we can make that last node's next point to our new node instead of the nullptr.
    NODE *T = P;
    while(T->next !=nullptr) {
        T = T->next;
    }
    T->next = S;
    T = T->next;
    P = R;
    while(P != nullptr){
        cout << P->info;
        if (P->next == nullptr) break;
        else cout << "->";
        P = P->next; //same as i++ in a for loop. to go from 1 location to another
    }
    cout << endl;
    
    //insert 20 before 22
    NODE *middle = new NODE;
    NODE *before = new NODE;
    NODE *after = new NODE;
    middle ->info = 20;
    
    
    before = R;
    after = R;
    
    while(after->info != 22) {before = after; after = after-> next;}
    
    middle ->next = after;
    before->next = middle;
    P = R;
    while(P != nullptr){
        cout << P->info;
        if (P->next == nullptr) break;
        else cout << "->";
        P = P->next; //same as i++ in a for loop. to go from 1 location to another
    }
    
    
    //computing the average of the linked list
    P = R;
    int average = 0, divide = 0;
    while(P != nullptr){
        average += P->info;
        divide++;
        P = P->next;
    }
    average = average/divide;
    cout << endl<<"The average is: "<< average<<endl;
    
    //determining how many people are above the average in the linked list
    P = R;
    int above = 0;
    while(P!=nullptr) {
        if (P->info >= average) above++;
        P = P->next;
    }
    cout << "There are " << above << " people whose age are above average age." << endl<<endl;
/////////////////////////////////////////////////////////////////////////////////////
    cout << "Part 2 " << endl;
    struct node {
        string name;
        int age;
        node* next;
    };
    node x[10];
    fstream f;
    f.open("/Users/Hamstache/pro5.txt", ios::in);
    for (int i = 0; i<10; ++i){
        f>>x[i].name>>x[i].age;
    }
    f.close();
    
    //now to put all these values in a linked list
    node *LL, *start;
    LL = new (node);
    LL -> name = x[0].name;
    LL -> age = x[0].age;
    start = LL;
    //setting all the values in the array to their corresponding value in the LL -- whether it be a name or an age
    for (int i = 1;i<5;i++){
        start -> next = new node;
        start = start -> next;
        start->name = x[i].name;
        start->age = x[i].age;
    }
    start -> next = nullptr;
    start = LL;
    
    //display the new linked list
    start = LL;
    cout << "   Name     Age     " << endl;
    cout << "____________________" << endl;
    while(start != nullptr){
        cout << "   " << start->name <<"     "<< start->age;
        if (start->next == nullptr) break;
        else cout << endl;
        start = start->next; //same as i++ in a for loop. to go from 1 location to another
    }
    //Display name of the oldest person
    start = LL;
    string oldestname;
    int oldest = 0;
    while(start!=nullptr) {
        if (start->age > oldest) {oldest = start->age; oldestname = start->name;}
        start = start ->next;
    }
    cout <<endl<< "The oldest person is " << oldestname << endl;
    start = LL;
    //Remove the first node
    node *first = start;
    start = first->next;
    delete first;
    //Remove the last node
    node *a, *b;
    a = start;
    b = start;
    while (a->next != nullptr) { b=a; a = a->next;}
    b->next = nullptr;
    delete a;
    
    
    //Display the remaining people in the list
    cout << "After removing the first and last person from the list, the following people are in the list:";
    while(start!=nullptr){ cout << start->name << " "; start = start->next;}
    
    
    
    return 0;
}

