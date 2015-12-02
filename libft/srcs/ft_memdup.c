#include <libft.h>

void			*ft_memdup(void *data, size_t len)
{
	void		*ret;
	size_t		idx;

	if ((ret = malloc(len)))
	{
		idx = -1;
		while (++idx < len)
			*(unsigned char *)(ret + idx) = *(unsigned char *)(data + idx);
	}
	return (ret);
}
