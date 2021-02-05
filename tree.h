
struct treenode{
  treenode *left;
  treenode *right;
  int value;
};
struct stacknode{
  stacknode *nextnode;
  treenode *treehead;
};

class tree
{
  
 public:
  treenode* buildtree();
  void printinfix(treenode*);
  void printprefix(treenode*);
  void printpostfix(treenode*);
  

 private:
  stacknode* head;
};


