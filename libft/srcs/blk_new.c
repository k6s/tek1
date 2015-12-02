#include <libft.h>

t_blk           *blk_new(void *data, size_t len)
{
    t_blk       *new;

    if ((new = malloc(sizeof(*new))))
    {
        new->data = data;
        new->len = len;
    }
    return (new);
}
