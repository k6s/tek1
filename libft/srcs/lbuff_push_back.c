#include <libft.h>

t_lbuff             *lbuff_push_back(t_lbuff **lbuff, t_blk *data)
{
    t_lbuff         *new;
    t_lbuff         *ptr;

    if ((new = lbuff_new_elem(data)))
    {
        if (!*lbuff)
            *lbuff = new;
        else
        {
            ptr = *lbuff;
            while (ptr->next)
                ptr = ptr->next;
            ptr->next = new;
        }
    }
    return (new);
}
