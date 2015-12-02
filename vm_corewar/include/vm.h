/*
** vm.h for corewar in /home/cano_c/rendu/ELEM/corewar
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Wed Mar 18 17:15:34 2015
** Last update Fri Apr 10 14:58:03 2015 
*/
#ifndef VM_H_
# define VM_H_

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <curses.h>
# include <op.h>
# include <my.h>

# define BUFF_LEN	10

typedef struct s_vm		t_vm;
typedef struct s_lst		t_lst;
typedef struct s_player		t_player;
typedef struct s_proc		t_proc;

/*
** Les differentes "parties" (sections) d'un executable .cor,
** TEXT_OFF correspond au debut du code du programme
** (section .TEXT)
*/
# define NAME_OFF	sizeof(int)
# define COMMENT_OFF	NAME_OFF + PROG_NAME_LENGTH
# define TEXT_OFF	sizeof(header_t)

# define MAX_OP		0x10

/*
** PLAYERS
** =============================================================================
*/

struct		s_player
{
  int32_t      	p_id;
  off_t		ld_addr;
  char		name[PROG_NAME_LENGTH + 1];
  void		*file;
  size_t	file_len;
  char		alive;
  t_player	*next;
};

ssize_t		get_players(char **argv, t_player **players, off_t *ld_addr,
			    int32_t *p_id);
void		*get_file_content(int fd, size_t *len);

struct		s_lst
{
  void		*data;
  size_t	len;
  t_lst		*prev;
  t_lst		*next;
};

t_lst		*new_lst(size_t data_len);
void		lst_append(t_lst **lst, t_lst *new);

/*
** PROCESSUS
** =============================================================================
*/

/*
** Liste chainee des processus en court a passer a l'ordonnanceur
** (scheduling en anglais dans le sujet).
** Elle contient pour chaque maillon le numero du processus, ses registres, son
** PC, l'offset de fin du code du programme, le carry, le nombre de cycles que
** l'instruction en court doit encore realiser.
*/

struct		s_proc
{
  int		id;
  char      	regs[REG_NUMBER][REG_SIZE];
  off_t		pc;
  off_t		s_pc;
  off_t		entry;
  off_t		end;
  char		carry;
  size_t	cycles;
  size_t	turn;
  char		alive;
  t_proc	*next;
};

t_proc		*new_proc(t_player *s_player, off_t entry, off_t end, int id);
void		proc_append(t_proc **s_proc, t_proc *new, size_t turn);
t_player	*start_game(t_vm *vm);

t_proc		*op_func(op_t *op, t_proc *p, char *arena);

/*
** COREWAR INSTRUCTIONS
** =============================================================================
*/

/*
** Prend l'octet de codage des parametres et le numero de l'argument (commencant
** a 0) et retourne le type de l'argument (1 -> registre, 2 -> direct,
** 3 -> indirect, > 3  ou < 1 -> erreur)
*/

# define ARG_TYPE(ocp, idx)	(((ocp) >> (6 - (idx) * 2)) & 3)

# define AG_REG		1
# define AG_DIR		2
# define AG_IND		3

typedef t_proc		*(*t_ft_inst)(t_vm *, t_proc *, t_lst **lst);
typedef unsigned char	t_uchar;

struct		s_vm
{
  WINDOW	**wins;
  ssize_t      	max_live_cycles;
  ssize_t       max_cycles;
  int		nbr_live;
  t_player	*s_players;
  t_player	*winner;
  int		nb_procs;
  t_proc	*procs;
  char		*arena;
  size_t	turn;
  t_uchar	alive;
};

/*
** Index des instructions dansl'op_tab
*/

typedef enum e_inst
  {
    E_LIVE = 0,
    E_LD,
    E_ST,
    E_ADD,
    E_SUB,
    E_AND,
    E_OR,
    E_XOR,
    E_ZJMP,
    E_LDI,
    E_STI,
    E_FRK,
    E_LLD,
    E_LLDI,
    E_LFORK,
    E_AFF
  } t_inst;

