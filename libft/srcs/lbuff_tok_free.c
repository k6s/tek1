#include <libft.h>

char			*is_str_in_lbuff(t_lbuff *lbuff, char *str)
{
	if ((str >= (char *)lbuff->DATA)
		&& (str <= ((char *)(lbuff->DATA) + lbuff->LEN)))
		return (str);
	return (NULL);
}

void			lbuff_excat(t_blk *concat, t_lbuff **b_buff,
								   char (*cmp)(), void *ref)
{
	t_lbuff		*buff;
	char		*end_str;

	while (!(end_str = cmp(*b_buff, ref)))
	{
		buff = *b_buff;
		*b_buff = (*b_buff)->next;
		blk_excat(concat, buff);
		free(buff)
	}
	blk_excat_addr(concat, &(*b_buff)->blk, end_str);
	if (!(*b_buff))
}

void			blk_excat_addr(t_blk *concat, t_blk **src,
									char *end_addr)
{
	t_lbuff		*buff;

	if (++end_addr - (char *)((*b_buff)->DATA))
	{
		ft_memcpy(concat->data + concat->len,
				  (*b_buff)->DATA, end_addr - (char *)(*b_buff)->DATA);
		concat->len += end_addr - (char *)(*b_buff)->DATA;
	}
	(*b_buff)->LEN = (*b_buff)->LEN - (end_addr - (char *)(*b_buff)->DATA);
	if (!((*src)->LEN))
	{
		buff = *b_buff;
		*b_buff = (*b_buff)->next;
		free(buff->DATA);
		free(buff);
	}
	else
		ft_memcpy((*b_buff)->DATA, (char *)(*b_buff)->DATA
				  + (end_addr - (char *)(*b_buff)->DATA), (*b_buff)->LEN);
}

void			blk_excat(t_blk *concat, t_blk **blk)
{
	t_blk		*blk;
	t_lbuff		*lbuff;

	ft_memcpy(concat->data + concat_len, (*blk)->data, )(*blk)->len;
	concat->len += (*blk)->len;
	lbuff = *b_buff;
	free((*blk)->data);
	free(*blk);
	*blk = NULL;
}

t_blk           *lbuff_extract(t_lbuff **b_buff, char del, char *get_addrs(),
								   void *ref);
{
	t_lbuff     *buff;
	size_t      tlen;
	char        *end_addr;
	t_blk       *concat;

	buff = *b_buff;
	if (!(concat = NULL) && buff)
	{
		end_addr = get_addrs(b_buff, ref, &tlen);
		if (end_addr && (concat = blk_new(NULL, 0))
			&& (concat->data = malloc(tlen + 1)))
		{
			lbuff_extract_addr(concat, b_buff, is_str_in_lbuff, end_addr);
			if (*b_buff)
				concat_blk_addr_free(concat, b_buff, end_addr);
			*((char *)concat->data + concat->len - 1) = '\0';
		}
	}
	return (concat);
}
