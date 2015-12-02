/*
** minitalk.h for minitalk in /home/k6/epitech/UNIX/minitalk
** 
** Made by Chloe Cano
** Login   <cano_c@epitech.net>
** 
** Started on  Fri Feb 20 15:04:46 2015
** Last update Mon Mar 16 12:28:25 2015 
*/
#ifndef MINITALK_H_
# define MINITALK_H_

# include <sys/types.h>
# include <signal.h>
# include <my.h>
# include <get_next_line.h>

# define BUFF_LEN	10
# define USAGE		"usage: ./client pid_server msg"
# define EPID		"minitalk: cannot get process pid. exiting..."
# define PID_BLEN	(sizeof(int) * 8)


/*
** void			set_sig_handler(void);
** void			sig_handle(int sig, siginfo_t *siginfo, void *context);
*/

/*
** SERVER
** =============================================================================
*/

extern int		g_pid;

void			sig_receive_msg(int sig);
void			sig_receive_pid(int sig);
void			new_client(void);

/*
** CLIENT
** =============================================================================
*/

extern char		*msg;

void			sig_exit(int pid);
void			send_pid(int pid, int serv_pid);
int			send_str(int pid, char *str);
void			kill_serv(int signo, int pid);

#endif /* !MINITALK_H_ */
