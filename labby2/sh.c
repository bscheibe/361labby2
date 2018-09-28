#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "sh.h"

int sh( int argc, char **argv, char **envp ) {

  char *prompt = calloc(PROMPTMAX, sizeof(char));
  char *commandline = calloc(MAX_CANON, sizeof(char));
  char *command, *arg, *commandpath, *p, *pwd, *owd;
  char **args = calloc(MAXARGS, sizeof(char*));
  int uid, i, status, argsct, go = 1;
  struct passwd *password_entry;
  char *homedir;
  struct pathelement *pathlist;

  uid = getuid();
  password_entry = getpwuid(uid);               /* get passwd info */
  homedir = password_entry->pw_dir;		/* Home directory to start
						  out with*/

  if ((pwd = getcwd(NULL, PATH_MAX+1)) == NULL ) {
    perror("getcwd");
    exit(2);
  }

  owd = calloc(strlen(pwd) + 1, sizeof(char));
  memcpy(owd, pwd, strlen(pwd));
  prompt[0] = ' '; prompt[1] = '\0';

  /* Put PATH into a linked list */
  pathlist = get_path();

  while (go) {
    /* print your prompt */
	printf(" [%s]> ", pwd);

    /* get command line and process */
	if (fgets(commandline, PROMPTMAX, stdin) == NULL) {
		printf("\n");
		continue;
	}
	arg = strtok(commandline, " ");
	i = 0;
	while (arg != NULL) {
		args[i] = (char*)calloc(strlen(arg) + 1, sizeof(char));
		strncpy(args[i], arg, strlen(arg));
		arg = strtok(NULL, " ");
		i++;
	}
	printf(args[0]);
    /* check for each built in command and implement */
	if (!strcmp(args[0], "exit\n")) {
		return 0;
	}
	if (!strcmp(args[0], "which\n")) {
		//
	}
	else if (!strcmp(args[0], "where\n")) {
		//
	}
	else if (!strcmp(args[0], "cd\n")) {
		//
	}
	else if (!strcmp(args[0], "pwd\n")) {
		//
	}
	else if (!strcmp(args[0], "list\n")) {
		//
	}
	else if (!strcmp(args[0], "pid\n")) {
		//
	}
	else if (!strcmp(args[0], "kill\n")) {
		//
	}
	else if (!strcmp(args[0], "prompt\n")) {
		//
	}
	else if (!strcmp(args[0], "printev\n")) {
		//
	}
	else if (!strcmp(args[0], "alias\n")) {
		//
	}
	else if (!strcmp(args[0], "history\n")) {
		//
	}
	else if (!strcmp(args[0], "setenv\n")) {
		//
	}

     /*  else  program to exec */
//	}
       /* find it */
       /* do fork(), execve() and waitpid() */
//
//    else
//    fprintf(stderr, "%s: Command not found.\n", args[0]);
// }
//	printf("\n");
  }
  return 0;
} /* sh() */

char *which(char *command, struct pathelement *pathlist ) {
   /* loop through pathlist until finding command and return it.  Return
   NULL when not found. */

} /* which() */

char *where(char *command, struct pathelement *pathlist ) {
  /* similarly loop through finding all locations of command */
} /* where() */

void list ( char *dir ) {
  /* see man page for opendir() and readdir() and print out filenames for
  the directory passed */
} /* list() */
