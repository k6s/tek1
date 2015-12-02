#include <libft.h>

t_blk				*blk_tok(t_blk *blk, char tok)
{
	char			*p_data;
	t_blk			*ret;
	static t_blk	ref = {NULL, 0};

	if (!(ret = NULL) && blk)
	{
		ref.data = blk->data;
		ref.len = blk->len;
	}
	if ((p_data = ref.data) && (ref.len > 0))
	{
		while (((unsigned)((void *)p_data - ref.data) < ref.len)
			   && (*p_data != tok))
			++p_data;
		if ((((unsigned)((void *)p_data - ref.data)) < ref.len)
			&& (ret = blk_dup(&ref, (void *)p_data - ref.data + 1)))
		{
			ref.len -= (void *)p_data - ref.data;
			if (ref.len)
				--ref.len;
			ref.data += (void *)p_data - ref.data + 1;
		}
	}
	return (ret);
}
