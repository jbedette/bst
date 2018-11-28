#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main(){
  ifstream fin;
  fin.open("data2.txt");

  int index = 0;
  char addr[50];
  char name[50];
  int acct = 0;
  long int phon = 0;
  int date[3];
  float last = 0;
  float curr = 0;
  while(fin && fin >> index && !fin.eof()){
    fin.ignore(100,'|');
    fin.get(addr,49,'\n');
    fin.ignore(100,'|');
    fin.get(name,49,'\n');
    fin.ignore(100,'|');
    fin >> acct;
    fin.ignore(100,'|');
    fin >> phon;
    fin.ignore(100,'|');
    fin >> 
  }
  return 0;
}

