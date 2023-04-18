#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <limits.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

char *show_input(void);
int compareEnv(char *s1, char *s2);
void prompt(void);
void execute_proc(char **cmd);
char *_strcat(char *src);
int _strlen(char *str);
char **identify_string(char *parameter);
void place(char *str);
void controlC(int sig);
char *findfile(char *command);
char *find_command(char *command);
int compare(char *s1, char *s2);
int _strcmpdir(char *s1, char *s2);
int charput(char c);
void place(char *str);
char *str_concat(char *s1, char *s2);
int lookforslash(char *cmd);
int compareExit(char *s1, char *s2);
#endif
