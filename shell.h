#ifndef SHELL_H
#define SHELL_H

#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

extern char **environ;

void executeByPath(char *);
char *getCommand(void);

#endif /* SHELL_H */
