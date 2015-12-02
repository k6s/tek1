#include <libft.h>

t_lbuff			*lbuff_extract_blk(t_lbuff **lbuff)
{
	t_blk		*blk;

	blk = (*l_buff)->blk;
	free(*lbuff);
	return (blk);
}
