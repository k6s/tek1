#include <k6_sock.h>

int						main(int argc, char **argv)
{
	t_class_sock		*class_sock;
	t_sock				*sock;
	int					sock_flags[3] = {AF_INET, SOCK_STREAM, 0};

	printf("class_sock size %d\n", sizeof(*class_sock));
	class_sock = get_class_sock();
	if (class_sock)
	{
		sock = class_sock->new(NULL, -1, sock_flags);
		class_sock->set(sock);
		if (class_sock->load() > -1)
		{
			printf("Open socket [%d]\n", sock->file->fd);
			close(sock->file->fd);
		}
		else
			printf("invalid sockfd");
	}
	else
		printf("class_sock NULL");
	return (0);
}
