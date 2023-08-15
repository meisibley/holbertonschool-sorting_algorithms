#include "sort.h"

/**
 * quick_sort - It sorts an array of int in ascending order using Quick sort
 * @array: Given array need to sort
 * @size: size of this array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	int i, j;

	if (!array || size <= 1)
		return;
	i = 0;
	j = (int)size - 1;
	/*build another func so can bring low & high arguments use recursive*/
	quicksort(array, i, j, size);
}

/**
 * quicksort - recursive to run pivot tree, print array each branch created
 * @array: Given array need to sort
 * @low: low index in the array (i)
 * @high: high index in the array (j)
 * @size: array size
 *
 * Return: nothing
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		/*sort each pivot branch*/
		p = partition(array, low, high, size);
		/*recursive pivot binary tree*/
		quicksort(array, low, p - 1, size);
		quicksort(array, p + 1, high, size);
	}
}

/**
 * partition - Lomuto scheme partition, sort array branches
 * @array: Given array
 * @low: low index in the array
 * @high: high index in the array
 * @size: array size
 *
 * Return: next pivot index
 */
size_t partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, swap;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap = array[j];
			array[j] = array[i];
			array[i] = swap;
			if (i != j)
				print_array(array, size);
		}
	}
	i++;
	swap = array[high];
	array[high] = array[i];
	array[i] = swap;
	if (i != high)
		print_array(array, size);
	return (i);
}
