/*
** minishell1.h for minishell1 in /home/cano_c/rendu/ELEM/CPE_2014_bsq
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Tue Jan 13 14:04:15 2015
** Last update Sun Feb  1 22:49:45 2015 
*/

#ifndef MINISHELL1_H_
# define MINISHELL1_H_

# ifndef _POSIX_SOURCE
#  define _POSIX_SOURCE
# endif

# include <my.h>
# include <termcap.h>
# include <termios.h>
# include <fcntl.h>
# include <sys/types.h>
# include <linux/limits.h>
# include <dirent.h>
# include <sys/stat.h>
# include <get_next_line.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_prog		t_prog;
typedef struct s_progs		t_progs;
typedef struct s_term		t_term;
typedef struct s_buff		t_buff;
typedef struct s_line		t_line;
typedef struct s_hist		t_hist;

/*
** BUILTINS
*/

# define ROOT_DIR		"PWD=/"

typedef int	(*t_builtfp)(t_term *, char **);

char		add_builtins(t_progs *s_progs);

int		my_exit(t_term *s_term, char **av);
int		my_unsetenv(t_term *term, char **av);
int		my_setenvi(t_term *term, char **av);
int		my_env(t_term *term, char **av);
int		my_cd(t_term *term, char **av);

/*
** PROGS INDEX
*/

struct			s_prog
{
  char			name[NAME_MAX];
  size_t		namlen;
  char			path[PATH_MAX];
  t_builtfp		builtfp;
};


struct			s_progs
{
  char			exist;
  t_prog		*prog;
  t_progs		*next[256];
};

t_prog		*find_prog(t_progs *progs, char *progname);
char		add_prog(char *filename, char *path, t_progs *s_progs);
t_progs		*get_path_progs(char *path);

/*
** GENERAL TERM STRUCT
*/

struct			s_term
{
  char			**environ;
  t_progs		*progs;
  struct termios	*tsave;
  char			end;
  pid_t			pid;
t_line		*line;
};

/*
** ENVIRONMENT
*/

char		get_environ(t_term *s_term, char **environ);
char		**add_env_var(char **environ, char *new);
int		ow_env_var(char **environ, char *var_name, char *new);
char		*get_envvar_name(char *s);
void		del_envvar(char **environ, char *target);
char		**my_setenv(char **env, char *var, char ow);

/*
** UTILS
*/

pid_t		my_getpid(void);


/*
** SIGNALS
*/

t_term		*static_term(t_term *term);
void		init_signals(void);

/*
** TERMCAPS
*/

int		tput_putc(int i);
struct termios	*init_termcap(char **environ);
void		restore_termcap(struct termios *tsave);

/*
** CLEANING
*/

void		free_strtab(char **strtab);
void		free_progs(t_progs *progs);
void		free_stuff(t_term *s_term);


/*
** READ CMDLINE
*/
int		shell_readloop(t_term *s_term);
void		clear_line(t_buff *line);
void		clear_hist(t_hist *hist);

/*
** CMDLINE EDITION
*/

# define BUFF_SIZE	1

struct			s_buff
{
  char			buff[BUFF_SIZE];
  size_t		len;
  t_buff		*next;
  t_buff		*prev;
};

# define PROMPT_MAX	PATH_MAX + 30

struct			s_line
{
  char			prompt[PROMPT_MAX];
  t_buff		*line;
  char			*s;
  t_hist		*hist;
  t_hist		*c_hist;
};

struct			s_hist
{
  t_buff		*buff;
  t_hist		*next;
  t_hist		*prev;
};

# define K_NB		5
# define K_UP		65
# define K_DO		66
# define K_RI		67
# define K_LE		68
# define K_DEL		127

int		special_key(t_buff **s_buff, t_line *s_line, char *key,
			    t_term *s_term);

/*
** EXECUTE CMDLINE
*/

char		exe_cmd(t_prog *prog, char **av, char **environ);
char		exe_builtin(t_prog *prog, char **av, t_term *s_term);

#endif /* !MINISHELL1_H_ */
