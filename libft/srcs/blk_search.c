#include <libft.h>

char		*blk_search(t_blk *haystack,t_blk *needle)
{
	int		idx;

	idx = -1;
	if (haystack->len < needle->len)
		return (NULL);
	while ((unsigned)(++idx) < (haystack->len - needle->len))
	{
		if (!memcmp(haystack->data + idx, needle, needle->len))
			return (haystack->data + idx);
	}
	return (NULL);
}
