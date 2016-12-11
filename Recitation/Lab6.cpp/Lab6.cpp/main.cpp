//
//  main.cpp
//  Lab6.cpp
//
//  Created by Nabil Ettachfini on 10/13/16.
//  Copyright © 2016 Nabil Ettachfini. All rights reserved.
//

#include <iostream>

using namespace std;
struct TreeNode
{
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

void deleteNode(TreeNode *node, int key);
void deleteAndReplaceMinRight(TreeNode *node, int key);
void preOrderTraversal(TreeNode *node);
void inOrderTraversal(TreeNode *node);
void postOrderTraversal(TreeNode *node);

int main() {
    TreeNode *root = NULL;
    //test case input
    int a[] = { 25, 15, 30, 28, 35, 27, 29, 33, 70};
    int length = 9;
    int value = 30;
    //end of input
    
    for(int i=0; i<length; i++) {
        TreeNode *newnode = new TreeNode;
        newnode->key = a[i];
        newnode->left=NULL;
        newnode->right=NULL;
        newnode->parent = NULL;
        if(root == NULL) {
            root = newnode;
        }
        else {
            TreeNode *temp = root;
            TreeNode *temp2 = NULL;
            while(temp!=NULL) {
                temp2=temp;
                if(temp->key > a[i]) {
                    temp = temp->left;
                }
                else {
                    temp = temp->right;
                }
            }
            if(a[i]<temp2->key)
            {
                newnode->parent = temp2;
                temp2->left = newnode;
            }
            else
            {
                newnode->parent = temp2;
                temp2->right = newnode;
            }
        }
    }
    deleteNode(root, value);
    cout<<"Pre Order Traversal:"<<endl;
    preOrderTraversal(root);
    cout<<endl<<"In Order Traversal:"<<endl;
    inOrderTraversal(root);
    cout<<endl<<"Post Order Traversal:"<<endl;
    postOrderTraversal(root);
    
    deleteAndReplaceMinRight(root,value);
    cout<<"Pre Order Traversal:"<<endl;
    preOrderTraversal(root);
    cout<<endl<<"In Order Traversal:"<<endl;
    inOrderTraversal(root);
    cout<<endl<<"Post Order Traversal:"<<endl;
    postOrderTraversal(root);
    return 0;
}
//---------------------TO DO----------------------
void deleteNode(TreeNode *node, int key)
{
    // Implement your code here
    n
}


//---------------------TO DO----------------------
void deleteAndReplaceMinRight(TreeNode *node, int key) {
    // Implement your code here
    while(node !=NULL)
    {
        if(key< node->key)
        {
            node=node->left;
        }
        else if ( key> node->key)
        {
            node=node->right;
        }
        else
        {
            break;
        }
    }
        if(node!=NULL)
        {
            // if it has no children
            if(node->left==NULL && node->right==NULL)
            { // if the node is a left child
                
                if(node->parent->left == node)
                {
                    node->parent->left=NULL;
                }
                else
                { // if the node is a right child
                    node->parent->right=NULL;
                }
                delete node;
            }
            else if (node->right == NULL) // if it only has a left child
            {
                if(node->parent->left == node)
                {
                    node->parent->left= node->left;
                    node->left->parent= node->parent;
                }
                else
                {
                    node->parent->right= node->left; //copied from above and changed left to right
                    node->left->parent= node->parent;
                }
                delete node;
            }
            // if it only has a right childn
            else if (node->left == NULL)
            {
                cout<<"right"<<endl;
                if(node->parent->left == node)
                {
                    node->parent->left= node->right;
                    node->right->parent= node->parent;
                }
                else
                {
                    node->parent->right= node->right;
                    node->right->parent= node->parent;
                }
                delete node;
            }
            else
            {
                cout<< "Two"<<endl;
                TreeNode* min=node->right;
                while(min->left !=NULL)
                {
                    min=min->left;
                }
                node->key=min->key;
                if(min->right !=NULL)
                {
                    min->right->parent= min->parent;
                }
                if(min->parent->left == min){
                    min->parent->left = min->right;
                }
                else
                {
                    min->parent->right= min->right;
                }
                delete min;
            }
        }
    }


// we found the node we want to delete

void preOrderTraversal(TreeNode *node)
{
    if(node == NULL){
        return;
    }
    else
    {
        cout<<node->key<<" ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}
void inOrderTraversal(TreeNode *node)
{
    if(node == NULL)
        return;
    else
    {
        inOrderTraversal(node->left);
        cout<<node->key<<" ";
        inOrderTraversal(node->right);
    }
}
void postOrderTraversal(TreeNode *node)
{
    if(node == NULL)
        return;
    else
    {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout<<node->key<< " ";
        
    }
}
