// data structure definition

struct qnode{
  // node data
  int level;
  double xy[2];
  struct qnode *child[4];
  struct node *nextLeaf;
};
typedef struct qnode Node;

Node *makeNode( double x, double y, int level );


void writeTree(Node *head);
void makeChildren(Node *parent );
void writeNode(FILE *fp, Node *node );
void growTree(Node *node);
void printOut(FILE *fp, Node *node);
void destroyNode( Node *node );
