#include "head.h"

//John Bedette
//cs163, p4, binary search tree



node * tree::recGetIos(node * root){
  node * ios = NULL;
  if(root->r && root->r->l){
    ios = root->r;
    while(ios->l){
      ios = ios->l;
    }
  }else{
    ios = root->l;
    while(ios->r){
      ios = ios->r;
    }
  }
  return ios;
}

