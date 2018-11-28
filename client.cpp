#include "head.h"
#include <fstream>
#include <cstring>
using namespace std;

//creates tree, calls populate,displays tree
client::client(){
  bst = new tree;
  populate();
  dispAll();
}



//destroys tree
client::~client(){
  delete bst;
}



//reads data from ext file
//feeds into a temp company
//company is passed into the table
//table ptrs are assigned to the temp
//temp is assigned to null
//then temp is made into a new temp company
//the process repeats
int client::populate(){
    company * temp;
    int count = 0;
    ifstream fin;
    fin.open("data.txt");
    if(!fin) return count;
    int index = 0;
    while(fin && fin >> index && !fin.eof()){
        fin.ignore(100,'|');

        temp = new company;
        char name[50];
        char addr[50];

        fin.get(addr,49,'|');//1
        fin.ignore(100,'|');
        fin.get(name,49,'|');//2
        fin.ignore(100,'|');
        fin >> temp->acct;//3
        fin.ignore(100,'|');
        fin >> temp->phon;//4
        fin.ignore(100,'|');

        fin >> temp->lastD[0];//5[0]
        fin.ignore(100,'/');
        fin >> temp->lastD[1];//5[1]
        fin.ignore(100,'/');
        fin >> temp->lastD[2];//5[2]
        fin.ignore(100,'|');

        fin >> temp->currP;//6
        fin.ignore(100,'|');
        fin >> temp->lastP;//7
        fin.ignore(100,'\n');
        
        temp->addr = new char[strlen(addr)+1];
        temp->name = new char[strlen(name)+1];
        strcpy(temp->name,name);
        strcpy(temp->addr,addr);

        count += bst->add(temp);
        temp = NULL;
    }
    fin.close();
    if(!(count-index)) cout << "\nAll items succesfully added.";
    return 0;
}



//calls dispall on tree
void client::dispAll(){
  bst->dispAll();
}




//takes search term from client
//feeds search term to tree->retrieve
//sets temp company as equal to desired company values
//displays errors
void client::disp(){
    company * temp = NULL;
    char term[50];
    cout << "\nCompany to display: ";
    cin.get(term,49,'\n');
    cin.clear();
    cin.ignore(100,'\n');
    bst->retrieve(temp,term);
    if(temp)temp->disp();
    else cout << "\nCompany not found";
}



//takes term to search for for deletion
//displays success and failure 
void client::rem(){
    char term[50];
    cout << "\nEnter company to delete: ";
    cin.get(term,49,'\n');
    if(bst->remove(term)) cout << "\nCompany deleted";
    else cout << "\nDelete failed, did you enter the correct company name?";
}


//menu function for user interface
//exits on input of 'e'
void client::menu(){
    char opt = ' ';
    while(opt != 'e'){
        opt = ' ';
        cout << "\nWelcome to my binary search tree, would you like to: ";
        cout << "\n--[D]isplay all bills?";
        cout << "\n--[S]ee only one bill?";
        cout << "\n--[A]dd a new bill?";
        cout << "\n--[R]emove a bill?";
        cout << "\n--[P]urge bills older than six months?";
        cout << "\n--[G]et the height of binary tree that represents the eternally growing mountain of debt that is slowly crushing your will to live?";
        cout << "\n--[E]xit?\n";
        cin >> opt;
        cin.clear();
        cin.ignore(100,'\n');
        opt = tolower(opt);
        if(opt == 'd')dispAll();
        if(opt == 's')disp();
        if(opt == 'a')add();
        if(opt == 'r')rem();
        if(opt == 'g')height();
        if(opt == 'p')purgeOld();
    }
    cout << "\nGoodbye";
}



//displays height to user
void client::height(){
  cout << "\nThe height is: " << bst->getHeight();
}



//takes in user defined date, passes to tree::purgeOld
//removes all dates six months before date
void client::purgeOld(){
  int today[3];
  cout << "\nEnter today's date\n>Enter month(mm): ";
  cin >> today[0];
  cout <<"\n>Enter day(dd): ";
  cin >> today[1];
  cout << "\nEnter year(yyyy): ";
  cin >> today[2];

  if( today[0] > 12 || today[0] < 1 ||
      today[1] > 31 || today[1] < 1 ||
      today[2] > 2018 || today[2] < 1
    )cout << "\nErr: please enter a valid date";
  else bst->purgeOld(today);
}



//takes in a user defined company
//passes to table
//displays success/fail
//sets temp to null
void client::add(){
    company * temp = new company;
    char name[50];
    char addr[50];
    cout << "\nPlease enter company...";
    cout << "\n--name: ";
    cin.get(name,49,'\n');
    cin.clear();
    cin.ignore(100,'\n');
    cout << "\n--address: ";
    cin.get(addr,49,'\n');
    cin.clear();
    cin.ignore(100,'\n');
    cout << "\n--phone: ";
    cin >> temp->phon;
    cin.clear();
    cin.ignore(100,'\n');
    cout << "\n--account: ";  
    cin >> temp->acct;
    cin.clear();
    cin.ignore(100,'\n');
    cout << "\n--date of last payment: ";
    cout << "\n-Enter month(mm): ";
    cin >> temp->lastD[0];
    cin.ignore(100,'\n');
    cout << "\n-Enter day(dd): ";
    cin >> temp->lastD[1];
    cin.ignore(100,'\n');
    cout << "\n-Enter year(yyyy): ";
    cin >> temp->lastD[2];
    cin.ignore(100,'\n');
    cout << "\n--amount of last payment: ";
    cin >> temp->lastP;
    cout << "\n--current amount owed: ";
    cin >> temp->currP;
    cin.clear();
    cin.ignore(100,'\n');
    temp->name = new char[strlen(name) +1];
    temp->addr = new char[strlen(addr) + 1];
    strcpy(temp->name,name);
    strcpy(temp->addr,addr);
    if(bst->add(temp)){
        cout << "\nCompany Added";
    }
    else cout << "\nError: adding company failed";
    temp = NULL; 
}






