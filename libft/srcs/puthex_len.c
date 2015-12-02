#include <libft.h>

ssize_t			puthex_len(int64_t nbr, ssize_t len)
{
	char		c;
	const char	base[17] = "0123456789abcdef";

	if (len)
		puthex_len(nbr / 16, len - 1);
	c =  base[nbr % 16];
	write(1, &c, 1);
	return (len);
}
