#ifndef MYCLI_H /* my command-line interface */
# define MYCLI_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>
#include <sys/stat.h>

void prompt(const char**); /* creating prompt and given to readline */
void exuc(char*);

# endif