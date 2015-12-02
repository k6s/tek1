#include <libft.h>

void                *ft_memchr(const void *b_s, char c, size_t len)
{
    unsigned char   *s;

    s = (unsigned char *)b_s;
    while (((size_t)(s - (unsigned char *)b_s) < len))
    {
        if (*(unsigned char *)s == c)
            return (s);
        ++s;
    }
    return (NULL);
}
