#include <k6_file.h>

static char				use_mmap(int flags[2], t_file *file)
{
	struct stat			stat_buff;

	if (!fstat(file->fd, &stat_buff))
	{
		if (file->blk
			|| (file->blk = blk_new(NULL, stat_buff.st_size)))
		{
			if (!file->DATA)
			{
				file->DATA = mmap(NULL, file->LEN, flags[CLASS_FILE_PROT],
								  flags[CLASS_FILE_FLAGS], file->fd, 0);
				if (file->DATA == (void *)-1)
					return (-1);
			}
			return (1);
		}
	}
	return (-1);
}

static char			use_read(int flags[2], t_file *file)
{
	printf("not implemented... yet\n");
}

char				get_file_content(int flags[2], char mean)
{
	t_class_file	*class_file;

	if ((mean == FILE_MMAP()))
		return (use_mmap(flags, file));
	else if ((mean == FILE_READ()))
		return ((use_read(flags, file)));
}
