# Shell
by Arpita Abrol

##### Features:
* Forks and executes commands
* Parses multiple commands on one line (use " ; " between commands)
* cd added
* exit added
* multiple spaces stripped


##### Attempted:
* redirecting
* piping

##### Bugs:
* Using cd .. causes the shell to go up two directories


##### Files & Function Headers:

shell.c:

/*==========
Args: a pointer to a directory
Return: void
Function: hard-coded cd command
==========*/

/*==========
Args: none
Return: void
Function: hard-coded exit command
==========*/

/*==========
  Args: command, search for chr
  Return: first time something is present in the command
  Function: searches aray for sometihng
  ==========*/
  
/*==========
Args: one command (post semicolon parsing)
Return: void
Function: removes all spaces
==========*/

/*==========
Args: input: input string with semicolons
Return: void
Function: the shell, ofr the most part. in charge of running command splitting and forking, and 'special' occurances like piping, cd, exit, redirect, etc
==========*/