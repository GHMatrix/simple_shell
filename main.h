#ifndef MAIN_H
#define MAIN_H

#include <stdio.h> /* for printf*/
#include <unistd.h> /* for fork, execve*/
#include <stdlib.h>
#include <string.h> /* for strtok*/
#include <stddef.h>
#include <errno.h> /* for errno and perror */
#include <sys/types.h> /* for type pid */
#include <sys/wait.h> /* for wait */
#include <sys/stat.h> /* for use of stat function */
#include <signal.h> /* for signal management */
#include <fcntl.h> /* for open files*/

/************* MACROS **************/

#include "macros.h" /* for msg help and prompt */

/************* STRUCTURES **************/

/**
 * struct info- struct for the program's data
 * @prog_name: the name of the executable
 * @ip_line: pointer to the input read for _getline
 * @cmd_name: pointer to the first command typed by the user
 * @cmd_counter: number of excecuted comands
 * @file_desc: file descriptor to the input of commands
 * @tokens: pointer to array of tokenized input
 * @env: copy of the environ
 * @aliases: array of pointers with aliases.
 */
typedef struct info
{
	char *prog_name;
	char *ip_line;
	char *cmd_name;
	int cmd_counter;
	int file_desc;
	char **tokens;
	char **env;
	char **aliases;
} prog_data;

/**
 * struct builtins - struct for the builtins
 * @builtin: the name of the builtin
 * @function: the associated function to be called for each builtin
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(prog_data *data);
} builtins;


/* FUNCTIONS */

void initialize_data(prog_data *data, int arc, char *argv[], char **env);

void sysinfo(char *prompt, prog_data *data);

void handle_ctrl_c(int opr UNUSED);

/* getline.c */

int _getline(prog_data *data);

int check_logic_ops(char *array_commands[], int i, char array_operators[]);

/* expand.c */

void expand_variables(prog_data *data);

void expand_alias(prog_data *data);

int buffer_add(char *buffer, char *str_to_add);


/* str_tok.c  */

void tokenize(prog_data *data);

char *_strtok(char *line, char *delim);


/* execute.c  */

int execute(prog_data *data);


/* builtins_list.c  */

int builtins_list(prog_data *data);


/* find_in_path.c  */

char **tokenize_path(prog_data *data);

int find_program(prog_data *data);


/* helpers_free.c  */

void free_array_of_pointers(char **directories);

void free_recurrent_data(prog_data *data);

void free_all_data(prog_data *data);


/* builtins_extra.c  */

int builtin_exit(prog_data *data);

int builtin_cd(prog_data *data);

int set_work_directory(prog_data *data, char *new_dir);

int builtin_help(prog_data *data);

int builtin_alias(prog_data *data);


/* builtins_env.c  */

int builtin_env(prog_data *data);

int builtin_set_env(prog_data *data);

int builtin_unset_env(prog_data *data);


/* env_mgt.c  */

char *env_get_key(char *name, prog_data *data);

int env_set_key(char *key, char *value, prog_data *data);

int env_remove_key(char *key, prog_data *data);

void print_environ(prog_data *data);


/* helpers_print.c  */

int _print(char *string);

int _printe(char *string);

int _print_error(int errorcode, prog_data *data);


/* helpers_string.c  */

int str_length(char *string);

char *str_duplicate(char *string);

int str_compare(char *string1, char *string2, int number);

char *str_concat(char *string1, char *string2);

void str_reverse(char *string);


/* helpers_numbers.c  */

void long_to_string(long number, char *string, int base);

int _atoi(char *s);

int count_characters(char *string, char *character);


/* alias_mgt.c  */

int output_alias(prog_data *data, char *alias);

char *get_alias(prog_data *data, char *alias);

int set_alias(char *alias_string, prog_data *data);


#endif

