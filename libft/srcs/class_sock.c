#include <k6_sock.h>

t_class_sock				*init_class_sock(void)
{
	t_class_sock			*class_sock;

	if ((class_sock = malloc(sizeof(*class_sock))))
	{
		class_sock->file = get_class_file();
		class_sock->new = new_sock;
		class_sock->set = set_sock;
		class_sock->load = load_sock;
	}
	return (class_sock);
}

static t_class_sock			*static_class_sock(void)
{
	static t_class_sock		*class_sock = NULL;

	if (!class_sock)
		class_sock = init_class_sock();
	return (class_sock);
}

t_class_sock				*get_class_sock(void)
{
	return (static_class_sock());
}

void						set_sock(t_sock *sock)
{
	t_class_sock			*class_sock;

	class_sock = get_class_sock();
	if (class_sock && class_sock->file)
	{
		class_sock->self = sock;
		class_sock->file->self = sock->file;
	}
}

char						load_sock(void)
{
	t_class_sock			*class_sock;
	t_sock					*sock;

	class_sock = get_class_sock();
	sock = class_sock->self;
	sock->file->fd = socket(sock->flags[SOCK_TYPE], sock->flags[SOCK_DOMAIN],
							sock->flags[SOCK_PROTO]);
	return (sock->file->fd);
}

t_sock						*new_sock(t_file *file, int fd, int flags[3])
{
	t_sock					*sock;
	t_class_sock			*class_sock;

	sock = NULL;
	class_sock = static_class_sock();
	if (class_sock && (sock = malloc(sizeof(*sock))))
	{
		if (file)
			sock->file = file;
		if (!(sock->file = class_sock->file->new(fd, NULL)))
			return (NULL);
		else
			sock->file->fd = -1;
		if (fd > -1)
			sock->file->fd = fd;
		sock->flags[0] = flags[0];
		sock->flags[1] = flags[1];
		sock->flags[2] = flags[2];
	}
	return (sock);
}
