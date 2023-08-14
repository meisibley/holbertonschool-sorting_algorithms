#include "sort.h"

/**
 * selection_sort - It sorts an array of int in ascending using Selection sort
 * @array: a given array to be sorted
 * @size: The size of array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	int i, j, k, current;

	if (!array || size <= 1)
		return;
	for (i = 0; i < (int)size - 1; i++)
	{
		current = array[i];
		for (j = i + 1; j <= (int)size - 1; j++)
		{
			if (current > array[j])
			{
				current = array[j];
				k = j;
			}
		}
		if (current != array[i])
		{
			array[k] = array[i];
			array[i] = current;
			print_array(array, size);
		}
	}
}
