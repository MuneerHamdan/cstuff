#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

int running = 1;

void* print(void* arg) {
  while (running) {
    printf("-");
    fflush(stdout);
    usleep(200000);
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
  pthread_create(&thread, NULL, print, NULL);
  while (1) {
    //clear input string
    memset(cmd, 0, sizeof(cmd));
    //get input string
    if (fgets(cmd, sz, stdin) == NULL)
      break;
    //compare input string
    cmp = strcmp(cmd, "quit\n");

    if (cmp == 0) {
      running = 0;
      break;
    }
  }
  pthread_join(thread, NULL);
}


//start program
int main() {

  printf("\
      welcome, what would you like to do\n\
      \n\
      run: run the program\n\
      help: show this message\n\
      quit: quit\n\
      ");
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
