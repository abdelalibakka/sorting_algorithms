#include "sort.h"
#include <stdlib.h>
/**
* count_array - creating the_count_array
* @array: array_of_integers
* @size: size_of_array
* @k: largest_number_in unsorted_array
* Return: the count_array
*/
int *count_array(int *array, size_t size, int k)
{
	int *ca, i;
	size_t j;

	ca = malloc((k + 1) * sizeof(int));
	if (ca == NULL)
		return (NULL);
	for (i = 0; i < (k + 1); i++)
		ca[i] = 0;
	for (j = 0; j < size; j++)
		ca[array[j]]++;
	for (i = 1; i <= k; i++)
		ca[i] = ca[i] + ca[i - 1];
	print_array(ca, k + 1);
	return (ca);
}
/**
* counting_sort - sortsArray of_integers in a ascendingOrder
* using the Counting_sortAlgorithm
* @array: array_of_integers
* @size: size_of_array
*/
void counting_sort(int *array, size_t size)
{
	int *b, k, *ca, j;
	size_t i;

	if (array == NULL || size < 2)
		return;
	k = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	ca = count_array(array, size, k);
	if (ca == NULL)
		return;

	b = malloc(size * sizeof(int));
	if (b == NULL)
	{
		free(ca);
		return;
	}

	for (j = size - 1; j >= 0; j--)
		b[--ca[array[j]]] = array[j];
	for (i = 0; i < size; i++)
		array[i] = b[i];
	free(b);
	free(ca);
}
