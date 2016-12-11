


#include <iostream>
#include <string>
#include  "HW3-Todo-StackLinkedList.hpp"

using namespace std;


TodoStackLinkedList:: TodoStackLinkedList() // this is a contructor
{
    stackHead=NULL;
    
}
bool TodoStackLinkedList:: isEmpty()
{
    return stackHead==NULL;
}

void TodoStackLinkedList :: push(string todoItem)
{
    
    TodoItem *newItem = new TodoItem;
    newItem->todo = todoItem;
    newItem-> next= stackHead;
    stackHead=newItem;
}

void TodoStackLinkedList :: pop()
{
    if(isEmpty())
        
    {
        cout<< "Stack empty, cannot pop an item."<< endl;
    }
    
    else
    {
        TodoItem* temp= stackHead->next;
        delete stackHead;
        stackHead= temp;
    }
}
TodoItem*  TodoStackLinkedList :: peek()
{
 
    if(isEmpty())
    {
        cout<< "Stack empty, cannot peek." <<endl;
        return NULL;
    }
    else
    {
        return stackHead;
    }
}
