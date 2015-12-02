#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>

# include <stdio.h>

typedef struct s_string         t_string;
typedef struct s_lbuff          t_lbuff;
typedef struct s_blk            t_blk;

/*
 * Standard libc functions
 */

void            *ft_memchr(const void *s, char c, size_t n);
void            *ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memdup(void *data, size_t len);

ssize_t			puthex_len(int64_t nbr, ssize_t len);

/*
 * 
 */

struct          s_blk
{
    void        *data;
    size_t      len;
};

t_blk           *blk_new(void *data, size_t len);
t_blk			*blk_tok(t_blk *blk, char tok);
t_blk			*blk_dup(t_blk *blk, size_t len);
char			*ft_blkstr(t_blk *haystack, t_blk *needle);

/*
 * SIMPLE CHAINED LIST
 * ============================================================================
 */

# define DATA	blk->data
# define LEN	blk->len

struct          s_lbuff
{
	t_blk		*blk;
    t_lbuff     *next;
};

/*
 * Create and destroy functions
 * ============================
 */

/*
 * lbuff_new_elem() malloc a new t_lbuff elem and assign it's data field to the
 * return off the blk_new function, passing data and len as parameters.
 * lbuff_push_back create a new t_lbuff elem using lbuff_new_elem() and push it
 * at the end of the t_lbuff list, updating lbuff pointer if necessary.
 * Those functiuns return the newly created lbuff elem or NULL if malloc failed.
 */
t_lbuff         *lbuff_new_elem(t_blk *data);
t_lbuff         *lbuff_push_back(t_lbuff **lbuff, t_blk *data);
t_lbuff			*lbuff_qsort(t_lbuff *lbuff, int (*cmp)());

/*
 * t_lbuff list to t_blk elem
 * ==========================
 */

/*
 * lbuff_extract_blk() returns the blk field of the t_lbuff parameter then free
 * it.
 */
t_blk			*lbuff_extract_blk(t_lbuff **buff);

/*
 * lbuff_extract_tok() copy the t_lbuff elems data fields into a t_blk elem
 * until a *del characeter is met (including it). The t_buff list is updated and
 * start now right after the  *del character. It's basically a custom function
 * of strtok. It returns the t_blk elem or NULL in case of pb or if no *del char
 * is met.
 */
t_blk			*lbuff_extract_tok(t_lbuff **b_buff, char *del);

char            *lbuff_memchr(t_lbuff **lbuff_ptr, char c, size_t *tlen);

#endif
