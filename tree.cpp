#include <iostream>
#include <cstring>
#include "tree.h"

using namespace std;

treenode *tree::buildtree()
{

  int inputs[100] = {3, 4, 2, -3, 1, 5, -2, 2, 3, -5, -5, -4, -1};
  int counter = 0;
  while (inputs[counter] != 0)
  {
    if (inputs[counter] >= 0 && inputs[counter] <= 1000)
    {
      cout << "here" << endl;
      stacknode *temp = new stacknode;
      treenode *branch = new treenode;
      temp->nextnode = head;
      head = temp;
      temp->treehead = branch;
      branch->value = inputs[counter];
    }
    else if (inputs[counter] == -1 || inputs[counter] == -2 || inputs[counter] == -3 || inputs[counter] == -4 || inputs[counter] == -5)
    {
      stacknode *temp = new stacknode;
      treenode *branch = new treenode;
      branch->right = (head->treehead);
      branch->left = ((head->nextnode)->treehead);
      temp->nextnode = (head->nextnode)->nextnode;
      head = temp;
      temp->treehead = branch;
      branch->value = inputs[counter];
    }
    counter++;
  }
  cout << "Got here!" << endl;
  return head->treehead;
}
void tree::printinfix(treenode *temp)
{
  if (temp != NULL)
  {
    //cout << "here1" << endl;
    if (temp->value == -1 || temp->value == -2 || temp->value == -3 || temp->value == -4 || temp->value == -5)
    {
      cout << "(";
    }
    //cout << "herea" << endl;
    printinfix(temp->left);
    //cout << "hereb" << endl;
    if (temp->value == -1 || temp->value == -2 || temp->value == -3 || temp->value == -4 || temp->value == -5)
    {
      if (temp->value == -1)
      {
        cout << "+";
      }
      else if (temp->value == -2)
      {
        cout << "-";
      }
      else if (temp->value == -3)
      {
        cout << "*";
      }
      else if (temp->value == -4)
      {
        cout << "/";
      }
      else if (temp->value == -5)
      {
        cout << "^";
      }
    }
    else
    {
      cout << temp->value;
    }
    printinfix(temp->right);
    if (temp->value == -1 || temp->value == -2 || temp->value == -3 || temp->value == -4 || temp->value == -5)
    {
      cout << ")";
    }
  }
}
void tree::printprefix(treenode *temp)
{
  if (temp != NULL)
  {
    if (temp->value == -1 || temp->value == -2 || temp->value == -3 || temp->value == -4 || temp->value == -5)
    {
      if (temp->value == -1)
      {
        cout << "+";
      }
      else if (temp->value == -2)
      {
        cout << "-";
      }
      else if (temp->value == -3)
      {
        cout << "*";
      }
      else if (temp->value == -4)
      {
        cout << "/";
      }
      else if (temp->value == -5)
      {
        cout << "^";
      }
    }
    else
    {
      cout << temp->value;
    }
    printprefix(temp->left);
    printprefix(temp->right);
  }
}
void tree::printpostfix(treenode *temp)
{
  if (temp != NULL)
  {
    //if (temp->value == -1 || temp->value == -2 || temp->value == -3 || temp->value == -4 || temp->value == -5)
    //{
      printpostfix(temp->left);
      printpostfix(temp->right);
      if (temp->value == -1 || temp->value == -2 || temp->value == -3 || temp->value == -4 || temp->value == -5)
      {
        if (temp->value == -1)
        {
          cout << "+ ";
        }
        else if (temp->value == -2)
        {
          cout << "- ";
        }
        else if (temp->value == -3)
        {
          cout << "* ";
        }
        else if (temp->value == -4)
        {
          cout << "/ ";
        }
        else if (temp->value == -5)
        {
          cout << "^ ";
        }
      }
      else
      {
        cout << temp->value << " ";
      }
    //}
  }
}
