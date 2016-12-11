

#include <iostream>
#include <string>
#include  "HW3-Todo-StackArray.hpp"

using namespace std;


TodoStackArray :: TodoStackArray() // this is a contructor 
{
    stackTop = 0; // perhaps number of items, possibly change to -1 if latest element

}


 bool TodoStackArray :: isEmpty()
{
    return stackTop == 0;
}

bool TodoStackArray :: isFull()

{
    return MAX_STACK_SIZE== stackTop;
}

void TodoStackArray :: push(string todoItem) // deleted std incase grading error
{
    if (!isFull()) // checking if is full
    {
    TodoItem *newItem = new TodoItem;
    newItem->todo = todoItem;
    stack[stackTop]= newItem;
    stackTop++;
    }
    else
        cout<<"Stack full, cannot add new todo item."<<endl;

    
}

void TodoStackArray :: pop()
{

    if(isEmpty())
        
    {
        cout<< "Stack empty, cannot pop an item."<< endl;
    }
    
    else
    {
        delete stack[stackTop-1];
        stackTop--;
    }
}

TodoItem*  TodoStackArray :: peek()
{
    if(isEmpty())
    {
        cout<< "Stack empty, cannot peek." <<endl;
        return NULL;
    }
    else
    {
        return stack[stackTop-1];
    }
}

// TodoStackArray();
// bool isEmpty();
// bool isFull();
//void push(std::string todoItem);
//void pop();
// TodoItem* peek();


// TodoStackArray;