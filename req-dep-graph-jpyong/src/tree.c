#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* newNode(const char* mName) {
  //creating a new node on the heap so that we can retain across function calls
  Node* n = (Node*)malloc(sizeof(Node));

  //checking to make sure malloc worked
  if (n == NULL) {
    printf("Memory Allocation failed\n");
    exit(EXIT_FAILURE);
  }
  
  //importing data into the node DOWNLOADING MOVESET
  strcpy(n->modName, mName);
  n->child = NULL;
  n->next = NULL;

  return n;
}

void addSibling(Node* rootSib, Node* newSib) {
  if (rootSib == NULL || newSib == NULL) {
    return;
  }

  if (rootSib->next == NULL) { //no siblings, can add directly
    rootSib->next = newSib;
  } else {
    Node* currentSib = rootSib->next;
    while (currentSib->next != NULL) {
      currentSib = currentSib->next;
    }
    currentSib->next = newSib;
  }
}

void addChild(Node* parent, Node* child) {
  if (parent == NULL || child == NULL) {
    return;
  }

  if (parent->child == NULL) { //no child yet, can add directly
    parent->child = child;
  } else { //need to go to the end of childs siblings and add there
    Node* currentNode = parent->child; 
    while (currentNode->next != NULL) {
      currentNode = currentNode->next; 
    }
    currentNode->next = child;
  }
}

void freeTree(Node* root) {
  if (root == NULL) return;
  freeTree(root->child);
  freeTree(root->next);
  free(root);
}
