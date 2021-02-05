#ifndef TREE_H
#define TREE_H

struct stacknode(){
  stacknode *nextnode;
  treenode *treehead;

}
struct treenode(){
  treenode *left;
  treenode *right;
  int value;
}

class item
{
  
 public:
  tree(string);
  ~tree();
  void buildtree(string);
  void printinfix();
  void printprefix();
  void printpostfix();
  

 private:
  stacknode* head;
   int location; //room_id
};


#endif
