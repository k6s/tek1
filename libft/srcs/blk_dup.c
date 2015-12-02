#include <libft.h>

t_blk			*blk_dup(t_blk *blk, size_t len)
{
	void		*data;

	if ((data = ft_memdup(blk->data, len)))
		return (blk_new(data, len));
	return (NULL);
}
