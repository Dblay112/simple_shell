#include "shellheader.h"

/**
 * reset_structure - resets value of the arg in the func
 * @reader: pointer to the struct
 * @descriptor: handles a file opening or not
 * Return: nothing
 */

void reset_structure(bline *reader, int explainer)
{
	reader->explainer = 0;
	memfill_shell(reader->readerloc, 0, sizeof(reader->readerloc));
	reader->indes = 0;
	reader->lens = 0;

	if (reader->explainer != explainer)
	{
		reader->explainer = explainer;
		reader->indes = 0;
		reader->lens = 0;
	}

	if (explainer == -1)
	{
		reader->explainer = 0;
		reader->indes = 0;
		reader->lens = 0;
	}
}

/**
 * filereader - function to read from a file descriptor
 * @descriptor: file descriptor from which data will be read
 * @reader: pointer to the struct
 * Return: the data that has been read
 */

ssize_t filereader(int explainer, bline *reader)
{
	ssize_t r;

	r = shell_buffile(explainer, reader->readerloc + reader->lens,
		OUR_LINE_LENGTH - reader->lens);
	if (r < 0)
	{
		return (-1);
	}
	if (r == 0 && reader->lens == 0)
	{
		return (-1);
	}
	if (r == 0)
	{
		return (0);
	}
	reader->lens += r;
	return (r);
}

/**
 * fileplacereader - reads info from the line in the function
 * @line_length: length of the input
 * @reader: pointer to the reader
 * @line: line to be read
 * Return: info read from the input
 */

int fileplacereader(bline *reader, ssize_t *line_length, char **line)
{
	int i;
	char *p = reader->readerloc + reader->indes;
	char *end = reader->readerloc + reader->indes + reader->lens;

	while (p < end && *p != '\n')
	{
		p++;
	}

	if (p < end)
	{
	*line_length = p - (reader->readerloc + reader->indes);
	*line = (char *)malloc((*line_length + 1) * sizeof(char));
	if (*line == NULL)
	{
		return (-1);
	}
	for (i = 0; i < *line_length; i++)
	{
		(*line)[i] = reader->readerloc[reader->indes + i];
	}
	(*line)[*line_length] = '\0';
	reader->indes += *line_length + 1;
	reader->lens -= *line_length + 1;
	if (reader->lens == 0)
	{
		reader->indes = 0;
	}
	return (1);
	}

	if (reader->lens == OUR_LINE_LENGTH)
	{
		reader->indes = 0;
		reader->lens = 0;
	}
	return (0);
}
/**
 * bufferfile_handler - read and store in line pointer
 * @lineptr: pointer to store the data
 * @n: pointer to the variable used to store the data
 * @descriptor: file descriptor of the file that will be read
 * Return: the length of the line
 */


ssize_t bufferfile_handler(char **lineptr, size_t *n, int explainer)
{
	static bline reader;
	ssize_t line_length = 0;
	ssize_t r;
	int result;

	reset_structure(&reader, explainer);

	while (1)
	{
		r = filereader(explainer, &reader);
		if (r < 0)
		{
		return (-1);
		}
		if (r == 0)
		{
			break;
		}
		result = fileplacereader(&reader, &line_length, lineptr);
		if (result == -1)
		{
			return (-1);
		}
		if (result == 1)
		{
			*n = line_length;
			return (line_length);
		}
	}

	*lineptr = NULL;
	*n = 0;
	return (0);
}
