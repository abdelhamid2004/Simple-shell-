#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;
char *habiba_read(void);
char **abdelhamid_tokin(char *order, int *n);
int _execv(char **order_words,int n, char **argv, int ix);
char *string_cpy(char *dest, char *src);
char *string_cat(char *destination, char *source);
int string_len(char *s);
int string_cmp(char *s, char *s1);
char *pathhandle(char *command);
void free_the_array(char **array);
char *get_environment(char *var);
char *get_path(char *order);
void _printerror(char *nm, char *cmd, int ix);
void _printerror(char *nm, char *cmd, int ix);
void string_reverse(char *st, int length);
char *_intger_to_assci(int num);
int bulit_in(char *s, char **env);
void print_environment(char **env);
#endif
