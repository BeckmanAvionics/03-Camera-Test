#include <iostream>
#include <stdio.h>      /* puts, printf */
#include <time.h>       /* time_t, struct tm, time, gmtime */
#define PST (-8)
using namespace std;


int main () {
  time_t rawtime;
  struct tm * ptm;
  time ( &rawtime );
  ptm = gmtime ( &rawtime );
  puts ("Current Time");
  printf ("%02d-%02d-%02d_%2dhr%02dm\n",ptm->tm_mday,(ptm->tm_mon+1),(ptm->tm_year+1900),(ptm->tm_hour+PST)%24,ptm->tm_min);
  return 0;
}
