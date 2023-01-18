#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int list_len(listint_t *h);
void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int l, int r);
void lomuto_sort(int *array, size_t size, int l, int r);
void swap(int *a, int *b);
void heapify(int *arr, int size_int, int i, size_t size);
void heap_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void recur_split(int *array, int *tmp_arr, size_t start, size_t end);
void copy_array(int *array, size_t start, int *tmp_arr, size_t end);
void print_da_array(int *array, size_t start, size_t end);
void merge_it(int *array, int *tmp_arr, size_t start, size_t mid, size_t end);

#endif
