//
//  Reci5.cpp
//  Lab5.cpp
//
//  Created by Nabil Ettachfini on 10/6/16.
//  Copyright © 2016 Nabil Ettachfini. All rights reserved.
//

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Return the total number of nodes in the BST.
int getSize(Node* node);

// Return the minimal value in the BST.
int getminValue(Node* node); // can use a while loop

// Return the maximum depth of a path in the tree.
int getmaxDepth(Node* node);

// print the tree starting the youngest(smallest) child.
void printTree(Node* node);

// Insert the new value into the BST in the correct position.
Node *newNode(int data);

// add data given the root (parent)
Node *addNode(Node* node, int data);


int main (int argc, char* argv[]){
    Node* root = NULL;
    
    root = newNode(5);
    
    addNode(root,3); //left child to 5
    addNode(root,9); //right child to 5
    
    addNode(root,1); //left child to 3
    addNode(root,4); //right child to 3
    
    addNode(root,6); //left child to 9
    
    addNode(root, 2); // right child to 1
    
    
    printTree(root);
    cout << endl << "There are " << getSize(root) << " nodes in the tree" << endl;
    cout << "The minimum value node is:  " << getminValue(root) << endl;
    cout << "There max depth is: " << getmaxDepth(root) << endl;
}


Node *newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return(node);
}
// we will use recursion
// take care of 2 cases. The base case how the function stops. And the recursive case.
Node *addNode(Node* node, int data)
{
    // base case
    if(node == NULL)
    {
        return newNode(data); // created the node with the data
    }
    // recursive case
    else{
        if(data <= node->data)  node->left = addNode(node->left,data);
        else node->right = addNode(node->right,data);
        return node;
    }
}
// search heap with heap and recursive functions
int getSize(Node* node)
{
    // BASE CASE
        if(node == NULL)
        {
            return 0;
        }
    // RECURSIVE CASE
        else{
          int l=   getSize(node->left);
            int r= getSize(node->right);
            return r+l+1; // you add one becasue of the root node.  to get the size in the whole tree.
        }
}

int getminValue(Node* node)
{
    Node* current=node;
    while ( current->left !=NULL) // for max value change it to 'left' to ' right '
    {
        current=current->left;
    }
    return current->data;
}

void printTree(Node* node)
{
    if ( node == NULL) return;
    printTree(node->left);
    cout<< node->data << endl;  // only cout once because it is recursive
    printTree(node->right);
    
    
    
    
}

int getmaxDepth(Node* node)
{
    // BASE CASE
    
    if(node==NULL)
    {
        return -1;
    }
    else{
        int l=   getmaxDepth(node->left);
        int r=  getmaxDepth(node->right);
        if (l > r) return (l+1);
        else return (r+1);
    }
}





