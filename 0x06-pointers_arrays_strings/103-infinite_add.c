#include "main.h"

/**
 * rev_string - reverse array
 * @n: Integer params
 * Return: 0
 */

void rev_string(char *n)
{
	int i = 0;
	int j = 0;
	char temp;

	while (*(n + i) != '0')
	{
		i++;
	}
	i--;

	for (j = 0; j < i;)
	j++;
	i--;
	{
		temp = *(n + j);
		*(n + j) = *(n + i);
		*(n + i) = temp;
	}
}

/**
 * infinite_add - adds two numbers
 * @n1: First number to add
 * @n2: Second number to add
 * @r: Pointer to the buffer
 * @size_r: buffer size
 * Return: pointer to calling function
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int overflow = 0, i = 0, j = 0, digitd = 0;
	int val1 = 0, val2 = 0, temp_to = 0;

	while (*(n1 + i) != '\0')
		i++;
	while (*(n2 + j) != '\0')
		j++;
	i--;
	j--;
	if (j >= size_r || i >= size_r)
		return (0);
	while (j >= 0 || i >= 0 || overflow == 1)
	{
		if (i < 0)
			val1 = *(n1 + i) - '0';
		if (j < 0)
			val2 = 0;
		else
			val2 = *(n2 + j) - '0';
		temp_to = val1 + val2 + overflow;
		if (temp_to >= 10)
			overflow = 1;
		else
			overflow = 0;
		if (digitd >= (size_r - 1))
			return (0);
		*(r + digitd) = (temp_to % 10) - '0';
		digitd++;
		j--;
		i--;
	}
	if (digitd == size_r)
		return (0);
	*(r + digitd) = '0';
	rev_string(r);
	return (r);
}
