#include <k6_elf.h>

static t_class_elf		*init_class_elf()
{
	t_class_elf			*class_elf;

	if ((class_elf = malloc(sizeof(*class_elf))))
	{
		class_elf->file = get_class_file();
		class_elf->self = NULL;
		class_elf->new = new_elf;
		class_elf->set = set_elf;
		class_elf->destroy = destroy_elf;
		class_elf->destroy_class = destroy_class_elf;
		class_elf->get_shelf = get_shelf;
		class_elf->get_section = get_elf_section;
		class_elf->get_symtab = get_elf_symtab;
		class_elf->print_shelf = print_shelf;
	}
	return (class_elf);
}

t_class_elf				*static_class_elf(t_elf *elf, char destroy)
{
	static t_class_elf	*s_class_elf = NULL;

	if (s_class_elf || (s_class_elf = init_class_elf()))
	{
		if (elf)
			s_class_elf->self = elf;
		if (destroy)
		{
			free(s_class_elf);
			s_class_elf = NULL;
		}
	}
	return (s_class_elf);
}

t_class_elf				*get_class_elf(void)
{
	return (static_class_elf(NULL, 0));
}

void					set_elf(t_elf *elf)
{
	t_class_elf			*class_elf;

	static_class_elf(elf, 0);
	class_elf = get_class_elf();
	class_elf->file->set(elf->file);
}


t_elf					*new_elf(char *pathname, int fd, t_file *file)
{
	t_elf				*elf;
	t_class_elf			*class_elf;

	class_elf = get_class_elf();
	if (class_elf && (elf = malloc(sizeof(*elf))))
	{
		if (file)
			elf->file = file;
		else
			elf->file = class_elf->file->new(fd, pathname);
		elf->header = NULL;
	}	
	return (elf);
}

ssize_t					get_elf_symtab(void)
{
	t_class_elf			*class_elf;
	const t_blk			symtab_ref = {".symtab", 8};
	t_shelf				*symtab_sh;
	t_blk				*symtab;
	ssize_t				idx;

	if ((class_elf = get_class_elf()))
	{
		if ((symtab = class_elf->get_section(&symtab_ref)))
		{
			if ((symtab_sh = class_elf->get_shelf(&symtab_ref)))
			{
				idx = -1;
				if ((class_elf->self->symtab = malloc(sizeof(t_symtab *)
									* (symtab_sh->size / sizeof(t_symtab)))))
				{
					while ((size_t)++idx < (symtab_sh->size / sizeof(t_symtab)))
						class_elf->self->symtab[idx] = symtab->data + idx
							* sizeof(t_symtab);
					return (idx);
				}
			}
		}
	}
	return (-1);
}

t_blk					*get_elf_section(t_blk *section_name)
{
	t_class_elf			*class_elf;
	t_shelf				*section_sh;
	t_blk				*section_blk;
	void				*section;

	class_elf = get_class_elf();
	section_sh = class_elf->get_shelf(section_name);
	section = NULL;
	if (section_sh)
		section = section_sh->offset + class_elf->self->file->DATA;
	section_blk = blk_new(section, section_sh->size);
	return (section_blk);
}

t_shelf					*get_shelf(t_blk *section_name)
{
	t_class_elf			*class_elf;
	t_shelf				*shelf;
	void				*shstrtab;
	size_t				len;
	ssize_t				idx;

	class_elf = get_class_elf();
	shelf = class_elf->self->shelf[class_elf->self->header->section_str_idx];
	shstrtab = (void *)(class_elf->self->file->DATA + shelf->offset);
	idx = -1;
	while (++idx < class_elf->self->header->section_entry_num)
	{
		len = section_name->len - 1;
		if (!memcmp(section_name->data,
					shstrtab + class_elf->self->shelf[idx]->name, len))
			return (class_elf->self->shelf[idx]);
	}
	return (NULL);
}

void				print_shelf(void)
{
	int				idx;
	t_class_elf		*class_elf;
	t_shelf			**shelf;

	idx = -1;
	if ((class_elf = get_class_elf()) && class_elf->self)
	{
		shelf = class_elf->self->shelf;
		printf("                                    Sections Header				\
			   \n");
		printf("LEN (Bytes): %d\tNUMBER: %d\tSTR_IDX: %d\n",\
			   class_elf->self->header->section_entry_len,
			   class_elf->self->header->section_entry_num,\
			   class_elf->self->header->section_str_idx);
		printf("===============================================================\
			   ====================\n");
		while (++idx < class_elf->self->header->section_entry_num)
		{
			printf("[%d]\tname: %x\ttype: %x\tflags: %x\taddr: %lx\toffset: %lx\n",
				   idx, shelf[idx]->name, shelf[idx]->type, shelf[idx]->flags,
				   shelf[idx]->addr, shelf[idx]->offset);
			printf("\tsize: %x\tlink: %x\tinfo: %x\taddralign: %x\tentsize: %x\n",
				   shelf[idx]->size, shelf[idx]->link, shelf[idx]->info,
				   shelf[idx]->addralign, shelf[idx]->entsize);
			printf("===========================================================\
				   ========================\n");
		}
	}
}

static char				fill_shelf(void)
{
	t_class_elf			*class_elf;
	t_helf				*helf;
	int32_t				idx;
	char				*p_file;

	if (!(class_elf = get_class_elf()))
		return (-1);
	helf = class_elf->self->header;
	p_file = class_elf->self->file->DATA;
	if ((class_elf->self->shelf
		 = malloc(sizeof(helf) * helf->section_entry_num)))
	{
		idx = -1;
		while (++idx < helf->section_entry_num)
		{
			class_elf->self->shelf[idx]
				= (t_shelf *)(p_file + helf->section_off
							  + (helf->section_entry_len * idx));
		}
		return (1);
	}
	return (-1);
}

static char				get_helf(void)
{
	char				*p_file;
	t_class_elf			*class_elf;

	class_elf = get_class_elf();
	if (class_elf && (p_file = class_elf->self->file->DATA))
	{
		class_elf->self->header = class_elf->self->file->DATA;
		if (class_elf->self->header->magic == ELF_CIGAM)
			return (fill_shelf());

	}
	return (-1);
}

char					load_elf(int perms)
{
	t_class_elf			*class_elf;
	t_elf				*elf;

	class_elf = get_class_elf();
	elf = class_elf->self;
	if (elf && elf->file)
	{
		if (elf->file || (load_file(perms)) > -1)
		{
			printf("FILE LOADED\n");
			return (get_helf());
		}
	}
	return (-1);
}

t_file					*destroy_elf(void)
{
	t_class_elf			*class_elf;
	t_file				*file;

	class_elf = get_class_elf();
	file = NULL;
	if (class_elf && class_elf->self)
	{
		file = class_elf->self->file;
		free(class_elf->self);
		class_elf->self = NULL;
	}
	return (file);
}

void					destroy_class_elf(void)
{
	static_class_elf(NULL, 1);
}
