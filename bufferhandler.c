#include "shellheader.h"

/**
 * shell_buffile - function to read and store content in a buffer
 * @descriptor: file descriptor  from which the function will read STDIN.
 * @buffer: pointer to the buffer where the content will be stored.
 * @max_length: maximum char to read and store
 *
 * Return: the total number of characters read and stored in the buffer
 */

ssize_t shell_buffile(int descriptor, char *buffer, ssize_t max_length)
{
	ssize_t total_read;
	ssize_t bytes_read;
	char ch;

	bytes_read = 0;
	total_read = 0;
	while (total_read < max_length - 1)
	{
		bytes_read = read(descriptor, &ch, 1);

	if (bytes_read == -1)
	{
		return (-1);
	}
	else if (bytes_read == 0)
	{
		break;
	}
	else
	{
		buffer[total_read] = ch;
		total_read++;
	if (ch == '\n')
	{
		break;
	}
	}
	}

	buffer[total_read] = '\0';
	return (total_read);
}

/**
 * reader_shell - reads the content of a file spelt by the file descriptor
 * @descriptor: identifier of the file from which the function will read.
 * @buffer: A pointer to a pointer that will store the address of buffer
 * Return: total number of bytes read from the file ex null
 */

ssize_t reader_shell(int descriptor, char **buffer)
{
	off_t file_size;
	ssize_t buffer_size;
	ssize_t total_read;

	file_size = flush_file(descriptor, 0, SEEK_END);
	if (file_size == -1)
	{
		return (-1);
	}

	buffer_size = file_size + 1;
	*buffer = (char *)malloc(buffer_size * sizeof(char));
	if (*buffer == NULL)
	{
		return (-1);
	}

	flush_file(descriptor, 0, SEEK_SET);
	total_read = read(descriptor, *buffer, buffer_size - 1);
	if (total_read == -1)
	{
		free(*buffer);
		return (-1);
	}

	(*buffer)[total_read] = '\0';
	return (total_read);
}

/**
 * flush_file - recursive function to manipulate the file pointer position
 * @descriptor:  identifier of the file pointer
 * @offset:offset to be applied to the file pointer
 * @whence:  reference point from where the offset  applied.
 * Return: updated file pointer position within the file.
 */

off_t flush_file(int descriptor, off_t offset, int whence)
{
	off_t current_offset;
	off_t new_offset;
	off_t file_size;

	current_offset = flush_file(descriptor, 0, SEEK_CUR);
	new_offset = current_offset;
	if (whence == SEEK_SET)
	{
		new_offset = offset;
	}
	else if (whence == SEEK_CUR)
	{
		new_offset = current_offset + offset;
	}
	else if (whence == SEEK_END)
	{
		file_size = flush_file(descriptor, 0, SEEK_END);
		new_offset = file_size + offset;
	}

	flush_file(descriptor, new_offset, SEEK_SET);
	return (new_offset);
}

/**
 * mimic_flush - what can i say this here ezra did a flush style mimicer of fflush
 * @stream: the file itself could be stdin or stdout aman said
 * Return: 1 on success (for stdout), 0 on failure on other streams).
 */

int mimic_flush(FILE *stream)
{
	if (stream == stdout)
	{
		file_writer('\n', stream);
		return (0);
	}
	else
	{
		return (EOF);
	}
}
