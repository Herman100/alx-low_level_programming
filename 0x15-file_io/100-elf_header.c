#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_elf_header - prints the ELF header information
 * @header: pointer to the ELF header
 */
void print_elf_header(Elf32_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
	printf("  Class: %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ?
			"ELF32" : "ELF64");
	printf("  Data:     %s\n", header->e_ident[EI_DATA] == ELFDATA2MSB ?
			"big endian" : "little endian");
	printf("  Version:       %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:       %s\n", header->e_ident[EI_OSABI] == 0 ?
			"UNIX - System V" : "unknown");
	printf("  ABI Version:         %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type: %s\n", header->e_type == ET_NONE ? "NONE (Unknown type)" :
			header->e_type == ET_REL ? "REL (Relocatable file)" :
			header->e_type == ET_EXEC ? "EXEC (Executable file)" :
			header->e_type == ET_DYN ? "DYN (Shared object file)" :
			header->e_type == ET_CORE ? "CORE (Core file)" :
			"unknown");
	printf("  Entry point address:  %#lx\n", (unsigned long)header->e_entry);
	printf("\n");
}

/**
 * main - displays the information contained in
 * the ELF header at the start of an ELF file.
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf32_Ehdr header;

	if (argc != 2)

	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		return (98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))

	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(fd);
		return (98);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
		header.e_ident[EI_MAG1] != ELFMAG1 ||
		header.e_ident[EI_MAG2] != ELFMAG2 ||
		header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file %s\n", argv[1]);
		close(fd);
		return (98);
	}

	print_elf_header(&header);
	close(fd);
	return (0);
}

