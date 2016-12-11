//
//  main.cpp
//  HW2-LinkedListNetwork.cpp
// Professor: Elle Boese
// CSCI 2270 Fall 2016
//  Created by Nabil Ettachfini on 9/15/16.
//  Copyright © 2016 Nabil Ettachfini. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

struct city
{
    string 	name; 			// name of the city
    city 	*next; 			// pointer to the next city
    int 	numberMessages;	// how many messages passed through this city
    string 	message; 		// message we are sending accross
};

city* addCity(city *head, city *previous, string cityName );
city* deleteCity(city *head, string cityName);
city* deleteEntireNetwork(city *head);
city* searchNetwork(city *head, string cityName);
city* loadDefaultSetup(city *head);
void transmitMsg(city *head, string receiver, string filename);
void printPath(city *head);
void displayMenu();
city* handleUserInput(city *head);

/* Do NOT modify main function */
int main(int argc, char* argv[])
{
    // pointer to the head of our network of cities
    city *head = NULL;
    
    head = handleUserInput(head);
    printPath(head);
    head = deleteEntireNetwork(head);
    if (head == NULL)
        cout << "Path cleaned" << endl;
    else
        printPath(head);
    
    cout << "Goodbye!" << endl;
    return 0;
}

/*
 * Purpose: handle the interaction with the user
 * @param head the start of the linked list
 * @return the start of the linked list
 * Do NOT modify
 */
city* handleUserInput(city *head)  // do not TOUCH!!
{
    bool quit = false;
    string s_input;
    int input;
    
    // loop until the user quits
    while (!quit)
    {
        displayMenu(); // this is at the bottom
        
        // read in input, assuming a number comes in
        getline(cin, s_input);
        input = stoi(s_input);
        
        switch (input)
        {
                // print all nodes
            case 1: 	//rebuild network
                head = loadDefaultSetup(head);
                printPath(head);
                break;
                
            case 2:		// print path
                printPath(head);
                break;
                
            case 3: //message is read in from file
            {
                string cityReceiver;
                cout << "Enter name of the city to receive the message: " << endl;
                getline(cin, cityReceiver);
                
                cout << "Enter the message to send: " << endl;
                string message;
                getline(cin, message);
                
                transmitMsg(head, cityReceiver, message);
            }
                break;
                
            case 4:
            {
                string newCityName;
                string prevCityName;
                cout << "Enter a new city name: " << endl;
                getline(cin, newCityName);
                
                cout << "Enter the previous city name (or First): " << endl;
                getline(cin, prevCityName);
                
                // find the node containing prevCity
                city *tmp = NULL;
                if(prevCityName !="First")
                    tmp = searchNetwork(head, prevCityName);
                // add the new node
                head = addCity(head, tmp, newCityName);
                printPath(head);
            }
                break;
                
            case 5: 	// delete city
            {
                string city;
                cout << "Enter a city name: " << endl;
                getline(cin, city);
                head = deleteCity(head, city);
                printPath(head);
            }
                break;
                
            case 6: 	// delete network
                head = deleteEntireNetwork(head);
                break;
                
            case 7: 	// quit
                quit = true;
                cout << "Quitting... cleaning up path: " << endl;
                break;
                
            default: 	// invalid input
                cout << "Invalid Input" << endl;
                break;
        }
    }
    return head;
}

/*
 * Purpose: Add a new city to the network
 *   between the city *previous and the city that follows it in the network.
 * @param head pointer to start of the list
 * @param previous name of the city that comes before the new city
 * @param cityName name of the new city
 * @return pointer to first node in list
 */
city* addCity(city *head, city *previous, string cityName )
{
    city* newCity= new city;
    newCity-> name=cityName;
    newCity-> message="";
    newCity-> numberMessages=0;
    newCity->next = NULL;
    if (head == NULL)
    {
        // head = new city;
        head =  newCity;
        // head= newCity; // new way
        // head->next=newCity; // delete
        previous= head;
    }
    else if(previous == NULL)
    {
        // if (head->next != NULL)
        newCity-> next= head; //-> next;
        head= newCity;  // head-> next
        previous = head;
    }
    
    else
    {
        if (previous->next != NULL)
            newCity-> next= previous-> next;
        previous-> next = newCity;
        
        
        /*
         city* adder = previous;
         city* tmp;
         adder=head;
         adder= new city;
         tmp= previous -> next;
         previous -> next= adder;
         adder -> next=tmp;
         adder -> name=cityName;
         head=head;
         city* temp;
         temp = previous ->next;
         previous -> next= head;
         head-> next=temp;
         head -> name =cityName;
         head=head;
         head = new city;
         city *newCity= new city;
         head -> name = cityName; // name is inside the strcut member and cityname is the value you are getting
         */
        
        cout << "prev: " << previous->name << "  new: " << cityName << endl;
    }
    // maybe keep the cout out of the else is statement
    
    
    return head;
}

/*
 * Purpose: Search the network for the specified city and return a pointer to that node
 * @param ptr head of the list
 * @param cityName name of the city to look for in network
 * @return pointer to node of cityName, or NULL if not found
 * @see addCity, deleteCity
 */
city *searchNetwork(city *ptr, string cityName) //input a city looks for a particular city
{
    while ( ptr !=NULL)
    {
        if ( ptr-> name== cityName)
        {
            break;
        }
        
        else
        {
            ptr= ptr->next;
        }
    }
    
    return ptr;
}

