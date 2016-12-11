//
//  main.cpp
//  Homework8.cpp
//
//  Created by Nabil Ettachfini on 10/29/16.
//  Copyright © 2016 Nabil Ettachfini. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "PatientQueue.hpp"
using namespace std;
void PatientQueue :: enqueue(int priority, string name)  //  Check Boese slides to double check the code Nabil, go get help in CSEL for this
{
    cout << "Adding " << priority << " " << name << endl;
    int spot = ++lastIndex;
    waitlist[spot] = new Patient(priority, name);
    while(waitlist[spot/2]){
        if(waitlist[spot]->priority >= waitlist[spot/2]->priority) break; // maybe less than check after testing
        swap(spot, spot/2);
        spot= spot/2;
    }
    printList();
}

Patient* PatientQueue::dequeue() // This also isn't working check to see why as well
{
    if(isEmpty())
    {
        cout<<"No one waiting!"<< endl;
        return NULL;
    }
    Patient * beggining=waitlist[1];
    cout<<"Processing "<< beggining->priority<<" "<<beggining->name<< endl;
    int child;
    int hole =1;
    waitlist[1]=waitlist[lastIndex--];
    Patient* temp= waitlist[hole]; // changed from int to pointer
    for(;hole*2 <= lastIndex; hole = child)
    {
        child=hole*2;
       if( child!=lastIndex && waitlist[child+1]->priority < waitlist[child]->priority) // less then
        {
            child++;
        }
      if( waitlist[child] ->priority < temp->priority) // less than
        {
            swap( hole, child);
        }
      else break;
    }
    waitlist[hole]= temp;
    return beggining;
}

PatientQueue::~PatientQueue()
{
    cout<< "We're CLOSING! Deleting patient queue!"<< endl;
    for(int i=1; i<=lastIndex;i++)
    {
        cout<<"Removing "<< waitlist[i]->name << " from the queue." << endl;
        delete waitlist[i];
    }
}
int PatientQueue :: size() // this should be COMPLETE
{
    return lastIndex;
}

void PatientQueue :: swap(int index1, int index2)  // this should be COMPLETE
{
    Patient* tmp = waitlist[index1];
    waitlist[index1] = waitlist[index2];
    waitlist[index2] = tmp;
}
bool PatientQueue :: isEmpty() // this should be COMPLETE
{
    if ( lastIndex == 0) // maybe change to 1
    {
        return true;
    }
    else
    {
        return false;
    }
}
void PatientQueue:: printList() // this should be COMPLETE
{
    cout <<"==="<< endl << "Patients Waiting " << endl;
    if(isEmpty())
    {
        cout<< "No one waitng!" << endl;
    }
    else
    {
        for(int i=1; i<= lastIndex; i++)
        {
            cout<< "["<< waitlist[i]->priority<<"]"<< waitlist[i]->name<< endl;
        }
    }
    cout<<"==="<< endl;
}
PatientQueue :: PatientQueue()
{
    lastIndex=0;
}

 
 

  /*
  // this the old enqueue
  int hole = ++lastIndex;
  for(; hole > 1 && priority < waitlist[hole/2]->priority ; hole /=2) // its less than because weare doing a minumum
  {
  waitlist[hole] = waitlist [ hole/2];
  }

*/

