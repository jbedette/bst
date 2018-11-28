#include <iostream>
#include <cstring>

//John Bedette, cs163
//Project 4, Binary Search Tree
//
//project flow,
//data comes in from client.cpp file,
//is assigned by tree.cpp
//client.cpp interacts with users, they call functions which call the tree.cpp functions
//


/*INPUT: data.txt
 * int:input index|charArr:address|charArr:company name|int:account#|long int:phone#|int:lastD months/int:lastD days|int:lastd years|float:lastP|float:currentP
 */


//company struct, holds data
//disp will read out data
struct company{
	company();
	~company();//destroys the two dynamic char arrs
	int disp();//reads out data to user
	char * name, * addr;
  int lastD[3];//last date, [0] = month, [1] = day, [2] = year
	int acct; 
  long int phon;
	float lastP, currP;
};
struct node{
	node();
  ~node();
  node * l, * r;//[l]eft child & [r]ight child
  company * data;//ptr to company object
};
class tree{
  public:
    tree();
    ~tree();//calls recursive delete, works post-order, calls delete on data then node
    int add(company * temp);//takes in a company pointer, creates a node pointer, assigns node->data to company
    int dispAll();//recurses through calling disp on each node's data 
    int retrieve(company * & temp, char term[]);//takes in search term and a temp company, calls search, assigns temp to = found company->data
    int purgeOld(int today[]);//takes in a user inputted date, converts it to total days, subtracts half a year, passes it to recursive purge
    int getHeight();//calls recursive height finding function
    int remove(char term[]);//takes in term and removes node with matchin data->name
  private:
    int dest(node * & head);//recursively destroys tree, post order
    int search(node * head,node * & found, char term[]);//takes in temp pointer, recurses until term match is found, assings temp pointer to found node
    int searchPrev(node * head, node * & prev, char term[]);//finds a node's parent
    node * recGetIos(node * root);//returns a node's ios
    int recGetH(node * root);//recurses through getting height of tree
    int recPurge(node * & root, long int sixMnth);//recurses through, finds nodes with last paid dates older than six months, deletes them
    int recDispAll(node * root);//displays all nodes
    int recAdd(node * & root, company * temp);//recurses, finds place where node can be allocated, allocates and assigns data
    node * root;
};
class client{
  public:
    client();
    ~client();
    int populate();//reads in data from data.txt, creates companies to be assigned to nodes, calls tree::add with nodes
    void dispAll();//calls tree recusive function to display all alphabetically
    void add();//gets user inputted company, calls tree::add to assign it
    void disp();//gets user term, calls retrieve function, retrieve assigns the found node's company data to a dummy contained in client::disp
    void rem();//gets user term, removes node with associated data->name
    void menu();//menu function for user interface
    void purgeOld();//takes in a date from user, passes date to tree::purgeOld
    void height();//calls tree::getHeight displays height
  private:
    tree * bst;
};

//utility
//date to days conversion
long int convDate(int today[]);//converts date(mm/dd/yyyy) to total days, returns as long int

