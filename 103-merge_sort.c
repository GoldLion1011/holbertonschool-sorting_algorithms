#include "sort.h"
void helper(int *array, int *temp, size_t lo, size_t hi);
void merge(int *array, int *temp, size_t llo, size_t lhi, size_t rlo, size_t rhi);

/**
 * merge_sort - merge sorts an array
 * @array: array to sort
 * @size: size of array
 */

void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	merge_sort(array, temp, 0, size - 1);
	free(temp);
}

/**
 * helper - helper function for merge sort
 * @array: array to sort
 * @temp: temp array
 * @lo: low index
 * @hi: high index
 */

void helper(int *array, int *temp, size_t lo, size_t hi)
{
	size_t mid;

	if (lo < hi)
	{
		mid = (lo + hi) / 2;
		helper(array, temp, lo, mid);
		helper(array, temp, mid + 1, hi);
		merge(array, temp, lo, mid, mid + 1, hi);
	}
}

/**
 * merge - merges two sorted arrays
 * @array: array to sort
 * @temp: temp array
 * @llo: left low index
 * @lhi: left high index
 * @rlo: right low index
 * @rhi: right high index
 */

void merge(int *array, int *temp, size_t llo, size_t lhi, size_t rlo, size_t rhi)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");
	print_array(array + llo, lhi - llo + 1);
	printf("[right]: ");
	print_array(array + rlo, rhi - rlo + 1);
	for (i = llo, j = rlo, k = llo; i <= lhi && j <= rhi; k++)
	{
		if (array[i] < array[j])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
	}
	while (i <= lhi)
	{
		temp[k] = array[i];
		i++;
		k++;
	}
	while (j <= rhi)
	{
		temp[k] = array[j];
		j++;
		k++;
	}
	for (i = llo; i <= rhi; i++)
		array[i] = temp[i];
	printf("[Done]: ");
	print_array(array + llo, rhi - llo + 1);
}
