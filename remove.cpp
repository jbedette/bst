#include "head.h"

//John Bedette
//cs163, p4, binary search tree



//my big beefy remove function
//not the cleanest, but i love it like a child
int tree::remove(char term[]){
  int succ = 0;
  if(!root) return succ;
  if(!root->l && !root->r){
    delete root->data;
    delete root;
    root = NULL;
    return ++succ;
  }
  //assign found to correct node
  node * found = NULL;
  succ += search(root,found, term);

  //not found
  if(!found){
    return succ;
  }

  //match found starts

  //if there are no children
  if(!found->l && !found->r){
    node * fprev;//to be set to parent of node found
    int foundParentOpt = searchPrev(root,fprev,term);//found dir stores direction of found from parent
    //0, is root, 1 l of parent, 2 r of parent
    delete found->data;
    found->data = NULL;
    delete found;
    if(foundParentOpt)(foundParentOpt == 1) ? fprev->l = NULL : fprev->r = NULL;
  }

  //if one child is null
  else if(!found->l || !found->r){
    node * temp = (found->l) ? found->l : found->r;
    delete found->data;
    found->data = NULL;
    found->data = temp->data;
    found->l = temp->l;
    found->r = temp->r;
    delete temp;
    temp = NULL;
  }

  //if we need the ios
  else{

    node * ios = recGetIos(found);
    node * iosParent;
    int iosParentOpt = 0;
    iosParentOpt += searchPrev(root,iosParent,ios->data->name);

    delete found->data;
    found->data = NULL;
    found->data = ios->data; 
    delete ios;
    if(iosParentOpt == 2) iosParent->r = NULL;
    if(iosParentOpt == 1) iosParent->l = NULL;
  }
  return succ;
}




