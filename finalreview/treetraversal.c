typedef struct NodeObj{
  int key;
  struct NodeObj* left;
  struct NodeObj* right;
} NodeObj;

typedef NodeObj* Node;

void printPreOrder(Node N) {
  
