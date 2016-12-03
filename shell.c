#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>


void cmdline2( char *a ) {
  char *s;
  char *command[20];
  int i = 0;
  int first = 0;
  a = strsep(&a, "\n");
  while(a != NULL){
    s = strsep(&a, " ");
    command[i] = s;
    i++;
  }
  if( strcmp(command[0], " ") ) {
    first = 1;
  }
  command[i] = 0; //terminating null;
  execvp(command[0], command);
  _exit(0);
}

void cmdline() {
  printf("What would you like to do? ");
  char *a = calloc(1,256);
  fgets (a, 255, stdin);
  char *s;
  char *command[20];
  int i = 0;
  a = strsep(&a, "\n");
  while(a != NULL){
    s = strsep(&a, ";");
    command[i] = s;
    i++;
  }
  command[i] = NULL;
  for( i=0; command[i]; i++ ) {
    printf("%s\n",command[i]);
    int pid;
    int status;
    pid = fork();
    if( pid == 0 ) {
      cmdline2( command[i] );
    }
    else {
      wait( &status );
    }
  }
  free(a);

}

int main() {
  cmdline();
  return 0;
}
