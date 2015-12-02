#include <k6_file.h>

static char			use_mmap(int flags[2])
{
	t_class_file		*class_file;

	class_file = get_class_file();
	if ((mmap(class_file->self->DATA,
			class_file->self->LEN, flags[CLASS_FILE_PROT],
			flags[CLASS_FILE_FLAGS], class_file->self->fd,
			class_file->self->offset)) == MAP_FAILED)
		return (-1);
	else
		return (class_file->self->LEN);
}

char					get_file_content(int flags[2], char mean)
{
	if (mean == FILE_MMAP)
		return (use_mmap(flags));
	return (-1);
}

char					load_file(int perms)
{
	t_class_file		*class_file;
	t_file				*file;

	class_file = get_class_file();
	if (class_file && (file = class_file->self))
	{
		if ((file->fd < 0 && file->pathname) &&
			(file->fd = open(file->pathname, perms)) > -1)
			return (1);
	}
	return (-1);
}
