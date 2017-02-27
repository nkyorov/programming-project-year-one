#include "prototypes.h"

struct node {
  struct qnode *leafHead;
};
typedef struct node listNode;


void createList(listNode *listNode);
void expandTreeList (listNode *listNode);
void emptyContents(listNode *listNode);
void AddNode(listNode *listNode, Node *node);
void listWrite(listNode *listNode);
