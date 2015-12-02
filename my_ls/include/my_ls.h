/*
** my_ls.h for my_ls in /home/cano_c/rendu/UNIX/PSU_2014_my_ls
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Nov 24 14:50:05 2014
** Last update Sun Nov 30 17:45:15 2014 Cano Chloe
*/

#ifndef MY_LS_H_
# define MY_LS_H_

# define _POSIX_C_SOURCE	200112L

# include <my.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <dirent.h>
# include <unistd.h>
# include <linux/kdev_t.h>

# define LONG_ETYPE	(__POSIX_VERSION > 199506L ? 1 : 0)

# define O_REV	1
# define O_REC	2
# define O_TIM	4
# define O_LNG	8
# define O_DIR	16
# define O_ALL	32
# define O_ARG	64

typedef struct s_ls_entry	t_ls_entry;

# define ENTRY(blk)	((t_ls_entry *)(blk->data))

struct		s_ls_entry
{
  char		path[PATH_MAX];
  char		lnk[PATH_MAX];
  struct stat	stat;
  char		pwd[LOGIN_NAME_MAX];
  char		grp[LOGIN_NAME_MAX];
  char		*error;
  int		len[6];
};

/*
** get_entry.c
*/
t_blk		*get_entry(char *path, int opt, int *padding);
void		get_padding(t_blk *blk, int *len);
int		get_args_entries(int opt_idx, int op, t_lst **lst, char **argv);

/*
** get_dir_entries.c
*/
t_lst		*get_dir_entries(t_blk *blk, t_lst **s_lst, int opt, int *len);

/*
** print_long.c
*/
void		print_long(t_blk *s_blk, int *len);

/*
** print_mode.c
*/
void		print_perms(mode_t *st_mode);
void		print_type(mode_t *st_mode);

/*
** get_long.c
*/
void		get_long(t_blk *s_blk);

/*
** print_reg.c
*/
void		print_error(char *msg, char *err_msg);
void		print_entry(t_blk *blk, int opt, int *len);

size_t		get_filename_idx(char *path);
void		print_lnk(t_blk *blk);

int		entry_time_cmp(t_blk *e1, t_blk *e2, size_t len);
int		entry_cmp(t_blk *e1, t_blk *e2, size_t len);

int		ls_rec(t_lst *p_lst, int opt, int *nb_files);

/*
** file_utils.c
*/
size_t		get_filename_idx(char *path);
void		print_dir_name(t_blk *blk, int *nb_file);
void		print_lnk(t_blk *blk);

/*
** ls_files_dir.c
*/
void		ls_dir(t_blk *blk, int opt, int nb_files);
int		ls_files(t_lst **lst, int opt, char print_dir, int *len);
void		print_files(t_lst **s_lst, t_lst **p_lst, int opt, int *len);

/*
** padding.c
*/
void		get_padding(t_blk *blk, int *len);
void		get_files_padding(t_lst *lst, int *len);

#endif /* !MY_LS_H_ */
