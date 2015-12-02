#ifndef FILE_H
# define FILE_H

# include <libft.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/mman.h>

typedef struct s_class_file		t_class_file;
typedef struct s_file			t_file;

/*
 * FILE CLASS
 * ============================================================================
 */
struct				s_class_file
{
	t_file			*self;
	t_file			*(*new)();
	void			(*set)();
	char			(*load)();
	char			(*get_content)(int flags[2], char mean);
	t_blk			*(*destroy)();
	void			(*destroy_class)();
};

t_class_file		*get_class_file(void);

t_file				*new_file(int fd, char *pathname);
void				set_file(t_file *file);
# define CLASS_FILE_PERMS	0
char				load_file(int perms);
# define CLASS_FILE_PROT	0
# define CLASS_FILE_FLAGS	1
char				get_file_content(int flags[2], char mean);
# define FILE_MMAP			0
# define FILE_READ			1
t_blk				*destroy_file(void);
void				destroy_class_file(void);

/*
 * FILE OBJ
 * ============================================================================
 */
struct				s_file
{
	int				fd;
	char			*pathname;
	size_t			offset;
	t_blk			*blk;
};

#endif
