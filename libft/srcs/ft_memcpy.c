#include <libft.h>

void        *ft_memcpy(void *dest, const void *src, size_t n)
{
    int     i;

    i = -1;
    while ((size_t)++i < n)
        *(char *)(dest + i) = *(char *)(src + i);
    return (dest);
}
