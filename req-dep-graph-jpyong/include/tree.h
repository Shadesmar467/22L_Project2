#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Downstream module = Child
  Upstream module = Parent
  Same-level module = Sibling*/

typedef struct {
    char modName[30]; 
    Node *child;
    Node *next;
} Node; //using N-ary tree left-child/right-sibling implementation for the dependency tree

Node* newNode(const char* mName); //newNode creates a new Node given the input of the module name
//the input is the module name that you desire to create a node for

Node* addSibling(Node* n, const char* mName); //add sibling (another child for upstream file)
//the input is the node you desire to link the sibling to, and the module name is for the node that will be created

Node* addChild(Node* n, const char* mName);  //add Child dependency (downstream file)
//the input is the node you desire to link the child to, and the module name is for the node that will be created

#endif TREE_H