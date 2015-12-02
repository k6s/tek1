/*
** get_long.c for my_ls in /home/cano_c/rendu/UNIX/PSU_2014_my_ls
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Sat Nov 29 21:15:42 2014
** Last update Sun Nov 30 17:20:26 2014 Cano Chloe
*/

#include <my_ls.h>

/*
** If getpwuid/getgrgid returns NULL, then the
** uid/gid is displayed instead of group/owner name.
*/

static void		get_logins(t_blk *blk)
{
  struct passwd		*pwd;
  struct group		*grp;

  if ((pwd = getpwuid(ENTRY(blk)->stat.st_uid)))
    {
      my_strncpy(ENTRY(blk)->pwd, pwd->pw_name, LOGIN_NAME_MAX);
      ENTRY(blk)->len[1] = my_strlen(ENTRY(blk)->pwd);
    }
  else
    {
      ENTRY(blk)->pwd[0] = 0;
      ENTRY(blk)->len[1] = get_nbr_len(ENTRY(blk)->stat.st_uid);
    }
  if ((grp = getgrgid(ENTRY(blk)->stat.st_gid)))
    {
      my_strncpy(ENTRY(blk)->grp, grp->gr_name, LOGIN_NAME_MAX);
      ENTRY(blk)->len[2] = my_strlen(ENTRY(blk)->grp);
    }
  else
    {
      ENTRY(blk)->len[2] = get_nbr_len(ENTRY(blk)->stat.st_gid);
      ENTRY(blk)->grp[0] = 0;
    }
}

/*
** If the file is a character or block device, it's minor and major numbers
** replace the usual size.
*/

void			get_long(t_blk *blk)
{
  get_logins(blk);
  ENTRY(blk)->len[0] = get_nbr_len(ENTRY(blk)->stat.st_nlink);
  if (S_ISCHR(ENTRY(blk)->stat.st_mode) || S_ISBLK(ENTRY(blk)->stat.st_mode))
    {
      ENTRY(blk)->len[3] = get_nbr_len(MAJOR(ENTRY(blk)->stat.st_rdev));
      ENTRY(blk)->len[4] = get_nbr_len(MINOR(ENTRY(blk)->stat.st_rdev));
    }
  else
      ENTRY(blk)->len[3] = get_nbr_len(ENTRY(blk)->stat.st_size);
  ENTRY(blk)->len[5] = ENTRY(blk)->stat.st_blocks;
}
