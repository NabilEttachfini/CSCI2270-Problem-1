//
//  main.cpp
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
int getminValue(Node* node);
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
    
    addNode(root, 2); //left child to 4
    
    
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

Node *addNode(Node* node, int data) {
    // 1. If the tree is empty, return a new, single node
    if (node == NULL)
    {
        return (newNode(data));
    }
    else
    {
        // 2. Otherwise, recur down the tree
        if (data < node -> data)
            node (argv[])
        {
                Node* root = NULL;
                
                root = newNode(5);
                
                addNode(root,3); //left child to 5
                addNode(root,9); //right child to 5
                
                addNode(root,1); //left child -> left = addNode(node -> left, data);
                else
                    node -> right = addNode(node -> right, data);
                return(node);
            }
    }

    
    
    
}


int getSize(Node* node) {
    
    if (node == NULL)
    {
        return (0);
    }
    else
    {
        return(getSize(node -> left) + 1 + getSize(node -> right));
    }


int  "There are " << getSize(root) << " nodes in the tree" << endl;
cout<< "The minimum value node is:  " << getminValue(root) << endl;
cout<< "There max" << getminValue(<#Node *node#>) <<endl;
    if (node == NULL)
    {
        return (0);
    }
    else
    {
        Node* current = node;
        
        while(current -> left != NULL)
        {
            current = current -> left;
        }
        return(current -> data);
    }
}


int getminValue(Node* node) {
    
    
    
    
    
}

void printTree(Node* node) {
    if (node == NULL) return;
    printTree(node -> left);
    cout << node -> data << " ";
    printTree(node -> right);
}

int getmaxDepth(Node* node) {
   if (node == NULL)
    {
        return (0);
    }
    else
    {
        int lDepth = getmaxDepth(node -> left);
        int rDepth = getmaxDepth(node -> right);
        
        if (lDepth > rDepth) return (lDepth+1);
        else return (rDepth+1);
    }

}