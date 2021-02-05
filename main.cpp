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



int main(){
  node *queuehead = new node;
  node *stackhead = new node;
  node *queuetail = new node;
  tree* t = new tree();
  treenode* temp = t->buildtree();
  t->printpostfix(temp);
  t->printinfix(temp);
  t->printprefix(temp);
  /*  bool stillreading = true;
  int input[100];
  char formula[100];
  char *pch = &formula[0];
  int temp;
  cin >> formula;
  
  for (int x = 0; x <= 99; x++){
    input[x] = -1;
  }
  
  while (pch != NULL)
    {
      temp = atoi(pch);
      //cout << pch << endl;
      input[i] = temp;
      pch = strtok (NULL, " ");
      cout << heaparray[i] << endl;
      i++;
    }


  
  int curr = 0;
  while (pch != NULL){
    if( *pch > = 48 && *pch <= 57)
      {
	//its a number goes in the queue
	temp = atoi(pch);
	//cout << pch << endl;
	if(queuehead == NULL){
	  queuehead = enqueue(queuehead, temp, 0);
	  queuetail = queuehead;
	}
	else{
	  queuehead = enqueue(queuehead, temp, o);
	}	
      } else if( *pch == '+' || *pch == '-' || *pch == '*' || *pch == '/' || *pch == '^') 
      {
	while(stackhead != NULL){
	  if((*pch == '+' || *pch == '-') && stackhead->value == '*' || stackhead->value == '/' || stackhead->value == '^'){
	    if(*pch == '*' || *pch == '/') && stackhead->value == '^'){
	    if()
	  }

	}
	}
	
      }
      pch = strtok (NULL, " ");
    

  }
  */

}

int peek(node *head){
  return head->value;
}
node* pop(node* head){
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
node* push(node* head, int i){
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
 node* enqueue(node* head, int i, bool t){
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
node* dequeue(node* head){
  while((head->nextnode)-> nextnode != NULL){
    head = head->nextnode;
  }
  node *temp = head->nextnode;
  head->nextnode = NULL;
  delete temp;
  return head;
}
