#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include "tree.h"
using namespace std;

struct node{
  int value;
  bool type; //0 number 1 symbol
  node *nextnode; 
};

node* enqueue(node*,int,bool);

int main(){
  node *queuehead = new node; //node * to hold the first node in the queue  
  node *stackhead = new node; //node * to hold the first node in the stack
  node *queuetail = new node; //node * to hold the node at the end of the queue
  tree* t = new tree(); //new implementation of the expression tree
  treenode* tempt = t->buildtree(); // build a new expression tree
  if (tempt != NULL) //if the tree was built
    cout << "built the tree" << endl;
  else // if tree wasnt built
    cout << "temp is null" << endl;
  t->printpostfix(tempt); //postfix
  cout << endl << endl;
  t->printinfix(tempt); //infix
  cout << endl << endl;
  t->printprefix(tempt); //prefix
  bool stillreading = true; // variables for the shunting yard algorithm.
  int input[100]; //input array
  char formula[100];
  char *pch = &formula[0];
  int temp;
  cin >> formula;
  int i = 0;
  
  for (int x = 0; x <= 99; x++){ //sets all array slots to -1
    input[x] = -1;
  }
  
  while (pch != NULL)
    {
      temp = atoi(pch);
      //cout << pch << endl;
      input[i] = temp;
      pch = strtok (NULL, " ");
      cout << input[i] << endl;
      i++;
    }


  
  int curr = 0;
  while (pch != NULL){
    if( *pch >= 48 && *pch <= 57)
      {
	//its a number goes in the queue
	temp = atoi(pch);
	//cout << pch << endl;
	if(queuehead == NULL){ //begining of shunting algorithm
	  queuehead = enqueue(queuehead, temp, 0);
	  queuetail = queuehead;
	}
	else{
	  queuehead = enqueue(queuehead, temp, 0);
	}	
      } else if( *pch == '+' || *pch == '-' || *pch == '*' || *pch == '/' || *pch == '^') 
      {
	while(stackhead != NULL){
	  if((*pch == '+' || *pch == '-') && stackhead->value == '*' || stackhead->value == '/' || stackhead->value == '^'){
	    if((*pch == '*' || *pch == '/') && stackhead->value == '^'){
      }
	  }

	}
	}
	
      }
      pch = strtok (NULL, " ");
    

  }

int peek(node *head){ //peek function
  return head->value;
}
node* pop(node* head){ //pop function
  node* temp;
  if(head == NULL){
    temp = NULL;
  }
  else if(head->nextnode == NULL){
    temp = NULL;
    delete head;
  }
  else{
    temp = head->nextnode;
    delete head;
  }
  return temp;
}
node* push(node* head, int i){ //push function
  if(head == NULL){
    node *temp = new node;
    temp->value = i;
    return temp;
  }
  else{
    node *temp = new node;
    temp->value = i;
    temp->nextnode = head;
    return temp;
  }
  

}
 node* enqueue(node* head, int i, bool t){ //enqueue function
  if(head == NULL){
    node *temp = new node;
    temp->value = i;
    temp->type = t;
    return temp;
  }
   else{
    node *temp = new node;
    temp->value = i;
    temp->type = t;
    temp->nextnode = head;
    return temp;
  }

}
node* dequeue(node* head){ //dequeue function
  while((head->nextnode)-> nextnode != NULL){
    head = head->nextnode;
  }
  node *temp = head->nextnode;
  head->nextnode = NULL;
  delete temp;
  return head;
}
