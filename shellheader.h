#ifndef SHELLHEADER_H
#define SHELLHEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <dirent.h>
#include <stdbool.h>


#define OUR_LINE_LENGTH 10000
#define OUR_ALIASES 100

/**
 * struct owner - name describing structure
 * @explainer: opens and closes a file
 * @show_flag: line input reader
 * @shinput: mimics read data
 * @argv: argument vector count values
 */

typedef struct owner
{
	int explainer;
	int show_flag;
	char *shinput;
	char **argv;
} ownership;

/**
 * struct curvedline - structure that mimics get line function
 * @explainer: opens and closes a file
 * @readerloc: input taken buffer
 * @indes: input that halted the buffer
 * @lens: line length of the function
 */

typedef struct curvedline
{
	int explainer;
	char readerloc[OUR_LINE_LENGTH];
	int indes;
	int lens;
} bline;

/**
 * struct infohandler - handles lines input
 * @path: the value of foremost argument
 * @arg: the totlal argumment
 * @show: counted line
 * @argc: the total argument count
 * @argv: argument vector count in the func
 * @pipefd: pipe file descriptor
 * @report: executes condition in the shell
 * @lrf_fd : left pipe reduction in shell
 * @shell: counts stuff in shell
 */

typedef struct infohandler
{
	char *path;
	char *arg;
	int argc;
	int show;
	char **argv;
	int pipefd[2];
	int report;
	int lrf_fd;
	char *shell;
} info_t;

/**
 * struct table - name of structure
 * @types: pointer to the types in struct
 * @func: pointer to the func in the struct
 */

typedef struct board
{
	char *type;
	int (*func)(info_t *);
} builtin_board;

/**
 * struct enter_alias - name of the structure
 * @alias: handles the alias in the shell
 * @force: force in the function
 */

typedef struct enter_alias
{
	char alias[256];
	char force[256];
} alias_enter;


ssize_t bufferfile_handler(char **lineptr, size_t *n, int explainer);
ssize_t shell_buffile(int explainer, char *buffer, ssize_t max_length);
ssize_t reader_shell(int explainer, char **buffer);
off_t flush_file(int explainer, off_t offset, int whence);
int mimic_flush(FILE *stream);

int stringlength(const char *str);
int stringcompare(char *str1, char *str2);
char *findcharacter(char *str, char *character);
char *appendstring(char *dest, const char *src);
char *copystring(char *dests, char *source);
char *stringduplicate(char *str);


void shell_printer(void);
void executeshell_f(info_t *info);
void ssfree(info_t *info, int exit_status);
void e_construct(info_t *info, const char *message);

char **allenv_shell(void);
int findbuiltin_shell(info_t *info);
int exitbuiltin_shell(info_t *info);
int custom_env(info_t *info);
int oldsetenv_shell(info_t *info);
int oldunsetenv_shell(info_t *info);
int shell_aliashandler(info_t *info);


int stringsplit(info_t *inform);
char **mimic_strtokd(char *str, char *d);
int shell_lim(char c, char *delim);
void shellexec(info_t *info);
char *shellpath(info_t *info, char *pathstr, char *cmd);
int loopshellmain(int explainer, int argc, char **argv, char *line,
		size_t line_length, ownership file, info_t info,
		int built_in_ret);

char *numconverter(long int num, int base, int flags);
void _printer(char *str);
int stringcompare_n(const char *str1, const char *str2, size_t n);
char *getshell_env(const char *variable);
void file_writer(char c, FILE *stream);
int shell_builtincd(info_t *info);


int commandsearch(info_t *info, char *path);
char *mul_strings(char *pathstr, int start, int stop);
extern char **environ;
void reset_structure(bline *reader, int descriptor);
ssize_t filereader(int explainer, bline *reader);
int fileplacereader(bline *reader, ssize_t *line_length, char **line);


void mimic_buffile(ownership file, char *line, size_t line_length);
void ini_builtin(info_t *info, int argc, char **argv, char *line);
void shell_freedom(info_t *info, char *line);
char *memfill_shell(char *s, char b, unsigned int n);
void controlC(__attribute__((unused))int thisway);


#endif
