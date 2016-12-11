// reciation for lab4 on DOUBLY LINKED LIST



#include <cstdlib>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

void PrintForward(Node* head); // from head to tail
void PrintReverse(Node* tail); // from  tail to null

/*
 Note 1:
 stoi function is related to C++11
 use flag [-std=c++11] to compile
 e.g. g++ -std=c++11 main.cpp -o hw2
 
 Note 2:
 Grade of hw1 should be updated tomorrow
 Don't worry, if it is my fault,
 I will help you to correct the score
 
 */



int main(int argc, char** argv)
{
    // pointer is variable that stores
    // the address value of another variable of some type
    Node* head;
    Node* tail;
    Node* n;
    
    // Node 1:
    n = new Node; // create a new Node, and assign
    // the address of the Node to pointer n
    n->data = 1;
    n->prev = NULL;
    // leave ->next
    head = n;
    tail = n;
    
    // Node 2
    n = new Node;    // this creates NEW MEMORY and the second we must assign the value that it will. it will put the  new adress into that space. so like n is equal to the adress of data now. summarizes this is NODE 1 did not see that lol ;)))
    n->data = 2;
    n->prev = tail;
    tail->next = n;
    tail = n;
    
    // Node 3
    n = new Node;
    n->data = 3;
    n->prev = tail;
    tail->next = n;
    tail = n;
    
    // Node 4 - tail Node
    n = new Node;
    n->data = 4;
    n->prev = tail;
    tail->next = n;
    tail = n;
    tail->next = NULL;
    
    PrintForward(head);
    PrintReverse(tail);
    
    return 0;
}

void PrintForward(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void PrintReverse(Node* tail)
{
    Node* temp= tail;
    
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev ;
    }
    cout << endl;
}