#include "head.h"

long int convDate(int today[]){
  long int totDays = today[1];//days
  int y = today[2];//years
  for(int m = today[0]; m > 0; --m){//mnth->days
    if( m == 2 ) totDays += 28;
    else if(
        m == 1 ||
        m == 3 ||
        m == 5 ||
        m == 7 ||
        m == 8 ||
        m == 10 ||
        m == 12
        ){
      totDays += 31;
    }else{
      totDays += 30;
    }
  }
  return totDays += y*365;
}
