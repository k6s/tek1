#ifndef K6_SOCK_H
# define K6_SOCK_H

# include <k6_file.h>
# include <sys/socket.h>
# include <sys/types.h>

typedef struct s_class_sock				t_class_sock;
typedef struct s_sock					t_sock;

struct			s_class_sock
{
	t_class_file	*file;
	t_sock		*self;
	t_sock		*(*new)();
	void		(*set)();
	char		(*load)();
};

t_class_sock	*get_class_sock();

t_sock			*new_sock(t_file *file, int fd, int flags[3]);
void			set_sock(t_sock *sock);
char			load_sock(void);

struct			s_sock
{
	t_file		*file;
# define SOCK_TYPE			0
# define SOCK_DOMAIN		1
# define SOCK_PROTO			2
	int			flags[3];
};

#endif
