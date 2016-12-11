//
//  Problem2.cpp
//  quiz2review.cpp
//
//  Created by Nabil Ettachfini on 9/29/16.
//  Copyright © 2016 Nabil Ettachfini. All rights reserved.
//
 // QUESTION 2
#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    
    
    return 0;
}



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


