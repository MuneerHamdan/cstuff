#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

int running = 1;
int* stuff;
int size = 1;

void* run(void* args) {

  stuff = malloc(size * sizeof(int));
  if (stuff == NULL)
    printf("malloc failed\n");

  while (running) {
    printf("%d", stuff[size]);
    fflush(stdout);
    usleep(200000);
  }
  return NULL;
}

// run thing
void start() {

  printf("\n\
      type 'quit' at any time to quit program\n\
      ");

  char c;

  pthread_t thread;
  pthread_create(&thread, NULL, run, NULL);

  while (1) {

    c = getchar();

    if (c == 'a') {
      size++;
      stuff = realloc(stuff, size * sizeof(int));
      stuff[size - 1] = size;
    }

    if (c == 'q') {
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
      start: start the program\n\
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
  char s2[] = "start\n";
  //compare s1 s2
  int cmp = strcmp(s1, s2);
  if (cmp == 0)
    start();

  free(stuff);
  return 0;
}
