#include "head.h"

//John Bedette
//cs163, p4, binary search tree



//search funtion,
//recurses through until finding 
//node->data->name == term
//then assings a passed in node * to the
//correct node
//returns success
int tree::search(node * head,node * & found, char term[]){
  found = NULL;
  int match = 1;
  int succ = 0;
  if(!head) return succ;
  match = strcmp(head->data->name,term);
  if(!match){
    found = head;
    ++succ;
  }
  else if(match < 0) search(head->l,found,term);
  else search(head->r,found,term); 
  return succ;
}



//finds a nodes parent and assigns it to
//a passed in node *
//checks if either of the children contain
//the requested term
//returns what direction the node is
int tree::searchPrev(node * root, node * & parent, char term[]){
  if(!root) return 0;
  parent = NULL;
  int succ = 0;
  int match = 1;
  int matchl = 1;
  int matchr = 1;
  if(root->l){
    matchl = strcmp(root->l->data->name, term);
    if(!matchl){
      parent = root;
      ++succ;
      return succ;
    }
  }
  if(root->r){
    matchr = strcmp(root->r->data->name, term);
    if(!matchr){
      parent = root;
      succ += 2;
      return succ;
    }
  }
  match = strcmp(root->data->name, term);
  if(match < 0) succ += searchPrev(root->l,parent,term);
  else succ += searchPrev(root->r,parent,term);
  return succ;
}

