#include <k6_file.h>

static t_class_file		*init_class_file(void)
{
	t_class_file		*class_file;

	if ((class_file = malloc(sizeof(*class_file))))
	{
		class_file->new = new_file;
		class_file->set = set_file;
		class_file->load = load_file;
		class_file->get_content = get_file_content;
		class_file->destroy = destroy_file;
		class_file->destroy_class = destroy_class_file;
	}
	return (class_file);
}

t_class_file			*static_class_file(t_file *file, char destroy)
{
	static t_class_file	*class_file = NULL;

	if (class_file || (class_file = init_class_file()))
	{
		if (file)
			class_file->self = file;
		if (destroy)
		{
			free(class_file);
			class_file = NULL;
		}
	}
	return (class_file);
}

t_file					*new_file(int fd, char *pathname)
{
	t_file				*file;

	if ((file = malloc(sizeof(*file))))
	{
		file->fd = fd;
		file->pathname = pathname;
		file->blk = NULL;
	}
	return (file);
}

t_class_file			*get_class_file(void)
{
	return (static_class_file(NULL, 0));
}

void					set_file(t_file *file)
{
	static_class_file(file, 0);
}

t_blk					*destroy_file(void)
{
	t_class_file		*class_file;
	t_blk				*blk;

	blk = NULL;
	class_file = get_class_file();
	if (class_file && (class_file->self))
	{
		blk = class_file->self->blk;
		close(class_file->self->fd);
		free(class_file->self);
		class_file->self = NULL;
	}
	return (blk);
}

void					destroy_class_file()
{
	static_class_file(NULL, 1);
}