/*
 * Purpose: deletes all cities in the network starting at the head city.
 * @param ptr head of list
 * @return NULL as the list is empty
 */
city* deleteEntireNetwork(city *ptr) // write logic for delete each city using pointers from city to  city
{
    if (ptr==NULL)
    {
        return ptr;
    }
    
    while (ptr != NULL)
    {
        cout << "deleting: " << ptr-> name << endl;
        city *next = ptr->next;
        delete ptr;
        ptr = next;
    }
    
    cout << "Deleted network" << endl;
    // return head, which should be NULL
    return ptr;
}

/* sends messages from file */
void transmitMsg(city *head, string receiver, string message)
{
    if(head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    city * sender= head;
    while(sender->name != receiver)
    {
        sender-> message= message;
        sender->numberMessages++;
        cout << sender->name << " [# messages passed: " << sender->numberMessages << "] received: " << sender->message << endl;
        sender= sender->next;
    }
    sender -> message=message;
    sender-> numberMessages++;
    cout << sender->name << " [# messages passed: " << sender->numberMessages << "] received: " << sender->message << endl;
    
    // city* sender =  new city(); // sender is whatever node is sending the message to the next
    
    
}
/*
 * Purpose: delete the city in the network with the specified name.
 * @param head first node in list
 * @param cityName name of the city to delete in the network
 * @return head node of list
 */
city* deleteCity(city *head, string cityName)
{
    city* previous = NULL;
    city* curr=head;
    
    while( curr !=  NULL)
    {
        if( curr-> name == cityName)
        {
            if(  previous == NULL) //
            {
                head= curr->next;
            }
            else
            {
                previous->next= curr-> next;
            }
            delete curr;
            return head;
            
        }
        previous=curr;
        curr= curr-> next;
        
    }
    
    // if the city dosn't exist, nothing we can do.
    // 		use this output statement
    cout << "City does not exist." << endl;
    
    return head;
}


/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void printPath(city *ptr)
{
    city *listPrinter;
    listPrinter = ptr;
    cout << "== CURRENT PATH ==" << endl;
    
    // If the head is NULL
    if (ptr == NULL)
        cout << "nothing in path" << endl;
    else
    {
        while(listPrinter != NULL)
        {
            /*if(listPrinter->name == "NULL")
             {
             cout << " " << listPrinter->name << endl;
             listPrinter = listPrinter->next;
             }*/
            // if (listPrinter->name != "")
            
            cout << listPrinter->name << " -> ";
            
            
            listPrinter = listPrinter->next;
        }
        cout << "NULL" << endl;
    }
    //cout << "=================" << endl;
    //listPrinter = head;
    
    //cout << "== CURRENT PATH ==" << endl;
    
    
    
    cout << "===" << endl;
}


/*
 * Purpose: populates the network with the predetermined cities
 * @param head start of list
 * @return head of list
 */
city* loadDefaultSetup(city *head)
{
    head = deleteEntireNetwork(head);
    head = addCity(head,NULL,"Los Angeles"); // make for each city
    /*addCity( head,searchNetwork(head,"Los Angeles"), "Pheonix"); // going thourgh searchNetwork to find the next city
     addCity( head,searchNetwork(head,"Pheonix"), "Denver");
     addCity( head,searchNetwork(head,"Denver"), "Dallas");
     addCity( head,searchNetwork(head,"Dallas"), "Atlanta");
     addCity( head,searchNetwork(head,"Atlanta"), "New York");*/
    
    string cities[6] = {"Los Angeles", "Phoenix", "Denver", "Dallas", "Atlanta", "New York"}; // NULL is for the actual pointer ;))
    //int cityCounter;
    
    // city *head;
    //city *listPointer;
    
    // city *LosAngeles, *Phoenix, *Denver, *Dallas, *Atlanta, *NY, *lastCity;
    /*LosAngeles = new city;  //Horrid coding practices but I was getting tired of getting seg faults so I did it by hand instead.
     head = LosAngeles;
     Phoenix = new city;
     Denver = new city;
     Dallas = new city;
     Atlanta = new city;
     NY = new city;
     lastCity = new city;
     listPointer = head;
     
     LosAngeles->next = Phoenix;
     Phoenix->next = Denver;
     Denver->next = Dallas;
     Dallas->next = Atlanta;
     Atlanta->next = NY;
     NY->next = lastCity;
     */
    
    city *current= head;  // -> next;
    for(int i=1;i<6;i++)
    {
        /*
         listPointer->name = cities[i];
         listPointer = listPointer->next;
         */
        head = addCity(head,current,cities[i]);
        current=current->next;
    }
    //listPointer = head;
    //cityCounter = 11;
    
    return head;
    
    /*city* cty = head-> next; // did this to point to the previous city to include in each addcity
     head= addCity (head,cty, "Pheonix");
     cty=head->next; // point to previous city
     head= addCity(head,cty, "Denver");
     cty=head-> next;
     head= addCity(head,cty, "Dallas");
     cty=head-> next;
     head= addCity(head,cty, "Atlanta");
     cty=head->next;
     head= addCity(head,cty, "NewYork");
     */
    //use searchNetwork  function
}

/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "======Main Menu=====" << endl;
    cout << "1. Build Network" << endl;
    cout << "2. Print Network Path" << endl;
    cout << "3. Transmit Message" << endl;
    cout << "4. Add City" << endl;
    cout << "5. Delete City" << endl;
    cout << "6. Clear Network" << endl;
    cout << "7. Quit" << endl;
}

