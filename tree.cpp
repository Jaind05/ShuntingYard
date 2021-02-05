#include <iostream>
#include <cstring>
#include "tree.h"

using namespace std;


tree::tree(string inputs){

}
tree::~tree(){

}

void tree::buildtree(string inputs){

  int inputs [100];
  int counter = 0;
  while(inputs[counter]!= 0){
    if(inputs[counter]>=0 && inputs[counter] <= 1000 && inputs[counter] != + && inputs[counter] != * && inputs[counter] != / && inputs[counter] != - && inputs[counter] != ^){
      stacknode *temp = new stacknode;
      treenode *branch = new treenode;
      temp->nextnode = head;
      head = temp;
      temp->treehead = branch;
      branch->value = inputs[counter];
    }
    else if(input[curr] == + || input[curr] == - || input[curr] == * || input[curr] == / || input[curr] == ^){
      stacknode *temp = new stacknode;
      treenode *branch = new treenode;
      branch->right = (head->treehead);
      branch->left = ((head->nextnode)->treehead);
      temp->nextnode = (head->nextnode)->nextnode;
      head = temp;
    }

  }


}
void tree::printinfix(){


}
void tree::printprefix(node* temp){


}
void tree::printpostfix(nopde* temp){


}

