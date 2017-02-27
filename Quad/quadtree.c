#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prototypes.h"

Node *makeNode( double x, double y, int level ){
  int i;

  // allocate the data structure
  Node *node = (Node *)malloc(sizeof(Node));

  // set the node data
  node->level = level;
  node->xy[0] = x;
  node->xy[1] = y;

  // set children to NULL
  for( i=0; i<4; ++i )
    node->child[i] = NULL;
    printf("Node made\n");

  return node;
}

void writeTree( Node *head ){
  FILE *fp = fopen("quad.out","w");
  writeNode(fp,head);
  fclose(fp);
  return;
}

void makeChildren( Node *parent ){
  // parent data
  double x = parent->xy[0];
  double y = parent->xy[1];
  int level = parent->level;

  // child edge length
  double hChild = pow(2.0,-(level+1));

  // create children at level+1
  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );

  return;
}

// recursively search for leaf nodes
void writeNode(FILE *fp, Node *node ){
  int i;
  if( node->child[0] == NULL )
    printOut( fp, node );
  else{
    for ( i=0; i<4; ++i ){
      writeNode( fp, node->child[i] );
  }
}
  return;
}

void printOut( FILE *fp, Node *node ) {

  // node data
  double x = node->xy[0];
  double y = node->xy[1];
  int level = node->level;
  double h = pow(2.0,-level);

  // print out the corner points
  fprintf(fp, " %g %g\n",x,y);
  fprintf(fp, " %g %g\n",x+h,y);
  fprintf(fp, " %g %g\n",x+h,y+h);
  fprintf(fp, " %g %g\n",x,y+h);
  fprintf(fp, " %g %g\n\n",x,y);

  return;
}


void growTree(Node *node){
  int i;
  if( node->child[0] != NULL ){
    for ( i=0; i<4; ++i ){
      growTree(node->child[i]);
    }
  }
  else {
    makeChildren(node);
  }
  return;
}

//Function preventing memory leaks, frees allocated space
void destroyNode( Node *node ){
  int i;
  if( node->child[0] == NULL ){
    free(node);
  }
  else{
    for ( i=0; i<4; ++i ){
      destroyNode(node->child[i]);
    }
    free(node);
  }
  return;
}
