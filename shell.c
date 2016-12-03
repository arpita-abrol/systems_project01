#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>
#include <signal.h>

/*
Args: a pointer to a directory
Return: void
Function: hard-coded cd command
*/
void cd( char *dir ) {
  if( chdir(dir) == -1 ) {
    printf("The system cannot find the path specified.\n");
  }
  else {
    chdir( dir );
  }
}


/*
Args: none
Return: void
Function: hard-coded exit command
*/
void exit_funct() {
  exit(0);
}



/*
Args: one command (post semicolon parsing)
Return: void
Function: removes all spaces
*/
void removeSpaces( char *cmd[]) {
  char *new[sizeof(&cmd)];
  int i ,j;
  for( i = 0, j = 0; cmd[i]; i++ ) {
    if(strcmp(cmd[i]," ")>0){
      new[j] = cmd[i];
      j++;
    }
  }
  i=0;
  while( i != j ){ 
    cmd[i] = new[i];
    i++;
  }
  cmd[i] = 0;
}


/*
Args: input: input string with semicolons
Return: void
Function: the shell, ofr the most part. in charge of running command splitting and forking, and 'special' occurances like piping, cd, exit, redirect, etc
*/
void cmdline(char *input) {
  strtok(input, "\n"); //rm new line
  char *command[sizeof(input)];
  char *a = input;
  
  //sep into multiple cmds
  int ctr = 0;
  while(a != NULL){
    command[ctr] = strsep(&a, ";");
    ctr++;
  }
  command[ctr] = NULL;
  
  //NOTE: RM WHITE SPACE
  removeSpaces(command);

  //runs command(s)
  for( ctr = 0; command[ctr]; ctr++ ) {
    char *cmd = command[ctr];
    char *sub_command[sizeof(cmd)];
    char *cmd2 = cmd;
    int i = 0;
    for( i=0; cmd2; i++ ) {
      sub_command[i] = strsep(&cmd2, " ");
    }
    sub_command[i] = NULL;
    //note: rm spaces
    removeSpaces(sub_command);

    //'special' stuff, woohoo
    if( strcmp(sub_command[0], "cd") == 0 ) {
      cd(sub_command[1]);
    }
    else if( strcmp(sub_command[0], "exit") == 0 ) {
      exit_funct();
    }
    //fork + run
    else {
      int pid = fork();
      int status;
      if(pid == 0){
	execvp(sub_command[0],sub_command);
      }
      else{
	wait( &status );
      }
    }

  }
  
}

int main() {
  while (1) {
    char input[256];
    char cwd[256];
    getcwd(cwd, sizeof(cwd));
    printf("%s $ ", cwd);
    fgets(input, sizeof(input), stdin);
    cmdline( input );
  }

  return 0;
}