/*
** Retourne la structure s_proc passe en parametre et initialise son champ cycle
** en accord avec le nombre de cycle specifie dans op_tab. Si l'opcode est
** invalide ou le champion a termine son execution, retourne NULL.
*/
t_proc			*next_inst(char *arena, t_proc *s_proc);

t_proc			*inst_live(t_vm *vm, t_proc *proc, t_lst **lst);
t_proc			*inst_ld(t_vm *vm, t_proc *proc, t_lst **lst);
t_proc			*inst_st(t_vm *vm, t_proc *s_proc, t_lst **lst);
t_proc			*inst_add(t_vm *vm, t_proc *proc, t_lst **lst);
t_proc			*inst_sub(t_vm *vm, t_proc *proc, t_lst **lst);
t_proc			*inst_and(t_vm *vm, t_proc *proc, t_lst **lst);
t_proc			*inst_or(t_vm *vm, t_proc *s_proc, t_lst **lst);
t_proc			*inst_xor(t_vm *vm, t_proc *s_proc, t_lst **lst);
t_proc			*inst_sti(t_vm *vm, t_proc *proc, t_lst **lst);
t_proc			*inst_zjmp(t_vm *vm, t_proc *proc, t_lst **lst);

/*
** ARGUMENTS
** =============================================================================
*/

typedef int32_t		t_reg;
typedef int16_t		t_ind;
typedef int32_t		t_dir;

/*
** Retourne l'adresse de l'argument, considerant qu'il s'agit d'un
** registre / index / valeur directe et avance le PC de jusqu'a l'argument
** suivant.
*/
void			*reg_addr(t_vm *vm, t_lst **vars, t_proc *s_proc);
void			*ind_addr(t_vm *vm, t_lst **vars, t_proc *s_proc);
void			*ind_addr_i(t_vm *vm, t_lst **vars, t_proc *s_proc);
void			*dir_addr(t_vm *vm, t_lst **vars, t_proc *s_proc);

/*
** Retourne l'addresse de l'argument et avance le PC jusqu'a l'argument suivant.
** Si l'argument est un index, retourne l'addresse pointe par l'index
** (arena + (PC + arg % IDX_MOD) % MEM_SIZE)
*/
void			*get_arg_addr(args_type_t arg_type, args_type_t types,
				      t_proc *s_proc, t_vm *vm, t_lst **vars);
/*
** retourne l'addresse de l'argument. Si c'est un index, retourne l'addresse de
** l'index. (arena + PC % MEM_SIZE);
*/
void			*get_arg_addr_i(args_type_t arg_type, args_type_t types,
					t_proc *s_proc, t_vm *vm, t_lst **vars);

/*
** Si les arguments sont correct retourne 1, sinon avance le pc jusqu'a la
** prochaine instruction et retourne 0.
*/
int			check_args(op_t *op_desc, t_proc *s_proc, char op);

/*
** Retourne la valeur de val en inversant l'endian.
** es_reg_value n'existe pas car es_dir_value s'applique aussi aux registres.
*/

t_dir			es_dir_value(const t_dir *val);
t_ind			es_ind_value(const t_ind *val);

/*
** Avance le pc d'un argument.
*/
void			skip_arg(args_type_t arg_type, t_proc *s_proc);

/*
** CURSES WINDOW
** =============================================================================
*/

# define NB_WINS	2
# define WIN_MAIN	0
# define WIN_ARENA	1

WINDOW			**curses_init(void);
void			dump_line(unsigned char *arena, size_t idx, WINDOW *win);
void			update_win(WINDOW *win, unsigned char *arena,
				   unsigned char *dst, size_t len);
t_lst			*dump_clvar(WINDOW *win, char *arena, char *var,
				    size_t len);
void			restore_lvar(WINDOW *win, char *arena, char *var,
				     size_t len);

#endif /* !VM_H_ */
