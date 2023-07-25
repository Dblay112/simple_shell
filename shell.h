#ifndef _SHELL_H_
#define _SHELL_H_
#define _GNU_SOURCE



#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>


#define MAXIMUM_PATH_LENGTH 4096
#define SEPARATER_PATH ":"
#define PROMPT_SIGN "$ "
#define TOKENS_AT_MAX 1024
#define SIZE_OF_BUFFER 1024


void *simpleshell_getline(void);

int simpleshell_execute(char **args);


char **simpleshell_tokenize(char *str, const char *delim);
char **simpleshell_tokenize_input(char *inputs);


char *_getenv(const char *selorm);

void simpleshell_free_error(char **argv, char *arg);
void simpleshell_tokens(char **ptr);
void simpleshell_freepath(void);

void simpleshell_prompt(void);

char *simpleshell_getpath(void);


char *simpleshell_findpath(char *bright);


void _puts(char *string);
void _puterror(char *brr);


int _strlen(const char *);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strstr(char *haystack, char *pins);
char *_strchr(char *s, char c);

void handles_sigint(int sigs);
void handles_sigquit(int sigs);
void handles_sigstp(int sigs);

char *_strcpy(char *, char *);
char *_strcat(char *, const char *);
char *_strdup(const char *);
int _putchar(char);
unsigned int _strspn(char *s, char *substring);

int simpleshell_builtin(char **args);
int execute_builtin(char *cmd, char **args);
void simpleshell_help(void);
void simpleshell_exit(char **args);
void simpleshell_cd(char **args);
int simpleshell_setenv(char **args);
int simpleshell_unsetenv(char **args);
int simpleshell_env(void);
int simpleshell_clear(char **args);

int _atoi(const char *string);
char *_memset(char *, char, unsigned int);
char *_memcpy(char *dest, char *src, unsigned int b);
void *_realloc(void *, unsigned int, unsigned int);
void *_calloc(unsigned int member, unsigned int size);

char *simpleshell_input(void);
void simpleshell_last_input(void);

#endif
