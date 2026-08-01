#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>


void* foo(void* arg) {
  int i = 0;
  while(i != -1) {
    printf("hello ");
  }
  return NULL;
}

// run thing
void run() {
  char cmd[100];
  int sz = sizeof(cmd) / sizeof(char);
  // while input is not quit
  int cmp = -1;

  int linenumber = 0;

  pthread_t thread;
  pthread_create(&thread, NULL, foo, NULL);
  while (cmp != 0) {
    //clear input string
//    memset(cmd, 0, sizeof(cmd));
    //get input string
//    fgets(cmd, sz, stdin);
    //compare input string
 //   cmp = strcmp(cmd, "quit\n");
    printf("cmp ");

    //okay so basically if theres no input within the time limit just continue
    //so we need a time limit
    //
  }
  pthread_join(thread, NULL);
}


//start program
int main() {
  //allocate s1
  char s1[100];
  //get s1 size
  int sz = sizeof(s1) / sizeof(char);
  //get s1 from user input
  fgets(s1, sz, stdin);
  //make s2
  char s2[] = "run\n";
  //compare s1 s2
  int cmp = strcmp(s1, s2);
  if (cmp == 0)
    run();
  else

  return 0;
}
