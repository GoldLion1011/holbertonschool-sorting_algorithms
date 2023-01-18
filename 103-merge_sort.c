#include "sort.h"

/**
 * merge_sort - merge sorts an array
 * @array: pointer to array to sort
 * @size: size of array
 */

void merge_sort(int *array, size_t size)
{
	int *tmp_arr = malloc(sizeof(array[0]) * size);

	copy_array(array, 0, tmp_arr, size);
	recur_split(array, tmp_arr, 0, size);
	free(tmp_arr);
}

/**
 * recur_split - recursively splits array into subarrays
 * @array: pointer to array to sort
 * @tmp_arr: pointer to temporary array
 * @start: start index of array
 * @end: end index of array
 */
void recur_split(int *array, int *tmp_arr, size_t start, size_t end)
{
	size_t mid;

	if (end - start < 2)
		return;
	mid = (start + end) / 2;
	recur_split(tmp_arr, array, start, mid);
	recur_split(tmp_arr, array, mid, end);
	merge_it(array, tmp_arr, start, mid, end);
}

/**
 * copy_array - copies array into temporary array
 * @array: pointer to array to copy
 * @start: start index of array
 * @tmp_arr: pointer to temporary array
 * @end: end index of array
 */
void copy_array(int *array, size_t start, int *tmp_arr, size_t end)
{
	size_t i;

	for (i = start; i < end; i++)
		tmp_arr[i] = array[i];
}

/**
 * print_da_array - prints array
 * @array: pointer to array to print
 * @start: start index of array
 * @end: end index of array
 */
void print_da_array(int *array, size_t start, size_t end)
{
	size_t i;

	for (i = start; i < end; i++)
	{
		printf("%d ", array[i]);
		if (i < end - 1)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 * merge_it - merges two subarrays
 * @array: pointer to array to sort
 * @tmp_arr: pointer to temporary array
 * @start: start index of array
 * @mid: middle index of array
 * @end: end index of array
 */
void merge_it(int *array, int *tmp_arr, size_t start, size_t mid, size_t end)
{
	size_t i = start, j = mid, k = start;

	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || tmp_arr[i] <= tmp_arr[j]))
		{
			array[k] = tmp_arr[i];
			i++;
		}
		else
		{
			array[k] = tmp_arr[j];
			j++;
		}
	}
	printf("Merging...\n[left]: ");
	print_da_array(tmp_arr, start, mid);
	printf("[right]: ");
	print_da_array(tmp_arr, mid, end);
	printf("[Done]: ");
	print_da_array(array, start, end);
}
