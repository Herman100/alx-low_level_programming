#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 *
 * Return: actual number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    ssize_t num_read, num_written;
    char *buf;

    if (!filename)
        return (0);

    buf = malloc(sizeof(char) * (letters + 1));
    if (!buf)
        return (0);

    /* Open file for reading */
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        free(buf);
        return (0);
    }

    /* Read from file */
    num_read = read(fd, buf, letters);
    if (num_read == -1)
    {
        free(buf);
        close(fd);
        return (0);
    }

    /* Null-terminate the buffer */
    buf[num_read] = '\0';

    /* Print to standard output */
    num_written = write(STDOUT_FILENO, buf, num_read);
    if (num_written == -1 || num_written != num_read)
    {
        free(buf);
        close(fd);
        return (0);
    }

    /* Cleanup and return the number of bytes read */
    free(buf);
    close(fd);
    return (num_read);
}

