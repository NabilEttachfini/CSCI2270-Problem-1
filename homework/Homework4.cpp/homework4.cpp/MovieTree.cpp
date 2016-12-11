// Nabil Ettachfini
// CSCI 2270, Elle Boese
// TA:Yang :)
// Fall 2016
// Homework #5

#include <iostream>
#include <string>
#include  <list>
#include <cctype>
 #include  "MovieTree.hpp"


using namespace std;
string toLowercase(string instr);


MovieTree :: MovieTree()
{
    root = NULL;
}

MovieTree :: ~MovieTree(){ // this will delete the tree
    DeleteAll(root);
    
    /*MovieNode* tree= root;
     list <MovieNode*> myQ;
     // myQ.push_back(root);
     while(tree != NULL)
     {
     if( tree->leftChild)
     {
     myQ.push_back( tree->leftChild);
     }
     if( tree->rightChild)
     {
     myQ.push_back( tree->rightChild);
     }
     delete tree;
     if( !myQ.empty())
     {
     tree= myQ.front();
     myQ.pop_front();
     }
     else{
     tree = NULL;
     }
     }
     */
}
void MovieTree :: DeleteAll(MovieNode* node)
{
    if(node) // maybe need if node is equal to null then put return inside
    {
        DeleteAll(node->rightChild);
        DeleteAll(node->leftChild);
        delete node;
    }
}
void MovieTree:: countMovieNodes(MovieNode *node, int *c)
{
    if ( node->rightChild != NULL)
    {
        countMovieNodes ( node->rightChild, c);
    }
    *c=*c+1;
    if( node->leftChild !=NULL)
    {
        countMovieNodes( node->leftChild, c);
    }
}
int MovieTree :: countMovieNodes()
{
    int c=0;
    countMovieNodes( root, &c);
    return c;
}
void MovieTree :: deleteMovieNode(string title) // cout when movie isnt found
{
    MovieNode * node = search(title);
    if(node==NULL)
    {
        cout<<"Movie not found"<<endl;
        return; // this may not be needed
    }
    // if it has no children
    if (node != NULL)
    {
        if(node->leftChild == NULL && node->rightChild ==NULL)
        {
            if(node==root)
            {
                delete node;
                root= NULL;
            }
          else  if (node->parent->leftChild == node)
            {
                node->parent->leftChild = NULL;
                delete node;
            }
         else // (node->parent->rightChild == node)
            {
                node->parent->rightChild = NULL;
                delete node; 
            }
        }
        else if ( node ->rightChild ==NULL)
        {
            if(node->parent == NULL)
            {
                root = node->leftChild;
                node->leftChild->parent = NULL;
            }
            
            else if(node->parent->leftChild == node)
            {
                node->parent->leftChild= node->leftChild;
                node->leftChild->parent= node->parent;
            }
            else
            {
                node->parent->rightChild= node-> leftChild;
                node->leftChild->parent= node->parent;
            }
            delete node;
        }
        else if (node->leftChild==NULL)
        {
            if(node->parent==NULL)
            {
                root= node->rightChild;
                node->rightChild->parent=NULL;
            }
          else  if(node->parent->leftChild== node)
            {
                node->parent->leftChild= node->rightChild;
                node->rightChild->parent= node->parent;
            }
            else
            {
                node->parent->rightChild= node->rightChild;
                node->rightChild->parent= node->parent;
            }
            delete node;
        }
        else
        {
            MovieNode * min = treeMinimum(node->rightChild);
            while(min->leftChild != NULL)
            {
                min=min->leftChild;
            }
            // moving all data over, fixed from just moving the title before hand
            node->title=min->title;
            node->ranking=min->ranking;
            node->year=min->year;
            node->quantity=min->quantity;
            
            if(min->rightChild !=NULL)
            {
                min->rightChild->parent=min->parent;
            }
            if(min->parent->leftChild == min)
            {
                min->parent->leftChild=min->rightChild;
            }
            else   min->parent->rightChild= min->rightChild;
            delete min;
        }
    }
}



void MovieTree :: printMovieInventory()
{
    printMovieInventory(root);
}

