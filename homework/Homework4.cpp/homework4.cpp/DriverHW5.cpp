// hw-5 driver
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include "MovieTree.hpp"
using namespace std;

void displayMenu();
void handleUserInput(MovieTree*);

int main(int argc, const char * argv[] ){
    //  pointer to the head of our network of cities
    MovieTree* root = new MovieTree; // not sure if this should be movie node or movie tree,
    
    // root = handleUserInput(root); // this needs to be fi
    ifstream txtstream;
    txtstream.open(argv[1]); // does this need to be argv 1 or 2? 
    string input;
    if(txtstream.is_open())
        
    {
        while(!txtstream.eof()) // this is end-of-file
              {
                  getline(txtstream,input);
                  stringstream sstream(input);
                  
                  getline(sstream,input,','); // this sets de-limator
                  int ranking = stoi(input);
                  
                  getline(sstream,input,','); // this sets de-limator
                  string title= input;
                  
                  getline(sstream,input,','); // this sets de-limator
                  int year = stoi(input);
                  
                  getline(sstream,input,','); // this sets de-limator
                  int quantity = stoi(input);
                  
                  root-> addMovieNode(ranking,title,year,quantity);
              }
        
        handleUserInput(root);
        delete root;
    }
    else{
        cout<<"File did not open correctly"<<endl;
        txtstream.close();
    }
              return 0;
              }
              
        void handleUserInput(MovieTree* tree)
              {
                  bool quit = false;
                  string s_input;
                  int input;
                  
                  // loop until the user quits
                  while (!quit) {
                      
                      displayMenu(); // this is at the bottom
                  
                  // read in input, assuming a value comes in, and dont forget to getline in the cases below
                  getline(cin, s_input);
                  input = stoi(s_input);
                  string mTitle;
                  switch (input)
                  {
                          // print all nodes
                      case 1:// this is find movie, bases on the order in the homework asignment
                      {
                          cout << "Enter title:" << endl; // if you switch the string make sure to change the rest of below
                          getline(cin,mTitle);
                          tree->findMovie(mTitle);
                      }
                          break;
                          
                      case 2:		// This is to rent a movie, in order from the homework
                      {
                          cout << "Enter title:" << endl;
                          getline(cin,mTitle);
                          tree->rentMovie(mTitle);
                      }
                          break;
                          
                      case 3: //This will print the entire inventory
                      {
                          tree->printMovieInventory(); // I believe this is all that needs to be done, comeback after testing
                      }
                          break;
                      
                      case 4: //This is the new delete option
                      {
                          string remove;
                          cout<<"Enter title: " << endl;
                          getline(cin, remove);
                          tree ->deleteMovieNode(remove);
                      }
                          break;
                      case 5: // this will count the movie
                      {
                          int count;
                          count= tree->countMovieNodes();
                          cout<<"Number of movies:  "<< count << endl;
                      }
                          break;
                      case 6:  // This is to quit out of the program
                      {
                          cout<< "Goodbye!" <<endl;
                          quit=true;
                      }
                          break;
                      
                  }
                  }
                  return;
              }
              
              void displayMenu()
              {
                  cout << "======Main Menu======" << endl;
                  cout << "1. Find a movie" << endl;
                  cout << "2. Rent a movie" << endl;
                  cout << "3. Print the inventory" << endl;
                  cout << "4. Delete a movie" << endl;
                  cout << "5. Count the Movies"<<endl;
                  cout << "6. Quit and Delete" << endl;
              }
