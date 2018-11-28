#include "head.h"

//John Bedette
//cs163 p4 binary search tree
//company data struct



//assigns everythign to falsey values
company::company(){
  name = NULL;
  addr = NULL;
  lastD[0] = 0;
  lastD[1] = 0;
  lastD[2] = 0;
  acct = 0;
  phon = 0;
  lastP = 0;
  currP = 0;
}



//deletes both dyn allocated arrays
company::~company(){
  delete name;
  delete addr;
}



//displays company data to user
int company::disp(){
  std::cout 
    << "\n\n" << name
    << "\n=========="  
    << "\nPhone #: " << phon
    << "\nAddress: " << addr
    << "\nAccount #: " << acct
    << "\nLast payment date: " << lastD[0]
    << "/" << lastD[1] << '/' <<lastD[2] 
    << "\nLast payment amount: " << lastP
    << "\nCurrent amount due: " << currP
    << "\n==========";
  return 1;
}
