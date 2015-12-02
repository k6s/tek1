#include <libft.h>

char           *lbuff_memchr(t_lbuff *lbuff, char del, size_t *tlen)
{
    char        *end_str;
	t_lbuff		**lbuff_ptr;

    *tlen = 0;
	lbuff_ptr = lbuff;
    while ((*lbuff_ptr) && !(end_str = ft_memchr((*lbuff_ptr)->DATA, del,
		(*lbuff_ptr)->LEN)))
    {
        *tlen += (*lbuff_ptr)->LEN;
        (*lbuff_ptr) = (*lbuff_ptr)->next;
    }
    if (*lbuff_ptr)
        *tlen += end_str - (char *)(*lbuff_ptr)->DATA;
    return (end_str);
}
