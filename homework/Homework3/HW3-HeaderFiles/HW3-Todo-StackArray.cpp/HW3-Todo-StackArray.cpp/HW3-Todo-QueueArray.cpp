#include <iostream>
#include <cmath>
#include "HW3-Todo-QueueArray.hpp"

using namespace std;



TodoQueueArray :: TodoQueueArray()
{
    // possibly sent front and end to zero
    queueFront=0;
    queueEnd=0;
    for( int i=0; i< MAX_QUEUE_SIZE; i++)
    {
        queue[i]= NULL;
    }
}

bool TodoQueueArray :: isEmpty()
{
    return queueEnd == queueFront  && queue[queueFront] == NULL;
    
    
    /* if(isEmpty())
     {
     return true;
     }
     else
     return false;
     */
}

bool TodoQueueArray:: isFull()
{
    
    return (( queueEnd +1)  %  MAX_QUEUE_SIZE == queueFront );
    
    
}

void TodoQueueArray:: enqueue(string todoItem) // removed the std::
{
    
    if ( isFull())
    {
        cout<<  "Queue full, cannot add new todo item."<<endl;
    }
    else
    {
        
        TodoItem *newItem = new TodoItem;
        newItem->todo = todoItem;
        // queue[queueEnd]= newItem;
       //  queueEnd++;
        
        if(isEmpty())
        {
            queue[queueFront]= newItem;
        }
        else
        {
            queueEnd= (queueEnd+1) % MAX_QUEUE_SIZE;
            queue[queueEnd]= newItem;
        }
        
    }
    
}


void TodoQueueArray:: dequeue()

{
    if( isEmpty())
    {
        cout<< "Queue empty, cannot dequeue an item."<< endl;
        return;
    }
    else
    {
    delete queue[queueFront] ;
    queue [queueFront] = NULL;
    queueFront = (queueFront +1) % MAX_QUEUE_SIZE;
        
        if( !queue[queueFront])
        {
            queueEnd=queueFront;
        }
        
    }
    
    
}



TodoItem* TodoQueueArray :: peek()
{
    if(isEmpty())
    {
        cout<< "Queue empty, cannot peek." <<endl;
        return NULL;
    }
    else
    {
        return queue[queueFront];
    }
    
    
}