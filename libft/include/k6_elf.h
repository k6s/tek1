#ifndef ELF_H
# define ELF_H

# include <k6_file.h>
# include <stdint.h>

# define ELF_MAGIC		0x7f454C46
# define ELF_CIGAM		0x464C457f

typedef struct s_class_elf		t_class_elf;
typedef struct s_elf			t_elf;

typedef struct s_helf			t_helf;
typedef struct s_shelf			t_shelf;

typedef struct s_shstr			t_shstr;
typedef struct s_symtab			t_symtab;

/*
 * ELF CLASS
 * ============================================================================
 */
struct					s_class_elf
{
	t_class_file		*file;
	t_elf				*self;
	t_elf				*(*new)();
	void				(*set)();
	t_file				*(*destroy)();
	void				(*destroy_class)();
	t_shelf				*(*get_shelf)();
	t_blk				*(*get_section)();
	ssize_t				(*get_symtab)();
	void				(*print_shelf)();
};

t_class_elf				*get_class_elf(void);


t_elf					*new_elf(char *pathname, int fd, t_file *file);
void					set_elf(t_elf *elf);
char					load_elf(int perms);
t_file					*destroy_elf(void);
void					destroy_class_elf(void);
t_blk					*get_elf_section(t_blk *section_str);
t_shelf					*get_shelf(t_blk *blk);
ssize_t					get_elf_symtab(void);
void					print_shelf(void);

/*
 * ELF OBJECT
 * ============================================================================
 */
struct					s_elf
{
	t_file				*file;
	t_helf				*header;
	t_shelf				**shelf;
	t_shstr				*shstr;
	t_symtab			**symtab;
	void				*prog_head;
};

/*
 * ELF HEADER
 * ============================================================================
 */
struct					s_helf
{
	int32_t				magic;
	char				format;
	char				endian;
	char				abi;
	char				abi_version;
	char				pad[8];
	int16_t				type;
	int16_t				instruct_set;
	int32_t				version;
# ifdef __x86_64__
	int64_t				entry_off;
	int64_t				prog_off;
	int64_t				section_off;
# else
	int32_t				entry_off;
	int32_t				prog_off;
	int32_t				section_off;
# endif
	int32_t				flags;
	int16_t				hlen;
	int16_t				prog_entry_len;
	int16_t				prog_entry_num;
	int16_t				section_entry_len;
	int16_t				section_entry_num;
	int16_t				section_str_idx;
};

/*
 * ELF SECTION
 * ============================================================================
 */

struct					s_shelf
{
	int32_t				name;	/* section name */
	int32_t				type;	/* SHT_... */
	int32_t				flags;	/* SHF_... */
#ifdef __x86_64__
	int64_t				addr;	/* virtual address */
	int64_t				offset;	/* file offset */
#else
	int32_t				addr;	/* virtual address */
	int32_t				offset;	/* file offset */
#endif
	int32_t				size;	/* section size */
	int32_t				link;	/* misc info */
	int32_t				info;	/* misc info */
	int32_t				addralign;	/* memory alignment */
	int32_t				entsize;	/* entry size if table */
};

/*
 * ELF SHSTRTAB
 * ============================================================================
 */
struct					s_shstr
{
	t_blk				entry_name;
	t_shelf				*header;
};

/*
 * ELF SYMTAB
 * ============================================================================
 */
struct					s_symtab
{
	/*
# ifdef __x86_64__
	uint64_t			name;
	uint64_t			value;
	uint64_t			size;
	unsigned char		info;
	unsigned char		pad;
	uint16_t			shidx;
*/
# ifdef __x86_64__
	uint32_t			name;
	unsigned char		info;
	unsigned char		pad;
	uint16_t			shidx;
	uint64_t			value;
	uint64_t			size;
# else
	int32_t				name;
	int32_t				value;
	int32_t				size;
	char				info;
	char				pad;
	int16_t				shidx;
# endif
};

#endif
