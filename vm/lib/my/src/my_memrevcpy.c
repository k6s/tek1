#include <my.h>

size_t			my_memrevcpy(void *dst, const void *src, size_t len)
{
  size_t		idx;
  const char		*sp = src;
  char			*dp;

  idx = 0;
  dp = dst;
  while (idx < len)
    {
      dp[idx] = sp[len - idx - 1];
      ++idx;
    }
  return (idx);
}
