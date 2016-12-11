

#include <iostream>
#include <string>
#include  "HW3-Todo-QueueLinkedList.hpp"

using namespace std;

TodoQueueLinkedList:: TodoQueueLinkedList()
{
    //
    
    queueFront = new TodoItem;
    queueFront->next = NULL;
    queueEnd = new TodoItem;
    queueEnd->next = NULL;


}

bool TodoQueueLinkedList:: isEmpty() // i think this function is good.
{
    if (queueFront->next == NULL)
    {
        return true;
    }
    else
        return false;
}
void TodoQueueLinkedList :: enqueue(string todoItem) // got rid of std::
{
    
  //  if( queueFront==NULL)
    
         // return;  this maybe shouldn't happen test and possibly change it if needed
    
    TodoItem* next= new TodoItem;
    
    if ( queueFront-> next == NULL)
    {
        queueFront-> next= next;
        queueEnd-> next= next;
        next->next = NULL;
        next-> todo = todoItem;
    }
    else
    {
        queueEnd->next->next=next;
        queueEnd->next=next;
        next->next=NULL;
        next->todo= todoItem;
    }
    
    return;
    // TodoItem *newItem = new TodoItem;
    // newItem->todo = todoItem;
    // newItem-> next= queueEnd;
    // queueEnd=newItem;
    
    
}

void TodoQueueLinkedList:: dequeue()
{
    if(isEmpty()) // see if works
        
    {
        cout<< "Queue empty, cannot dequeue an item."<< endl;
        return;
    }
    

    TodoItem * tmp1 = queueFront->next;
    queueFront->next = tmp1->next;
    delete tmp1;
    return;
    
    
}


TodoItem*  TodoQueueLinkedList :: peek()
{
    
    if(isEmpty())
    {
        cout<<"Queue empty, cannot peek." <<endl;
        return NULL;
    }
    else
    {
        return queueFront->next;
        return queueEnd; // maybe do not need
    }
    
}
// TodoQueueLinkedList();
// bool isEmpty();
// void enqueue(std::string todoItem);
// void dequeue();
// TodoItem* peek();
