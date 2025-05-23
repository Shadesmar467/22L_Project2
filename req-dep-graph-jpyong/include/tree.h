#ifndef TREE_H
#define TREE_H

/*Downstream module = Child
  Upstream module = Parent
  Same-level module = Sibling*/

typedef struct Node {
    char modName[30]; 
    struct Node *child;
    struct Node *next;
} Node; //using N-ary tree left-child/right-sibling implementation for the dependency tree

Node* newNode(const char* mName); //newNode creates a new Node given the input of the module name
//the input is the module name that you desire to create a node for

void addSibling(Node* rS, Node* nS); //add sibling (another child for upstream file)
//the input is the node you desire to link the sibling to, and the module name is for the node that will be created

void addChild(Node* p, Node* c);  //add Child dependency (downstream file)
//the input is the node you desire to link the child to, and the module name is for the node that will be created

void freeTree(Node* root);

#endif
