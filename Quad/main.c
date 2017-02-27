#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ListStructure.h"

int main( int argc, char **argv ){
  // create the head node:  level 0
  Node *head = makeNode( 0.0,0.0, 0 );
  makeChildren(head);
  makeChildren(head->child[0]);
  makeChildren((head->child[0])->child[3]);

  writeTree(head);




/*Task 3

  listNode list;
  createList(&list);
  AddNode(&list,head);

  expandTreeList (&list);
  emptyContents(&list);
  AddNode(&list,head);

  expandTreeList (&list);
  emptyContents(&list);
  AddNode(&list,head);

  listWrite(&list);
  destroyNode(head);

*/

/*Task 2

  Node *head = makeNode( 0.0,0.0, 0 );
  //Level 2
  growTree(head);
  //Level 3
  growTree(head);
  //Level 4
  growTree(head);
  //Level 5
  growTree(head);
  //Level 6
  growTree(head);
  //Level 7
  growTree(head);
  //Level 8
  growTree(head);
  //Level 9
  growTree(head);
  //Level 10
  growTree(head);
  writeTree(head);
  destroyNode(head);
  */
}
