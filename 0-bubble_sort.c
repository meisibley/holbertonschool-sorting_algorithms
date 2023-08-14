#include "sort.h"

/**
 * bubble_sort - bubble sort an array
 * @array: input array
 * @size: array size
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int swap, j;
	size_t i;

	if (!array || size <= 0)
		return;
	for (j = (int)size - 1; j >= 0; j--)
	{
		i = 0;
		while ((int)i < j)
		{
			if (array[i] > array[i + 1])
			{
				swap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = swap;
				print_array(array, size);
			}
			i++;
		}
	}
}
