#include <libft.h>

t_lbuff         *lbuff_new_elem(t_blk *data)
{
    t_lbuff     *new;

    if ((new = malloc(sizeof(*new))))
    {
		new->blk = data;
		new->next = NULL;
	}
    return (new);
}
