#ifndef _SHELL_H_
#define _SHELL_H_

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

/* for read/write buffers */
#define rbuffer_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define NORM 0
#define OR 1
#define AND 2
#define CHAIN 3

/* for convert_number() */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;	  /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
} info_t;

#define INFO_INIT                                                         \
	{                                                                     \
		NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, 0, 0, NULL, \
			0, 0                                                          \
	}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

int msl(info_t *, char **);
int builtin(info_t *);
void fi_path(info_t *);
void fanetrcmd(info_t *);

int check_f(info_t *, char *);
char *du_chars(char *, int, int);
char *fi_path(info_t *, char *, char *);

int loopmsl(char **);

void _pais(char *);
int _wctstderr(char);
int _wctgfd(char c, int fd);
int _paisfd(char *str, int fd);

int _lens(char *);
int _plcots(char *, char *);
char *swith(const char *, const char *);
char *_cts(char *, char *);

char *_cas(char *, char *);
char *_strc(char *, char *, int);
char *_strt(char *, char *, int);
char *_lacis(char *, char);
char *_das(const char *);
void _pis(char *);
int _wct_stdout(char);

char **_strw(char *, char *);

void freesl(char **);

int _free_pan(void **);

int get_interactive(info_t *);
int check_delim(char, char *);

int _casti(char *);
void err(info_t *, char *);
int decim(int, int);
char *_cnts(long int num, int base, int flags);

int ex_shell(info_t *);
int _chdir(info_t *);
int _m_alias(info_t *);

ssize_t bufferin(info_t *info, char **buf, size_t *len);
ssize_t getin(info_t *);
void shand(int);

void clear(info_t *);
void sinfo(info_t *, char **);
void freein(info_t *, int);

char *_get_voev(info_t *, const char *);
int _pce(info_t *);
int _ianev(info_t *);
int _raev(info_t *info);
int _unsetenv(info_t *, char *);
int _ianevo(info_t *, char *, char *);
int env_list(info_t *);

char **get_sace(info_t *);

size_t print_list_str(const list_t *);
void freelis(list_t **);

size_t len_lis(const list_t *);
char **return_arrs(list_t *);
size_t print_list(const list_t *);
ssize_t get_node_index(list_t *, list_t *);
int delete_node_at_index(list_t **, unsigned int);
list_t *add_node_end(list_t **, const char *, int);
list_t *node_swith(list_t *, char *, char);
char *_fillwc(char *, char, unsigned int);

int test_chain_delim(info_t *, char *, size_t *);
void ch_next(info_t *, char *, size_t *, size_t, size_t);
int r_alias(info_t *);
int pr_alias(list_t *);
int r_var(info_t *);
void comment_handle(char *);
int rstring(char **, char *);

void *_reabom(void *, unsigned int, unsigned int);
int _getnloi(info_t *, char **, size_t *);
ssize_t rbuffer(info_t *info, char *buf, size_t *i);

int env_lilis(info_t *);

#endif
