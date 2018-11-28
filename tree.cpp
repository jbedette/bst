#include "head.h"
#include <cstring>
//John Bedette, cs163
//tree functions except for remove,findios, and search funcs


tree::tree(){
  root = NULL;
}


//calls recursive destroy function, displays total deleted
tree::~tree(){
 int count = 0; 
 count += dest(root);
 std::cout << "\n" << count << " deleted";
}



//recurses through stripping tree of allocated data
int tree::dest(node * & head){
  if(!head) return 0;
  int count = 0;
  count += dest(head->l);
  count += dest(head->r);
  delete head->data;
  delete head;
  //head->data = NULL;
  //head = NULL;
  ++count;
  return count;
}



//wrapper function to call recursive add
int tree::add(company * temp){
  return recAdd(root, temp);
}


//run string compare of node->data->name vs temp-> name for l/r
//direction logic, create new node at correct place, assign data
int tree::recAdd(node * & root,company * temp){
  int succ = 0;
  if(!root){
    root = new node;
    root->data = temp;
    ++succ;
  }else if(strcmp(root->data->name, temp->name) < 0){
    succ += recAdd(root->l, temp);
  }else{
    succ += recAdd(root->r, temp);
  }
  return succ;
}



//calls recursive display all and counts nodes
int tree::dispAll(){ 
  int count = 0;
  count += recDispAll(root);
  return count;
}



//counts nodes and displays them
int tree::recDispAll(node * root){ 
  if(!root) return 0;
  recDispAll(root->l); 
  int count = 0;
  count += (root) ? root->data->disp() : 0;
  recDispAll(root->r);
  return count;
}



//take in an array of ints representing today
//convert array into a total count of days, subtracts half a year
//pass to recursive date check/purge
int tree::purgeOld(int today[]){
  int count = 0;
  long int sixMnth = convDate(today) - 182;
  count += recPurge(root, sixMnth);
  return count;
}



//take in root and int value of days leading up to six months ago
//convert node's last paid date to integer of total days
//if last date on node is < six mnth
//remove all matching
int tree::recPurge(node * & root, long int sixMnth){
  if(!root) return 0;
  int count = 0;
  long int lastD = convDate(root->data->lastD);
  if(root->l)count += recPurge(root->l,sixMnth);
  if(root->r)count += recPurge(root->r,sixMnth);
  if(lastD < sixMnth){
    remove(root->data->name); 
    ++count;
  }
  return count;
}



//recursive height wrapper
int tree::getHeight(){
  return recGetH(root);    
}



//recurses through nodes getting height 
//returns highest
int tree::recGetH(node * root){
  if(!root) return 0;
  int sum = 0;
  int lh = 0; 
  int rh = 0;
  ++sum;
  lh += recGetH(root->l);
  rh += recGetH(root->r);
  sum += (lh > rh) ? lh : rh;
  return sum;
}



//takes in temp node, calls search, if found, temp is assigned to node data
int tree::retrieve(company * & temp, char term[]){
  int succ = 0;
  node * found = NULL;
  succ += search(root,found,term);
  if(found) temp = found->data;
  return succ;
}







