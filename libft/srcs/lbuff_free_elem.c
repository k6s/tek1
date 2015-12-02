#include <libft.h>

void            lbuff_free_elem(t_lbuff **lbuff)
{
    free((*l_buff)->DATA);
    free(*l_buff);
    *l_buff = NULL;
}
