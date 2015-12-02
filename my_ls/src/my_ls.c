/*
** my_ls.c for my_ls in /home/cano_c/rendu/UNIX/PSU_2014_my_ls
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Mon Nov 24 14:24:45 2014
** Last update Sun Nov 30 18:32:28 2014 Cano Chloe
*/

#include <my_ls.h>

int		usage(char op)
{
  if (op)
    {
      my_putstr("Invalid option -");
      my_putchar(op);
      my_putchar('\n');
    }
  my_putstr("usage: ./my_ls [-lRrdta] [FILE]\n");
  return (0);
}

int		get_op_flag(char op)
{
  if (op == 'r')
    return (O_REV);
  if (op == 'R')
    return (O_REC);
  if (op == 't')
    return (O_TIM);
  if (op == 'l')
    return (O_LNG);
  if (op == 'd')
    return (O_DIR);
  if (op == 'a')
    return (O_ALL);
  if (op == 'R')
    return (O_REC);
  return (-1);
}

int		call_print_funcs(int opt, int nb_files, t_lst *s_lst)
{
  t_blk		*blk;
  t_lst		*tmp;

  if (opt & O_REC)
    return (ls_rec(s_lst, opt, &nb_files));
  while (s_lst)
    {
      blk = &s_lst->blk;
      ls_dir(blk, opt, nb_files);
      tmp = s_lst;
      if (s_lst)
	s_lst = s_lst->next;
      free(tmp);
    }
  return (0);
}

int		my_ls(int opt, int argc, char **argv, int opt_idx)
{
  t_lst		*s_lst;
  int		nb_files;
  int		len[6];

  s_lst = NULL;
  opt_idx = opt_idx < 0 ? argc : opt_idx;
  if ((nb_files = get_args_entries(opt_idx, opt, &s_lst, argv)) == -1)
    exit(2);
  my_bzero(len, 6 * sizeof(len[0]));
  if (opt & O_LNG)
    get_files_padding(s_lst, len);
  ls_files(&s_lst, opt, opt & O_DIR, len);
  if (!(opt & O_DIR))
    call_print_funcs(opt, nb_files, s_lst);
  return (0);
}

int		main(int argc, char **argv)
{
  int		opt;
  int		ret;
  int		op_idx;
  const char	*current = ".";

  op_idx = -1;
  opt = 0;
  while ((ret = my_getopt(argv, "lRrtda", &op_idx)) != -1)
    {
      if (ret == -2)
	exit(usage(argv[op_idx][1]));
      opt += get_op_flag(ret);
    }
  if (argc < 2 || op_idx == 1)
    {
      argv[1] = (char *)current;
      argc = 2;
      op_idx = -1;
    }
  exit(my_ls(opt, argc, argv, op_idx));
}