#include <iostream> // for debugging purposes
void MovieTree ::  addMovieNode(int ranking, string title, int releaseYear, int quantity) // this might be a little messed up
{
    //cout << "Commencing adding node" << endl;
    // DO NOT FORGET TO CONVERT THINGS TO LOWERCASE!! YOU GOT THIS NABIL
    MovieNode* newNode= new MovieNode(ranking, title, releaseYear , quantity);
    newNode-> parent=NULL;
    newNode->leftChild=NULL;
    newNode->rightChild=NULL;
    
    if (!root)
    {
        root = newNode;
        //cout << "Adding root node, " << title << endl;
        return;
    }
    
    MovieNode* tmp1= root;
    MovieNode*  momdad= tmp1;
    
    while (tmp1)
    {
        momdad=tmp1;
        if( toLowercase(title) < toLowercase( tmp1->title)) // make sure this works, and this should compare the titles.
        {
            tmp1=tmp1->leftChild;
        }
        else tmp1=tmp1-> rightChild;
    }
    //  MovieNode* root= new MovieNode (ranking,title,releaseYear, quantity);
    // while(!tmp1)
    //  {
    // momdad=root; this is not needed
    
    //cout << "Adding " << title << " to list, ";
    
    if( toLowercase(title)  < toLowercase(momdad->title)) // not too sure what it needs to be less than on, also i changed the parent to tmp1, check if works after rest is complete
    {
        momdad->leftChild = newNode;
        
        //cout << "left child" << endl;
    }
    else
    {
        momdad->rightChild = newNode;
        
        //cout << "right child" << endl;
    }
    //  }
    
    newNode->parent = momdad;
    //  tmp1->rightChild=NULL;
    //  tmp1->leftChild=NULL;
}

// might need to set things to null again, check with CA at office hours


void MovieTree :: findMovie(string title) // COME BACK AND FIX THIS MY DUDE
{
    MovieNode* foundMovie=search(title); // changed all to foundMovie to match the cout statments provided
    if(!foundMovie) // essentailly this is like saying if it's equal to NULL
    {
        cout << "Movie not found." << endl;
    }
    else{
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << foundMovie->ranking << endl;
        cout << "Title:" << foundMovie->title << endl;
        cout << "Year:" << foundMovie->year << endl;
        cout << "Quantity:" << foundMovie->quantity << endl;
    }
}
void MovieTree :: rentMovie(string title)
{
    MovieNode* foundMovie=search(title); // does this need to be foundMovie? because of the cout
    
    if(foundMovie == NULL)  // FIND A CLEANER WAY TO DO THIS
    {
        cout << "Movie not found." << endl;
    }
    
    else if( foundMovie->quantity !=0) // changed all to foundMovie to match the cout statments provided
    {
        foundMovie->quantity --;    // this should take the quantity of that movie and take one out once rented.
        cout << "Movie has been rented." << endl;
        cout << "Movie Info:" << endl;
        cout << "===========" << endl;
        cout << "Ranking:" << foundMovie->ranking << endl;
        cout << "Title:" << foundMovie->title << endl;
        cout << "Year:" << foundMovie->year << endl;
        cout << "Quantity:" << foundMovie->quantity << endl;
        
        if( foundMovie->quantity==0) // to delete when the quantity is zero
        {
            deleteMovieNode(title);
        }
    }
    else
        cout << "Movie out of stock." << endl;
}

void MovieTree :: printMovieInventory(MovieNode * node)
{
    if(node)
    {
        printMovieInventory (node-> leftChild); // this is like what we did in class.
        cout << "Movie: "<< node->title <<" "<< node->quantity <<endl;
        printMovieInventory (node->rightChild);
        
    }
}


MovieNode * MovieTree :: search (string title)  // Do this first, because the other functions use this. i got rid of the std::
{
    
    
    if( root == NULL)
    {
        return NULL;
    }
    MovieNode* tmp2= root;
    while(tmp2){
        
        if (toLowercase(tmp2->title)  == toLowercase(title))
        {
            return tmp2;
        }
        if( toLowercase(title)  < toLowercase (tmp2->title)) // maybe do not even need the momdad part
        {
            tmp2=tmp2->leftChild;
        }
        else tmp2=tmp2->rightChild;
    }
    return NULL;
}
MovieNode* MovieTree :: treeMinimum(MovieNode* node)
{
    MovieNode* previous= node;
    if(!node) // same thing as node == null
    {
        return NULL;
    }
    while(node != NULL)
    {
        previous = node;
        node = node->leftChild;
    }
    return previous;
}

string toLowercase(string instr)
{
    string outstr = instr;
    for (int i = 0; i < instr.length(); i++)
    {
        outstr[i] = tolower(instr[i]);
    }
    return outstr;
}




