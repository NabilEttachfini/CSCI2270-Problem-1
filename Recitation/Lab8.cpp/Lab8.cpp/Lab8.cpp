//
//  main.cpp
//  Lab8.cpp
//  this is for hash table
//  Created by Nabil Ettachfini on 10/27/16.
//  Copyright © 2016 Nabil Ettachfini. All rights reserved.
//

#include <iostream>
#include "Lab8StarterCode.hpp"
using namespace std;

int HashTab :: HashFunc(int key)
{
    return key % TABLE_SIZE;
}
void HashTab::Insert(int key)
{
    int hash_val=HashFunc(key);
    if(htable[hash_val] == NULL)
    {
        htable[hash_val] = new Node(key);
    }
    else
    {
        Node*current =  htable[hash_val];
        while(current->next !=NULL)
        {
            current= current->next;
        }
        
        current -> next= new Node(key);
    }
    
}
void HashTab:: display()
{
    for (int i=0;i<TABLE_SIZE; i++)
    {
        Node*current= htable[i];
        cout<<i<<":  " << endl;
        while( current != NULL)
        {
            cout<< current->key<<"-->" << endl;
            current= current->next;
        }
        cout<< endl;
    }
}
int HashTab::Find(int key)
{ // find the position of the linked list in the array "htable"
    int hash_val=HashFunc(key);
    int c =0 ;
    if( htable[hash_val]==NULL)
    {
        return -1;
    }
    else{
        Node* current = htable[hash_val];
        while(current !=NULL && current->key != key)
        {
            current=current->next;
            c++;
        }
        if(current->key==key)
        {
            return c;
        }
        else{
            return -1;
        }
    }
}


void HashTab:: Delete(int key)
{
    int hash_val= HashFunc(key);
    if ( htable[hash_val] !=NULL)
    {
        Node* current = htable[hash_val];
        Node* prev=NULL;
        while(current !=NULL && current->key != key)
        {
            prev=current;
            current=current->next;
        }
        if(prev==NULL)
        {
            htable[hash_val] = current->next;
            delete current;
        }else{
            prev->next = current -> next;
            delete current;
        }
    }
    
}
















