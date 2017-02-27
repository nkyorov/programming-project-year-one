#include <stdlib.h>
#include <stdio.h>
#include "ListStructure.h"

//Creates linked list
void createList(listNode *listNode) {
        listNode->leafHead = NULL;
}

void listWrite(listNode *listNode) {
    //Temporary holder for  next leaf
    Node *pHolder = listNode->leafHead;
    FILE *fp = fopen("quad.out","w");

    while(pHolder != NULL){
      ////If next leaf isn't empty use temporary holder.
      writeNode(fp,pHolder);
      pHolder = pHolder->nextLeaf;
    }

    fclose(fp);
  }

void AddNode(listNode *listNode, Node *node) {
      int i;
      if (node->child[0] == NULL) {
      //If true,  "nextLeaf" becomes "leafHead"
      node->nextLeaf = listNode->leafHead;
      listNode->leafHead = node;
      }
      else {
      //Keep looping through
          for(i = 0; i < 4; i++) {
              AddNode(listNode , node->child[i]);
          }
      }
  }


  void expandTreeList ( listNode *listNode ) {
      Node *pHolder = listNode->leafHead;
      while(pHolder != NULL){
        makeChildren(pHolder);
        pHolder = pHolder->nextLeaf;

      }
      return;
  }
//If we want to grow the list more times, we need to reset current pointers
  void emptyContents( listNode *listNode ) {
      Node *pHolder = listNode->leafHead;
      while(pHolder != NULL){
        pHolder->nextLeaf = NULL;
        pHolder = pHolder->nextLeaf;
      }
      listNode->leafHead = NULL;
  }
