//
//  main.cpp
//  quiz2review.cpp
//
//  Created by Nabil Ettachfini on 9/29/16.
//  Copyright © 2016 Nabil Ettachfini. All rights reserved.
//
// ALL PROBLEMS ARE COMING FROM THE QUIZ 2 REVIEW ON THE WEBSITE
#include <iostream>
using namespace std;
/*
struct node{
    int date;
    node* next;
    int value; // possibly remove jusrt did this to remove an error.
};
*/
int main(int argc, const char * argv[]) {


    return 0;
}

node* DeleteNode(node* head, int value)
{
    node *current;
    node * prev;
    current=head;
    prev=head;


while(current!=NULL){ // look at diagram to help you.
    // this is to delete the head node
    if (head->value ==value){
        head=head->next;
        delete current;
        current=head;
        prev=head;
    }
    else if( current->value==value){ // to delete the current node
        prev->next= current->next;
        delete current;
        current= prev->next;
    }
else
{
    prev=current;
    current=current->next;
}

    
}
    return head;
}

 // QUESTION 2
/*
struct Classrooms{
    string destination;
    Classrooms *next;
};
Classrooms& reversePath(Classrooms* head)
{
    Classrooms* prev=NULL;
    Classrooms* current=head;
    Classrooms* temp=NULL;
    
        while(current!=NULL) // this is how to reverse the linked list.
        {
            temp=current->next;
            current->next=prev;
            prev=current;
            current=temp;
            
        }
    head=prev; // you must do this  and also return head
    return  head;
}
*/

// QUESTION 3













